Seaspray_Cave_B1F_MapScripts::
	.byte 0


Seaspray_Cave_B1F_EventScript_Dewgong::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SEASPRAY_CAVE_DEWGONG, Seaspray_Cave_B1F_EventScript_Dewgong_Join
	goto_if_unset FLAG_BADGE07_GET, Seaspray_Cave_B1F_EventScript_Dewgong_PreTateLiza
	playmoncry SPECIES_DEWGONG, 2
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Seaspray_Cave_B1F_EventScript_Dewgong_2
	playmoncry SPECIES_DEWGONG, 2
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_3, MSGBOX_DEFAULT
Seaspray_Cave_B1F_EventScript_Dewgong_1:
	release
	end

Seaspray_Cave_B1F_EventScript_Dewgong_2:
	playmoncry SPECIES_DEWGONG, 2
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_1, MSGBOX_DEFAULT
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
	setwildbattlewithcustommoves SPECIES_DEWGONG, 0, ITEM_DEWGONGITE, MOVE_HORN_DRILL, MOVE_FREEZE_DRY, MOVE_AQUA_JET, MOVE_SLACK_OFF, 2, NATURE_BRAVE, 252, 252, 252, 252, 252, 252
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, Seaspray_Cave_B1F_EventScript_Dewgong_6
	case B_OUTCOME_WON, Seaspray_Cave_B1F_EventScript_Dewgong_6
	case B_OUTCOME_RAN, Seaspray_Cave_B1F_EventScript_Dewgong_7
	case B_OUTCOME_PLAYER_TELEPORTED, Seaspray_Cave_B1F_EventScript_Dewgong_7
	goto Seaspray_Cave_B1F_EventScript_Dewgong_1

Seaspray_Cave_B1F_EventScript_Dewgong_6:
	goto Seaspray_Cave_B1F_EventScript_Dewgong_Join
	goto Seaspray_Cave_B1F_EventScript_Dewgong_1

Seaspray_Cave_B1F_EventScript_Dewgong_7:
	setvar VAR_0x8004, SPECIES_DEWGONG
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname 0, VAR_0x8004
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_2, MSGBOX_DEFAULT
	goto Seaspray_Cave_B1F_EventScript_Dewgong_1


Seaspray_Cave_B1F_EventScript_Dewgong_PreTateLiza::
	message Seaspray_Cave_B1F_EventScript_Dewgong_PreTateLiza_Text_0
	release
	end


Seaspray_Cave_B1F_EventScript_Dewgong_Join::
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Seaspray_Cave_B1F_EventScript_Dewgong_Join_2
Seaspray_Cave_B1F_EventScript_Dewgong_Join_1:
	goto_if_unset FLAG_DEFEATED_SEASPRAY_CAVE_DEWGONG, Seaspray_Cave_B1F_EventScript_Dewgong_Join_5
Seaspray_Cave_B1F_EventScript_Dewgong_Join_4:
	release
	end

Seaspray_Cave_B1F_EventScript_Dewgong_Join_2:
	setflag FLAG_OBTAINED_SEASPRAY_CAVE_DEWGONG
	givecustommon SPECIES_DEWGONG, 50, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_BRAVE, 2, 252, 4, 0, 0, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_HORN_DRILL, MOVE_FREEZE_DRY, MOVE_AQUA_JET, MOVE_SLACK_OFF, FALSE
	playfanfare MUS_OBTAIN_ITEM
	message Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_1
	waitfanfare
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Seaspray_Cave_B1F_EventScript_Dewgong_Join_1

Seaspray_Cave_B1F_EventScript_Dewgong_Join_5:
	setflag FLAG_DEFEATED_SEASPRAY_CAVE_DEWGONG
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_DEWGONGITE, 1
	message Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_2
	waitfanfare
	goto Seaspray_Cave_B1F_EventScript_Dewgong_Join_4


Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate::
	lock
	faceplayer
	checktrainerflag TRAINER_KAYLEE
	goto_if 0, Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_2
	msgbox Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_4, MSGBOX_NPC
Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_1:
	release
	end

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_2:
	msgbox Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_5
	msgbox Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_3, MSGBOX_NPC
	goto Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_1

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_5:
	trainerbattle_no_intro TRAINER_KAYLEE, Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_1
	msgbox Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_2, MSGBOX_NPC
	giveitem ITEM_DEWGONGITE, 1
	goto Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_1


Seaspray_Cave_B1F_EventScript_Dewgong_Text_0:
	.string "The Dewgong considers you a worthy\n"
	.string "opponent. It seems it wishes to test\l"
	.string "you in battle.$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_1:
	.string "Dewgong: Gong!$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_2:
	.string "The {STR_VAR_1} ran away!$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_3:
	.string "Dewgong: Gong...$"

Seaspray_Cave_B1F_EventScript_Dewgong_PreTateLiza_Text_0:
	.string "The Dewgong finds you pitiful. Perhaps\n"
	.string "return after growing stronger?{PAUSE_UNTIL_PRESS}$"

Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_0:
	.string "Dewgong seems to want to join your\n"
	.string "team, will you let this Dewgong join\l"
	.string "you?$"

Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_1:
	.string "{PLAYER} received a Dewgong!$"

Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_2:
	.string "{PLAYER} received a Dewgongite!$"

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_0:
	.string "Do you want to battle?, I have a pretty\n"
	.string "good prize for you if you win.$"

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_1:
	.string "I got defeated...$"

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_2:
	.string "That was a great battle, here is your\n"
	.string "prize, you earned it!$"

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_3:
	.string "Oh well...$"

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_4:
	.string "It was a good battle but I already gave\n"
	.string "you your prize.$"
