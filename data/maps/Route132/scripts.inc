Route132_MapScripts:: @ 81F74E9
	.byte 0

Route132_EventScript_Gilbert:: @ 81F74EA
	trainerbattle_single TRAINER_GILBERT, Route132_Text_GilbertIntro, Route132_Text_GilbertDefeat
	msgbox Route132_Text_GilbertPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Dana:: @ 81F7501
	trainerbattle_single TRAINER_DANA, Route132_Text_DanaIntro, Route132_Text_DanaDefeat
	msgbox Route132_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Ronald:: @ 81F7518
	trainerbattle_single TRAINER_RONALD, Route132_Text_RonaldIntro, Route132_Text_RonaldDefeat
	msgbox Route132_Text_RonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Kiyo:: @ 81F752F
	trainerbattle_single TRAINER_KIYO, Route132_Text_KiyoIntro, Route132_Text_KiyoDefeat
	msgbox Route132_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Paxton:: @ 81F7546
	trainerbattle_single TRAINER_PAXTON, Route132_Text_PaxtonIntro, Route132_Text_PaxtonDefeat
	msgbox Route132_Text_PaxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Darcy:: @ 81F755D
	trainerbattle_single TRAINER_DARCY, Route132_Text_DarcyIntro, Route132_Text_DarcyDefeat
	msgbox Route132_Text_DarcyPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Jonathan:: @ 81F7574
	trainerbattle_single TRAINER_JONATHAN, Route132_Text_JonathanIntro, Route132_Text_JonathanDefeat
	msgbox Route132_Text_JonathanPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_Makayla:: @ 81F758B
	trainerbattle_single TRAINER_MAKAYLA, Route132_Text_MakaylaIntro, Route132_Text_MakaylaDefeat
	msgbox Route132_Text_MakaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route132_EventScript_LegendaryNPC::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route132_EventScript_LegendaryNPC_2
	checktrainerflag TRAINER_MAKAYLA
	goto_if 1, Route132_EventScript_LegendaryNPC_8
Route132_EventScript_LegendaryNPC_6:
	msgbox Route132_EventScript_LegendaryNPC_Text_2
Route132_EventScript_LegendaryNPC_1:
	release
	end

Route132_EventScript_LegendaryNPC_2:
	msgbox Route132_EventScript_LegendaryNPC_Text_0
	goto Route132_EventScript_LegendaryNPC_1

Route132_EventScript_LegendaryNPC_5:
	msgbox Route132_EventScript_LegendaryNPC_Text_1
	goto Route132_EventScript_LegendaryNPC_1

Route132_EventScript_LegendaryNPC_7:
	checktrainerflag TRAINER_DARCY
	goto_if 1, Route132_EventScript_LegendaryNPC_12
	goto Route132_EventScript_LegendaryNPC_6

Route132_EventScript_LegendaryNPC_8:
	checktrainerflag TRAINER_JONATHAN
	goto_if 1, Route132_EventScript_LegendaryNPC_7
	goto Route132_EventScript_LegendaryNPC_6

Route132_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_KIYO
	goto_if 1, Route132_EventScript_LegendaryNPC_16
	goto Route132_EventScript_LegendaryNPC_6

Route132_EventScript_LegendaryNPC_12:
	checktrainerflag TRAINER_PAXTON
	goto_if 1, Route132_EventScript_LegendaryNPC_11
	goto Route132_EventScript_LegendaryNPC_6

Route132_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_DANA
	goto_if 1, Route132_EventScript_LegendaryNPC_19
	goto Route132_EventScript_LegendaryNPC_6

Route132_EventScript_LegendaryNPC_16:
	checktrainerflag TRAINER_RONALD
	goto_if 1, Route132_EventScript_LegendaryNPC_15
	goto Route132_EventScript_LegendaryNPC_6

Route132_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_GILBERT
	goto_if 1, Route132_EventScript_LegendaryNPC_5
	goto Route132_EventScript_LegendaryNPC_6


Route132_EventScript_LegendaryNPC_Text_0:
	.string "You can find legendary Pokémon on this\n"
	.string "route. But you have to beat all\l"
	.string "trainers in this place and become the\l"
	.string "Champion first. Talk to me again then.$"

Route132_EventScript_LegendaryNPC_Text_1:
	.string "You are now worthy to catch Buzzwole,\n"
	.string "Pheromosa and Kartana here. Just use\l"
	.string "your DexNav, they will now appear.$"

Route132_EventScript_LegendaryNPC_Text_2:
	.string "You are not worthy yet to catch\n"
	.string "Buzzwole, Pheromosa or Kartana. Beat\l"
	.string "all trainers here first.$"
