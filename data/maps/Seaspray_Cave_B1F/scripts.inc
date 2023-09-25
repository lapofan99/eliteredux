Seaspray_Cave_B1F_MapScripts::
	.byte 0


Seaspray_Cave_B1F_EventScript_Dewgong::
	lock
	faceplayer
	playmoncry SPECIES_DEWGONG, 2
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_0, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	setflag FLAG_TOTEM_BATTLE
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 2
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 2
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 0
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_DEWGONG
	setwildbattlewithcustommoves SPECIES_DEWGONG, 75, ITEM_DEWGONGITE, MOVE_HORN_DRILL, MOVE_FREEZE_DRY, MOVE_AQUA_JET, MOVE_SLACK_OFF, 0, NATURE_ADAMANT, 252, 252, 252, 252, 252, 252
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, Seaspray_Cave_B1F_EventScript_Dewgong_3
	case B_OUTCOME_WON, Seaspray_Cave_B1F_EventScript_Dewgong_3
	case B_OUTCOME_RAN, Seaspray_Cave_B1F_EventScript_Dewgong_4
	case B_OUTCOME_PLAYER_TELEPORTED, Seaspray_Cave_B1F_EventScript_Dewgong_4
Seaspray_Cave_B1F_EventScript_Dewgong_1:
	release
	end

Seaspray_Cave_B1F_EventScript_Dewgong_3:
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Seaspray_Cave_B1F_EventScript_Dewgong_6
	playmoncry SPECIES_DEWGONG, 2
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_3, MSGBOX_DEFAULT
Seaspray_Cave_B1F_EventScript_Dewgong_5:
	setflag FLAG_DEFEATED_SEASPRAY_CAVE_DEWGONG
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_DEWGONGITE, 1
	message Seaspray_Cave_B1F_EventScript_Dewgong_Text_4
	waitfanfare
	goto Seaspray_Cave_B1F_EventScript_Dewgong_1

Seaspray_Cave_B1F_EventScript_Dewgong_4:
	setvar VAR_0x8004, SPECIES_DEWGONG
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname 0, VAR_0x8004
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_5, MSGBOX_DEFAULT
	goto Seaspray_Cave_B1F_EventScript_Dewgong_1

Seaspray_Cave_B1F_EventScript_Dewgong_6:
	givecustommon SPECIES_DEWGONG, 75, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_MODEST, 0, 252, 4, 0, 0, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_HORN_DRILL, MOVE_FREEZE_DRY, MOVE_AQUA_JET, MOVE_SLACK_OFF, FALSE
	playfanfare MUS_OBTAIN_ITEM
	message Seaspray_Cave_B1F_EventScript_Dewgong_Text_2
	waitfanfare
	goto Seaspray_Cave_B1F_EventScript_Dewgong_5


Seaspray_Cave_B1F_EventScript_Dewgong_Text_0:
	.string "Dewgong: Gong!$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_1:
	.string "Dewgong seems to want to join your\n"
	.string "team, will you let this Dewgong join\l"
	.string "you?$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_2:
	.string "{PLAYER} received a Dewgong!$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_3:
	.string "Dewgong ran away!$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_4:
	.string "{PLAYER} received a Dewgongite!$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_5:
	.string "The {STR_VAR_1} ran away!$"
