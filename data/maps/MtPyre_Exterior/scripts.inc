MtPyre_Exterior_MapScripts:: @ 8231FCC
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	.byte 0

MtPyre_Exterior_OnTransition: @ 8231FD2
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit:: @ 8231FD8
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 12
	goto_if_lt MtPyre_Exterior_EventScript_EnterFromSummit
	return

MtPyre_Exterior_EventScript_EnterFromSummit:: @ 8231FE9
	setweather WEATHER_FOG_HORIZONTAL
	return

MtPyre_Exterior_EventScript_FogTrigger:: @ 8231FED
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

MtPyre_Exterior_EventScript_SunTrigger:: @ 8231FF2
	setweather WEATHER_SUNNY
	doweather
	end

MtPyre_Exterior_EventScript_Yda::
	trainerbattle_single TRAINER_YDA_MTPYRE, MtPyre_Exterior_EventScript_Yda_Text_0, MtPyre_Exterior_EventScript_Yda_Text_1
	msgbox MtPyre_Exterior_EventScript_Yda_Text_2, MSGBOX_NPC
	release
	end


MtPyre_Exterior_EventScript_Yda_Text_0:
	.string "Hey there, sorry, but you can't go any\n"
	.string "further.\p"
	.string "Why not?...\p"
	.string "...Don't you know who am I?\p"
	.string "I'm Ydarissep, the great oracle!\p"
	.string "I have the extraordinary ability to\n"
	.string "predict where and when a new Pokémon\l"
	.string "species will show up just by sniffing\l"
	.string "the air.\p"
	.string "Anyone trying to steal this discovery\n"
	.string "from me is in for a battle!$"

MtPyre_Exterior_EventScript_Yda_Text_1:
	.string "I bet you didn't see that coming, I lost!$"

MtPyre_Exterior_EventScript_Yda_Text_2:
	.string "Smell ya later.$"
