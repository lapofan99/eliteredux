VerdanturfMeadow_MapScripts::
	.byte 0

VerdanturfMeadow_EventScript_GiftMeganiumite::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_AUDINO, VerdanturfMeadow_EventScript_TakeCareOfAudino
	msgbox VerdanturfMeadow_Text_PleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_AUDINO
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
	copyvar VAR_0x800A, VAR_RESULT
	givemon SPECIES_AUDINO, VAR_0x800A, ITEM_AUDINITE
	compare VAR_RESULT, 0
	goto_if_eq VerdanturfMeadow_EventScript_ReceiveAudinoParty
	compare VAR_RESULT, 1
	goto_if_eq VerdanturfMeadow_EventScript_ReceiveAudinoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

VerdanturfMeadow_EventScript_ReceiveAudinoParty::
	call VerdanturfMeadow_EventScript_ReceivedAudinoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfMeadow_EventScript_TakeCareOfAudino
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VerdanturfMeadow_EventScript_TakeCareOfAudino
	end

VerdanturfMeadow_EventScript_ReceiveAudinoPC::
	call VerdanturfMeadow_EventScript_ReceivedAudinoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfMeadow_EventScript_SendAudinoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto VerdanturfMeadow_EventScript_SendAudinoToPC
	end

VerdanturfMeadow_EventScript_SendAudinoToPC::
	call Common_EventScript_TransferredToPC
	goto VerdanturfMeadow_EventScript_TakeCareOfAudino
	end

VerdanturfMeadow_EventScript_ReceivedAudinoFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message VerdanturfMeadow_Text_PlayerReceivedAudino
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_AUDINO
	return

VerdanturfMeadow_EventScript_TakeCareOfAudino::
	msgbox VerdanturfMeadow_Text_TakeCareOfAudino, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_AUDINO
	release
	end

VerdanturfMeadow_Text_PleaseTakePokemon:
	.string "Do you know the Pokémon Audino?\p"
	.string "I'm giving them away to promote\n"
	.string "Audino welfare!\p"
	.string "Some Trainers use Audino like punching\n"
	.string "bags for their Pokémon, just to make\l"
	.string "their team grow quickly.\p"
	.string "This is not OK!\p"
	.string "Please take this Audino to keep it safe\n"
	.string "from EXP-mad Trainers!$"

VerdanturfMeadow_Text_PlayerReceivedAudino:
	.string "{PLAYER} received Audino!$"

VerdanturfMeadow_Text_TakeCareOfAudino:
	.string "Take good care of Audino!$"

VerdanturfMeadow_EventScript_Meganiumite_Battle::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, VerdanturfMeadow_EventScript_Meganiumite_Battle_2
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_6, MSGBOX_NPC
VerdanturfMeadow_EventScript_Meganiumite_Battle_1:
	release
	end

VerdanturfMeadow_EventScript_Meganiumite_Battle_2:
	checktrainerflag TRAINER_MEGANIUMITE_VERDANTURF_MEADOW
	goto_if 0, VerdanturfMeadow_EventScript_Meganiumite_Battle_5
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_5, MSGBOX_NPC
	goto VerdanturfMeadow_EventScript_Meganiumite_Battle_1

VerdanturfMeadow_EventScript_Meganiumite_Battle_5:
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq VerdanturfMeadow_EventScript_Meganiumite_Battle_8
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_4, MSGBOX_NPC
	goto VerdanturfMeadow_EventScript_Meganiumite_Battle_1

VerdanturfMeadow_EventScript_Meganiumite_Battle_8:
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_1, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_MEGANIUMITE_VERDANTURF_MEADOW, VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_2
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_3, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_MEGANIUMITE, 1
	waitmessage
	goto VerdanturfMeadow_EventScript_Meganiumite_Battle_1


VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_0:
	.string "Ah, I see you've triumphed over Norman,\n"
	.string "quite the impressive feat at your age.\l"
	.string "How about we put your skills to the\l"
	.string "test in a friendly match? If you win,\l"
	.string "I'll reward you with this Meganiumite!$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_1:
	.string "Splendid, let's start!$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_2:
	.string "Your strength is truly awe-inspiring...$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_3:
	.string "You truly are strong. I hope to see your\n"
	.string "growth even further into the future.\l"
	.string "But for now, take this gift from me, and\l"
	.string "use it well.$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_4:
	.string "That's a bit disappointing. I hope you\n"
	.string "change your mind.$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_5:
	.string "I trust you'll find delight in the token\n"
	.string "I've bestowed upon you!$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_6:
	.string "Greetings! Have you come to savor the\n"
	.string "fragrance of these blossoms? You\l"
	.string "strike me as someone with different\l"
	.string "interests. A Pokémon Trainer,\l"
	.string "perchance? Well, here's a proposition\l"
	.string "for you: how about dropping by after\l"
	.string "exploring Petalburg? I may just have a\l"
	.string "little something that piques your\l"
	.string "curiosity.$"
