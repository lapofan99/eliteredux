SPECIES_VENUSAUR
{
    .name = Assault Vest Physical Tank
    .lvl = 0,
    .species = SPECIES_VENUSAUR, // Assault Vest Tank
    .heldItem = ITEM_LEFTOVERS,
    .ability = 0, // ABILITY_CHLOROPLAST, ABILITY_EFFECT_SPORE, ABILITY_CHLOROPHYLL},
    // .innates = {ABILITY_OVERGROW, ABILITY_THICK_FAT, ABILITY_POISON_TOUCH},
    .ivs = {31, 0, 31, 31, 31, 31},
    .evs = {252, 0, 252, 0, 4, 0},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_BOLD,
    .moves = MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_LEECH_SEED, MOVE_SLEEP_POWDER
    }
venusaur
{
    .name = Wide Lens, Chloroplast
    .lvl = 0,
    .species = SPECIES_VENUSAUR, // Wide Lens, Chloroplast
    .heldItem = ITEM_WIDE_LENS,
    .ability = 0, // ABILITY_CHLOROPLAST, ABILITY_EFFECT_SPORE, ABILITY_CHLOROPHYLL},
    // .innates = {ABILITY_OVERGROW, ABILITY_THICK_FAT, ABILITY_POISON_TOUCH},
    .ivs = {31, 0, 31, 31, 31, 31},
    .evs = {252, 0, 0, 252, 0, 4},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_MODEST,
    .moves = MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_EARTH_POWER, MOVE_SLEEP_POWDER
    }
SPECIES_CHARIZARD
{
    .name = Offensive, White Herb, Burnate
    .lvl = 3,
    .species = SPECIES_CHARIZARD, // Flannery, White Herb, Burnate
    .heldItem = ITEM_WHITE_HERB,
    .ability = 0, // ABILITY_BURNATE, ABILITY_AERILATE, ABILITY_TOUGH_CLAWS},
    // .innates = {ABILITY_BLAZE, ABILITY_LEVITATE, ABILITY_SUN_WORSHIP},
    .ivs = {31, 0, 31, 31, 31, 31},
    .evs = {0, 0, 4, 252, 0, 252},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_TIMID,
    .moves = MOVE_SOLAR_BEAM, MOVE_SCORCHING_SANDS, MOVE_DRACO_METEOR, MOVE_HYPER_VOICE
    }
SPECIES_BLASTOISE_MEGA
{
    .name = Singles Shell Smash
    .species = BLASTOISE_MEGA SPECIES_BLASTOISE_MEGA,
    .heldItem = ITEM_BLASTOISINITE,
    .ability = 0, // ABILITY_TORRENT, ABILITY_SHELL_ARMOR, ABILITY_MEGA_LAUNCHER},
    .evs = {0, 0, 6, 252, 0, 252},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    .nature = NATURE_TIMID,
    .moves = MOVE_SHELL_SMASH, MOVE_HYDRO_PUMP, MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON
    .comment = Inaccurate moves cannot miss thanks to Artillery. With the added Steel type upon Mega Evolution, Blastoise gains STAB on Flash Cannon and additional resistances, so you can time the Mega Evolution well and get rewarded for it.
    }
escavalier
{
    name = Speed Boost Sweeper
    species = 
    item = leftovers
    ability = no guard
    evs = 0, 252, 4, 0, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = jolly
    moves = megahorn, iron head / close combat / drill run, protect, swords dance
   comment = Use protect to get more speed boost and leftovers recovery at the same time. 
}