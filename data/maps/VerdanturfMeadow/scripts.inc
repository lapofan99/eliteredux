VerdanturfMeadow_MapScripts::
	.byte 0

VerdanturfMeadow_EventScript_GiftAudino::
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

VerdanturfMeadow_EventScript_Mega_Meganium_Battle::
	lock
	faceplayer
	checktrainerflag TRAINER_NEW_TEST
	goto_if 0, VerdanturfMeadow_EventScript_Mega_Meganium_Battle_2
	msgbox VerdanturfMeadow_EventScript_Mega_Meganium_Battle_Text_4, MSGBOX_NPC
VerdanturfMeadow_EventScript_Mega_Meganium_Battle_1:
	release
	end

VerdanturfMeadow_EventScript_Mega_Meganium_Battle_2:
	msgbox VerdanturfMeadow_EventScript_Mega_Meganium_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq VerdanturfMeadow_EventScript_Mega_Meganium_Battle_5
	msgbox VerdanturfMeadow_EventScript_Mega_Meganium_Battle_Text_3, MSGBOX_NPC
	goto VerdanturfMeadow_EventScript_Mega_Meganium_Battle_1

VerdanturfMeadow_EventScript_Mega_Meganium_Battle_5:
	trainerbattle_no_intro TRAINER_NEW_TEST, VerdanturfMeadow_EventScript_Mega_Meganium_Battle_Text_1
	msgbox VerdanturfMeadow_EventScript_Mega_Meganium_Battle_Text_2, MSGBOX_NPC
	giveitem ITEM_DEWGONGITE, 1
	goto VerdanturfMeadow_EventScript_Mega_Meganium_Battle_1


VerdanturfMeadow_EventScript_Mega_Meganium_Battle_Text_0:
	.string "Steven: Young trainer, show me what\n"
	.string "you've got, before we talk.$"

VerdanturfMeadow_EventScript_Mega_Meganium_Battle_Text_1:
	.string "I got defeated...$"

VerdanturfMeadow_EventScript_Mega_Meganium_Battle_Text_2:
	.string "That was a great battle, here is your\n"
	.string "prize, you earned it!$"

VerdanturfMeadow_EventScript_Mega_Meganium_Battle_Text_3:
	.string "Oh well...$"

VerdanturfMeadow_EventScript_Mega_Meganium_Battle_Text_4:
	.string "It was a good battle but I already gave\n"
	.string "you your prize.$"
