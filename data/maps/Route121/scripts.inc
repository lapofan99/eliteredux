.set LOCALID_GRUNT_1, 12
.set LOCALID_GRUNT_2, 13
.set LOCALID_GRUNT_3, 14

Route121_MapScripts:: @ 81F5DFC
	.byte 0

Route121_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox Route121_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route121_EventScript_Nurse::
	lock
	faceplayer
	msgbox Route121_Nurse_Text_YouNeedHealing, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route121_Nurse_EventScript_PlayerIsGenji
	compare VAR_RESULT, NO
	goto_if_eq Route121_Nurse_EventScript_PlayerNotGenji
	end

Route121_Nurse_EventScript_PlayerIsGenji::
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route121_Nurse_Text_AllBetter, MSGBOX_DEFAULT
	release
	end

Route121_Nurse_EventScript_PlayerNotGenji::
	msgbox Route121_Nurse_Text_GoodLuck, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_Woman:: @ 81F5DFD
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
	end

Route121_EventScript_MtPyrePierSign:: @ 81F5E06
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
	end

Route121_EventScript_SafariZoneSign:: @ 81F5E0F
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
	end

Route121_EventScript_AquaGruntsMoveOut:: @ 81F5E18
	lockall
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route121_Text_OkayMoveOutToMtPyre, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Route121_Movement_Grunt1Exit
	applymovement LOCALID_GRUNT_2, Route121_Movement_Grunt2Exit
	applymovement LOCALID_GRUNT_3, Route121_Movement_Grunt3Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	setvar VAR_ROUTE121_STATE, 1
	releaseall
	end

Route121_Movement_Grunt1Exit: @ 81F5E59
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_Grunt2Exit: @ 81F5E62
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_Grunt3Exit: @ 81F5E6B
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_EventScript_Vanessa:: @ 81F5E74
	trainerbattle_single TRAINER_VANESSA, Route121_Text_VanessaIntro, Route121_Text_VanessaDefeat
	msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Walter:: @ 81F5E8B
	trainerbattle_single TRAINER_WALTER_1, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, Route121_EventScript_RegisterWalter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route121_EventScript_RematchWalter
	msgbox Route121_Text_WalterPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterWalter:: @ 81F5EB7
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_WalterRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WALTER_1
	release
	end

Route121_EventScript_RematchWalter:: @ 81F5ED6
	trainerbattle_rematch TRAINER_WALTER_1, Route121_Text_WalterRematchIntro, Route121_Text_WalterRematchDefeat
	msgbox Route121_Text_WalterPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Tammy:: @ 81F5EED
	trainerbattle_single TRAINER_TAMMY, Route121_Text_TammyIntro, Route121_Text_TammyDefeat
	msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Kate:: @ 81F5F04
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_KateIntro, Route121_Text_KateDefeat, Route121_Text_KateNotEnoughMons
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Joy:: @ 81F5F1F
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_JoyIntro, Route121_Text_JoyDefeat, Route121_Text_JoyNotEnoughMons
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Jessica:: @ 81F5F3A
	trainerbattle_single TRAINER_JESSICA_1, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat, Route121_EventScript_RegisterJessica
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route121_EventScript_RematchJessica
	msgbox Route121_Text_JessicaPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterJessica:: @ 81F5F66
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_JessicaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JESSICA_1
	release
	end

Route121_EventScript_RematchJessica:: @ 81F5F85
	trainerbattle_rematch TRAINER_JESSICA_1, Route121_Text_JessicaRematchIntro, Route121_Text_JessicaRematchDefeat
	msgbox Route121_Text_JessicaPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Cale:: @ 81F5F9C
	trainerbattle_single TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat
	msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Myles:: @ 81F5FB3
	trainerbattle_single TRAINER_MYLES, Route121_Text_MylesIntro, Route121_Text_MylesDefeat
	msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Pat:: @ 81F5FCA
	trainerbattle_single TRAINER_PAT, Route121_Text_PatIntro, Route121_Text_PatDefeat
	msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Marcel:: @ 81F5FE1
	trainerbattle_single TRAINER_MARCEL, Route121_Text_MarcelIntro, Route121_Text_MarcelDefeat
	msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Cristin:: @ 81F5FF8
	trainerbattle_single TRAINER_CRISTIN_1, Route121_Text_CristinIntro, Route121_Text_CristinDefeat, Route121_EventScript_RegisterCristin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route121_EventScript_RematchCristin
	msgbox Route121_Text_CristinPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterCristin:: @ 81F6024
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_CristinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CRISTIN_1
	release
	end

Route121_EventScript_RematchCristin:: @ 81F6043
	trainerbattle_rematch TRAINER_CRISTIN_1, Route121_Text_CristinRematchIntro, Route121_Text_CristinRematchDefeat
	msgbox Route121_Text_CristinPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_Text_OkayMoveOutToMtPyre: @ 81F605A
	.string "Okay!\n"
	.string "We're to move out to Mt. Pyre!$"

Route121_Text_AheadLoomsMtPyre: @ 81F607F
	.string "Ahead looms Mt. Pyre…\p"
	.string "It is a natural monument to the spirits\n"
	.string "of departed Pokémon…$"

Route121_Text_MtPyrePierSign: @ 81F60D3
	.string "Mt. Pyre Pier\p"
	.string "…The sign is old and worn out.\n"
	.string "The words are barely legible…$"

Route121_Text_SafariZoneSign: @ 81F611E
	.string "“Filled with rare Pokémon!”\n"
	.string "Safari Zone$"

Route121_Text_Skitty:
	.string "Skitty: Meenya?$"

Route121_Nurse_Text_YouNeedHealing:
	.string "I am a wandering\n"
	.string "Pokémon Center employee.\p"
	.string "Why don't I take care of your\n"
	.string "Pokémon's ills in a flash?$"

Route121_Nurse_Text_AllBetter:
	.string "I took care of all that ailed\n"
	.string "your Pokémon in a flash!$"

Route121_Nurse_Text_GoodLuck:
	.string "Okay then!\n"
	.string "Good luck on your journey!$"

Route121_EventScript_LegendaryNPC::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route121_EventScript_LegendaryNPC_2
	checktrainerflag TRAINER_VANESSA
	goto_if 1, Route121_EventScript_LegendaryNPC_8
Route121_EventScript_LegendaryNPC_6:
	msgbox Route121_EventScript_LegendaryNPC_Text_2
Route121_EventScript_LegendaryNPC_1:
	release
	end

Route121_EventScript_LegendaryNPC_2:
	msgbox Route121_EventScript_LegendaryNPC_Text_0
	goto Route121_EventScript_LegendaryNPC_1

Route121_EventScript_LegendaryNPC_5:
	msgbox Route121_EventScript_LegendaryNPC_Text_1
	goto Route121_EventScript_LegendaryNPC_1

Route121_EventScript_LegendaryNPC_7:
	checktrainerflag TRAINER_TAMMY
	goto_if 1, Route121_EventScript_LegendaryNPC_12
	goto Route121_EventScript_LegendaryNPC_6

Route121_EventScript_LegendaryNPC_8:
	checktrainerflag TRAINER_WALTER_1
	goto_if 1, Route121_EventScript_LegendaryNPC_7
	goto Route121_EventScript_LegendaryNPC_6

Route121_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_JESSICA_1
	goto_if 1, Route121_EventScript_LegendaryNPC_16
	goto Route121_EventScript_LegendaryNPC_6

Route121_EventScript_LegendaryNPC_12:
	checktrainerflag TRAINER_KATE_AND_JOY
	goto_if 1, Route121_EventScript_LegendaryNPC_11
	goto Route121_EventScript_LegendaryNPC_6

Route121_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_MYLES
	goto_if 1, Route121_EventScript_LegendaryNPC_20
	goto Route121_EventScript_LegendaryNPC_6

Route121_EventScript_LegendaryNPC_16:
	checktrainerflag TRAINER_CALE
	goto_if 1, Route121_EventScript_LegendaryNPC_15
	goto Route121_EventScript_LegendaryNPC_6

Route121_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_MARCEL
	goto_if 1, Route121_EventScript_LegendaryNPC_23
	goto Route121_EventScript_LegendaryNPC_6

Route121_EventScript_LegendaryNPC_20:
	checktrainerflag TRAINER_PAT
	goto_if 1, Route121_EventScript_LegendaryNPC_19
	goto Route121_EventScript_LegendaryNPC_6

Route121_EventScript_LegendaryNPC_23:
	checktrainerflag TRAINER_CRISTIN_1
	goto_if 1, Route121_EventScript_LegendaryNPC_5
	goto Route121_EventScript_LegendaryNPC_6


Route121_EventScript_LegendaryNPC_Text_0:
	.string "In the realm where justice's light doth\n"
	.string "shine,\p"
	.string "Three swords emerged with valor strong\n"
	.string "and true.\p"
	.string "Virizion, Cobalion, Terrakion,\p"
	.string "they wield their blades as the most\n"
	.string "noble, righteous crew.\p"
	.string "Virizion, swift and graceful as the\n"
	.string "breeze,\p"
	.string "With verdant elegance and keen insight.\p"
	.string "Its blade cuts through deceit and\n"
	.string "brings release,\p"
	.string "Ensuring truth prevails with all its\n"
	.string "might.\p"
	.string "Cobalion, sturdy guardian of law,\p"
	.string "With iron will and virtue as its guide.\p"
	.string "Its sword strikes down the wicked,\n"
	.string "without flaw,\p"
	.string "Protecting innocent souls far and wide.\p"
	.string "Terrakion, a force with strength\n"
	.string "untamed,\p"
	.string "Its blade unyielding, never to relent.\p"
	.string "Defending those in need, it stands\n"
	.string "unblamed,\p"
	.string "A beacon of justice brightly sent.\p"
	.string "With hearts determined and spirits\n"
	.string "aligned,\p"
	.string "You embark on a noble quest.\p"
	.string "Two destinies entwined, two wills put to\n"
	.string "test,\p"
	.string "To seize the Swords of Justice, a quest\n"
	.string "expressed.$"

Route121_EventScript_LegendaryNPC_Text_1:
	.string "Triumphant now, your quest complete,\p"
	.string "your efforts rewarded, the Swords now\n"
	.string "near.\p"
	.string "Show yourself, give him a treat,\p"
	.string "Victory's embrace, your heart holds\n"
	.string "dear.$"

Route121_EventScript_LegendaryNPC_Text_2:
	.string "You stands at the route's final bend,\p"
	.string "For your journey is near completion,\n"
	.string "victory in sight!\p"
	.string "To catch the Swords of Justice, you\n"
	.string "must transcend,\p"
	.string "by triumphing over others with might!$"
