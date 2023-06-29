VictoryRoad_B1F_MapScripts:: @ 82364E4
	.byte 0

VictoryRoad_B1F_EventScript_Samuel:: @ 82364E5
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon:: @ 82364FC
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle:: @ 8236513
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell:: @ 823652A
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle:: @ 8236541
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro: @ 8236558
	.string "The thought that I'm getting closer to\n"
	.string "the Pokémon League…\p"
	.string "I'm getting stage fright…$"

VictoryRoad_B1F_Text_SamuelDefeat: @ 82365AD
	.string "I couldn't do a thing…$"

VictoryRoad_B1F_Text_SamuelPostBattle: @ 82365C4
	.string "The Pokémon League became distant\n"
	.string "again… What a letdown…$"

VictoryRoad_B1F_Text_ShannonIntro: @ 82365FD
	.string "To win your way through the Pokémon\n"
	.string "League, you need the trust of your\l"
	.string "Pokémon.$"

VictoryRoad_B1F_Text_ShannonDefeat: @ 823664D
	.string "Your relationship is based on\n"
	.string "solid trust.$"

VictoryRoad_B1F_Text_ShannonPostBattle: @ 8236678
	.string "By being together all the time, trust\n"
	.string "grows between Pokémon and Trainers.$"

VictoryRoad_B1F_Text_MichelleIntro: @ 82366C2
	.string "This isn't the goal. It's only a place\n"
	.string "on the way to the Pokémon League.$"

VictoryRoad_B1F_Text_MichelleDefeat: @ 823670B
	.string "That's the way!$"

VictoryRoad_B1F_Text_MichellePostBattle: @ 823671B
	.string "You'll do fine, for sure!\n"
	.string "Your Pokémon are all eager to go!$"

VictoryRoad_B1F_Text_MitchellIntro: @ 8236757
	.string "My Pokémon are cosmically\n"
	.string "awe inspiring!$"

VictoryRoad_B1F_Text_MitchellDefeat: @ 8236780
	.string "I've never met anyone like you before.$"

VictoryRoad_B1F_Text_MitchellPostBattle: @ 82367A7
	.string "Even outside of battle, I sense\n"
	.string "incredible power emanating from you\l"
	.string "and your Pokémon.$"

VictoryRoad_B1F_Text_HalleIntro: @ 82367FD
	.string "Okay, no need to get your back up!\n"
	.string "Relax, let's take it easy!$"

VictoryRoad_B1F_Text_HalleDefeat: @ 823683B
	.string "Whoa!\n"
	.string "Wonderful!$"

VictoryRoad_B1F_Text_HallePostBattle: @ 823684C
	.string "Sure, this is Victory Road.\p"
	.string "But it's not all that different from\n"
	.string "the path you've taken so far.\p"
	.string "Try to enjoy things the rest of\n"
	.string "the way!$"

VictoryRoad_B1F_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox VictoryRoad_B1F_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_B1F_EventScript_LegendaryNPC_2
	msgbox VictoryRoad_B1F_EventScript_LegendaryNPC_Text_4
VictoryRoad_B1F_EventScript_LegendaryNPC_1:
	release
	end

VictoryRoad_B1F_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, VictoryRoad_B1F_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_HALLE
	goto_if 1, VictoryRoad_B1F_EventScript_LegendaryNPC_11
VictoryRoad_B1F_EventScript_LegendaryNPC_9:
	msgbox VictoryRoad_B1F_EventScript_LegendaryNPC_Text_3
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_1

VictoryRoad_B1F_EventScript_LegendaryNPC_5:
	msgbox VictoryRoad_B1F_EventScript_LegendaryNPC_Text_1
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_1

VictoryRoad_B1F_EventScript_LegendaryNPC_8:
	msgbox VictoryRoad_B1F_EventScript_LegendaryNPC_Text_2
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_1

VictoryRoad_B1F_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_SHANNON
	goto_if 1, VictoryRoad_B1F_EventScript_LegendaryNPC_14
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_9

VictoryRoad_B1F_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_MITCHELL
	goto_if 1, VictoryRoad_B1F_EventScript_LegendaryNPC_10
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_9

VictoryRoad_B1F_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_SAMUEL
	goto_if 1, VictoryRoad_B1F_EventScript_LegendaryNPC_8
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_9


VictoryRoad_B1F_EventScript_LegendaryNPC_Text_0:
	.string "Sage: The hostile nature of these\n"
	.string "crevaces turn away most without a\l"
	.string "fighting spirit... but not you. Am I\l"
	.string "right?$"

VictoryRoad_B1F_EventScript_LegendaryNPC_Text_1:
	.string "This treacherous cave has drawn those\n"
	.string "with a fighting spirit that matches its\l"
	.string "own!\p"
	.string "Whether born from nature or forged\n"
	.string "through life's trials, renegade spirits\l"
	.string "are naturally attracted to these dank\l"
	.string "corridors.\p"
	.string "Take the story of Type:Null: once\n"
	.string "created to eliminate the Ultra Beasts,\l"
	.string "they went berserk and turned rogue\l"
	.string "against their creators.\p"
	.string "They now reside here with Marshadow, a\n"
	.string "mysterious shadow brought to life\l"
	.string "thanks to their sheer willpower and\l"
	.string "indomitable spirit.\p"
	.string "Meeting these two is not an affair to\n"
	.string "take lightly. First, beat the Pokémon\l"
	.string "League, then come back to me.$"

VictoryRoad_B1F_EventScript_LegendaryNPC_Text_2:
	.string "Your spirit is aligned with the\n"
	.string "creatures residing in this place. They\l"
	.string "have allowed me to reveal their\l"
	.string "locations to you: I added their info to\l"
	.string "your DexNav. I can't wait to see your\l"
	.string "fight against them!$"

VictoryRoad_B1F_EventScript_LegendaryNPC_Text_3:
	.string "I commend your dedication, becoming\n"
	.string "champion must've been a difficult\l"
	.string "affair. But, if you managed to do that,\l"
	.string "I'm sure you'll also be able to beat the\l"
	.string "last few trainers in this cave. Defeat\l"
	.string "them and come back to me.$"

VictoryRoad_B1F_EventScript_LegendaryNPC_Text_4:
	.string "...but you're at Victory Road? Why would\n"
	.string "you NOT have a fighting spirit?$"
