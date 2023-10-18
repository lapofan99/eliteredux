EverGrandeCity_Hall4_MapScripts:: @ 82295A8
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall4_OnWarp
	.byte 0

EverGrandeCity_Hall4_OnWarp: @ 82295AE
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall4_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall4_EventScript_TurnPlayerNorth:: @ 82295B8
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_Hall4_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_E4, EverGrandeCity_Hall4_EventScript_Calvin_Text_0, EverGrandeCity_Hall4_EventScript_Calvin_Text_1, FALSE
	msgbox EverGrandeCity_Hall4_EventScript_Calvin_Text_2, MSGBOX_NPC
	settrainerflag TRAINER_CALVIN_E4
	release
	end


EverGrandeCity_Hall4_EventScript_Calvin_Text_0:
	.string "Hehe! I slipped into the Pokémon League\n"
	.string "'cause they said I wasn't ready. Look\l"
	.string "at me now, I'm Calvin, and I'm a wall\l"
	.string "before the Champion! Ready for a real\l"
	.string "challenge?$"

EverGrandeCity_Hall4_EventScript_Calvin_Text_1:
	.string "Whoa, you're tough! Promise you won't\n"
	.string "rat me out?$"

EverGrandeCity_Hall4_EventScript_Calvin_Text_2:
	.string "Hey, give the Champion a run for his\n"
	.string "money, will ya? Good luck!$"
