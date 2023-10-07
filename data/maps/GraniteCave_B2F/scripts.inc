GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_B2F_SetFlashRadius:
	end

GraniteCave_B2F_EventScript_HitmonStone::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, GraniteCave_B2F_EventScript_HitmonStone_2
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_6, MSGBOX_NPC
GraniteCave_B2F_EventScript_HitmonStone_1:
	release
	end

GraniteCave_B2F_EventScript_HitmonStone_2:
	goto_if_unset FLAG_OBTAINED_HITMON_MEGA_STONE, GraniteCave_B2F_EventScript_HitmonStone_5
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_7, MSGBOX_NPC
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_5:
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq GraniteCave_B2F_EventScript_HitmonStone_8
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_6, MSGBOX_NPC
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_8:
	checkpartyfortypeornumber TYPE_FIGHTING, 1
	compare VAR_RESULT, 1
	goto_if_eq GraniteCave_B2F_EventScript_HitmonStone_11
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_5, MSGBOX_NPC
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_11:
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_1, MSGBOX_NPC
	random 3
	switch VAR_RESULT
	case 0, GraniteCave_B2F_EventScript_HitmonStone_16
	case 1, GraniteCave_B2F_EventScript_HitmonStone_17
	case 2, GraniteCave_B2F_EventScript_HitmonStone_18
GraniteCave_B2F_EventScript_HitmonStone_14:
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_3, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_HITMONCHANITE, 1
	giveitem ITEM_HITMONLEENITE, 1
	giveitem ITEM_HITMONTOPITE, 1
	setflag FLAG_OBTAINED_HITMON_MEGA_STONE
	waitfanfare
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_4, MSGBOX_NPC
	waitmessage
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_16:
	trainerbattle_no_intro TRAINER_HITMONSTONE_BLACKBELT_1, GraniteCave_B2F_EventScript_HitmonStone_Text_2
	goto GraniteCave_B2F_EventScript_HitmonStone_14

GraniteCave_B2F_EventScript_HitmonStone_17:
	trainerbattle_no_intro TRAINER_HITMONSTONE_BLACKBELT_2, GraniteCave_B2F_EventScript_HitmonStone_Text_2
	goto GraniteCave_B2F_EventScript_HitmonStone_14

GraniteCave_B2F_EventScript_HitmonStone_18:
	trainerbattle_no_intro TRAINER_HITMONSTONE_BLACKBELT_3, GraniteCave_B2F_EventScript_HitmonStone_Text_2
	goto GraniteCave_B2F_EventScript_HitmonStone_14


GraniteCave_B2F_EventScript_HitmonStone_Text_0:
	.string "Do you seek strength, young one? Prove\n"
	.string "yourself to me, and I will grant you\l"
	.string "strength unrivaled.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_1:
	.string "Then let us begin$"

GraniteCave_B2F_EventScript_HitmonStone_Text_2:
	.string "Thank...you...$"

GraniteCave_B2F_EventScript_HitmonStone_Text_3:
	.string "Congratulations, here is your reward$"

GraniteCave_B2F_EventScript_HitmonStone_Text_4:
	.string "This item is blablabla...$"

GraniteCave_B2F_EventScript_HitmonStone_Text_5:
	.string "You don't have the correct Pokémon$"

GraniteCave_B2F_EventScript_HitmonStone_Text_6:
	.string "...$"

GraniteCave_B2F_EventScript_HitmonStone_Text_7:
	.string "TEXT$"
