Route105_MapScripts:: @ 81EE1DB
	map_script MAP_SCRIPT_ON_LOAD, Route105_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route105_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route105_OnFrame
	.byte 0

Route105_OnLoad: @ 81EE1EB
	call_if_unset FLAG_REGI_DOORS_OPENED, Route105_CloseRegiEntrance
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute105North
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute105South
	end

Route105_CloseRegiEntrance:: @ 81EE20B
	setmetatile 9, 19, METATILE_General_RockWall_RockBase, 1
	setmetatile 9, 20, METATILE_General_RockWall_SandBase, 1
	return

Route105_OnTransition: @ 81EE21E
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH
	call_if_eq AbnormalWeather_StartKyogreWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH
	call_if_eq AbnormalWeather_StartKyogreWeather
	end

Route105_OnFrame: @ 81EE240
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route105_EventScript_Foster:: @ 81EE24A
	trainerbattle_single TRAINER_FOSTER, Route105_Text_FosterIntro, Route105_Text_FosterDefeated
	msgbox Route105_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Luis:: @ 81EE261
	trainerbattle_single TRAINER_LUIS, Route105_Text_LuisIntro, Route105_Text_LuisDefeated
	msgbox Route105_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Dominik:: @ 81EE278
	trainerbattle_single TRAINER_DOMINIK, Route105_Text_DominikIntro, Route105_Text_DominikDefeated
	msgbox Route105_Text_DominikPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Beverly:: @ 81EE28F
	trainerbattle_single TRAINER_BEVERLY, Route105_Text_BeverlyIntro, Route105_Text_BeverlyDefeated
	msgbox Route105_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Imani:: @ 81EE2A6
	trainerbattle_single TRAINER_IMANI, Route105_Text_ImaniIntro, Route105_Text_ImaniDefeated
	msgbox Route105_Text_ImaniPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Josue:: @ 81EE2BD
	trainerbattle_single TRAINER_JOSUE, Route105_Text_JosueIntro, Route105_Text_JosueDefeated
	msgbox Route105_Text_JosuePostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Andres:: @ 81EE2D4
	trainerbattle_single TRAINER_ANDRES_1, Route105_Text_AndresIntro, Route105_Text_AndresDefeated, Route105_EventScript_AndresRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route105_EventScript_AndresRematch
	msgbox Route105_Text_AndresPostBattle, MSGBOX_DEFAULT
	release
	end

Route105_EventScript_AndresRegisterMatchCallAfterBattle:: @ 81EE300
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route105_Text_AndresRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANDRES_1
	release
	end

Route105_EventScript_AndresRematch:: @ 81EE31F
	trainerbattle_rematch TRAINER_ANDRES_1, Route105_Text_AndresRematchIntro, Route105_Text_AndresRematchDefeated
	msgbox Route105_Text_AndresRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_Text_DadPokenavCall: @ 81EE336
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Dad: Oh, {PLAYER}?\p"
	.string "… … … … … …\n"
	.string "Where are you now?\l"
	.string "It sounds windy wherever you are.\p"
	.string "I just heard from Devon's Mr. Stone\n"
	.string "about your PokéNav, so I decided\l"
	.string "to give you a call.\p"
	.string "It sounds like you're doing fine,\n"
	.string "so that's fine with me.\p"
	.string "You take care now.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Route104_Text_RegisteredDadInPokenav: @ 81EE463
	.string "Registered Dad Norman\n"
	.string "in the PokéNav.$"

Route105_EventScript_FeraligatriteX_Battle::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, Route105_EventScript_FeraligatriteX_Battle_2
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_5, MSGBOX_NPC
Route105_EventScript_FeraligatriteX_Battle_1:
	release
	end

Route105_EventScript_FeraligatriteX_Battle_2:
	checktrainerflag TRAINER_MEGANIUMITE_VERDANTURF_MEADOW
	goto_if 0, Route105_EventScript_FeraligatriteX_Battle_5
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_4, MSGBOX_NPC
	goto Route105_EventScript_FeraligatriteX_Battle_1

Route105_EventScript_FeraligatriteX_Battle_5:
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route105_EventScript_FeraligatriteX_Battle_8
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_3, MSGBOX_NPC
	goto Route105_EventScript_FeraligatriteX_Battle_1

Route105_EventScript_FeraligatriteX_Battle_8:
	trainerbattle_no_intro TRAINER_MEGANIUMITE_VERDANTURF_MEADOW, Route105_EventScript_FeraligatriteX_Battle_Text_1
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_2, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_MEGANIUMITE, 1
	waitmessage
	goto Route105_EventScript_FeraligatriteX_Battle_1


Route105_EventScript_FeraligatriteX_Battle_Text_0:
	.string "Ah, I see you've triumphed over Norman,\n"
	.string "quite the impressive feat at your age.\l"
	.string "How about we put your skills to the\l"
	.string "test in a friendly match? If you win,\l"
	.string "I'll reward you with this Meganiumite!$"

Route105_EventScript_FeraligatriteX_Battle_Text_1:
	.string "I got defeated...$"

Route105_EventScript_FeraligatriteX_Battle_Text_2:
	.string "You truly are strong. I hope to see your\n"
	.string "growth even further into the future.\l"
	.string "But for now, take this gift from me, and\l"
	.string "use it well.$"

Route105_EventScript_FeraligatriteX_Battle_Text_3:
	.string "That's a bit disappointing. I hope you\n"
	.string "change your mind.$"

Route105_EventScript_FeraligatriteX_Battle_Text_4:
	.string "I trust you'll find delight in the token\n"
	.string "I've bestowed upon you!$"

Route105_EventScript_FeraligatriteX_Battle_Text_5:
	.string "Greetings! Have you come to savor the\n"
	.string "fragrance of these blossoms? You\l"
	.string "strike me as someone with different\l"
	.string "interests. A Pokémon Trainer,\l"
	.string "perchance? Well, here's a proposition\l"
	.string "for you: how about dropping by after\l"
	.string "exploring Petalburg? I may just have a\l"
	.string "little something that piques your\l"
	.string "curiosity.$"
