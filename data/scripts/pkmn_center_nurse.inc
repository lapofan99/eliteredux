Common_EventScript_PkmnCenterNurse::
    lock
    faceplayer
    checkitem ITEM_POKE_VIAL, 1
    compare VAR_RESULT, 1
    goto_if_eq EventScript_PkmnCenterNurseHasVial
    msgbox gText_AreYouARookieTrainer, MSGBOX_DEFAULT
    giveitem ITEM_POKE_VIAL, 1
    setvar VAR_POKE_VIAL_MAX_CHARGES, 1
    setvar VAR_POKE_VIAL_CHARGES, 1
    msgbox gText_ExplainPokeVial, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_HealPkmn
    compare VAR_RESULT, NO
    goto_if_eq EventScript_PkmnCenterNurse_Goodbye
    end

EventScript_PkmnCenterNurseHasVial::
    call_if_set FLAG_RECEIVED_OLD_ROD, Give_Pokeblock_Case
    checkitem ITEM_RARE_CANDY, 400
    compare VAR_RESULT, TRUE
    call_if_ne ADDITEM_RARE_CANDY
    checkitem ITEM_MASTER_BALL, 400
    compare VAR_RESULT, TRUE
    call_if_ne ADDITEM_MASTER_BALL
    checkitem ITEM_ABILITY_PATCH, 400
    compare VAR_RESULT, TRUE
    call_if_ne ADDITEM_ABILITY_PATCH
    checkitem ITEM_ABILITY_CAPSULE, 400
    compare VAR_RESULT, TRUE
    call_if_ne ADDITEM_ABILITY_CAPSULE
    setvar VAR_0x8006, 4
    special GetSettingsMonStats
    compare VAR_0x8005, 1
    call_if_eq Give_Nuzlocke_Items
	call_if_eq Give_all_TMHMs
	call_if_eq Give_BattleItems
	call_if_eq Give_all_Type_Gems
	call_if_eq Give_all_Mega_Stones
	call_if_eq Give_Cut_Items_After_Roxanne
	call_if_eq Give_Thief_Items_After_Thief
	call_if_eq Give_Thief_Items_After_Museum
    call_if_eq Give_Thief_Items_After_Wattson
    call_if_eq Give_Thief_Items_After_Flannery
    call_if_eq Give_Thief_Items_After_Norman
    call_if_eq Give_Thief_Items_After_Winoma
    call EventScript_PkmnCenterNurse_HealPkmn
    end

EventScript_PkmnCenterNurse_Goodbye::
    message gText_WeHopeToSeeYouAgain
    return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
    EventScript_PkmnCenterNurse_HealPkmn::
    copyvar VAR_POKE_VIAL_CHARGES, VAR_POKE_VIAL_MAX_CHARGES @ refill Poke Vial
    incrementgamestat GAME_STAT_USED_POKECENTER
    call EventScript_PkmnCenterNurse_TakeAndHealPkmn
    goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
    end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
    message gText_IllTakeYourPkmn
    return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
    message gText_IllTakeYourPkmn2
    return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
    applymovement VAR_0x800B, Common_Movement_FaceLeft
    waitmovement 0
    dofieldeffect FLDEFF_POKECENTER_HEAL
    waitfieldeffect FLDEFF_POKECENTER_HEAL
    applymovement VAR_0x800B, Common_Movement_FaceDown
    waitmovement 0
    special HealPlayerParty
    return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
    specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
    compare VAR_RESULT, 0
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    specialvar VAR_RESULT, BufferUnionRoomPlayerName
    copyvar VAR_0x8008, VAR_RESULT
    compare VAR_0x8008, 0
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    compare VAR_0x8008, 1
    goto_if_eq EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
    end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
    applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
    waitmovement 0
    return

EventScript_PkmnCenterNurse_ReturnPkmn2::
    message gText_ThankYouForWaiting
    waitmessage
    applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
    goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
    msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
    setflag FLAG_NURSE_UNION_ROOM_REMINDER
    message CableClub_Text_PlayerIsWaiting
    waitmessage
    applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain
    return

EventScript_PkmnCenterNurse_CheckPokerus::
    specialvar VAR_RESULT, IsPokerusInParty
    compare VAR_RESULT, TRUE
    goto_if_eq EventScript_PkmnCenterNurse_ExplainPokerus
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
    end

EventScript_PkmnCenterNurse_ExplainPokerus::
    message gText_PokerusExplanation
    setflag FLAG_POKERUS_EXPLAINED
    return

EventScript_PkmnCenterNurse_GoldCard::
    goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
    setflag FLAG_NURSE_MENTIONS_GOLD_CARD
    msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
    playse SE_PIN
    applymovement VAR_0x800B, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement VAR_0x800B, Common_Movement_Delay48
    waitmovement 0
    msgbox gText_NoticesGoldCard, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_GoldCardHealPkmn
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_AskForUsual::
    msgbox gText_YouWantTheUsual, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_GoldCardHealPkmn
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
    setvar VAR_0x8004, 1
    goto EventScript_PkmnCenterNurse_HealPkmn
    end

Movement_PkmnCenterNurse_Bow:
    nurse_joy_bow
    delay_4
    step_end


Give_Pokeblock_Case:
	checkitem ITEM_POKEBLOCK_CASE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_POKEBLOCK_CASE
	return


Give_Nuzlocke_Items:
	call_if_set FLAG_BADGE01_GET, Give_Cut_Items_After_Roxanne
    	call_if_set FLAG_RECEIVED_TM46, Give_Thief_Items_After_Thief
    	call_if_set FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS, Give_Thief_Items_After_Museum
    	call_if_set FLAG_BADGE03_GET, Give_Thief_Items_After_Wattson
    	call_if_set FLAG_BADGE04_GET, Give_Thief_Items_After_Flannery
    	call_if_set FLAG_BADGE05_GET, Give_Thief_Items_After_Norman
    	call_if_set FLAG_BADGE06_GET, Give_Thief_Items_After_Winoma
	checkitem ITEM_BIG_PEARL, 400
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_BIG_PEARL
	checkitem ITEM_MAX_REPEL, 250
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_MAX_REPEL
	return

Give_BattleItems:
  checkitem ITEM_PROTECTIVE_PADS, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_PROTECTIVE_PADS
  checkitem ITEM_ROCKY_HELMET, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ROCKY_HELMET
  checkitem ITEM_HEAVY_DUTY_BOOTS, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_HEAVY_DUTY_BOOTS
  checkitem ITEM_THROAT_SPRAY, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_THROAT_SPRAY
  checkitem ITEM_ADAMANT_ORB, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ADAMANT_ORB
  checkitem ITEM_LUSTROUS_ORB, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_LUSTROUS_ORB
  checkitem ITEM_GRISEOUS_ORB, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_GRISEOUS_ORB
  checkitem ITEM_SOUL_DEW, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SOUL_DEW
  checkitem ITEM_AIR_BALLOON, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_AIR_BALLOON
  checkitem ITEM_WEAKNESS_POLICY, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_WEAKNESS_POLICY
  checkitem ITEM_ASSAULT_VEST, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ASSAULT_VEST
  checkitem ITEM_DAMP_ROCK, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_DAMP_ROCK
  checkitem ITEM_HEAT_ROCK, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_HEAT_ROCK
  checkitem ITEM_ICY_ROCK, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ICY_ROCK
  checkitem ITEM_SMOOTH_ROCK, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SMOOTH_ROCK
  checkitem ITEM_EXPERT_BELT, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_EXPERT_BELT
  checkitem ITEM_LIGHT_BALL, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_LIGHT_BALL
  checkitem ITEM_SCOPE_LENS, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SCOPE_LENS
  checkitem ITEM_SHED_SHELL, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SHED_SHELL
  checkitem ITEM_TERRAIN_EXTENDER, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_TERRAIN_EXTENDER
  checkitem ITEM_WIDE_LENS, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_WIDE_LENS
  checkitem ITEM_EVIOLITE, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_EVIOLITE
  checkitem ITEM_LEFTOVERS, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_LEFTOVERS
  checkitem ITEM_BLACK_SLUDGE, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_BLACK_SLUDGE
  checkitem ITEM_TOXIC_ORB, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_TOXIC_ORB
  checkitem ITEM_FLAME_ORB, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_FLAME_ORB
  checkitem ITEM_LIFE_ORB, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_LIFE_ORB
  checkitem ITEM_CHOICE_BAND, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_CHOICE_BAND
  checkitem ITEM_CHOICE_SPECS, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_CHOICE_SPECS
  checkitem ITEM_CHOICE_SCARF, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_CHOICE_SCARF
  checkitem ITEM_FOCUS_SASH, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_FOCUS_SASH
  checkitem ITEM_LIGHT_CLAY, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_LIGHT_CLAY
  checkitem ITEM_RED_ORB, 3
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_RED_ORB
  checkitem ITEM_BLUE_ORB, 3
  	compare VAR_RESULT, TRUE
  	call_if_ne ADDITEM_BLUE_ORB
	return

Give_Z_Power:
  checkitem ITEM_Z_RING, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_Z_RING
  checkitem ITEM_NORMALIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_NORMALIUM_Z
  checkitem ITEM_FIGHTINIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_FIGHTINIUM_Z
  checkitem ITEM_FLYINIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_FLYINIUM_Z
  checkitem ITEM_POISONIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_POISONIUM_Z
  checkitem ITEM_GROUNDIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_GROUNDIUM_Z
  checkitem ITEM_ROCKIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_ROCKIUM_Z
  checkitem ITEM_BUGINIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_BUGINIUM_Z
  checkitem ITEM_GHOSTIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_GHOSTIUM_Z
  checkitem ITEM_STEELIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_STEELIUM_Z
  checkitem ITEM_FIRIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_FIRIUM_Z
  checkitem ITEM_WATERIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_WATERIUM_Z
  checkitem ITEM_GRASSIUM_Z, 50
  	compare VAR_RESULT, TRUE
  	call_if_ne ADDITEM_ITEM_GRASSIUM_Z
  checkitem ITEM_ELECTRIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_ELECTRIUM_Z
  checkitem ITEM_PSYCHIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_PSYCHIUM_Z
  checkitem ITEM_ICIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_ICIUM_Z
  checkitem ITEM_DRAGONIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_DRAGONIUM_Z
  checkitem ITEM_DARKINIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_DARKINIUM_Z
  checkitem ITEM_FAIRIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_FAIRIUM_Z
  checkitem ITEM_ALORAICHIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_ALORAICHIUM_Z
  checkitem ITEM_DECIDIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_DECIDIUM_Z
  checkitem ITEM_EEVIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_EEVIUM_Z
  checkitem ITEM_INCINIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_INCINIUM_Z
  checkitem ITEM_KOMMONIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_KOMMONIUM_Z
  checkitem ITEM_LUNALIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_LUNALIUM_Z
  checkitem ITEM_LYCANIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_LYCANIUM_Z
  checkitem ITEM_MARSHADIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_MARSHADIUM_Z
  checkitem ITEM_MEWNIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_MEWNIUM_Z
  checkitem ITEM_MIMIKIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_MIMIKIUM_Z
  checkitem ITEM_PIKANIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_PIKANIUM_Z
  checkitem ITEM_PIKASHUNIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_PIKASHUNIUM_Z
  checkitem ITEM_PRIMARIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_PRIMARIUM_Z
  checkitem ITEM_SNORLIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_SNORLIUM_Z
  checkitem ITEM_SOLGANIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_SOLGANIUM_Z
  checkitem ITEM_TAPUNIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TAPUNIUM_Z
  checkitem ITEM_ULTRANECROZIUM_Z, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_ULTRANECROZIUM_Z
	return

Give_all_Type_Gems:
	checkitem ITEM_BUG_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_BUG_GEM
	
	checkitem ITEM_DARK_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_DARK_GEM
	
	checkitem ITEM_DRAGON_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_DRAGON_GEM
	
	checkitem ITEM_ELECTRIC_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_ELECTRIC_GEM
	
	checkitem ITEM_FAIRY_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_FAIRY_GEM
	
	checkitem ITEM_FIGHTING_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_FIGHTING_GEM
	
	checkitem ITEM_FIRE_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_FIRE_GEM
	
	checkitem ITEM_FLYING_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_FLYING_GEM
	
	checkitem ITEM_GHOST_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_GHOST_GEM
	
	checkitem ITEM_GRASS_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_GRASS_GEM
	
	checkitem ITEM_GROUND_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_GROUND_GEM
	
	checkitem ITEM_ICE_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_ICE_GEM
	
	checkitem ITEM_NORMAL_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_NORMAL_GEM
	
	checkitem ITEM_POISON_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_POISON_GEM
	
	checkitem ITEM_PSYCHIC_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_PSYCHIC_GEM
	
	checkitem ITEM_ROCK_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_ROCK_GEM
	
	checkitem ITEM_STEEL_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_STEEL_GEM
	
	checkitem ITEM_WATER_GEM, 50
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_WATER_GEM

	return

Give_all_Mega_Stones:
	checkitem ITEM_ABOMASITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_ABOMASITE
	
	checkitem ITEM_ABSOLITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_ABSOLITE
	
	checkitem ITEM_AERODACTYLITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_AERODACTYLITE
	
	checkitem ITEM_AGGRONITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_AGGRONITE
	
	checkitem ITEM_ALAKAZITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_ALAKAZITE
	
	checkitem ITEM_ALTARIANITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_ALTARIANITE
	
	checkitem ITEM_AMPHAROSITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_AMPHAROSITE
	
	checkitem ITEM_AUDINITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_AUDINITE
	
	checkitem ITEM_BANETTITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_BANETTITE
	
	checkitem ITEM_BEEDRILLITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_BEEDRILLITE
	
	checkitem ITEM_BLASTOISINITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_BLASTOISINITE
	
	checkitem ITEM_BLAZIKENITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_BLAZIKENITE
	
	checkitem ITEM_CAMERUPTITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_CAMERUPTITE
	
	checkitem ITEM_CHARIZARDITE_X, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_CHARIZARDITE_X
	
	checkitem ITEM_CHARIZARDITE_Y, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_CHARIZARDITE_Y
	
	checkitem ITEM_DIANCITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_DIANCITE
	
	checkitem ITEM_GALLADITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_GALLADITE
	
	checkitem ITEM_GARCHOMPITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_GARCHOMPITE
	
	checkitem ITEM_GARDEVOIRITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_GARDEVOIRITE
	
	checkitem ITEM_GENGARITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_GENGARITE
	
	checkitem ITEM_GLALITITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_GLALITITE
	
	checkitem ITEM_GYARADOSITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_GYARADOSITE
	
	checkitem ITEM_HERACRONITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_HERACRONITE
	
	checkitem ITEM_HOUNDOOMINITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_HOUNDOOMINITE
	
	checkitem ITEM_KANGASKHANITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_KANGASKHANITE
	
	checkitem ITEM_LATIASITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_LATIASITE
	
	checkitem ITEM_LATIOSITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_LATIOSITE
	
	checkitem ITEM_LOPUNNITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_LOPUNNITE
	
	checkitem ITEM_LUCARIONITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_LUCARIONITE
	
	checkitem ITEM_MANECTITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_MANECTITE
	
	checkitem ITEM_MAWILITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_MAWILITE
	
	checkitem ITEM_MEDICHAMITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_MEDICHAMITE
	
	checkitem ITEM_METAGROSSITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_METAGROSSITE
	
	checkitem ITEM_MEWTWONITE_X, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_MEWTWONITE_X
	
	checkitem ITEM_MEWTWONITE_Y, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_MEWTWONITE_Y
	
	checkitem ITEM_PIDGEOTITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_PIDGEOTITE
	
	checkitem ITEM_PINSIRITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_PINSIRITE
	
	checkitem ITEM_SABLENITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_SABLENITE
	
	checkitem ITEM_SALAMENCITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_SALAMENCITE
	
	checkitem ITEM_SCEPTILITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_SCEPTILITE
	
	checkitem ITEM_SCIZORITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_SCIZORITE
	
	checkitem ITEM_SHARPEDONITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_SHARPEDONITE
	
	checkitem ITEM_SLOWBRONITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_SLOWBRONITE
	
	checkitem ITEM_STEELIXITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_STEELIXITE
	
	checkitem ITEM_SWAMPERTITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_SWAMPERTITE
	
	checkitem ITEM_TYRANITARITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_TYRANITARITE
	
	checkitem ITEM_VENUSAURITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_VENUSAURITE
	
	checkitem ITEM_MILOTICITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_MILOTICITE
	
	checkitem ITEM_FLYGONITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_FLYGONITE
	
	checkitem ITEM_BUTTERFRENITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_BUTTERFRENITE
	
	checkitem ITEM_LAPRASITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_LAPRASITE
	
	checkitem ITEM_MACHAMPITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_MACHAMPITE
	
	checkitem ITEM_KINGLERITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_KINGLERITE
	
	checkitem ITEM_KINGDRANITE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADD_ITEM_KINGDRANITE

	return
Give_all_TMHMs:
	checkitem ITEM_TM01_FOCUS_PUNCH, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM01_FOCUS_PUNCH

	checkitem ITEM_TM02_DRAGON_CLAW, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM02_DRAGON_CLAW

	checkitem ITEM_TM03_WATER_PULSE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM03_WATER_PULSE

	checkitem ITEM_TM04_CALM_MIND, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM04_CALM_MIND

	checkitem ITEM_TM05_ROAR, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM05_ROAR

	checkitem ITEM_TM06_TOXIC, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM06_TOXIC

	checkitem ITEM_TM07_HAIL, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM07_HAIL

	checkitem ITEM_TM08_BULK_UP, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM08_BULK_UP

	checkitem ITEM_TM09_BULLET_SEED, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM08_BULK_UP

	checkitem ITEM_TM10_HIDDEN_POWER, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM10_HIDDEN_POWER

	checkitem ITEM_TM11_SUNNY_DAY, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM11_SUNNY_DAY

	checkitem ITEM_TM12_TAUNT, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM12_TAUNT

	checkitem ITEM_TM13_ICE_BEAM, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM13_ICE_BEAM

	checkitem ITEM_TM14_BLIZZARD, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM14_BLIZZARD

	checkitem ITEM_TM15_HYPER_BEAM, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM15_HYPER_BEAM

	checkitem ITEM_TM16_LIGHT_SCREEN, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM16_LIGHT_SCREEN

	checkitem ITEM_TM17_PROTECT, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM17_PROTECT

	checkitem ITEM_TM18_RAIN_DANCE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM18_RAIN_DANCE

	checkitem ITEM_TM19_GIGA_DRAIN, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM19_GIGA_DRAIN

	checkitem ITEM_TM20_SAFEGUARD, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM20_SAFEGUARD

	checkitem ITEM_TM21_FRUSTRATION, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM21_FRUSTRATION

	checkitem ITEM_TM22_SOLARBEAM, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM22_SOLARBEAM

	checkitem ITEM_TM23_IRON_TAIL, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM23_IRON_TAIL

	checkitem ITEM_TM24_THUNDERBOLT, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM24_THUNDERBOLT

	checkitem ITEM_TM26_EARTHQUAKE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM26_EARTHQUAKE

	checkitem ITEM_TM27_RETURN, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM27_RETURN

	checkitem ITEM_TM28_DIG, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM28_DIG

	checkitem ITEM_TM29_PSYCHIC, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM29_PSYCHIC

	checkitem ITEM_TM30_SHADOW_BALL, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM30_SHADOW_BALL

	checkitem ITEM_TM31_BRICK_BREAK, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM31_BRICK_BREAK

	checkitem ITEM_TM32_DOUBLE_TEAM, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM32_DOUBLE_TEAM

	checkitem ITEM_TM33_REFLECT, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM33_REFLECT

	checkitem ITEM_TM34_SLUDGE_WAVE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM34_SLUDGE_WAVE

	checkitem ITEM_TM35_FLAMETHROWER, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM35_FLAMETHROWER

	checkitem ITEM_TM36_SLUDGE_BOMB, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM36_SLUDGE_BOMB

	checkitem ITEM_TM37_SANDSTORM, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM37_SANDSTORM

	checkitem ITEM_TM38_FIRE_BLAST, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM38_FIRE_BLAST

	checkitem ITEM_TM39_ROCK_TOMB, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM39_ROCK_TOMB

	checkitem ITEM_TM40_AERIAL_ACE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM40_AERIAL_ACE

	checkitem ITEM_TM41_TORMENT, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM41_TORMENT

	checkitem ITEM_TM42_FACADE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM42_FACADE

	checkitem ITEM_TM43_SECRET_POWER, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM43_SECRET_POWER

	checkitem ITEM_TM44_REST, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM44_REST

	checkitem ITEM_TM45_ATTRACT, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM45_ATTRACT

	checkitem ITEM_TM46_THIEF, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM46_THIEF

	checkitem ITEM_TM47_STEEL_WING, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM47_STEEL_WING

	checkitem ITEM_TM48_SKILL_SWAP, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM48_SKILL_SWAP

	checkitem ITEM_TM49_SLEEP_TALK, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM49_SLEEP_TALK

	checkitem ITEM_TM50_OVERHEAT, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM50_OVERHEAT

	checkitem ITEM_TM51_ROOST, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM51_ROOST

	checkitem ITEM_TM52_FOCUS_BLAST, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM52_FOCUS_BLAST

	checkitem ITEM_TM53_ENERGY_BALL, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM53_ENERGY_BALL

	checkitem ITEM_TM54_PSYSHOCK, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM54_PSYSHOCK

	checkitem ITEM_TM55_SCALD, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM55_SCALD

	checkitem ITEM_TM56_LEECH_LIFE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM56_LEECH_LIFE

	checkitem ITEM_TM57_CHARGE_BEAM, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM57_CHARGE_BEAM

	checkitem ITEM_TM58_ENDURE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM58_ENDURE

	checkitem ITEM_TM59_DRAGON_PULSE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM59_DRAGON_PULSE

	checkitem ITEM_TM60_DRAIN_PUNCH, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM60_DRAIN_PUNCH

	checkitem ITEM_TM61_WILL_O_WISP, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM61_WILL_O_WISP

	checkitem ITEM_TM62_ACROBATICS, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM62_ACROBATICS

	checkitem ITEM_TM63_ROCK_SLIDE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM63_ROCK_SLIDE

	checkitem ITEM_TM64_EXPLOSION, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM64_EXPLOSION

	checkitem ITEM_TM65_SHADOW_CLAW, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM65_SHADOW_CLAW

	checkitem ITEM_TM66_PAYBACK, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM66_PAYBACK

	checkitem ITEM_TM67_RECYCLE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM67_RECYCLE

	checkitem ITEM_TM68_GIGA_IMPACT, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM68_GIGA_IMPACT

	checkitem ITEM_TM69_ROCK_POLISH, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM69_ROCK_POLISH

	checkitem ITEM_TM70_AURORA_VEIL, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM70_AURORA_VEIL

	checkitem ITEM_TM71_STONE_EDGE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM71_STONE_EDGE

	checkitem ITEM_TM72_VOLT_SWITCH, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM72_VOLT_SWITCH

	checkitem ITEM_TM73_THUNDER_WAVE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM73_THUNDER_WAVE

	checkitem ITEM_TM74_GYRO_BALL, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM74_GYRO_BALL

	checkitem ITEM_TM75_SWORDS_DANCE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM75_SWORDS_DANCE

	checkitem ITEM_TM76_STEALTH_ROCK, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM76_STEALTH_ROCK

	checkitem ITEM_TM77_STRUGGLE_BUG, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM77_STRUGGLE_BUG

	checkitem ITEM_TM78_BULLDOZE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM78_BULLDOZE

	checkitem ITEM_TM79_FREEZE_DRY, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM79_FREEZE_DRY

	checkitem ITEM_TM80_VENOSHOCK, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM80_VENOSHOCK

	checkitem ITEM_TM81_X_SCISSOR, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM81_X_SCISSOR

	checkitem ITEM_TM82_DRAGON_TAIL, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM82_DRAGON_TAIL

	checkitem ITEM_TM83_FLAME_CHARGE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM83_FLAME_CHARGE

	checkitem ITEM_TM84_POISON_JAB, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM84_POISON_JAB

	checkitem ITEM_TM85_DREAM_EATER, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM85_DREAM_EATER

	checkitem ITEM_TM86_GRASS_KNOT, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM86_GRASS_KNOT

	checkitem ITEM_TM87_SMACK_DOWN, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM87_SMACK_DOWN

	checkitem ITEM_TM88_LOW_SWEEP, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM88_LOW_SWEEP

	checkitem ITEM_TM89_U_TURN, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM89_U_TURN

	checkitem ITEM_TM90_SUBSTITUTE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM90_SUBSTITUTE

	checkitem ITEM_TM91_FLASH_CANNON, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM91_FLASH_CANNON

	checkitem ITEM_TM92_TRICK_ROOM, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM92_TRICK_ROOM

	checkitem ITEM_TM93_WILD_CHARGE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM93_WILD_CHARGE

	checkitem ITEM_TM94_SUCKER_PUNCH, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM94_SUCKER_PUNCH

	checkitem ITEM_TM95_SNARL, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM95_SNARL

	checkitem ITEM_TM96_AVALANCHE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM96_AVALANCHE

	checkitem ITEM_TM97_DARK_PULSE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM97_DARK_PULSE

	checkitem ITEM_TM98_FALSE_SWIPE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM98_FALSE_SWIPE

	checkitem ITEM_TM99_DAZZLING_GLEAM, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM99_DAZZLING_GLEAM

	checkitem ITEM_TM100_CURSE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_TM100_CURSE

	checkitem ITEM_HM01_CUT, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_HM01_CUT

	checkitem ITEM_HM02_FLY, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_HM02_FLY

	checkitem ITEM_HM03_SURF, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_HM03_SURF

	checkitem ITEM_HM04_STRENGTH, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_HM04_STRENGTH

	checkitem ITEM_HM05_FLASH, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_HM05_FLASH

	checkitem ITEM_HM06_ROCK_SMASH, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_HM06_ROCK_SMASH

	checkitem ITEM_HM07_WATERFALL, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_HM07_WATERFALL

	checkitem ITEM_HM08_DIVE, 1
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ITEM_HM08_DIVE
	return

Give_Cut_Items_After_Roxanne:
	checkitem ITEM_MIRACLE_SEED, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_MIRACLE_SEED
	checkitem ITEM_CHARCOAL, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_CHARCOAL
	checkitem ITEM_LEEK, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_LEEK
	checkitem ITEM_BIG_ROOT, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_BIG_ROOT
	checkitem ITEM_MENTAL_HERB, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_MENTAL_HERB
	checkitem ITEM_POWER_HERB, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_POWER_HERB
	checkitem ITEM_WHITE_HERB, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_WHITE_HERB
	checkitem ITEM_ELECTRIC_SEED, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ELECTRIC_SEED
	checkitem ITEM_PSYCHIC_SEED, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_PSYCHIC_SEED
	checkitem ITEM_GRASSY_SEED, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_GRASSY_SEED
	checkitem ITEM_MISTY_SEED, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_MISTY_SEED
	checkitem ITEM_CHERI_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_CHERI_BERRY
	checkitem ITEM_CHESTO_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_CHESTO_BERRY
	checkitem ITEM_PECHA_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_PECHA_BERRY
	checkitem ITEM_RAWST_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_RAWST_BERRY
	checkitem ITEM_PERSIM_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_PERSIM_BERRY
	checkitem ITEM_OCCA_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_OCCA_BERRY
	checkitem ITEM_PASSHO_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_PASSHO_BERRY
	checkitem ITEM_WACAN_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_WACAN_BERRY
	checkitem ITEM_RINDO_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_RINDO_BERRY
	checkitem ITEM_YACHE_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_YACHE_BERRY
	checkitem ITEM_CHOPLE_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_CHOPLE_BERRY
	checkitem ITEM_KEBIA_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_KEBIA_BERRY
	checkitem ITEM_SHUCA_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SHUCA_BERRY
	checkitem ITEM_COBA_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_COBA_BERRY
	checkitem ITEM_PAYAPA_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_PAYAPA_BERRY
	checkitem ITEM_TANGA_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_TANGA_BERRY
	checkitem ITEM_CHARTI_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_CHARTI_BERRY
	checkitem ITEM_KASIB_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_KASIB_BERRY
	checkitem ITEM_HABAN_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_HABAN_BERRY
	checkitem ITEM_COLBUR_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_COLBUR_BERRY
	checkitem ITEM_BABIRI_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_BABIRI_BERRY
	checkitem ITEM_CHILAN_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_CHILAN_BERRY
	checkitem ITEM_ROSELI_BERRY, 100
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_ROSELI_BERRY
	return


Give_Thief_Items_After_Thief:
	checkitem ITEM_SITRUS_BERRY, 400
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SITRUS_BERRY
	checkitem ITEM_BRIGHT_POWDER, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_BRIGHT_POWDER
	checkitem ITEM_HARD_STONE, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_HARD_STONE
	checkitem ITEM_MYSTIC_WATER, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_MYSTIC_WATER
	checkitem ITEM_SILVER_POWDER, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SILVER_POWDER
	checkitem ITEM_POISON_BARB, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_POISON_BARB
	checkitem ITEM_SOFT_SAND, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SOFT_SAND
	checkitem ITEM_BLACK_BELT, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_BLACK_BELT
	return


Give_Thief_Items_After_Museum:
	checkitem ITEM_SILK_SCARF, 400
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SILK_SCARF
	checkitem ITEM_SHARP_BEAK, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SHARP_BEAK
	checkitem ITEM_NEVER_MELT_ICE, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_NEVER_MELT_ICE
	checkitem ITEM_TWISTED_SPOON, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_TWISTED_SPOON
	return


Give_Thief_Items_After_Wattson:
	checkitem ITEM_MAGNET, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_MAGNET
	return


Give_Thief_Items_After_Flannery:
	checkitem ITEM_BLACK_GLASSES, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_BLACK_GLASSES
	checkitem ITEM_SPELL_TAG, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_SPELL_TAG
	return

Give_Thief_Items_After_Norman:
	checkitem ITEM_DRAGON_FANG, 10
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_DRAGON_FANG
	return

Give_Thief_Items_After_Winoma:
	checkitem ITEM_PP_MAX, 90
	compare VAR_RESULT, TRUE
	call_if_ne ADDITEM_PP_MAX
	return

ADDITEM_POKEBLOCK_CASE:
	additem ITEM_POKEBLOCK_CASE, 1
	return

ADDITEM_RARE_CANDY:
	additem ITEM_RARE_CANDY, 400
	return

ADDITEM_ITEM_Z_RING:
    additem ITEM_Z_RING, 1
    return

ADDITEM_ITEM_NORMALIUM_Z:
	additem ITEM_NORMALIUM_Z, 50
	return

ADDITEM_ITEM_FIGHTINIUM_Z:
	additem ITEM_FIGHTINIUM_Z, 50
	return

ADDITEM_ITEM_FLYINIUM_Z:
	additem ITEM_FLYINIUM_Z, 50
	return

ADDITEM_ITEM_POISONIUM_Z:
	additem ITEM_POISONIUM_Z, 50
	return

ADDITEM_ITEM_GROUNDIUM_Z:
	additem ITEM_GROUNDIUM_Z, 50
	return

ADDITEM_ITEM_ROCKIUM_Z:
	additem ITEM_ROCKIUM_Z, 50
	return

ADDITEM_ITEM_BUGINIUM_Z:
	additem ITEM_BUGINIUM_Z, 50
	return

ADDITEM_ITEM_GHOSTIUM_Z:
	additem ITEM_GHOSTIUM_Z, 50
	return

ADDITEM_ITEM_STEELIUM_Z:
	additem ITEM_STEELIUM_Z, 50
	return

ADDITEM_ITEM_FIRIUM_Z:
	additem ITEM_FIRIUM_Z, 50
	return

ADDITEM_ITEM_WATERIUM_Z:
	additem ITEM_WATERIUM_Z, 50
	return

ADDITEM_ITEM_GRASSIUM_Z:
	additem ITEM_GRASSIUM_Z, 50
	return

ADDITEM_ITEM_ELECTRIUM_Z:
	additem ITEM_ELECTRIUM_Z, 50
	return

ADDITEM_ITEM_PSYCHIUM_Z:
	additem ITEM_PSYCHIUM_Z, 50
	return

ADDITEM_ITEM_ICIUM_Z:
	additem ITEM_ICIUM_Z, 50
	return

ADDITEM_ITEM_DRAGONIUM_Z:
	additem ITEM_DRAGONIUM_Z, 50
	return

ADDITEM_ITEM_DARKINIUM_Z:
	additem ITEM_DARKINIUM_Z, 50
	return

ADDITEM_ITEM_FAIRIUM_Z:
	additem ITEM_FAIRIUM_Z, 50
    return
ADDITEM_ITEM_ALORAICHIUM_Z:
	additem ITEM_ALORAICHIUM_Z, 50
	return

ADDITEM_ITEM_DECIDIUM_Z:
	additem ITEM_DECIDIUM_Z, 50
	return

ADDITEM_ITEM_EEVIUM_Z:
	additem ITEM_EEVIUM_Z, 50
	return

ADDITEM_ITEM_INCINIUM_Z:
	additem ITEM_INCINIUM_Z, 50
	return

ADDITEM_ITEM_KOMMONIUM_Z:
	additem ITEM_KOMMONIUM_Z, 50
	return

ADDITEM_ITEM_LUNALIUM_Z:
	additem ITEM_LUNALIUM_Z, 50
	return

ADDITEM_ITEM_LYCANIUM_Z:
	additem ITEM_LYCANIUM_Z, 50
	return

ADDITEM_ITEM_MARSHADIUM_Z:
	additem ITEM_MARSHADIUM_Z, 50
	return

ADDITEM_ITEM_MEWNIUM_Z:
	additem ITEM_MEWNIUM_Z, 50
	return

ADDITEM_ITEM_MIMIKIUM_Z:
	additem ITEM_MIMIKIUM_Z, 50
	return

ADDITEM_ITEM_PIKANIUM_Z:
	additem ITEM_PIKANIUM_Z, 50
	return

ADDITEM_ITEM_PIKASHUNIUM_Z:
	additem ITEM_PIKASHUNIUM_Z, 50
	return

ADDITEM_ITEM_PRIMARIUM_Z:
	additem ITEM_PRIMARIUM_Z, 50
	return

ADDITEM_ITEM_SNORLIUM_Z:
	additem ITEM_SNORLIUM_Z, 50
	return

ADDITEM_ITEM_SOLGANIUM_Z:
	additem ITEM_SOLGANIUM_Z, 50
	return

ADDITEM_ITEM_TAPUNIUM_Z:
	additem ITEM_TAPUNIUM_Z, 50
	return

ADDITEM_ITEM_ULTRANECROZIUM_Z:
	additem ITEM_ULTRANECROZIUM_Z, 50
	return

ADDITEM_ITEM_TM01_FOCUS_PUNCH:
	additem ITEM_TM01_FOCUS_PUNCH, 1
	return

ADDITEM_ITEM_TM02_DRAGON_CLAW:
	additem ITEM_TM02_DRAGON_CLAW, 1
	return

ADDITEM_ITEM_TM03_WATER_PULSE:
	additem ITEM_TM03_WATER_PULSE, 1
	return

ADDITEM_ITEM_TM04_CALM_MIND:
	additem ITEM_TM04_CALM_MIND, 1
	return

ADDITEM_ITEM_TM05_ROAR:
	additem ITEM_TM05_ROAR, 1
	return

ADDITEM_ITEM_TM06_TOXIC:
	additem ITEM_TM06_TOXIC, 1
	return

ADDITEM_ITEM_TM07_HAIL:
	additem ITEM_TM07_HAIL, 1
	return

ADDITEM_ITEM_TM08_BULK_UP:
	additem ITEM_TM08_BULK_UP, 1
	return

ADDITEM_ITEM_TM09_BULLET_SEED:
	additem ITEM_TM09_BULLET_SEED, 1
	return

ADDITEM_ITEM_TM10_HIDDEN_POWER:
	additem ITEM_TM10_HIDDEN_POWER, 1
	return

ADDITEM_ITEM_TM11_SUNNY_DAY:
	additem ITEM_TM11_SUNNY_DAY, 1
	return

ADDITEM_ITEM_TM12_TAUNT:
	additem ITEM_TM12_TAUNT, 1
	return

ADDITEM_ITEM_TM13_ICE_BEAM:
	additem ITEM_TM13_ICE_BEAM, 1
	return

ADDITEM_ITEM_TM14_BLIZZARD:
	additem ITEM_TM14_BLIZZARD, 1
	return

ADDITEM_ITEM_TM15_HYPER_BEAM:
	additem ITEM_TM15_HYPER_BEAM, 1
	return

ADDITEM_ITEM_TM16_LIGHT_SCREEN:
	additem ITEM_TM16_LIGHT_SCREEN, 1
	return

ADDITEM_ITEM_TM17_PROTECT:
	additem ITEM_TM17_PROTECT, 1
	return
ADDITEM_ITEM_TM18_RAIN_DANCE:
	additem ITEM_TM18_RAIN_DANCE, 1
	return

ADDITEM_ITEM_TM19_GIGA_DRAIN:
	additem ITEM_TM19_GIGA_DRAIN, 1
	return

ADDITEM_ITEM_TM20_SAFEGUARD:
	additem ITEM_TM20_SAFEGUARD, 1
	return

ADDITEM_ITEM_TM21_FRUSTRATION:
	additem ITEM_TM21_FRUSTRATION, 1
	return

ADDITEM_ITEM_TM22_SOLARBEAM:
	additem ITEM_TM22_SOLARBEAM, 1
	return

ADDITEM_ITEM_TM23_IRON_TAIL:
	additem ITEM_TM23_IRON_TAIL, 1
	return

ADDITEM_ITEM_TM24_THUNDERBOLT:
	additem ITEM_TM24_THUNDERBOLT, 1
	return

ADDITEM_ITEM_TM26_EARTHQUAKE:
	additem ITEM_TM26_EARTHQUAKE, 1
	return

ADDITEM_ITEM_TM27_RETURN:
	additem ITEM_TM27_RETURN, 1
	return

ADDITEM_ITEM_TM28_DIG:
	additem ITEM_TM28_DIG, 1
	return

ADDITEM_ITEM_TM29_PSYCHIC:
	additem ITEM_TM29_PSYCHIC, 1
	return

ADDITEM_ITEM_TM30_SHADOW_BALL:
	additem ITEM_TM30_SHADOW_BALL, 1
	return

ADDITEM_ITEM_TM31_BRICK_BREAK:
	additem ITEM_TM31_BRICK_BREAK, 1
	return

ADDITEM_ITEM_TM32_DOUBLE_TEAM:
	additem ITEM_TM32_DOUBLE_TEAM, 1
	return

ADDITEM_ITEM_TM33_REFLECT:
	additem ITEM_TM33_REFLECT, 1
	return

ADDITEM_ITEM_TM34_SLUDGE_WAVE:
	additem ITEM_TM34_SLUDGE_WAVE, 1
	return

ADDITEM_ITEM_TM35_FLAMETHROWER:
	additem ITEM_TM35_FLAMETHROWER, 1
	return

ADDITEM_ITEM_TM36_SLUDGE_BOMB:
	additem ITEM_TM36_SLUDGE_BOMB, 1
	return

ADDITEM_ITEM_TM37_SANDSTORM:
	additem ITEM_TM37_SANDSTORM, 1
	return

ADDITEM_ITEM_TM38_FIRE_BLAST:
	additem ITEM_TM38_FIRE_BLAST, 1
	return

ADDITEM_ITEM_TM39_ROCK_TOMB:
	additem ITEM_TM39_ROCK_TOMB, 1
	return

ADDITEM_ITEM_TM40_AERIAL_ACE:
	additem ITEM_TM40_AERIAL_ACE, 1
	return

ADDITEM_ITEM_TM41_TORMENT:
	additem ITEM_TM41_TORMENT, 1
	return

ADDITEM_ITEM_TM42_FACADE:
	additem ITEM_TM42_FACADE, 1
	return

ADDITEM_ITEM_TM43_SECRET_POWER:
	additem ITEM_TM43_SECRET_POWER, 1
	return

ADDITEM_ITEM_TM44_REST:
	additem ITEM_TM44_REST, 1
	return

ADDITEM_ITEM_TM45_ATTRACT:
	additem ITEM_TM45_ATTRACT, 1
	return

ADDITEM_ITEM_TM46_THIEF:
	additem ITEM_TM46_THIEF, 1
	return

ADDITEM_ITEM_TM47_STEEL_WING:
	additem ITEM_TM47_STEEL_WING, 1
	return

ADDITEM_ITEM_TM48_SKILL_SWAP:
	additem ITEM_TM48_SKILL_SWAP, 1
	return

ADDITEM_ITEM_TM49_SLEEP_TALK:
	additem ITEM_TM49_SLEEP_TALK, 1
	return

ADDITEM_ITEM_TM50_OVERHEAT:
	additem ITEM_TM50_OVERHEAT, 1
	return

ADDITEM_ITEM_TM51_ROOST:
	additem ITEM_TM51_ROOST, 1
	return

ADDITEM_ITEM_TM52_FOCUS_BLAST:
	additem ITEM_TM52_FOCUS_BLAST, 1
	return

ADDITEM_ITEM_TM53_ENERGY_BALL:
	additem ITEM_TM53_ENERGY_BALL, 1
	return

ADDITEM_ITEM_TM54_PSYSHOCK:
	additem ITEM_TM54_PSYSHOCK, 1
	return

ADDITEM_ITEM_TM55_SCALD:
	additem ITEM_TM55_SCALD, 1
	return

ADDITEM_ITEM_TM56_LEECH_LIFE:
	additem ITEM_TM56_LEECH_LIFE, 1
	return

ADDITEM_ITEM_TM57_CHARGE_BEAM:
	additem ITEM_TM57_CHARGE_BEAM, 1
	return

ADDITEM_ITEM_TM58_ENDURE:
	additem ITEM_TM58_ENDURE, 1
	return

ADDITEM_ITEM_TM59_DRAGON_PULSE:
	additem ITEM_TM59_DRAGON_PULSE, 1
	return

ADDITEM_ITEM_TM60_DRAIN_PUNCH:
	additem ITEM_TM60_DRAIN_PUNCH, 1
	return

ADDITEM_ITEM_TM61_WILL_O_WISP:
	additem ITEM_TM61_WILL_O_WISP, 1
	return

ADDITEM_ITEM_TM62_ACROBATICS:
	additem ITEM_TM62_ACROBATICS, 1
	return

ADDITEM_ITEM_TM63_ROCK_SLIDE:
	additem ITEM_TM63_ROCK_SLIDE, 1
	return

ADDITEM_ITEM_TM64_EXPLOSION:
	additem ITEM_TM64_EXPLOSION, 1
	return

ADDITEM_ITEM_TM65_SHADOW_CLAW:
	additem ITEM_TM65_SHADOW_CLAW, 1
	return

ADDITEM_ITEM_TM66_PAYBACK:
	additem ITEM_TM66_PAYBACK, 1
	return

ADDITEM_ITEM_TM67_RECYCLE:
	additem ITEM_TM67_RECYCLE, 1
	return

ADDITEM_ITEM_TM68_GIGA_IMPACT:
	additem ITEM_TM68_GIGA_IMPACT, 1
	return

ADDITEM_ITEM_TM69_ROCK_POLISH:
	additem ITEM_TM69_ROCK_POLISH, 1
	return

ADDITEM_ITEM_TM70_AURORA_VEIL:
	additem ITEM_TM70_AURORA_VEIL, 1
	return

ADDITEM_ITEM_TM71_STONE_EDGE:
	additem ITEM_TM71_STONE_EDGE, 1
	return

ADDITEM_ITEM_TM72_VOLT_SWITCH:
	additem ITEM_TM72_VOLT_SWITCH, 1
	return

ADDITEM_ITEM_TM73_THUNDER_WAVE:
	additem ITEM_TM73_THUNDER_WAVE, 1
	return

ADDITEM_ITEM_TM74_GYRO_BALL:
	additem ITEM_TM74_GYRO_BALL, 1
	return

ADDITEM_ITEM_TM75_SWORDS_DANCE:
	additem ITEM_TM75_SWORDS_DANCE, 1
	return

ADDITEM_ITEM_TM76_STEALTH_ROCK:
	additem ITEM_TM76_STEALTH_ROCK, 1
	return

ADDITEM_ITEM_TM77_STRUGGLE_BUG:
	additem ITEM_TM77_STRUGGLE_BUG, 1
	return

ADDITEM_ITEM_TM78_BULLDOZE:
	additem ITEM_TM78_BULLDOZE, 1
	return

ADDITEM_ITEM_TM79_FREEZE_DRY:
	additem ITEM_TM79_FREEZE_DRY, 1
	return

ADDITEM_ITEM_TM80_VENOSHOCK:
	additem ITEM_TM80_VENOSHOCK, 1
	return

ADDITEM_ITEM_TM81_X_SCISSOR:
	additem ITEM_TM81_X_SCISSOR, 1
	return

ADDITEM_ITEM_TM82_DRAGON_TAIL:
	additem ITEM_TM82_DRAGON_TAIL, 1
	return

ADDITEM_ITEM_TM83_FLAME_CHARGE:
	additem ITEM_TM83_FLAME_CHARGE, 1
	return

ADDITEM_ITEM_TM84_POISON_JAB:
	additem ITEM_TM84_POISON_JAB, 1
	return

ADDITEM_ITEM_TM85_DREAM_EATER:
	additem ITEM_TM85_DREAM_EATER, 1
	return

ADDITEM_ITEM_TM86_GRASS_KNOT:
	additem ITEM_TM86_GRASS_KNOT, 1
	return

ADDITEM_ITEM_TM87_SMACK_DOWN:
	additem ITEM_TM87_SMACK_DOWN, 1
	return

ADDITEM_ITEM_TM88_LOW_SWEEP:
	additem ITEM_TM88_LOW_SWEEP, 1
	return

ADDITEM_ITEM_TM89_U_TURN:
	additem ITEM_TM89_U_TURN, 1
	return

ADDITEM_ITEM_TM90_SUBSTITUTE:
	additem ITEM_TM90_SUBSTITUTE, 1
	return

ADDITEM_ITEM_TM91_FLASH_CANNON:
	additem ITEM_TM91_FLASH_CANNON, 1
	return

ADDITEM_ITEM_TM92_TRICK_ROOM:
	additem ITEM_TM92_TRICK_ROOM, 1
	return

ADDITEM_ITEM_TM93_WILD_CHARGE:
	additem ITEM_TM93_WILD_CHARGE, 1
	return

ADDITEM_ITEM_TM94_SUCKER_PUNCH:
	additem ITEM_TM94_SUCKER_PUNCH, 1
	return

ADDITEM_ITEM_TM95_SNARL:
	additem ITEM_TM95_SNARL, 1
	return

ADDITEM_ITEM_TM96_AVALANCHE:
	additem ITEM_TM96_AVALANCHE, 1
	return

ADDITEM_ITEM_TM97_DARK_PULSE:
	additem ITEM_TM97_DARK_PULSE, 1
	return

ADDITEM_ITEM_TM98_FALSE_SWIPE:
	additem ITEM_TM98_FALSE_SWIPE, 1
	return

ADDITEM_ITEM_TM99_DAZZLING_GLEAM:
	additem ITEM_TM99_DAZZLING_GLEAM, 1
	return

ADDITEM_ITEM_TM100_CURSE:
	additem ITEM_TM100_CURSE, 1
	return

ADDITEM_ITEM_HM01_CUT:
	additem ITEM_HM01_CUT, 1
	return

ADDITEM_ITEM_HM02_FLY:
	additem ITEM_HM02_FLY, 1
	return

ADDITEM_ITEM_HM03_SURF:
	additem ITEM_HM03_SURF, 1
	return

ADDITEM_ITEM_HM04_STRENGTH:
	additem ITEM_HM04_STRENGTH, 1
	return

ADDITEM_ITEM_HM05_FLASH:
	additem ITEM_HM05_FLASH, 1
	return

ADDITEM_ITEM_HM06_ROCK_SMASH:
	additem ITEM_HM06_ROCK_SMASH, 1
	return

ADDITEM_ITEM_HM07_WATERFALL:
	additem ITEM_HM07_WATERFALL, 1
	return

ADDITEM_ITEM_HM08_DIVE:
	additem ITEM_HM08_DIVE, 1
	return

ADD_ITEM_ABOMASITE:
	additem ITEM_ABOMASITE, 1
	return
	
ADD_ITEM_ABSOLITE:
	additem ITEM_ABSOLITE, 1
	return
	
ADD_ITEM_AERODACTYLITE:
	additem ITEM_AERODACTYLITE, 1
	return
	
ADD_ITEM_AGGRONITE:
	additem ITEM_AGGRONITE, 1
	return
	
ADD_ITEM_ALAKAZITE:
	additem ITEM_ALAKAZITE, 1
	return
	
ADD_ITEM_ALTARIANITE:
	additem ITEM_ALTARIANITE, 1
	return
	
ADD_ITEM_AMPHAROSITE:
	additem ITEM_AMPHAROSITE, 1
	return
	
ADD_ITEM_AUDINITE:
	additem ITEM_AUDINITE, 1
	return
	
ADD_ITEM_BANETTITE:
	additem ITEM_BANETTITE, 1
	return
	
ADD_ITEM_BEEDRILLITE:
	additem ITEM_BEEDRILLITE, 1
	return
	
ADD_ITEM_BLASTOISINITE:
	additem ITEM_BLASTOISINITE, 1
	return
	
ADD_ITEM_BLAZIKENITE:
	additem ITEM_BLAZIKENITE, 1
	return
	
ADD_ITEM_CAMERUPTITE:
	additem ITEM_CAMERUPTITE, 1
	return
	
ADD_ITEM_CHARIZARDITE_X:
	additem ITEM_CHARIZARDITE_X, 1
	return
	
ADD_ITEM_CHARIZARDITE_Y:
	additem ITEM_CHARIZARDITE_Y, 1
	return
	
ADD_ITEM_DIANCITE:
	additem ITEM_DIANCITE, 1
	return
	
ADD_ITEM_GALLADITE:
	additem ITEM_GALLADITE, 1
	return
	
ADD_ITEM_GARCHOMPITE:
	additem ITEM_GARCHOMPITE, 1
	return
	
ADD_ITEM_GARDEVOIRITE:
	additem ITEM_GARDEVOIRITE, 1
	return
	
ADD_ITEM_GENGARITE:
	additem ITEM_GENGARITE, 1
	return
	
ADD_ITEM_GLALITITE:
	additem ITEM_GLALITITE, 1
	return
	
ADD_ITEM_GYARADOSITE:
	additem ITEM_GYARADOSITE, 1
	return
	
ADD_ITEM_HERACRONITE:
	additem ITEM_HERACRONITE, 1
	return
	
ADD_ITEM_HOUNDOOMINITE:
	additem ITEM_HOUNDOOMINITE, 1
	return
	
ADD_ITEM_KANGASKHANITE:
	additem ITEM_KANGASKHANITE, 1
	return
	
ADD_ITEM_LATIASITE:
	additem ITEM_LATIASITE, 1
	return
	
ADD_ITEM_LATIOSITE:
	additem ITEM_LATIOSITE, 1
	return
	
ADD_ITEM_LOPUNNITE:
	additem ITEM_LOPUNNITE, 1
	return
	
ADD_ITEM_LUCARIONITE:
	additem ITEM_LUCARIONITE, 1
	return
	
ADD_ITEM_MANECTITE:
	additem ITEM_MANECTITE, 1
	return
	
ADD_ITEM_MAWILITE:
	additem ITEM_MAWILITE, 1
	return
	
ADD_ITEM_MEDICHAMITE:
	additem ITEM_MEDICHAMITE, 1
	return
	
ADD_ITEM_METAGROSSITE:
	additem ITEM_METAGROSSITE, 1
	return
	
ADD_ITEM_MEWTWONITE_X:
	additem ITEM_MEWTWONITE_X, 1
	return
	
ADD_ITEM_MEWTWONITE_Y:
	additem ITEM_MEWTWONITE_Y, 1
	return
	
ADD_ITEM_PIDGEOTITE:
	additem ITEM_PIDGEOTITE, 1
	return
	
ADD_ITEM_PINSIRITE:
	additem ITEM_PINSIRITE, 1
	return
	
ADD_ITEM_SABLENITE:
	additem ITEM_SABLENITE, 1
	return
	
ADD_ITEM_SALAMENCITE:
	additem ITEM_SALAMENCITE, 1
	return
	
ADD_ITEM_SCEPTILITE:
	additem ITEM_SCEPTILITE, 1
	return
	
ADD_ITEM_SCIZORITE:
	additem ITEM_SCIZORITE, 1
	return
	
ADD_ITEM_SHARPEDONITE:
	additem ITEM_SHARPEDONITE, 1
	return
	
ADD_ITEM_SLOWBRONITE:
	additem ITEM_SLOWBRONITE, 1
	return
	
ADD_ITEM_STEELIXITE:
	additem ITEM_STEELIXITE, 1
	return
	
ADD_ITEM_SWAMPERTITE:
	additem ITEM_SWAMPERTITE, 1
	return
	
ADD_ITEM_TYRANITARITE:
	additem ITEM_TYRANITARITE, 1
	return
	
ADD_ITEM_VENUSAURITE:
	additem ITEM_VENUSAURITE, 1
	return
	
ADD_ITEM_MILOTICITE:
	additem ITEM_MILOTICITE, 1
	return
	
ADD_ITEM_FLYGONITE:
	additem ITEM_FLYGONITE, 1
	return
	
ADD_ITEM_BUTTERFRENITE:
	additem ITEM_BUTTERFRENITE, 1
	return
	
ADD_ITEM_LAPRASITE:
	additem ITEM_LAPRASITE, 1
	return
	
ADD_ITEM_MACHAMPITE:
	additem ITEM_MACHAMPITE, 1
	return
	
ADD_ITEM_KINGLERITE:
	additem ITEM_KINGLERITE, 1
	return
	
ADD_ITEM_KINGDRANITE:
	additem ITEM_KINGDRANITE, 1
	return

ADD_ITEM_BUG_GEM:
	additem ITEM_BUG_GEM, 50
	return

ADD_ITEM_DARK_GEM:
	additem ITEM_DARK_GEM, 50
	return

ADD_ITEM_DRAGON_GEM:
	additem ITEM_DRAGON_GEM, 50
	return

ADD_ITEM_ELECTRIC_GEM:
	additem ITEM_ELECTRIC_GEM, 50
	return

ADD_ITEM_FAIRY_GEM:
	additem ITEM_FAIRY_GEM, 50
	return

ADD_ITEM_FIGHTING_GEM:
	additem ITEM_FIGHTING_GEM, 50
	return

ADD_ITEM_FIRE_GEM:
	additem ITEM_FIRE_GEM, 50
	return

ADD_ITEM_FLYING_GEM:
	additem ITEM_FLYING_GEM, 50
	return

ADD_ITEM_GHOST_GEM:
	additem ITEM_GHOST_GEM, 50
	return

ADD_ITEM_GRASS_GEM:
	additem ITEM_GRASS_GEM, 50
	return

ADD_ITEM_GROUND_GEM:
	additem ITEM_GROUND_GEM, 50
	return

ADD_ITEM_ICE_GEM:
	additem ITEM_ICE_GEM, 50
	return

ADD_ITEM_NORMAL_GEM:
	additem ITEM_NORMAL_GEM, 50
	return

ADD_ITEM_POISON_GEM:
	additem ITEM_POISON_GEM, 50
	return

ADD_ITEM_PSYCHIC_GEM:
	additem ITEM_PSYCHIC_GEM, 50
	return

ADD_ITEM_ROCK_GEM:
	additem ITEM_ROCK_GEM, 50
	return

ADD_ITEM_STEEL_GEM:
	additem ITEM_STEEL_GEM, 50
	return

ADD_ITEM_WATER_GEM:
	additem ITEM_WATER_GEM, 50
	return

ADDITEM_MASTER_BALL:
	additem ITEM_MASTER_BALL, 400
	return

ADDITEM_ABILITY_CAPSULE:
	additem ITEM_ABILITY_CAPSULE, 400
	return

ADDITEM_ABILITY_PATCH:
	additem ITEM_ABILITY_PATCH, 400
	return

ADDITEM_BIG_PEARL:
	additem ITEM_BIG_PEARL, 400
	return

ADDITEM_MAX_REPEL:
	additem ITEM_MAX_REPEL, 250
	return

ADDITEM_MIRACLE_SEED:
	additem ITEM_MIRACLE_SEED, 10
	return

ADDITEM_CHARCOAL:
	additem ITEM_CHARCOAL, 10
	return

ADDITEM_LEEK:
	additem ITEM_LEEK, 10
	return

ADDITEM_BIG_ROOT:
	additem ITEM_BIG_ROOT, 10
	return

ADDITEM_MENTAL_HERB:
	additem ITEM_MENTAL_HERB, 100
	return

ADDITEM_POWER_HERB:
	additem ITEM_POWER_HERB, 100
	return

ADDITEM_WHITE_HERB:
	additem ITEM_WHITE_HERB, 100
	return

ADDITEM_ELECTRIC_SEED:
	additem ITEM_ELECTRIC_SEED, 100
	return

ADDITEM_PSYCHIC_SEED:
	additem ITEM_PSYCHIC_SEED, 100
	return

ADDITEM_GRASSY_SEED:
	additem ITEM_GRASSY_SEED, 100
	return

ADDITEM_MISTY_SEED:
	additem ITEM_MISTY_SEED, 100
	return

ADDITEM_CHERI_BERRY:
	additem ITEM_CHERI_BERRY, 100
	return

ADDITEM_CHESTO_BERRY:
	additem ITEM_CHESTO_BERRY, 100
	return

ADDITEM_PECHA_BERRY:
	additem ITEM_PECHA_BERRY, 100
	return

ADDITEM_RAWST_BERRY:
	additem ITEM_RAWST_BERRY, 100
	return

ADDITEM_PERSIM_BERRY:
	additem ITEM_PERSIM_BERRY, 100
	return

ADDITEM_OCCA_BERRY:
	additem ITEM_OCCA_BERRY, 100
	return

ADDITEM_PASSHO_BERRY:
	additem ITEM_PASSHO_BERRY, 100
	return

ADDITEM_WACAN_BERRY:
	additem ITEM_WACAN_BERRY, 100
	return

ADDITEM_RINDO_BERRY:
	additem ITEM_RINDO_BERRY, 100
	return

ADDITEM_YACHE_BERRY:
	additem ITEM_YACHE_BERRY, 100
	return

ADDITEM_CHOPLE_BERRY:
	additem ITEM_CHOPLE_BERRY, 100
	return

ADDITEM_KEBIA_BERRY:
	additem ITEM_KEBIA_BERRY, 100
	return

ADDITEM_SHUCA_BERRY:
	additem ITEM_SHUCA_BERRY, 100
	return

ADDITEM_COBA_BERRY:
	additem ITEM_COBA_BERRY, 100
	return

ADDITEM_PAYAPA_BERRY:
	additem ITEM_PAYAPA_BERRY, 100
	return

ADDITEM_TANGA_BERRY:
	additem ITEM_TANGA_BERRY, 100
	return

ADDITEM_CHARTI_BERRY:
	additem ITEM_CHARTI_BERRY, 100
	return

ADDITEM_KASIB_BERRY:
	additem ITEM_KASIB_BERRY, 100
	return

ADDITEM_HABAN_BERRY:
	additem ITEM_HABAN_BERRY, 100
	return

ADDITEM_COLBUR_BERRY:
	additem ITEM_COLBUR_BERRY, 100
	return

ADDITEM_BABIRI_BERRY:
	additem ITEM_BABIRI_BERRY, 100
	return

ADDITEM_CHILAN_BERRY:
	additem ITEM_CHILAN_BERRY, 100
	return

ADDITEM_ROSELI_BERRY:
	additem ITEM_ROSELI_BERRY, 100
	return

ADDITEM_SITRUS_BERRY:
	additem ITEM_SITRUS_BERRY, 400
	return

ADDITEM_LEFTOVERS:
	additem ITEM_LEFTOVERS, 50
	return

ADDITEM_EVIOLITE:
	additem ITEM_EVIOLITE, 50
	return

ADDITEM_ROCKY_HELMET:
	additem ITEM_ROCKY_HELMET, 50
	return

ADDITEM_PROTECTIVE_PADS:
	additem ITEM_PROTECTIVE_PADS, 50
	return

ADDITEM_HEAVY_DUTY_BOOTS:
	additem ITEM_HEAVY_DUTY_BOOTS, 50
	return

ADDITEM_THROAT_SPRAY:
	additem ITEM_THROAT_SPRAY, 50
	return

ADDITEM_ADAMANT_ORB:
	additem ITEM_ADAMANT_ORB, 50
	return

ADDITEM_LUSTROUS_ORB:
	additem ITEM_LUSTROUS_ORB, 50
	return

ADDITEM_GRISEOUS_ORB:
	additem ITEM_GRISEOUS_ORB, 50
	return

ADDITEM_SOUL_DEW:
	additem ITEM_SOUL_DEW, 50
	return

ADDITEM_AIR_BALLOON:
	additem ITEM_AIR_BALLOON, 50
	return

ADDITEM_WEAKNESS_POLICY:
	additem ITEM_WEAKNESS_POLICY, 50
	return

ADDITEM_ASSAULT_VEST:
  additem ITEM_ASSAULT_VEST, 50
  return

ADDITEM_DAMP_ROCK:
  additem ITEM_DAMP_ROCK, 50
  return

ADDITEM_HEAT_ROCK:
  additem ITEM_HEAT_ROCK, 50
  return

ADDITEM_ICY_ROCK:
  additem ITEM_ICY_ROCK, 50
  return

ADDITEM_SMOOTH_ROCK:
  additem ITEM_SMOOTH_ROCK, 50
  return

ADDITEM_EXPERT_BELT:
  additem ITEM_EXPERT_BELT, 50
  return

ADDITEM_LIGHT_BALL:
  additem ITEM_LIGHT_BALL, 50
  return

ADDITEM_SCOPE_LENS:
  additem ITEM_SCOPE_LENS, 50
  return

ADDITEM_SHED_SHELL:
  additem ITEM_SHED_SHELL, 50
  return

ADDITEM_TERRAIN_EXTENDER:
  additem ITEM_TERRAIN_EXTENDER, 50
  return

ADDITEM_WIDE_LENS:
  additem ITEM_WIDE_LENS, 50
  return

ADDITEM_BLACK_SLUDGE:
  additem ITEM_BLACK_SLUDGE, 50
  return

ADDITEM_TOXIC_ORB:
  additem ITEM_TOXIC_ORB, 50
  return

ADDITEM_FLAME_ORB:
  additem ITEM_FLAME_ORB, 50
  return

ADDITEM_LIFE_ORB:
  additem ITEM_LIFE_ORB, 50
  return

ADDITEM_CHOICE_BAND:
  additem ITEM_CHOICE_BAND, 50
  return

ADDITEM_CHOICE_SPECS:
  additem ITEM_CHOICE_SPECS, 50
  return

ADDITEM_CHOICE_SCARF:
  additem ITEM_CHOICE_SCARF, 50
  return

ADDITEM_FOCUS_SASH:
  additem ITEM_FOCUS_SASH, 50
  return

ADDITEM_LIGHT_CLAY:
  additem ITEM_LIGHT_CLAY, 50
  return

ADDITEM_RED_ORB:
  additem ITEM_RED_ORB, 3
  return

ADDITEM_BLUE_ORB:
  additem ITEM_BLUE_ORB, 3
  return

ADDITEM_BRIGHT_POWDER:
	additem ITEM_BRIGHT_POWDER, 10
	return

ADDITEM_HARD_STONE:
	additem ITEM_HARD_STONE, 10
	return

ADDITEM_MYSTIC_WATER:
	additem ITEM_MYSTIC_WATER, 10
	return

ADDITEM_SILVER_POWDER:
	additem ITEM_SILVER_POWDER, 10
	return

ADDITEM_POISON_BARB:
	additem ITEM_POISON_BARB, 10
	return

ADDITEM_SOFT_SAND:
	additem ITEM_SOFT_SAND, 10
	return

ADDITEM_BLACK_BELT:
	additem ITEM_BLACK_BELT, 10
	return

ADDITEM_SILK_SCARF:
	additem ITEM_SILK_SCARF, 10
	return

ADDITEM_SHARP_BEAK:
	additem ITEM_SHARP_BEAK, 10
	return

ADDITEM_NEVER_MELT_ICE:
	additem ITEM_NEVER_MELT_ICE, 10
	return

ADDITEM_TWISTED_SPOON:
	additem ITEM_TWISTED_SPOON, 10
	return

ADDITEM_MAGNET:
	additem ITEM_MAGNET, 10
	return

ADDITEM_BLACK_GLASSES:
	additem ITEM_BLACK_GLASSES, 10
	return

ADDITEM_SPELL_TAG:
	additem ITEM_SPELL_TAG, 10
	return

ADDITEM_DRAGON_FANG:
	additem ITEM_DRAGON_FANG, 10
	return

ADDITEM_PP_MAX:
	additem ITEM_PP_MAX, 90
	return
