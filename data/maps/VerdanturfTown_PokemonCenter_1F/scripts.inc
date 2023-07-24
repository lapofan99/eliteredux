.set LOCALID_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts:: @ 8202726
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition: @ 8202731
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse:: @ 820273A
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_XscissorTM::
	lock
	faceplayer
	msgbox VerdanturfTown_PokemonCenter_1F_Text_DoYouLikeBugs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_PokemonCenter_1F_EventScript_DontLikeBugs
	msgbox VerdanturfTown_PokemonCenter_1F_Text_GiveTM81, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ReceivedTM81::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_HaveTM81, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_DontLikeBugs::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_DontLikeBugs, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PokeMart_PokeCenterVerdanturfTown
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_PokeCenterVerdanturfTown::
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_NONE
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman:: @ 8202748
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM:: @ 8202751
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_DoYouLikeBugs:
	.string "Yo! Bug-type Pokémon are wickedly cool!\n"
	.string "You agree, right?$"

VerdanturfTown_PokemonCenter_1F_Text_GiveTM81:
	.string "Yeah! I like you. We can be friends.$"

VerdanturfTown_PokemonCenter_1F_Text_HaveTM81:
	.string "TM81 is X-scissor.\n"
	.string "It's a wickedly cool Bug-type attack!$"

VerdanturfTown_PokemonCenter_1F_Text_DontLikeBugs:
	.string "No? We're not on the same wavelength.$"

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon: @ 820275A
	.string "You can't consider yourself a real\n"
	.string "Trainer if you don't have faith\l"
	.string "in your Pokémon.\p"
	.string "Only those people who can believe\n"
	.string "in their battling Pokémon can win\l"
	.string "through to the very end.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent: @ 820280B
	.string "The reason why anyone would visit\n"
	.string "Verdanturf…\p"
	.string "It's the Battle Tent. It goes without\n"
	.string "saying.\p"
	.string "Or is there somebody here that you\n"
	.string "came to see?$"

Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	checkitem ITEM_POKE_VIAL, 1
	compare VAR_RESULT, 1
	goto_if_eq Common_EventScript_PkmnCenterNurse_2
	msgbox Common_EventScript_PkmnCenterNurse_Text_0, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Common_EventScript_PkmnCenterNurse_Text_1
	waitmessage
	setflag FLAG_SYS_DEXNAV_GET
	waitfanfare
	msgbox Common_EventScript_PkmnCenterNurse_Text_2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Common_EventScript_PkmnCenterNurse_Text_3
	waitmessage
	call Common_EventScript_PkmnCenterNurse_GiveItems_First_Time
	waitfanfare
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	additem ITEM_POKE_VIAL
	setvar VAR_POKE_VIAL_MAX_CHARGES, 1
	setvar VAR_POKE_VIAL_CHARGES, 1
	msgbox Common_EventScript_PkmnCenterNurse_Text_4, MSGBOX_DEFAULT
Common_EventScript_PkmnCenterNurse_1:
	release
	end

Common_EventScript_PkmnCenterNurse_2:
	goto EventScript_PkmnCenterNurseHasVial
	goto Common_EventScript_PkmnCenterNurse_1


Common_EventScript_PkmnCenterNurse_GiveItems_First_Time::
	giveBattleItems
	return


Common_EventScript_PkmnCenterNurse_Text_0:
	.string "Hello, and welcome to the Pokémon\n"
	.string "Center.\p"
	.string "We can restore your tired Pokémon to\n"
	.string "full health, but that's not really\l"
	.string "needed as your Pokémon will auto-heal\l"
	.string "before every battle.\p"
	.string "This is your first time here, isn't it?\p"
	.string "It's your lucky day!\p"
	.string "We're currently giving out tons of\n"
	.string "useful items to all rookie Trainers.\p"
	.string "Here, take this DexNav first!$"

Common_EventScript_PkmnCenterNurse_Text_1:
	.string "{PLAYER} received the DexNav!$"

Common_EventScript_PkmnCenterNurse_Text_2:
	.string "I'll give you a Candy Box, TM Case, all\n"
	.string "Battle items, all Pokéballs, all TMs &\l"
	.string "HMs, all Berries, all Type Gems and some\l"
	.string "more stuff.\p"
	.string "Every time you speak to me, I'll fill all\n"
	.string "your items up again.$"

Common_EventScript_PkmnCenterNurse_Text_3:
	.string "{PLAYER} received a LOT of items!$"

Common_EventScript_PkmnCenterNurse_Text_4:
	.string "We hope to see you again!$"
