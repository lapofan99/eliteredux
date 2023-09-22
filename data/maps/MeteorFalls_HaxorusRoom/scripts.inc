MeteorFalls_HaxorusRoom_MapScripts::
	.byte 0


MeteorFalls_HaxorusRoom_EventScript_Haxorus::
	lock
	faceplayer
	playmoncry SPECIES_HAXORUS, 2
	msgbox MeteorFalls_HaxorusRoom_EventScript_Haxorus_Text_0, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	setflag FLAG_TOTEM_BATTLE
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 2
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 2
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 2
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_HAXORUS
	setflag FLAG_SHINY_CREATION
	setwildbattlewithcustommoves SPECIES_HAXORUS, 75, ITEM_HAXORUSITE, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_DRAGON_DANCE, 0, NATURE_JOLLY
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, MeteorFalls_HaxorusRoom_EventScript_Haxorus_3
	case B_OUTCOME_WON, MeteorFalls_HaxorusRoom_EventScript_Haxorus_3
	case B_OUTCOME_RAN, MeteorFalls_HaxorusRoom_EventScript_Haxorus_4
	case B_OUTCOME_PLAYER_TELEPORTED, MeteorFalls_HaxorusRoom_EventScript_Haxorus_4
MeteorFalls_HaxorusRoom_EventScript_Haxorus_1:
	release
	end

MeteorFalls_HaxorusRoom_EventScript_Haxorus_3:
	setflag FLAG_DEFEATED_METEOR_FALLS_HAXORUS
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	goto MeteorFalls_HaxorusRoom_EventScript_Haxorus_1

MeteorFalls_HaxorusRoom_EventScript_Haxorus_4:
	setvar VAR_0x8004, SPECIES_HAXORUS
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname 0, VAR_0x8004
	msgbox MeteorFalls_HaxorusRoom_EventScript_Haxorus_Text_1, MSGBOX_DEFAULT
	goto MeteorFalls_HaxorusRoom_EventScript_Haxorus_1


MeteorFalls_HaxorusRoom_EventScript_Haxorus_Text_0:
	.string "Haxorus: Hax!$"

MeteorFalls_HaxorusRoom_EventScript_Haxorus_Text_1:
	.string "The {STR_VAR_1} ran away!$"
