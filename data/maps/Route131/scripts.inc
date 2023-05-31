Route131_MapScripts:: @ 81F7404
	map_script MAP_SCRIPT_ON_TRANSITION, Route131_OnTransition
	.byte 0

Route131_OnTransition: @ 81F740A
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	call_if_ge Route131_EventScript_CheckSetAbnormalWeather
	call Route131_EventScript_SetLayout
	end

Route131_EventScript_SetLayout:: @ 81F741B
	setmaplayoutindex LAYOUT_ROUTE131_SKY_PILLAR
	return

Route131_EventScript_CheckSetAbnormalWeather:: @ 81F741F
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

Route131_EventScript_Richard:: @ 81F7429
	trainerbattle_single TRAINER_RICHARD, Route131_Text_RichardIntro, Route131_Text_RichardDefeat
	msgbox Route131_Text_RichardPostBattle, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_Herman:: @ 81F7440
	trainerbattle_single TRAINER_HERMAN, Route131_Text_HermanIntro, Route131_Text_HermanDefeat
	msgbox Route131_Text_HermanPostBattle, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_Susie:: @ 81F7457
	trainerbattle_single TRAINER_SUSIE, Route131_Text_SusieIntro, Route131_Text_SusieDefeat
	msgbox Route131_Text_SusiePostBattle, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_Kara:: @ 81F746E
	trainerbattle_single TRAINER_KARA, Route131_Text_KaraIntro, Route131_Text_KaraDefeat
	msgbox Route131_Text_KaraPostBattle, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_Reli:: @ 81F7485
	trainerbattle_double TRAINER_RELI_AND_IAN, Route131_Text_ReliIntro, Route131_Text_ReliDefeat, Route131_Text_ReliNotEnoughMons
	msgbox Route131_Text_ReliPostBattle, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_Ian:: @ 81F74A0
	trainerbattle_double TRAINER_RELI_AND_IAN, Route131_Text_IanIntro, Route131_Text_IanDefeat, Route131_Text_IanNotEnoughMons
	msgbox Route131_Text_IanPostBattle, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_Talia:: @ 81F74BB
	trainerbattle_single TRAINER_TALIA, Route131_Text_TaliaIntro, Route131_Text_TaliaDefeat
	msgbox Route131_Text_TaliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_Kevin:: @ 81F74D2
	trainerbattle_single TRAINER_KEVIN, Route131_Text_KevinIntro, Route131_Text_KevinDefeat
	msgbox Route131_Text_KevinPostBattle, MSGBOX_AUTOCLOSE
	end

Route131_EventScript_LegendaryNPC::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route131_EventScript_LegendaryNPC_2
	checktrainerflag TRAINER_RICHARD
	goto_if 1, Route131_EventScript_LegendaryNPC_8
Route131_EventScript_LegendaryNPC_6:
	msgbox Route131_EventScript_LegendaryNPC_Text_2
Route131_EventScript_LegendaryNPC_1:
	release
	end

Route131_EventScript_LegendaryNPC_2:
	msgbox Route131_EventScript_LegendaryNPC_Text_0
	goto Route131_EventScript_LegendaryNPC_1

Route131_EventScript_LegendaryNPC_5:
	msgbox Route131_EventScript_LegendaryNPC_Text_1
	goto Route131_EventScript_LegendaryNPC_1

Route131_EventScript_LegendaryNPC_7:
	checktrainerflag TRAINER_SUSIE
	goto_if 1, Route131_EventScript_LegendaryNPC_12
	goto Route131_EventScript_LegendaryNPC_6

Route131_EventScript_LegendaryNPC_8:
	checktrainerflag TRAINER_HERMAN
	goto_if 1, Route131_EventScript_LegendaryNPC_7
	goto Route131_EventScript_LegendaryNPC_6

Route131_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_RELI_AND_IAN
	goto_if 1, Route131_EventScript_LegendaryNPC_16
	goto Route131_EventScript_LegendaryNPC_6

Route131_EventScript_LegendaryNPC_12:
	checktrainerflag TRAINER_KARA
	goto_if 1, Route131_EventScript_LegendaryNPC_11
	goto Route131_EventScript_LegendaryNPC_6

Route131_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_KEVIN
	goto_if 1, Route131_EventScript_LegendaryNPC_5
	goto Route131_EventScript_LegendaryNPC_6

Route131_EventScript_LegendaryNPC_16:
	checktrainerflag TRAINER_TALIA
	goto_if 1, Route131_EventScript_LegendaryNPC_15
	goto Route131_EventScript_LegendaryNPC_6


Route131_EventScript_LegendaryNPC_Text_0:
	.string "The influence of the Sky Pillar has\n"
	.string "attracted a peculiar visitor from\l"
	.string "outer space:\p"
	.string "Necrozma, an alien creature whose\n"
	.string "hunger for light consumes everything\l"
	.string "that crosses their path.\p"
	.string "Hopping from planet to planet like a\n"
	.string "flock of hungry locusts, they only\l"
	.string "leave a trail of darkness and\l"
	.string "desolation behind.\p"
	.string "Their insatiable void within knows no\n"
	.string "bounds, so one must a stop at this!\p"
	.string "Me and my colleagues managed to\n"
	.string "temporarly stall him out here, but you\l"
	.string "must help us.\p"
	.string "You're already destined to become\n"
	.string "champion. Once you do, come back here\l"
	.string "and help us stop this disgrace from\l"
	.string "happening!$"

Route131_EventScript_LegendaryNPC_Text_1:
	.string "Great job with those trainers! Finally,\n"
	.string "we're ready to proceed: I marked\l"
	.string "Necrozma's location on your DexNav.\p"
	.string "The stakes couldn't be higher, but I'm\n"
	.string "sure you'll succeed in bringing this\l"
	.string "monster down!$"

Route131_EventScript_LegendaryNPC_Text_2:
	.string "Finally you came back! Before\n"
	.string "proceeding, make sure no one's getting\l"
	.string "caught in the crossfire: defeat all\l"
	.string "trainers in this route first!$"
