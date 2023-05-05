VictoryRoad_B2F_MapScripts:: @ 82368D4
	.byte 0

VictoryRoad_B2F_EventScript_Vito:: @ 82368D5
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen:: @ 82368EC
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline:: @ 8236903
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie:: @ 823691A
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix:: @ 8236931
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne:: @ 8236948
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro: @ 823695F
	.string "I trained together with my whole family,\n"
	.string "every one of us!\l"
	.string "I'm not losing to anyone!$"

VictoryRoad_B2F_Text_VitoDefeat: @ 82369B3
	.string "Better than my family?!\n"
	.string "Is that possible?!$"

VictoryRoad_B2F_Text_VitoPostBattle: @ 82369DE
	.string "I was better than everyone in my\n"
	.string "family. I've never lost before…\p"
	.string "I've lost my confidence…\n"
	.string "Maybe I'll go home…$"

VictoryRoad_B2F_Text_OwenIntro: @ 8236A4C
	.string "I'd heard that there was a tough\n"
	.string "little kid around. Do they mean you?$"

VictoryRoad_B2F_Text_OwenDefeat: @ 8236A92
	.string "The little shrimp is tough!$"

VictoryRoad_B2F_Text_OwenPostBattle: @ 8236AAE
	.string "The rumors I heard, that tough little\n"
	.string "kid is from Petalburg City.$"

VictoryRoad_B2F_Text_CarolineIntro: @ 8236AF0
	.string "You must be getting a little tired.$"

VictoryRoad_B2F_Text_CarolineDefeat: @ 8236B14
	.string "No signs of tiring at all!$"

VictoryRoad_B2F_Text_CarolinePostBattle: @ 8236B2F
	.string "Victory Road and the Pokémon League\n"
	.string "are long and grueling challenges.\l"
	.string "Beware of fatigue!$"

VictoryRoad_B2F_Text_JulieIntro: @ 8236B88
	.string "You shouldn't get complacent just\n"
	.string "because you have a lot of Gym Badges.\p"
	.string "There's always going to be someone\n"
	.string "who's better than you!$"

VictoryRoad_B2F_Text_JulieDefeat: @ 8236C0A
	.string "You're better than me!$"

VictoryRoad_B2F_Text_JuliePostBattle: @ 8236C21
	.string "Gaze on your collected Badges and\n"
	.string "remember the Trainers you've faced.$"

VictoryRoad_B2F_Text_FelixIntro: @ 8236C67
	.string "I've come this far, but the tension's\n"
	.string "giving me awful stomach pain…$"

VictoryRoad_B2F_Text_FelixDefeat: @ 8236CAB
	.string "Ooh…\n"
	.string "It hurts…$"

VictoryRoad_B2F_Text_FelixPostBattle: @ 8236CBA
	.string "I can't help getting all tense knowing\n"
	.string "that I'm nearing the Pokémon League.\p"
	.string "It's all I can do to feign calm.$"

VictoryRoad_B2F_Text_DianneIntro: @ 8236D27
	.string "The elite among the elite gather in\n"
	.string "this cave.\p"
	.string "How are you finding it?$"

VictoryRoad_B2F_Text_DianneDefeat: @ 8236D6E
	.string "Not rattled in the least bit!$"

VictoryRoad_B2F_Text_DiannePostBattle: @ 8236D8C
	.string "You do have guts! I like that!\n"
	.string "Keep it going!$"

VictoryRoad_B2F_EventScript_LegendaryNPC::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, VictoryRoad_B2F_EventScript_LegendaryNPC_2
	checktrainerflag TRAINER_JULIE
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_8
VictoryRoad_B2F_EventScript_LegendaryNPC_6:
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_2
VictoryRoad_B2F_EventScript_LegendaryNPC_1:
	release
	end

VictoryRoad_B2F_EventScript_LegendaryNPC_2:
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_0
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_1

VictoryRoad_B2F_EventScript_LegendaryNPC_5:
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_1
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_1

VictoryRoad_B2F_EventScript_LegendaryNPC_7:
	checktrainerflag TRAINER_OWEN
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_12
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_6

VictoryRoad_B2F_EventScript_LegendaryNPC_8:
	checktrainerflag TRAINER_CAROLINE
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_7
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_6

VictoryRoad_B2F_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_FELIX
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_15
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_6

VictoryRoad_B2F_EventScript_LegendaryNPC_12:
	checktrainerflag TRAINER_VITO
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_11
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_6

VictoryRoad_B2F_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_DIANNE
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_5
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_6


VictoryRoad_B2F_EventScript_LegendaryNPC_Text_0:
	.string "You can find legendary Pokémon on this\n"
	.string "route. But you have to beat all\l"
	.string "trainers in this place and become the\l"
	.string "Champion first. Talk to me again then.$"

VictoryRoad_B2F_EventScript_LegendaryNPC_Text_1:
	.string "You are now worthy to catch\n"
	.string "Calyrex-Shadow, Tapu Fini and Tapu\l"
	.string "Lele here. Just use your DexNav, they\l"
	.string "will now appear.$"

VictoryRoad_B2F_EventScript_LegendaryNPC_Text_2:
	.string "You are not worthy yet to catch\n"
	.string "Calyrex-Shadow, Tapu Fini or Tapu Lele.\l"
	.string "Beat all trainers here first.$"
