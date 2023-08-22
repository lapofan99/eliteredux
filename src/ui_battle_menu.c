#include "global.h"
#include "ui_battle_menu.h"
#include "strings.h"
#include "bg.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_anim.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_icon.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/abilities.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"

/*
 * 
 */

//==========DEFINES==========//
enum
{
    SPRITE_ARR_ID_MON_ICON_1,
    SPRITE_ARR_ID_MON_ICON_2,
    SPRITE_ARR_ID_MON_ICON_3,
    SPRITE_ARR_ID_MON_ICON_4,
    SPRITE_ARR_ID_STATUS,
    SPRITE_ARR_ID_ITEM,
    SPRITE_ARR_ID_TYPE_1,
    SPRITE_ARR_ID_TYPE_2,
    SPRITE_ARR_ID_TYPE_3,
    NUM_SPRITES,
};


struct MenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
    u8 battlerId;
    u8 modeId;
    u8 tabId;
    u8 tabModeId;
    u8 spriteIds[NUM_SPRITES];
};

enum WindowIds
{
    WINDOW_1,
};

enum battler_TabIds
{
    TAB_STATS,
    TAB_ABILITIES,
    TAB_MOVES,
    TAB_STATUS,
    TAB_DAMAGE_CALCULATOR,
    NUM_TABS,
};

enum menu_colors
{
    MENU_COLOR_BLUE,
    MENU_COLOR_RED,
    MENU_COLOR_YELLOW,
    MENU_COLOR_GREEN,
    NUM_COLORS,
};

enum modes
{
    MODE_BATTLER2,
    MODE_BATTLER0,
    MODE_FIELD,
    MODE_BATTLER1,
    MODE_BATTLER3,
    NUM_MODES
};
//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

//==========STATIC=DEFINES==========//
static void Battle_Menu_RunSetup(void);
static bool8 Menu_DoGfxSetup(void);
static bool8 Menu_InitBgs(void);
static void Menu_FadeAndBail(void);
static bool8 Menu_LoadGraphics(void);
static void Menu_InitWindows(void);
static void PrintToWindow(u8 windowId, u8 colorIdx);
static void PrintFieldTab(void);
static void PrintStatusTab(void);
static void PrintAbilityTab(void);
static void Task_MenuWaitFadeIn(u8 taskId);
static void Task_MenuMain(u8 taskId);

static u8 ShowSpeciesIcon(u8 num);
static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible);
static void SetMonTypeIcons(void);
static void SetTypeIconSpritePosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId);
static void CreateSetStatusSprite(void);
static u8 DestroyBattleMenuSprite(u8 spriteArrayId);
static void setBattler(void);
static void LoadTilemapFromMode(void);
static void PrintPage(void);

//==========CONST=DATA==========//
static const struct BgTemplate sMenuBgTemplates[] =
{
    {
        .bg = 0,    // windows, etc
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = 2,    // this bg loads the UI tilemap
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .priority = 0
    }
};

static const struct WindowTemplate sMenuWindowTemplates[] = 
{
    [WINDOW_1] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 0,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 30,        // width (per 8 pixels)
        .height = 20,       // height (per 8 pixels)
        .paletteNum = 0,    // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
};

static const u32 sMenuTiles[]    = INCBIN_U32("graphics/ui_menus/battle_menu/tiles.4bpp.lz");
static const u8 sStatDownArrow[] = INCBIN_U8("graphics/ui_menus/battle_menu/stat_down_arrow.4bpp");
static const u8 sStatUpArrow[]   = INCBIN_U8("graphics/ui_menus/battle_menu/stat_up_arrow.4bpp");
static const u8 sSelector[]      = INCBIN_U8("graphics/ui_menus/battle_menu/selector.4bpp");

//Palettes
static const u16 sMenuPalette[]        = INCBIN_U16("graphics/ui_menus/battle_menu/palette.gbapal");
static const u16 sMenuPalette_Blue[]   = INCBIN_U16("graphics/ui_menus/battle_menu/palette_blue.gbapal");
static const u16 sMenuPalette_Yellow[] = INCBIN_U16("graphics/ui_menus/battle_menu/palette_yellow.gbapal");
static const u16 sMenuPalette_Green[]  = INCBIN_U16("graphics/ui_menus/battle_menu/palette_green.gbapal");
static const u16 sMenuPalette_Red[]    = INCBIN_U16("graphics/ui_menus/battle_menu/palette_red.gbapal");

//Battler Tabs
static const u32 sMenu_Tilemap_Singles_Battler_Status[]     = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_singles_battler_status.bin.lz");
static const u32 sMenu_Tilemap_Doubles_Battler_Status[]     = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_doubles_battler_status.bin.lz");
//
static const u32 sMenu_Tilemap_Singles_Battler_Abilities[]  = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_singles_battler_abilities.bin.lz");
static const u32 sMenu_Tilemap_Doubles_Battler_Abilities[]  = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_doubles_battler_abilities.bin.lz");
//Field Tabs
static const u32 sMenu_Tilemap_Singles_Field[]              = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_singles_field.bin.lz");
static const u32 sMenu_Tilemap_Doubles_Field[]              = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_doubles_field.bin.lz");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  4,  2},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  1,  3},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT,  14, 2},
    [FONT_BLUE]   = {TEXT_COLOR_TRANSPARENT,  13, 2},
};

//==========FUNCTIONS==========//
// UI loader template
void Task_OpenBattleMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        UI_Battle_Menu_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void UI_Battle_Menu_Init(MainCallback callback)
{
    u8 i;
    if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    if(IsDoubleBattle())
        sMenuDataPtr->modeId = MODE_BATTLER2;
    else
        sMenuDataPtr->modeId = MODE_BATTLER0;
    setBattler();
    for(i = 0; i < NUM_SPRITES; i++)
        sMenuDataPtr->spriteIds[i] = SPRITE_NONE;
    sMenuDataPtr->savedCallback = callback;

    SetMainCallback2(Battle_Menu_RunSetup);
}

static void Battle_Menu_RunSetup(void)
{
    while (1)
    {
        if (Menu_DoGfxSetup() == TRUE)
            break;
    }
}

static void Menu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Menu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define POKEMON_ICON_X   (1 * 8)  + (2 * 8)

#define POKEMON_ICON_1_Y (4 * 8)  + (2 * 8)
#define POKEMON_ICON_2_Y (12 * 8) + (2 * 8)
#define POKEMON_ICON_3_Y (0 * 8)  + (2 * 8)
#define POKEMON_ICON_4_Y (16 * 8) + (2 * 8)

static bool8 Menu_DoGfxSetup(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (Menu_InitBgs())
        {
            sMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            Menu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (Menu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        LoadMessageBoxAndBorderGfx();
        Menu_InitWindows();
        gMain.state++;
        break;
    case 5:
        //CreateSetStatusSprite();
        ShowSpeciesIcon(0);
        ShowSpeciesIcon(1);
        ShowSpeciesIcon(2);
        ShowSpeciesIcon(3);
        //SetMonTypeIcons();
        PrintStatusTab();
        //PrintToWindow(WINDOW_1, FONT_BLACK);
        taskId = CreateTask(Task_MenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(Menu_VBlankCB);
        SetMainCallback2(Menu_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Menu_FreeResources(void)
{
    try_free(sMenuDataPtr);
    try_free(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
}

void LoadTilemapFromMode(void)
{
    try_free(sBg1TilemapBuffer);
    sBg1TilemapBuffer == NULL;

    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);

    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);

    //ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(1, sMenuTiles, 0, 0, 0);
    FreeTempTileDataBuffersIfPossible();

    if(sMenuDataPtr->modeId != MODE_FIELD){
        switch(sMenuDataPtr->tabId){
            case TAB_STATS:
                if(IsDoubleBattle())
                    LZDecompressWram(sMenu_Tilemap_Doubles_Battler_Status, sBg1TilemapBuffer);
                else
                    LZDecompressWram(sMenu_Tilemap_Singles_Battler_Status, sBg1TilemapBuffer);
            break;
            case TAB_ABILITIES:
            case TAB_MOVES:
                if(IsDoubleBattle())
                    LZDecompressWram(sMenu_Tilemap_Doubles_Battler_Abilities, sBg1TilemapBuffer);
                else
                    LZDecompressWram(sMenu_Tilemap_Singles_Battler_Abilities, sBg1TilemapBuffer);
            break;
            default:
                if(IsDoubleBattle())
                    LZDecompressWram(sMenu_Tilemap_Doubles_Field, sBg1TilemapBuffer);
                else
                    LZDecompressWram(sMenu_Tilemap_Singles_Field, sBg1TilemapBuffer);
            break;
        }
    }
    else{
        if(IsDoubleBattle()){
            LZDecompressWram(sMenu_Tilemap_Doubles_Field, sBg1TilemapBuffer);
        }
        else{
            LZDecompressWram(sMenu_Tilemap_Singles_Field, sBg1TilemapBuffer);
        }
    }
}

static void Task_MenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Menu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(Menu_VBlankCB);
    SetMainCallback2(Menu_MainCB);
}

static bool8 Menu_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;

    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 Menu_LoadGraphics(void)
{
    switch (sMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sMenuTiles, 0, 0, 0);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            if(IsDoubleBattle())
                LZDecompressWram(sMenu_Tilemap_Doubles_Battler_Status, sBg1TilemapBuffer);
            else
                LZDecompressWram(sMenu_Tilemap_Singles_Battler_Status, sBg1TilemapBuffer);
            sMenuDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sMenuPalette, 0, 32);
        sMenuDataPtr->gfxLoadState++;
        break;
    default:
        sMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void Menu_InitWindows(void)
{
    u32 i;

    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);

    FillWindowPixelBuffer(WINDOW_1, 0);
    LoadUserWindowBorderGfx(WINDOW_1, 720, 14 * 16);
    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);

    ScheduleBgCopyTilemapToVram(2);
}

static const u8 sText_MyMenu[] = _("HP: {STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_HP[] = _("{STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_PP[] = _("PP: {STR_VAR_1}/{STR_VAR_2}");

static const u8 sText_Ability[] = _("Ability:");
static const u8 sText_Innate[]  = _("Innate:");
static const u8 sText_Held_Item[] = _("Held Item:\n{STR_VAR_1}");
static const u8 sText_None[]  = _("None");
static const u8 sYourOpponentPokemonData[] = _("Your Opponent Pokémon Battle Data");
static const u8 sYourPokemonData[] = _("Your Pokémon Battle Data");

static const u8 sText_StatHP[]         = _("HP");
static const u8 sText_Attack[]         = _("Atk");
static const u8 sText_Defense[]        = _("Def");
static const u8 sText_SpecialAttack[]  = _("SpA");
static const u8 sText_SpecialDefense[] = _("SpD");
static const u8 sText_Speed[]          = _("Spd");
static const u8 sText_Accuracy[]       = _("Acc");
static const u8 sText_Evasion[]        = _("Eva");
static const u8 sText_Critical[]       = _("Crt");

static u8 statorder[NUM_BATTLE_STATS] = {
    STAT_HP,
    STAT_ATK,
    STAT_DEF,
    STAT_SPATK,
    STAT_SPDEF,
    STAT_SPEED,
    STAT_ACC,
    STAT_EVASION,
};

const u8 sText_Title_Battler_Stats[]    = _("Pokémon Stats");
const u8 sText_Title_Battler_Ability[]  = _("Abilities Info");
const u8 sText_Title_Battler_Moves[]    = _("Moves Info");
const u8 sText_Title_Battler_Status[]    = _("Pokémon Status");
const u8 sText_Title_Field_Stats[]      = _("Field Info");
const u8 sText_Title_Controllers[]      = _("{DPAD_UPDOWN}Switch {DPAD_LEFTRIGHT}Page");


const u8 sText_Title_Type[]     = _("Type(s):");
const u8 gText_NewLevelSymbol[] = _("{LV}{STR_VAR_1}");
#define SPACE_BETWEEN_TYPES (5 * 8)
static void PrintStatusTab(){
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 innate1 = gBaseStats[species].innates[0];
    u16 innate2 = gBaseStats[species].innates[1];
    u16 innate3 = gBaseStats[species].innates[2];
    u32 personality = gBattleMons[sMenuDataPtr->battlerId].personality;
    u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[sMenuDataPtr->battlerId].species, gBattleMons[sMenuDataPtr->battlerId].personality);
    u8 statStage;
    bool8 statStageUp = FALSE;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = -4;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Battler_Stats);
    x  = 19;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Controllers);

    //Pokemon Name
    x  = 9;
    y  = 4;
    x2 = 0;
    y2 = -4;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gSpeciesNames[species]);
    //Pokemon Gender
    x = x + 8;
    switch(gender){
        case MON_MALE:
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLUE], 0xFF, gText_MaleSymbol);
            break;
        case MON_FEMALE:
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_RED], 0xFF, gText_FemaleSymbol);
            break;
    }
    //Pokemon Level
    x++;
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].level, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_NewLevelSymbol);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    //Pokemon Type
    y++;
    x = 9;
    StringCopy(gStringVar1, sText_Title_Type);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    x2 = x2 + SPACE_BETWEEN_TYPES;

    StringCopy(gStringVar1, gTypeNames[gBattleMons[sMenuDataPtr->battlerId].type1]);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    if(gBattleMons[sMenuDataPtr->battlerId].type1 != gBattleMons[sMenuDataPtr->battlerId].type2){
        x2 = x2 + SPACE_BETWEEN_TYPES;
        StringCopy(gStringVar1, gTypeNames[gBattleMons[sMenuDataPtr->battlerId].type2]);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    }
    if(gBattleMons[sMenuDataPtr->battlerId].type3 != TYPE_MYSTERY){
        x2 = x2 + SPACE_BETWEEN_TYPES;
        StringCopy(gStringVar1, gTypeNames[gBattleMons[sMenuDataPtr->battlerId].type3]);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    }
    x2 = 0;

    //Stat Drops & Ups
    x = 9;
    y = 9;
    //Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Attack);
    y++;
    //Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Defense);
    y++;
    //Special Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialAttack);
    y++;
    //Special Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialDefense);
    y++;
    //Speed
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Speed);
    y = y + 2;
    //Accuracy
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Accuracy);
    //Evasion
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Evasion);
    //Critical
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Critical);
    
    x = 11;
    y = 9;
    for(i = 0; i < NUM_BATTLE_STATS - 1; i++){
        
        statStage = gBattleMons[sMenuDataPtr->battlerId].statStages[statorder[i + 1]];//HP is not taken into account
        if(statStage != DEFAULT_STAT_STAGE){
            if(statStage > DEFAULT_STAT_STAGE){
                statStageUp = TRUE;
                statStage = statStage - DEFAULT_STAT_STAGE;
            }
            else{
                statStageUp = FALSE;
                statStage = DEFAULT_STAT_STAGE - statStage;
            }

            for(j = 0; j < statStage; j++){
                if(statStageUp)
                    BlitBitmapToWindow(windowId, sStatUpArrow, ((x + j) * 8) + x2, (y * 8), 8, 8);
                else
                    BlitBitmapToWindow(windowId, sStatDownArrow, ((x + j) * 8) + x2, (y * 8), 8, 8);

            }
        }
        if(statorder[i + 1] == STAT_SPEED)
            y = y + 2;
        else
            y++;
    }

    //Stat names
    x  = 20;
    y  = 9;
    //HP
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_StatHP);
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].hp, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, gBattleMons[sMenuDataPtr->battlerId].maxHP, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sText_HP);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    y++;
    //Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Attack);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].attack, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Defense);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].defense, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Special Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialAttack);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].spAttack, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Special Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialDefense);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].spDefense, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Speed
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Speed);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].speed, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);

    x = 0;
    y = 0;
    BlitBitmapToWindow(windowId, sSelector, (x * 8) + x2, ((y + (sMenuDataPtr->modeId * 4)) * 8), 48, 32);
    
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}


const u8 sText_PrintAbilityTab_Ability[] = _("Ability");
const u8 sText_PrintAbilityTab_Innate[] = _("Innate");
#define SPACE_BETWEEN_ABILITY_AND_NAME (8 * 8)
#define SPACE_BETWEEN_ABILITIES 3
static void PrintAbilityTab(){
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 innate1 = gBaseStats[species].innates[0];
    u16 innate2 = gBaseStats[species].innates[1];
    u16 innate3 = gBaseStats[species].innates[2];
    u16 ability = gBattleMons[sMenuDataPtr->battlerId].ability;
    u32 personality = gBattleMons[sMenuDataPtr->battlerId].personality;
    u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[sMenuDataPtr->battlerId].species, gBattleMons[sMenuDataPtr->battlerId].personality);
    u8 statStage;
    bool8 statStageUp = FALSE;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;

    
    if(!isEnemyMon){ //Enemy Mons have disabled randomized innates/abilies 
        innate1 = RandomizeInnate(gBaseStats[species].innates[0], species, personality);
        innate2 = RandomizeInnate(gBaseStats[species].innates[1], species, personality);
        innate3 = RandomizeInnate(gBaseStats[species].innates[2], species, personality);
    }

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = 0;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Battler_Ability);
    x  = 19;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Controllers);

    // Main Ability
    x  = 9;
    y  = 3;
    x2 = 0;
    y2 = -4;
    //Title
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_PrintAbilityTab_Ability);
	// Name ---------------------------------------------------------------------------------------------------
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gAbilityNames[ability]);
	// Description ---------------------------------------------------------------------------------------------------
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2 + 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityDescriptionPointers[ability]);

    // Innate 1
    y = y + SPACE_BETWEEN_ABILITIES;
    //Title
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_PrintAbilityTab_Innate);
    // Name ---------------------------------------------------------------------------------------------------
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gAbilityNames[innate1]);
    // Description ---------------------------------------------------------------------------------------------------
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2 + 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityDescriptionPointers[innate1]);
    
    // Innate 2
    y = y + SPACE_BETWEEN_ABILITIES;
    //Title
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_PrintAbilityTab_Innate);
    // Name ---------------------------------------------------------------------------------------------------
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gAbilityNames[innate2]);
    // Description ---------------------------------------------------------------------------------------------------
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2 + 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityDescriptionPointers[innate2]);
       
    // Innate 3
    y = y + SPACE_BETWEEN_ABILITIES;
    //Title
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_PrintAbilityTab_Innate);
    // Name ---------------------------------------------------------------------------------------------------
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gAbilityNames[innate3]);
    // Description ---------------------------------------------------------------------------------------------------
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2 + 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityDescriptionPointers[innate3]);
    
    //Selector
    x = 0;
    y = 0;
    BlitBitmapToWindow(windowId, sSelector, (x * 8) + x2, ((y + (sMenuDataPtr->modeId * 4)) * 8), 48, 32);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}


const u8 gText_CurrentPP[]         = _("PP: {STR_VAR_1}/{STR_VAR_2}");
const u8 gText_MoveInfo_Power[]    = _("Power: {STR_VAR_1}");
const u8 gText_MoveInfo_Accuracy[] = _("Accuracy: {STR_VAR_1}");
const u8 gText_MoveInfo_Priority[] = _("Priority: {STR_VAR_1}");
const u8 gText_MoveInfo_Split[]    = _("Split: {STR_VAR_1}");

const u8 gText_Split_Physical[] = _("Physical");
const u8 gText_Split_Special[]  = _("Special");
const u8 gText_Split_Status[]   = _("Status");

const u8 gText_MoveInfo_Target1[] = _("Target 1: {STR_VAR_1}");
const u8 gText_MoveInfo_Target2[] = _("Target 2: {STR_VAR_1}");

const u8 gText_MoveInfo_Damage[] = _("Damage");

const u8 gText_Target_Nothing[]   = _("---");
const u8 sText_Title_Controllers_Move[]      = _("{DPAD_UPDOWN}Switch {DPAD_LEFTRIGHT}Page {A_BUTTON}Mode");
#define SPACE_BETWEEN_MOVES 1
#define SPACE_BETWEEN_DAMAGE (4 * 8)
#define MIN_MOVE_DAMAGE 4
#define ENABLE_DAMAGE_CALCULATION FALSE
static void PrintMoveTab(void){
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 move1   = gBattleMons[sMenuDataPtr->battlerId].moves[0];
    u16 move2   = gBattleMons[sMenuDataPtr->battlerId].moves[1];
    u16 move3   = gBattleMons[sMenuDataPtr->battlerId].moves[2];
    u16 move4   = gBattleMons[sMenuDataPtr->battlerId].moves[3];
    u16 ability = gBattleMons[sMenuDataPtr->battlerId].ability;
    u16 gBattleMoveDamage;
    u8 target = 1;
    u32 personality = gBattleMons[sMenuDataPtr->battlerId].personality;
    u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[sMenuDataPtr->battlerId].species, gBattleMons[sMenuDataPtr->battlerId].personality);
    u8 statStage;
    bool8 statStageUp = FALSE;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    
    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = 0;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Battler_Moves);
    x  = 16;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Controllers_Move);

    // First Move
    x  = 9;
    y  = 3;
    x2 = 0;
    y2 = -4;
    //Move Name
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gMoveNamesLong[move1]);
	// PP ---------------------------------------------------------------------------------------------------
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].pp[0],  STR_CONV_MODE_LEFT_ALIGN, 2); //Current PP
    ConvertIntToDecimalStringN(gStringVar2, gBattleMoves[move1].pp, STR_CONV_MODE_LEFT_ALIGN, 2); //Max PP
    StringExpandPlaceholders(gStringVar4, gText_CurrentPP);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
	//Type
    StringCopy(gStringVar4, gTypeNames[gBattleMoves[move1].type]);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
    y++;
    if(ENABLE_DAMAGE_CALCULATION == FALSE)
        y2 = 0;
    // Move Power ---------------------------------------------------------------------------------------------------
    if(gBattleMoves[move1].power != 0)
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move1].power, STR_CONV_MODE_LEFT_ALIGN, 3);
    else
        StringCopy(gStringVar1, gText_Target_Nothing);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Power);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    // Move Accuracy
    if(gBattleMoves[move1].accuracy != 0)
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move1].accuracy, STR_CONV_MODE_LEFT_ALIGN, 3);
    else
        StringCopy(gStringVar1, gText_Target_Nothing);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Accuracy);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    y++;
    // Move Priority ---------------------------------------------------------------------------------------------------
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move1].priority, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Priority);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    // Move Split
    switch(gBattleMoves[move1].split){
        case SPLIT_PHYSICAL:
            StringCopy(gStringVar1, gText_Split_Physical);
        break;
        case SPLIT_SPECIAL:
            StringCopy(gStringVar1, gText_Split_Special);
        break;
        case SPLIT_STATUS:
        default:
            StringCopy(gStringVar1, gText_Split_Status);
        break;
    }
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Split);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    y++;
    if(ENABLE_DAMAGE_CALCULATION == TRUE){
        //Damage Text
        x2 = 0;
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gText_MoveInfo_Damage);
        x2 = SPACE_BETWEEN_DAMAGE;
        //Damage Calculation Target 1
        if(isEnemyMon)
            target = B_POSITION_PLAYER_LEFT;
        else
            target = B_POSITION_OPPONENT_LEFT;
        gBattleMoveDamage = CalculateMoveDamage(move1, sMenuDataPtr->battlerId, target, gBattleMoves[move1].type, FALSE, FALSE, FALSE, FALSE);
        if(gBattleMoveDamage < MIN_MOVE_DAMAGE)
            StringCopy(gStringVar1, gText_Target_Nothing);
        else
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoveDamage, STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Target1);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        //Damage Calculation Target 2
        if(IsDoubleBattle()){
            if(isEnemyMon)
                target = B_POSITION_PLAYER_RIGHT;
            else
                target = B_POSITION_OPPONENT_RIGHT;
            gBattleMoveDamage = CalculateMoveDamage(move1, sMenuDataPtr->battlerId, target, gBattleMoves[move1].type, FALSE, FALSE, FALSE, FALSE);
            if(gBattleMoveDamage < MIN_MOVE_DAMAGE)
                StringCopy(gStringVar1, gText_Target_Nothing);
            else
                ConvertIntToDecimalStringN(gStringVar1, gBattleMoveDamage, STR_CONV_MODE_LEFT_ALIGN, 4);
            StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Target2);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        }
    }

    // Second Move
    x2 = 0;
    y = y + SPACE_BETWEEN_MOVES;
    if(ENABLE_DAMAGE_CALCULATION == FALSE)
        y2 = -4;
    //Move Name
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gMoveNamesLong[move2]);
	// PP ---------------------------------------------------------------------------------------------------
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].pp[0],  STR_CONV_MODE_LEFT_ALIGN, 2); //Current PP
    ConvertIntToDecimalStringN(gStringVar2, gBattleMoves[move2].pp, STR_CONV_MODE_LEFT_ALIGN, 2); //Max PP
    StringExpandPlaceholders(gStringVar4, gText_CurrentPP);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
	//Type
    StringCopy(gStringVar4, gTypeNames[gBattleMoves[move2].type]);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
    y++;
    if(ENABLE_DAMAGE_CALCULATION == FALSE)
        y2 = 0;
    // Move Power ---------------------------------------------------------------------------------------------------
    if(gBattleMoves[move2].power != 0)
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move2].power, STR_CONV_MODE_LEFT_ALIGN, 3);
    else
        StringCopy(gStringVar1, gText_Target_Nothing);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Power);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    // Move Accuracy
    if(gBattleMoves[move2].accuracy != 0)
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move2].accuracy, STR_CONV_MODE_LEFT_ALIGN, 3);
    else
        StringCopy(gStringVar1, gText_Target_Nothing);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Accuracy);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    y++;
    // Move Priority ---------------------------------------------------------------------------------------------------
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move2].priority, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Priority);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    // Move Split
    switch(gBattleMoves[move2].split){
        case SPLIT_PHYSICAL:
            StringCopy(gStringVar1, gText_Split_Physical);
        break;
        case SPLIT_SPECIAL:
            StringCopy(gStringVar1, gText_Split_Special);
        break;
        case SPLIT_STATUS:
        default:
            StringCopy(gStringVar1, gText_Split_Status);
        break;
    }
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Split);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    y++;
    if(ENABLE_DAMAGE_CALCULATION == TRUE){
        //Damage Text
        x2 = 0;
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gText_MoveInfo_Damage);
        x2 = SPACE_BETWEEN_DAMAGE;
        //Damage Calculation Target 1
        if(isEnemyMon)
            target = B_POSITION_PLAYER_LEFT;
        else
            target = B_POSITION_OPPONENT_LEFT;
        gBattleMoveDamage = CalculateMoveDamage(move2, sMenuDataPtr->battlerId, target, gBattleMoves[move2].type, FALSE, FALSE, FALSE, FALSE);
        if(gBattleMoveDamage < MIN_MOVE_DAMAGE)
            StringCopy(gStringVar1, gText_Target_Nothing);
        else
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoveDamage, STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Target1);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        //Damage Calculation Target 2
        if(IsDoubleBattle()){
            if(isEnemyMon)
                target = B_POSITION_PLAYER_RIGHT;
            else
                target = B_POSITION_OPPONENT_RIGHT;
            gBattleMoveDamage = CalculateMoveDamage(move2, sMenuDataPtr->battlerId, target, gBattleMoves[move2].type, FALSE, FALSE, FALSE, FALSE);
            if(gBattleMoveDamage < MIN_MOVE_DAMAGE)
                StringCopy(gStringVar1, gText_Target_Nothing);
            else
                ConvertIntToDecimalStringN(gStringVar1, gBattleMoveDamage, STR_CONV_MODE_LEFT_ALIGN, 4);
            StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Target2);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        }
    }

    // Third Move
    x2 = 0;
    y = y + SPACE_BETWEEN_MOVES;
    if(ENABLE_DAMAGE_CALCULATION == FALSE)
        y2 = -4;
    //Move Name
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gMoveNamesLong[move3]);
	// PP ---------------------------------------------------------------------------------------------------
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].pp[0],  STR_CONV_MODE_LEFT_ALIGN, 2); //Current PP
    ConvertIntToDecimalStringN(gStringVar2, gBattleMoves[move3].pp, STR_CONV_MODE_LEFT_ALIGN, 2); //Max PP
    StringExpandPlaceholders(gStringVar4, gText_CurrentPP);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
	//Type
    StringCopy(gStringVar4, gTypeNames[gBattleMoves[move3].type]);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
    y++;
    if(ENABLE_DAMAGE_CALCULATION == FALSE)
        y2 = 0;
    // Move Power ---------------------------------------------------------------------------------------------------
    if(gBattleMoves[move3].power != 0)
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move3].power, STR_CONV_MODE_LEFT_ALIGN, 3);
    else
        StringCopy(gStringVar1, gText_Target_Nothing);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Power);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    // Move Accuracy
    if(gBattleMoves[move3].accuracy != 0)
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move3].accuracy, STR_CONV_MODE_LEFT_ALIGN, 3);
    else
        StringCopy(gStringVar1, gText_Target_Nothing);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Accuracy);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    y++;
    // Move Priority ---------------------------------------------------------------------------------------------------
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move3].priority, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Priority);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    // Move Split
    switch(gBattleMoves[move3].split){
        case SPLIT_PHYSICAL:
            StringCopy(gStringVar1, gText_Split_Physical);
        break;
        case SPLIT_SPECIAL:
            StringCopy(gStringVar1, gText_Split_Special);
        break;
        case SPLIT_STATUS:
        default:
            StringCopy(gStringVar1, gText_Split_Status);
        break;
    }
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Split);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    y++;
    if(ENABLE_DAMAGE_CALCULATION == TRUE){
        //Damage Text
        x2 = 0;
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gText_MoveInfo_Damage);
        x2 = SPACE_BETWEEN_DAMAGE;
        //Damage Calculation Target 1
        if(isEnemyMon)
            target = B_POSITION_PLAYER_LEFT;
        else
            target = B_POSITION_OPPONENT_LEFT;
        gBattleMoveDamage = CalculateMoveDamage(move3, sMenuDataPtr->battlerId, target, gBattleMoves[move3].type, FALSE, FALSE, FALSE, FALSE);
        if(gBattleMoveDamage < MIN_MOVE_DAMAGE)
            StringCopy(gStringVar1, gText_Target_Nothing);
        else
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoveDamage, STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Target1);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        //Damage Calculation Target 2
        if(IsDoubleBattle()){
            if(isEnemyMon)
                target = B_POSITION_PLAYER_RIGHT;
            else
                target = B_POSITION_OPPONENT_RIGHT;
            gBattleMoveDamage = CalculateMoveDamage(move3, sMenuDataPtr->battlerId, target, gBattleMoves[move3].type, FALSE, FALSE, FALSE, FALSE);
            if(gBattleMoveDamage < MIN_MOVE_DAMAGE)
                StringCopy(gStringVar1, gText_Target_Nothing);
            else
                ConvertIntToDecimalStringN(gStringVar1, gBattleMoveDamage, STR_CONV_MODE_LEFT_ALIGN, 4);
            StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Target2);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        }
    }

    // Fourth Move
    x2 = 0;
    y = y + SPACE_BETWEEN_MOVES;
    if(ENABLE_DAMAGE_CALCULATION == FALSE)
        y2 = -4;
    //Move Name
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gMoveNamesLong[move4]);
	// PP ---------------------------------------------------------------------------------------------------
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].pp[0],  STR_CONV_MODE_LEFT_ALIGN, 2); //Current PP
    ConvertIntToDecimalStringN(gStringVar2, gBattleMoves[move4].pp, STR_CONV_MODE_LEFT_ALIGN, 2); //Max PP
    StringExpandPlaceholders(gStringVar4, gText_CurrentPP);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
	//Type
    StringCopy(gStringVar4, gTypeNames[gBattleMoves[move4].type]);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
    y++;
    if(ENABLE_DAMAGE_CALCULATION == FALSE)
        y2 = 0;
    // Move Power ---------------------------------------------------------------------------------------------------
    if(gBattleMoves[move4].power != 0)
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move4].power, STR_CONV_MODE_LEFT_ALIGN, 3);
    else
        StringCopy(gStringVar1, gText_Target_Nothing);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Power);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    // Move Accuracy
    if(gBattleMoves[move4].accuracy != 0)
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move4].accuracy, STR_CONV_MODE_LEFT_ALIGN, 3);
    else
        StringCopy(gStringVar1, gText_Target_Nothing);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Accuracy);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    y++;
    // Move Priority ---------------------------------------------------------------------------------------------------
    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move4].priority, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Priority);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    // Move Split
    switch(gBattleMoves[move4].split){
        case SPLIT_PHYSICAL:
            StringCopy(gStringVar1, gText_Split_Physical);
        break;
        case SPLIT_SPECIAL:
            StringCopy(gStringVar1, gText_Split_Special);
        break;
        case SPLIT_STATUS:
        default:
            StringCopy(gStringVar1, gText_Split_Status);
        break;
    }
    StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Split);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    y++;
    if(ENABLE_DAMAGE_CALCULATION == TRUE){
        //Damage Text
        x2 = 0;
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gText_MoveInfo_Damage);
        x2 = SPACE_BETWEEN_DAMAGE;
        //Damage Calculation Target 1
        if(isEnemyMon)
            target = B_POSITION_PLAYER_LEFT;
        else
            target = B_POSITION_OPPONENT_LEFT;
        gBattleMoveDamage = CalculateMoveDamage(move4, sMenuDataPtr->battlerId, target, gBattleMoves[move4].type, FALSE, FALSE, FALSE, FALSE);
        if(gBattleMoveDamage < MIN_MOVE_DAMAGE)
            StringCopy(gStringVar1, gText_Target_Nothing);
        else
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoveDamage, STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Target1);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        //Damage Calculation Target 2
        if(IsDoubleBattle()){
            if(isEnemyMon)
                target = B_POSITION_PLAYER_RIGHT;
            else
                target = B_POSITION_OPPONENT_RIGHT;
            gBattleMoveDamage = CalculateMoveDamage(move4, sMenuDataPtr->battlerId, target, gBattleMoves[move4].type, FALSE, FALSE, FALSE, FALSE);
            if(gBattleMoveDamage < MIN_MOVE_DAMAGE)
                StringCopy(gStringVar1, gText_Target_Nothing);
            else
                ConvertIntToDecimalStringN(gStringVar1, gBattleMoveDamage, STR_CONV_MODE_LEFT_ALIGN, 4);
            StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Target2);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        }
    }

    //Selector
    x = 0;
    y = 0;
    x2 = 0;
    BlitBitmapToWindow(windowId, sSelector, (x * 8) + x2, ((y + (sMenuDataPtr->modeId * 4)) * 8), 48, 32);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);

}

const u8 sText_Title_Field_Turns_Left[]                   = _("Turns Left:");
const u8 sText_Title_Field_Weather[]                      = _("Weather: {STR_VAR_1}");
const u8 sText_Title_Field_Weather_Rain[]                 = _("Rain");
const u8 sText_Title_Field_Weather_Sun[]                  = _("Sun");
const u8 sText_Title_Field_Weather_Sandstorm[]            = _("Sandstorm");
const u8 sText_Title_Field_Weather_Hail[]                 = _("Hail");
const u8 sText_Title_Field_Weather_Snow[]                 = _("Snow");
const u8 sText_Title_Field_Weather_Strong_Winds[]         = _("Strong Winds");
const u8 sText_Title_Field_Weather_Rain_Primal[]          = _("Primal Rain");
const u8 sText_Title_Field_Weather_Sun_Primal[]           = _("Primal Sun");

const u8 sText_Title_Field_Weather_Description_Rain[]         = _("Strengthens Water-type moves by\n"
                                                                  "50% while weakening Fire-type\n"
                                                                  "moves by 50%.");
const u8 sText_Title_Field_Weather_Description_Sun[]          = _("Strengthens the power of Fire-type\n"
                                                                  "moves by 50% and weakens Water-type\n"
                                                                  "moves by 50%.");
const u8 sText_Title_Field_Weather_Description_Sandstorm[]    = _("Any Pokémon that is not Rock, Ground\n"
                                                                  "or Steel-type will be damaged for\n"
                                                                  "1/16 of its maximum HP each turn.");
const u8 sText_Title_Field_Weather_Description_Hail[]         = _("Any Pokémon that is not Ice-type\n"
                                                                  "will be damaged each turn, Pokémon\n"
                                                                  "are twice as likely to get frostbite.");
const u8 sText_Title_Field_Weather_Description_Strong_Winds[] = _("Causes Electric, Ice, and Rock-type\n"
                                                                  "moves to deal neutral damage to \n"
                                                                  "Flying-type Pokémon.");
const u8 sText_Title_Field_Weather_Description_Primal_Rain[]  = _("Boosts the power of Water-type moves\n"
                                                                  "and protects Pokémon from Fire-type\n"
                                                                  "moves.");
const u8 sText_Title_Field_Weather_Description_Primal_Sun[]  = _("Boosts the power of Fire-type moves\n"
                                                                  "and protects Pokémon from Water-type\n"
                                                                  "moves.");

const u8 sText_Title_Field_Terrain[]                      = _("Terrain: {STR_VAR_1}");
const u8 sText_Title_Field_Terrain_Electric[]             = _("Electric");
const u8 sText_Title_Field_Terrain_Psychic[]              = _("Psychic");
const u8 sText_Title_Field_Terrain_Misty[]                = _("Misty");
const u8 sText_Title_Field_Terrain_Grassy[]               = _("Grassy");

const u8 sText_Title_Field_Terrain_Description_Electric[] = _("Pokémon on the ground won't fall\n"
                                                              "asleep. The power of Electric-type\n"
                                                              "moves is boosted.");
const u8 sText_Title_Field_Terrain_Description_Psychic[]  = _("Pokémon on the ground won't be hit\n"
                                                              "by priority moves. The power of\n"
                                                              "Psychic-type moves is boosted.");
const u8 sText_Title_Field_Terrain_Description_Misty[]    = _("Pokémon on the ground won't get any\n"
                                                              "status conditions, Damage from Dragon\n"
                                                              "type moves is halved.");
const u8 sText_Title_Field_Terrain_Description_Grassy[]   = _("Increases the power of Grass-type\n"
                                                              "moves, Restores 1/16 HP to all\n"
                                                              "Pokémon on the ground each turn.");

const u8 sText_Title_Field_Room[]                         = _("Room Type:");
const u8 sText_Title_Field_Trick_Room[]                   = _("Trick Room");
const u8 sText_Title_Field_Room_Description_Trick[]       = _("The move order is reversed, slower\n"
                                                              "Pokémon will attack before faster\n"
                                                              "Pokémon.");
const u8 sText_Title_Field_Wonder_Room[]                  = _("Wonder Room:");
const u8 sText_Title_Field_Magic_Room[]                   = _("Magic Room:");

const u8 sText_Title_Field_Nature_Power[]                 = _("Nature Power:");
const u8 sText_Title_Field_Secret_Power[]                 = _("Secret Power:");
const u8 sText_Title_Field_Paralysis[]                    = _("Causes Paralysis");

const u8 sText_Title_Field_Active[]                       = _("Active");
const u8 sText_Title_Field_Not_Active[]                   = _("Not Active");
const u8 sText_Title_Field_None[]                         = _("None");

#define SPACE_BETWEEN_LINES_FIELD ((6 * 8) + 4)
#define MAX_DESCRIPTION_LINES 3
#define LINES_BETWEEN_STUFF 1
static void PrintFieldTab(void)
{
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u8 turnsLeft = 5;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = -4;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Stats);
    x  = 19;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Controllers);

    // Weather
    x  = 9;
    y  = 3;
    x2 = 0;
    y2 = -4;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Weather);
    if((gBattleWeather & WEATHER_RAIN_ANY))
        StringCopy(gStringVar1, sText_Title_Field_Weather_Rain);
    else if((gBattleWeather & WEATHER_SUN_ANY))
        StringCopy(gStringVar1, sText_Title_Field_Weather_Sun);
    else if((gBattleWeather & WEATHER_SANDSTORM_ANY))
        StringCopy(gStringVar1, sText_Title_Field_Weather_Sandstorm);
    else if((gBattleWeather & WEATHER_HAIL_ANY))
        StringCopy(gStringVar1, sText_Title_Field_Weather_Hail);
    else if((gBattleWeather & WEATHER_STRONG_WINDS))
        StringCopy(gStringVar1, sText_Title_Field_Weather_Strong_Winds);
    else if((gBattleWeather & WEATHER_RAIN_PRIMAL))
        StringCopy(gStringVar1, sText_Title_Field_Weather_Rain_Primal);
    else if((gBattleWeather & WEATHER_SUN_PRIMAL))
        StringCopy(gStringVar1, sText_Title_Field_Weather_Sun_Primal);
    else
        StringCopy(gStringVar1, sText_Title_Field_None);

    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + SPACE_BETWEEN_LINES_FIELD, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    
    //Turns Left
    if((gBattleWeather & WEATHER_ANY)){
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Turns_Left);
        ConvertIntToDecimalStringN(gStringVar1, gWishFutureKnock.weatherDuration, STR_CONV_MODE_LEFT_ALIGN, 4);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
        y++;
        //Weather Description
        if((gBattleWeather & WEATHER_RAIN_ANY))
            StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Rain);
        else if((gBattleWeather & WEATHER_SUN_ANY))
            StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Sun);
        else if((gBattleWeather & WEATHER_SANDSTORM_ANY))
            StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Sandstorm);
        else if((gBattleWeather & WEATHER_HAIL_ANY))
            StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Hail);
        else if((gBattleWeather & WEATHER_STRONG_WINDS))
            StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Strong_Winds);
        else if((gBattleWeather & WEATHER_RAIN_PRIMAL))
            StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Primal_Rain);
        else if((gBattleWeather & WEATHER_SUN_PRIMAL))
            StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Primal_Sun);
        
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
    }
    else{
        y++;
    }
    //Terrain
    y = y + MAX_DESCRIPTION_LINES + LINES_BETWEEN_STUFF;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Terrain);
    if(gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
        StringCopy(gStringVar1, sText_Title_Field_Terrain_Electric);
    else if(gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
        StringCopy(gStringVar1, sText_Title_Field_Terrain_Grassy);
    else if(gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
        StringCopy(gStringVar1, sText_Title_Field_Terrain_Misty);
    else if(gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
        StringCopy(gStringVar1, sText_Title_Field_Terrain_Psychic);
    else
        StringCopy(gStringVar1, sText_Title_Field_None);

    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + SPACE_BETWEEN_LINES_FIELD, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    //Turns Left
    if(gFieldStatuses & STATUS_FIELD_TERRAIN_ANY){
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Turns_Left);
        ConvertIntToDecimalStringN(gStringVar1, gFieldTimers.terrainTimer, STR_CONV_MODE_LEFT_ALIGN, 4);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
        y++;
        //Terrain Description
        if((gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN))
            StringCopy(gStringVar1, sText_Title_Field_Terrain_Description_Electric);
        else if((gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN))
            StringCopy(gStringVar1, sText_Title_Field_Terrain_Description_Grassy);
        else if((gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN))
            StringCopy(gStringVar1, sText_Title_Field_Terrain_Description_Misty);
        else if((gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN))
            StringCopy(gStringVar1, sText_Title_Field_Terrain_Description_Psychic);

        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
    }
    else{
        y++;
    }

    /*//Nature Power
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Nature_Power);
    StringCopy(gStringVar1, gMoveNamesLong[MOVE_THUNDERBOLT]);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 1.5), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

    //Secret Power
    y++;
    StringCopy(gStringVar1, sText_Title_Field_Secret_Power);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    StringCopy(gStringVar1, sText_Title_Field_Paralysis);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 1.5), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    */

    //Rooms
    y = y + MAX_DESCRIPTION_LINES + LINES_BETWEEN_STUFF;
    StringCopy(gStringVar1, sText_Title_Field_Room);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    //Active
    if(gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
        StringCopy(gStringVar1, sText_Title_Field_Trick_Room);
    else
        StringCopy(gStringVar1, sText_Title_Field_None);
    
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    //Turns Left
    if(gFieldStatuses & STATUS_FIELD_TRICK_ROOM){
        StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
        y++;
        //Trick Room Description
        StringCopy(gStringVar1, sText_Title_Field_Room_Description_Trick);
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
    }
    else{
        y++;
    }

    /*//Wonder Room
    StringCopy(gStringVar1, sText_Title_Field_Wonder_Room);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    //Active
    StringCopy(gStringVar1, sText_Title_Field_Not_Active);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD + 6), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    //Turns Left
    StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2) + 3, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3) + 3, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    y++;

    //Magic Room
    StringCopy(gStringVar1, sText_Title_Field_Magic_Room);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    //Active
    StringCopy(gStringVar1, sText_Title_Field_Not_Active);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD + 6), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    //Turns Left
    StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2) + 3, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3) + 3, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    y++;*/

    //Selector
    x = 0;
    y = 0;
    BlitBitmapToWindow(windowId, sSelector, (x * 8) + x2, ((y + (sMenuDataPtr->modeId * 4)) * 8), 48, 32);
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
    const u8 *str = sText_MyMenu;
    u8 i, j;
    u8 x, y, x2, y2;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 innate1 = gBaseStats[species].innates[0];
    u16 innate2 = gBaseStats[species].innates[1];
    u16 innate3 = gBaseStats[species].innates[2];
    u32 personality = gBattleMons[sMenuDataPtr->battlerId].personality;
    u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[sMenuDataPtr->battlerId].species, gBattleMons[sMenuDataPtr->battlerId].personality);
    u8 statStage;
    bool8 statStageUp = FALSE;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;
    u8 move = MOVE_NONE;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    if(!isEnemyMon){ //Enemy Mons have disabled randomized innates/abilies 
        innate1 = RandomizeInnate(gBaseStats[species].innates[0], species, personality);
        innate2 = RandomizeInnate(gBaseStats[species].innates[1], species, personality);
        innate3 = RandomizeInnate(gBaseStats[species].innates[2], species, personality);
    }

    //Title
    x  = 7;
    y  = 2;
    x2 = 0;
    y2 = -4;
    if(isEnemyMon)
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sYourOpponentPokemonData);
    else
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sYourPokemonData);

    //Pokemon Name
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gSpeciesNames[species]);
    //Pokemon HP
    y++;
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].hp, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, gBattleMons[sMenuDataPtr->battlerId].maxHP, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sText_HP);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    //Pokemon Gender
    x = 2;
    y = 6;
    switch(gender){
        case MON_MALE:
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLUE], 0xFF, gText_MaleSymbol);
            break;
        case MON_FEMALE:
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_RED], 0xFF, gText_FemaleSymbol);
            break;
    }

    //Pokemon Level
    x++;
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].level, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_NewLevelSymbol);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);

    //Held Item
    x  = 22;
    y  = 3;
    if (gBattleMons[sMenuDataPtr->battlerId].item == ITEM_NONE)
        StringCopy(gStringVar1, sText_None);
    else
        StringCopy(gStringVar1, ItemId_GetName(gBattleMons[sMenuDataPtr->battlerId].item));
    StringExpandPlaceholders(gStringVar4, sText_Held_Item);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);

    //Stats
    x  = 3;
    y  = 7;
    //Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Attack);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].attack, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Defense);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].defense, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Special Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialAttack);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].spAttack, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Special Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialDefense);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].spDefense, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Speed
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Speed);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].speed, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);

    //Accuracy
    y = y + 2;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Accuracy);
    //Evasion
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Evasion);

    //Abilitites
    x = 15;
    y = 7;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Ability);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 5) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityNames[gBattleMons[sMenuDataPtr->battlerId].ability]);
    y++;
    //Innate 1
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Innate);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 5) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityNames[innate1]);
    y++;
    //Innate 2
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Innate);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 5) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityNames[innate2]);
    y++;
    //Innate 3
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Innate);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 5) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityNames[innate3]);

    //Moves
    y = y+2;
    for(i = 0; i < MAX_MON_MOVES; i++){
        move = gBattleMons[sMenuDataPtr->battlerId].moves[i];
        if(move != MOVE_NONE){
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gMoveNames[move]);
            //Current PP
            ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].pp[i], STR_CONV_MODE_LEFT_ALIGN, 3); //Current PP
            ConvertIntToDecimalStringN(gStringVar2, gBattleMoves[move].pp, STR_CONV_MODE_LEFT_ALIGN, 3); //Max PP, ToFix
            StringExpandPlaceholders(gStringVar4, sText_PP);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 8) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            y++;
        }
    }

    //Stat Drops & Ups
    x = 8;
    y = 7;
    for(i = 0; i < NUM_BATTLE_STATS - 1; i++){
        
        statStage = gBattleMons[sMenuDataPtr->battlerId].statStages[statorder[i + 1]];//HP is not taken into account
        if(statStage != DEFAULT_STAT_STAGE){
            if(statStage > DEFAULT_STAT_STAGE){
                statStageUp = TRUE;
                statStage = statStage - DEFAULT_STAT_STAGE;
            }
            else{
                statStageUp = FALSE;
                statStage = DEFAULT_STAT_STAGE - statStage;
            }

            for(j = 0; j < statStage; j++){
                if(statStageUp)
                    BlitBitmapToWindow(windowId, sStatUpArrow, ((x + j) * 8) + x2, (y * 8), 8, 8);
                else
                    BlitBitmapToWindow(windowId, sStatDownArrow, ((x + j) * 8) + x2, (y * 8), 8, 8);

            }
        }
        if(statorder[i + 1] == STAT_SPEED)
            y = y + 2;
        else
            y++;
    }
    
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void Task_MenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_MenuMain;
}

static void Task_MenuTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}
//Status

static const union AnimCmd sSpriteAnim_StatusPoison[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusParalyzed[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusSleep[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrozen[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusBurn[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusPokerus[] = {
    ANIMCMD_FRAME(20, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFaint[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrostbite[] = {
    ANIMCMD_FRAME(28, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_StatusCondition[] = {
    sSpriteAnim_StatusPoison,
    sSpriteAnim_StatusParalyzed,
    sSpriteAnim_StatusSleep,
    sSpriteAnim_StatusFrozen,
    sSpriteAnim_StatusBurn,
    sSpriteAnim_StatusPokerus,
    sSpriteAnim_StatusFaint,
    sSpriteAnim_StatusFrostbite,
};
static const struct OamData sOamData_StatusCondition =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
#define TAG_MON_STATUS      30001
static const struct SpriteTemplate sSpriteTemplate_StatusCondition =
{
    .tileTag = TAG_MON_STATUS,
    .paletteTag = TAG_MON_STATUS,
    .oam = &sOamData_StatusCondition,
    .anims = sSpriteAnimTable_StatusCondition,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

#define STATUS_ICON_X (7 * 8)
#define STATUS_ICON_Y (5 * 8)
static void CreateSetStatusSprite(void)
{
    u8 *spriteId = &sMenuDataPtr->spriteIds[SPRITE_ARR_ID_STATUS];
    u8 statusAnim;

    if (*spriteId == SPRITE_NONE)
        *spriteId = CreateSprite(&sSpriteTemplate_StatusCondition, STATUS_ICON_X, STATUS_ICON_Y, 0);

    //statusAnim = gBattleMons[sMenuDataPtr->battlerId].status1;
    statusAnim = sMenuDataPtr->battlerId;
    if (statusAnim != 0)
    {
        StartSpriteAnim(&gSprites[*spriteId], statusAnim - 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    }
}

static u8 DestroyBattleMenuSprite(u8 spriteArrayId)
{
    struct Sprite *sprite = &gSprites[sMenuDataPtr->spriteIds[spriteArrayId]];
    sMenuDataPtr->spriteIds[spriteArrayId] = SPRITE_NONE;
    DestroySpriteAndFreeResources(sprite);
}

static u8 ShowSpeciesIcon(u8 num)
{
	u16 species     = gBattleMons[num].species;
    u16 personality = gBattleMons[num].personality;
	LoadMonIconPalette(species);

    switch(num){
        case 0:
            sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1] = CreateMonIcon(species, SpriteCallbackDummy, POKEMON_ICON_X, POKEMON_ICON_1_Y, 0, personality);
                    
            gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1]].invisible = FALSE;
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1];
        break;
        case 1:
            sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_2] = CreateMonIcon(species, SpriteCallbackDummy, POKEMON_ICON_X, POKEMON_ICON_2_Y, 0, personality);
                    
            gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_2]].invisible = FALSE;
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_2];
        break;
        case 2:
            if(IsDoubleBattle()){
                sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_3] = CreateMonIcon(species, SpriteCallbackDummy, POKEMON_ICON_X, POKEMON_ICON_3_Y, 0, personality);
                        
                gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_3]].invisible = FALSE;
            }
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_3];
        break;
        case 3:
            if(IsDoubleBattle()){
                sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_4] = CreateMonIcon(species, SpriteCallbackDummy, POKEMON_ICON_X, POKEMON_ICON_4_Y, 0, personality);
                        
                gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_4]].invisible = FALSE;
            }
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_4];
        break;
    }
}
// different from pokemon_summary_screen
#define TYPE_ICON_PAL_NUM_0     13
#define TYPE_ICON_PAL_NUM_1     14
#define TYPE_ICON_PAL_NUM_2     15
static const u8 sMoveTypeToOamPaletteNum[NUMBER_OF_MON_TYPES] =
{
    [TYPE_NORMAL] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FIGHTING] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FLYING] = TYPE_ICON_PAL_NUM_1,
    [TYPE_POISON] = TYPE_ICON_PAL_NUM_1,
    [TYPE_GROUND] = TYPE_ICON_PAL_NUM_0,
    [TYPE_ROCK] = TYPE_ICON_PAL_NUM_0,
    [TYPE_BUG] = TYPE_ICON_PAL_NUM_2,
    [TYPE_GHOST] = TYPE_ICON_PAL_NUM_1,
    [TYPE_STEEL] = TYPE_ICON_PAL_NUM_0,
    [TYPE_MYSTERY] = TYPE_ICON_PAL_NUM_2,
    [TYPE_FIRE] = TYPE_ICON_PAL_NUM_0,
    [TYPE_WATER] = TYPE_ICON_PAL_NUM_1,
    [TYPE_GRASS] = TYPE_ICON_PAL_NUM_2,
    [TYPE_ELECTRIC] = TYPE_ICON_PAL_NUM_0,
    [TYPE_PSYCHIC] = TYPE_ICON_PAL_NUM_1,
    [TYPE_ICE] = TYPE_ICON_PAL_NUM_1,
    [TYPE_DRAGON] = TYPE_ICON_PAL_NUM_2,
    [TYPE_DARK] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FAIRY] = TYPE_ICON_PAL_NUM_1,
};

static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sMenuDataPtr->spriteIds[spriteArrayId]].invisible = invisible;
}

static void SetTypeIconSpritePosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite = &gSprites[sMenuDataPtr->spriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    sprite->oam.paletteNum = sMoveTypeToOamPaletteNum[typeId];
    sprite->x = x + 16;
    sprite->y = y + 8;
    SetSpriteInvisibility(spriteArrayId, FALSE);
}

#define TYPE_ICON_Y (5 * 8)
#define TYPE_ICON_1_X (7 * 8)
#define TYPE_ICON_2_X TYPE_ICON_1_X + (4 * 8)
#define TYPE_ICON_3_X TYPE_ICON_2_X + (4 * 8)
static void SetMonTypeIcons(void)
{
    u8 type1 = gBattleMons[sMenuDataPtr->battlerId].type1;
    u8 type2 = gBattleMons[sMenuDataPtr->battlerId].type2;
    u8 type3 = gBattleMons[sMenuDataPtr->battlerId].type3;

    if (type1 != type2)
    {
        SetTypeIconSpritePosAndPal(type1, TYPE_ICON_1_X, TYPE_ICON_Y, SPRITE_ARR_ID_TYPE_1);
        SetTypeIconSpritePosAndPal(type2, TYPE_ICON_2_X, TYPE_ICON_Y, SPRITE_ARR_ID_TYPE_2);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE_2, FALSE);
    }
    else
    {
        SetTypeIconSpritePosAndPal(type1, TYPE_ICON_1_X, TYPE_ICON_Y, SPRITE_ARR_ID_TYPE_1);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE_2, TRUE);
    }
}

static u8 tabColors[NUM_TABS] = {
    [TAB_STATS]             = MENU_COLOR_BLUE,
    [TAB_ABILITIES]         = MENU_COLOR_RED,
    [TAB_MOVES]             = MENU_COLOR_GREEN,
    [TAB_STATUS]            = MENU_COLOR_YELLOW,
    [TAB_DAMAGE_CALCULATOR] = MENU_COLOR_RED,
};

static void setBattler(void){
    switch(sMenuDataPtr->modeId){
        case MODE_BATTLER0:
            sMenuDataPtr->battlerId = 0;
        break;
        case MODE_BATTLER1:
            sMenuDataPtr->battlerId = 1;
        break;
        case MODE_BATTLER2:
            sMenuDataPtr->battlerId = 2;
        break;
        case MODE_BATTLER3:
            sMenuDataPtr->battlerId = 3;
        break;
        case MODE_FIELD:
            sMenuDataPtr->battlerId = 0;
        break;
    }
}

static void LoadTabPalette(void){
    switch(tabColors[sMenuDataPtr->tabId]){
        case MENU_COLOR_BLUE:
            LoadPalette(sMenuPalette_Blue, 0, 32);
        break;
        case MENU_COLOR_YELLOW:
            LoadPalette(sMenuPalette_Yellow, 0, 32);
        break;
        case MENU_COLOR_RED:
            LoadPalette(sMenuPalette_Red, 0, 32);
        break;
        case MENU_COLOR_GREEN:
            LoadPalette(sMenuPalette_Green, 0, 32);
        break;
        default:
            LoadPalette(sMenuPalette, 0, 32);
        break;
    }
}

static void PrintPage(void){
    LoadTilemapFromMode();
    LoadTabPalette();
    if(sMenuDataPtr->modeId != MODE_FIELD)
        switch(sMenuDataPtr->tabId){
            case TAB_STATS:
                PrintStatusTab();
            break;
            case TAB_ABILITIES:
                PrintAbilityTab();
            break;
            case TAB_MOVES:
                PrintMoveTab();
            break;
            default:
                PrintStatusTab();
            break;
        }
    else{
        PrintFieldTab();
    }
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_MenuTurnOff;
    }

    if (JOY_NEW(DPAD_DOWN)){
        if(IsDoubleBattle()){
            if(sMenuDataPtr->modeId != NUM_MODES - 1)
                sMenuDataPtr->modeId++;
            else
                sMenuDataPtr->modeId = 0;
        }
        else{
            if(sMenuDataPtr->modeId != MODE_BATTLER1)
                sMenuDataPtr->modeId++;
            else
                sMenuDataPtr->modeId = MODE_BATTLER0;
        }
        setBattler();
        PrintPage();
    }

    if (JOY_NEW(DPAD_UP)){
        if(IsDoubleBattle()){
            if(sMenuDataPtr->modeId != 0)
                sMenuDataPtr->modeId--;
            else
                sMenuDataPtr->modeId = NUM_MODES - 1;
        }
        else{
            if(sMenuDataPtr->modeId != MODE_BATTLER0)
                sMenuDataPtr->modeId--;
            else
                sMenuDataPtr->modeId = MODE_BATTLER1;
        }
        setBattler();
        PrintPage();
    }

    if (JOY_NEW(DPAD_LEFT)){
        if(sMenuDataPtr->tabId != 0)
            sMenuDataPtr->tabId--;
        else
            sMenuDataPtr->tabId = NUM_TABS - 1;
        setBattler();
        PrintPage();
    }

    if (JOY_NEW(DPAD_RIGHT)){
        if(sMenuDataPtr->tabId != NUM_TABS - 1)
            sMenuDataPtr->tabId++;
        else
            sMenuDataPtr->tabId = 0;
        setBattler();
        PrintPage();
    }
}