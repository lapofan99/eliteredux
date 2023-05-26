Route115_MapScripts:: @ 81F2920
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0

Route115_OnLoad: @ 81F2930
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute115West
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition: @ 81F2947
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST
	call_if_eq AbnormalWeather_StartGroudonWeather
	end

Route115_OnFrame: @ 81F2969
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route115_EventScript_Woman:: @ 81F2973
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro:: @ 81F297C
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign:: @ 81F2985
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy:: @ 81F298E
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Route115_EventScript_RegisterTimothy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route115_EventScript_RematchTimothy
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterTimothy:: @ 81F29BA
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_TimothyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIMOTHY_1
	release
	end

Route115_EventScript_RematchTimothy:: @ 81F29D9
	trainerbattle_rematch TRAINER_TIMOTHY_1, Route115_Text_TimothyRematchIntro, Route115_Text_TimothyRematchDefeat
	msgbox Route115_Text_TimothyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Koichi:: @ 81F29F0
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob:: @ 81F2A07
	trainerbattle_single TRAINER_NOB_1, Route115_Text_NobIntro, Route115_Text_NobDefeat, Route115_EventScript_RegisterNob
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route115_EventScript_RematchNob
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterNob:: @ 81F2A33
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_NobRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NOB_1
	release
	end

Route115_EventScript_RematchNob:: @ 81F2A52
	trainerbattle_rematch TRAINER_NOB_1, Route115_Text_NobRematchIntro, Route115_Text_NobRematchDefeat
	msgbox Route115_Text_NobPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Cyndy:: @ 81F2A69
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Route115_EventScript_RegisterCyndy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route115_EventScript_RematchCyndy
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterCyndy:: @ 81F2A95
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_CyndyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CYNDY_1
	release
	end

Route115_EventScript_RematchCyndy:: @ 81F2AB4
	trainerbattle_rematch TRAINER_CYNDY_1, Route115_Text_CyndyRematchIntro, Route115_Text_CyndyRematchDefeat
	msgbox Route115_Text_CyndyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Hector:: @ 81F2ACB
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra:: @ 81F2AE2
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden:: @ 81F2AF9
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix:: @ 81F2B10
	trainerbattle_single TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene:: @ 81F2B27
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Marlene:: @ 81F2B3E
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_NeverKnowWhenCavePokemonWillAppear: @ 81F2B55
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild Pokémon will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_RouteSignRustboro: @ 81F2BC9
	.string "Route 115\n"
	.string "{DOWN_ARROW} Rustboro City$"

Route115_Text_MeteorFallsSign: @ 81F2BE3
	.string "Meteor Falls\n"
	.string "FALLARBOR TOWN THROUGH HERE$"

Route115_EventScript_LegendaryNPC::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route115_EventScript_LegendaryNPC_2
	checktrainerflag TRAINER_TIMOTHY_1
	goto_if 1, Route115_EventScript_LegendaryNPC_8
Route115_EventScript_LegendaryNPC_6:
	msgbox Route115_EventScript_LegendaryNPC_Text_2
Route115_EventScript_LegendaryNPC_1:
	release
	end

Route115_EventScript_LegendaryNPC_2:
	msgbox Route115_EventScript_LegendaryNPC_Text_0
	goto Route115_EventScript_LegendaryNPC_1

Route115_EventScript_LegendaryNPC_5:
	msgbox Route115_EventScript_LegendaryNPC_Text_1
	goto Route115_EventScript_LegendaryNPC_1

Route115_EventScript_LegendaryNPC_7:
	checktrainerflag TRAINER_NOB_1
	goto_if 1, Route115_EventScript_LegendaryNPC_12
	goto Route115_EventScript_LegendaryNPC_6

Route115_EventScript_LegendaryNPC_8:
	checktrainerflag TRAINER_KOICHI
	goto_if 1, Route115_EventScript_LegendaryNPC_7
	goto Route115_EventScript_LegendaryNPC_6

Route115_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_HECTOR
	goto_if 1, Route115_EventScript_LegendaryNPC_16
	goto Route115_EventScript_LegendaryNPC_6

Route115_EventScript_LegendaryNPC_12:
	checktrainerflag TRAINER_CYNDY_1
	goto_if 1, Route115_EventScript_LegendaryNPC_11
	goto Route115_EventScript_LegendaryNPC_6

Route115_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_JAIDEN
	goto_if 1, Route115_EventScript_LegendaryNPC_20
	goto Route115_EventScript_LegendaryNPC_6

Route115_EventScript_LegendaryNPC_16:
	checktrainerflag TRAINER_KYRA
	goto_if 1, Route115_EventScript_LegendaryNPC_15
	goto Route115_EventScript_LegendaryNPC_6

Route115_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_HELENE
	goto_if 1, Route115_EventScript_LegendaryNPC_23
	goto Route115_EventScript_LegendaryNPC_6

Route115_EventScript_LegendaryNPC_20:
	checktrainerflag TRAINER_ALIX
	goto_if 1, Route115_EventScript_LegendaryNPC_19
	goto Route115_EventScript_LegendaryNPC_6

Route115_EventScript_LegendaryNPC_23:
	checktrainerflag TRAINER_MARLENE
	goto_if 1, Route115_EventScript_LegendaryNPC_5
	goto Route115_EventScript_LegendaryNPC_6


Route115_EventScript_Gen8_NPC::
	lock
	faceplayer
	checktrainerflag TRAINER_TIMOTHY_1
	goto_if 1, Route115_EventScript_Gen8_NPC_5
Route115_EventScript_Gen8_NPC_3:
	msgbox Route115_EventScript_Gen8_NPC_Text_2
Route115_EventScript_Gen8_NPC_1:
	release
	end

Route115_EventScript_Gen8_NPC_2:
	msgbox Route115_EventScript_Gen8_NPC_Text_0
	givemon SPECIES_DRACOVISH, 50, ITEM_NONE
	msgbox Route115_EventScript_Gen8_NPC_Text_1
	goto Route115_EventScript_Gen8_NPC_1

Route115_EventScript_Gen8_NPC_4:
	checktrainerflag TRAINER_NOB_1
	goto_if 1, Route115_EventScript_Gen8_NPC_9
	goto Route115_EventScript_Gen8_NPC_3

Route115_EventScript_Gen8_NPC_5:
	checktrainerflag TRAINER_KOICHI
	goto_if 1, Route115_EventScript_Gen8_NPC_4
	goto Route115_EventScript_Gen8_NPC_3

Route115_EventScript_Gen8_NPC_8:
	checktrainerflag TRAINER_HECTOR
	goto_if 1, Route115_EventScript_Gen8_NPC_13
	goto Route115_EventScript_Gen8_NPC_3

Route115_EventScript_Gen8_NPC_9:
	checktrainerflag TRAINER_CYNDY_1
	goto_if 1, Route115_EventScript_Gen8_NPC_8
	goto Route115_EventScript_Gen8_NPC_3

Route115_EventScript_Gen8_NPC_12:
	checktrainerflag TRAINER_JAIDEN
	goto_if 1, Route115_EventScript_Gen8_NPC_17
	goto Route115_EventScript_Gen8_NPC_3

Route115_EventScript_Gen8_NPC_13:
	checktrainerflag TRAINER_KYRA
	goto_if 1, Route115_EventScript_Gen8_NPC_12
	goto Route115_EventScript_Gen8_NPC_3

Route115_EventScript_Gen8_NPC_16:
	checktrainerflag TRAINER_HELENE
	goto_if 1, Route115_EventScript_Gen8_NPC_20
	goto Route115_EventScript_Gen8_NPC_3

Route115_EventScript_Gen8_NPC_17:
	checktrainerflag TRAINER_ALIX
	goto_if 1, Route115_EventScript_Gen8_NPC_16
	goto Route115_EventScript_Gen8_NPC_3

Route115_EventScript_Gen8_NPC_20:
	checktrainerflag TRAINER_MARLENE
	goto_if 1, Route115_EventScript_Gen8_NPC_2
	goto Route115_EventScript_Gen8_NPC_3


Route115_EventScript_LegendaryNPC_Text_0:
	.string "You can find legendary Pokémon on this\n"
	.string "route. But you have to beat all\l"
	.string "trainers in this place and become the\l"
	.string "Champion first. Talk to me again then.$"

Route115_EventScript_LegendaryNPC_Text_1:
	.string "You are now worthy to catch Azelf,\n"
	.string "Mesprit and Uxie here. Just use your\l"
	.string "DexNav, they will now appear.$"

Route115_EventScript_LegendaryNPC_Text_2:
	.string "You are not worthy yet to catch Azelf,\n"
	.string "Mesprit or Uxie. Beat all trainers here\l"
	.string "first.$"

Route115_EventScript_Gen8_NPC_Text_0:
	.string "IT IS FINALLY DONE. THANKS BITER\n"
	.string "FRIEND!$"

Route115_EventScript_Gen8_NPC_Text_1:
	.string "{PLAYER} got a {COLOR BLUE}Dracovish{COLOR DARK_GRAY} as a gift\n"
	.string "for defeating every trainer here!$"

Route115_EventScript_Gen8_NPC_Text_2:
	.string "I HAVE A MOUTH AND I MUST BITE. JOIN ME\n"
	.string "IN MY CARNIVOROUS JOURNEY THROUGH\l"
	.string "THESE LANDS.$"
