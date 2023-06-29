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
	msgbox Route132_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route132_EventScript_LegendaryNPC_2
	msgbox Route132_EventScript_LegendaryNPC_Text_4
Route132_EventScript_LegendaryNPC_1:
	release
	end

Route132_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route132_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_MAKAYLA
	goto_if 1, Route132_EventScript_LegendaryNPC_11
Route132_EventScript_LegendaryNPC_9:
	msgbox Route132_EventScript_LegendaryNPC_Text_3
	goto Route132_EventScript_LegendaryNPC_1

Route132_EventScript_LegendaryNPC_5:
	msgbox Route132_EventScript_LegendaryNPC_Text_1
	goto Route132_EventScript_LegendaryNPC_1

Route132_EventScript_LegendaryNPC_8:
	msgbox Route132_EventScript_LegendaryNPC_Text_2
	goto Route132_EventScript_LegendaryNPC_1

Route132_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_DARCY
	goto_if 1, Route132_EventScript_LegendaryNPC_15
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_JONATHAN
	goto_if 1, Route132_EventScript_LegendaryNPC_10
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_KIYO
	goto_if 1, Route132_EventScript_LegendaryNPC_19
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_PAXTON
	goto_if 1, Route132_EventScript_LegendaryNPC_14
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_DANA
	goto_if 1, Route132_EventScript_LegendaryNPC_22
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_RONALD
	goto_if 1, Route132_EventScript_LegendaryNPC_18
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_22:
	checktrainerflag TRAINER_GILBERT
	goto_if 1, Route132_EventScript_LegendaryNPC_8
	goto Route132_EventScript_LegendaryNPC_9


Route132_EventScript_LegendaryNPC_Text_0:
	.string "Sage: I stand as the gatekeeper to the\n"
	.string "resting place of the Ultra Beasts. Make\l"
	.string "no mistake: despite still wearing the\l"
	.string "battle scars inflicted upon them by\l"
	.string "King Calyrex and the Tapus, they\l"
	.string "possess an immense power, so tread\l"
	.string "with caution in their presence.\p"
	.string "Do you want to know how they got here?$"

Route132_EventScript_LegendaryNPC_Text_1:
	.string "The Ultra Beasts are creatures coming\n"
	.string "from worlds outside our galaxy. They\l"
	.string "came to Earth not by choice,\p"
	.string "but necessity: Necrozma's hunger\n"
	.string "didn't spare their planets, so they\l"
	.string "roamed until they found a hospitable\l"
	.string "place to live.\p"
	.string "Those who didn't immediately flee were\n"
	.string "either consumed or turned into\l"
	.string "soldiers for Necrozma's galactic army.\l"
	.string "Many of these\p"
	.string "Ultra Beasts perished in the war waged\n"
	.string "on them by the Tapus and King Calyrex,\l"
	.string "but it looks like some have survived by\l"
	.string "hiding in these small islands.\p"
	.string "These creatures suffered a lot in their\n"
	.string "life, I think they deserve a guardian\l"
	.string "to take care of them. Your heart seems\l"
	.string "in the right place. Once you'll be\l"
	.string "worthy of them, return to me\p"
	.string ".$"

Route132_EventScript_LegendaryNPC_Text_2:
	.string "Your heart is in the right place, and\n"
	.string "your strenght is the one of a great\l"
	.string "trainer. I added the location of some\l"
	.string "of the Ultra Beasts in your DexNav.\l"
	.string "There might be more in other routes,\l"
	.string "too: try to catch them all!$"

Route132_EventScript_LegendaryNPC_Text_3:
	.string "You have demonstrated great strenght\n"
	.string "so far. But I want to see it with my\l"
	.string "eyes! Defeat these last few trainers,\l"
	.string "and I'll show you the place where the\l"
	.string "Ultra Beasts reside.$"

Route132_EventScript_LegendaryNPC_Text_4:
	.string "Stay safe out there.$"
