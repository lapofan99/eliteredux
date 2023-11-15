Route111_RuinsExterior_MapScripts::
	.byte 0

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_2
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_6, MSGBOX_NPC
Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_1:
	release
	end

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_2:
	checktrainerflag TRAINER_KROOKODILENITE_ROUTE111_RUINS_EXTERIOR
	goto_if 0, Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_5
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_5, MSGBOX_NPC
	goto Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_1

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_5:
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_8
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_4, MSGBOX_NPC
	goto Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_1

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_8:
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_1, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_KROOKODILENITE_ROUTE111_RUINS_EXTERIOR, Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_2
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_3, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_KROOKODILENITE, 1
	waitmessage
	goto Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_1


Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_0:
	.string "Hmm, searching for something\n"
	.string "interesting, are we? I've already\l"
	.string "claimed this site, but I see spirit in\l"
	.string "you. Prove me right, and I'll reward you\l"
	.string "with something nice I've dug up.$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_1:
	.string "Let's get to it then!$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_2:
	.string "Ha, these old eyes never lie to me.$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_3:
	.string "I knew I saw something great in you!\n"
	.string "Take this, and get out of here before\l"
	.string "you get footprints on my dig!$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_4:
	.string "Such a shame, come back when you're\n"
	.string "ready to get your hands dirty!$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_5:
	.string "Your persistence is admirable, young\n"
	.string "one, yet fruitless. My treasures have\l"
	.string "been exhausted. Find your fortune\l"
	.string "elsewhere, and leave this hollow\l"
	.string "sanctum to rest undisturbed.$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_6:
	.string "What's this? A young explorer scurrying\n"
	.string "onto my site? Run along chap, maybe I'll\l"
	.string "entertain you when you're stronger.$"
