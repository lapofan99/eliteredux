.set LOCALID_OLD_SEA_MAP, 2
.set LOCALID_BUG_CATCHER, 3
.set LOCALID_SHEDINJAITE, 4

AbandonedShip_HiddenFloorRooms_MapScripts:: @ 8238C49
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_HiddenFloorRooms_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AbandonedShip_HiddenFloorRooms_OnFrame
	.byte 0

AbandonedShip_HiddenFloorRooms_OnFrame: @ 8238C4F
	map_script_2 VAR_TEMP_1, 0, AbandonedShip_HiddenFloorRooms_EventScript_DoHiddenItemSparkle
	.2byte 0

@ After the below calculation, VAR_TEMP_4 is the room number of the door the player entered
@ Bottom row, left column   (Rm 1)
@ Bottom row, middle column (Rm 2)
@ Bottom row, right column	(Rm 3)
@ Upper row,  left column   (Rm 4)
@ Upper row,  middle column (Rm 5)
@ Upper row,  right column  (Rm 6)
AbandonedShip_HiddenFloorRooms_EventScript_DoHiddenItemSparkle:: @ 8238C59
	setvar VAR_TEMP_1, 1
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	setvar VAR_TEMP_4, 1
	compare VAR_TEMP_2, 21
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_InMiddleRoomColumn
	compare VAR_TEMP_2, 36
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_InRightRoomColumn
	compare VAR_TEMP_3, 2
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_InUpperRoomRow
	switch VAR_TEMP_4
	case 1, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm1
	case 2, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm2
	case 3, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm3
	case 4, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm4
	case 5, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm5
	case 6, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm6
	end

AbandonedShip_HiddenFloorRooms_EventScript_InMiddleRoomColumn:: @ 8238CD1
	addvar VAR_TEMP_4, 1
	return

AbandonedShip_HiddenFloorRooms_EventScript_InRightRoomColumn:: @ 8238CD7
	addvar VAR_TEMP_4, 2
	return

AbandonedShip_HiddenFloorRooms_EventScript_InUpperRoomRow:: @ 8238CDD
	addvar VAR_TEMP_4, 3
	return

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm1:: @ 8238CE3
	delay 20
	dofieldeffectsparkle 10, 10, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom4Key
	compare VAR_RESULT, FALSE
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm4KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm2:: @ 8238D0C
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm3:: @ 8238D0D
	specialvar VAR_RESULT, FoundAbandonedShipRoom1Key
	compare VAR_RESULT, TRUE
	goto_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm3NoSparkle
	delay 20
	compare VAR_RESULT, FALSE
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm1KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_Rm3NoSparkle:: @ 8238D32
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm4:: @ 8238D33
	delay 20
	dofieldeffectsparkle 8, 5, 0
	dofieldeffectsparkle 11, 3, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom6Key
	compare VAR_RESULT, FALSE
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm6KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm5:: @ 8238D6B
	delay 20
	dofieldeffectsparkle 16, 3, 0
	dofieldeffectsparkle 25, 2, 0
	dofieldeffectsparkle 24, 6, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom2Key
	compare VAR_RESULT, FALSE
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm2KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm6:: @ 8238DB2
	end

AbandonedShip_HiddenFloorRooms_EventScript_Rm1KeySparkle:: @ 8238DB3
	dofieldeffectsparkle 42, 10, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm2KeySparkle:: @ 8238DC3
	dofieldeffectsparkle 20, 5, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm4KeySparkle:: @ 8238DD3
	dofieldeffectsparkle 1, 12, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm6KeySparkle:: @ 8238DE3
	dofieldeffectsparkle 1, 2, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Trash:: @ 8238DF3
	lockall
	msgbox AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorRooms_EventScript_OldSeaMap::
	lockall
	giveitem ITEM_OLD_SEA_MAP
	removeobject LOCALID_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	releaseall
	end

AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash: @ 8238DFE
	.string "It's bright and shiny!\n"
	.string "But it's just trash…$"

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_4
AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_3:
	msgbox AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_3, MSGBOX_NPC
AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_1:
	release
	end

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_2:
	checktrainerflag TRAINER_SHEDINJITE_ABANDONED_SHIP
	goto_if 0, AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_7
	msgbox AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_4, MSGBOX_NPC
	goto AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_1

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_4:
	goto_if_unset FLAG_DEFEATED_ABANDONDED_SHIP_BUGCATCHER, AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_2
	goto AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_3

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_7:
	msgbox AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_10
	msgbox AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_3, MSGBOX_NPC
	goto AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_1

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_10:
	msgbox AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_1, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_SHEDINJITE_ABANDONED_SHIP, AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_2
	setflag FLAG_DEFEATED_ABANDONDED_SHIP_BUGCATCHER
	clearflag FLAG_HIDE_ABANDONED_SHIP_SHEDINJITE
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	addobject LOCALID_SHEDINJAITE
	setobjectxy LOCALID_SHEDINJAITE, 23, 10
	setobjectmovementtype LOCALID_SHEDINJAITE, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	fadescreenswapbuffers FADE_FROM_BLACK
	goto AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_1


AbandonedShip_HiddenFloorRooms_OnResume::
	checktrainerflag TRAINER_SHEDINJITE_ABANDONED_SHIP
	goto_if 1, AbandonedShip_HiddenFloorRooms_OnResume_4
AbandonedShip_HiddenFloorRooms_OnResume_3:
	setflag FLAG_HIDE_ABANDONED_SHIP_SHEDINJITE
	setobjectxy LOCALID_SHEDINJAITE, 0, 0
AbandonedShip_HiddenFloorRooms_OnResume_1:
	return

AbandonedShip_HiddenFloorRooms_OnResume_2:
	setobjectxy LOCALID_SHEDINJAITE, 23, 10
	goto AbandonedShip_HiddenFloorRooms_OnResume_1

AbandonedShip_HiddenFloorRooms_OnResume_4:
	goto_if_unset FLAG_HIDE_ABANDONED_SHIP_SHEDINJITE, AbandonedShip_HiddenFloorRooms_OnResume_2
	goto AbandonedShip_HiddenFloorRooms_OnResume_3


AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_0:
	.string "...Nincada?$"

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_1:
	.string "It's so scary now...$"

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_2:
	.string "Thank...you...$"

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_3:
	.string "...$"

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_4:
	.string "remove this code$"
