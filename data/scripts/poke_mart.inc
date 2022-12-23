General_Pokemart_Script::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
    goto_if_set FLAG_BADGE07_GET, Mart_Mind_Badge
	goto_if_set FLAG_BADGE06_GET, Mart_Feather_Badge
	goto_if_set FLAG_BADGE05_GET, Mart_Balance_Badge
	goto_if_set FLAG_BADGE04_GET, Mart_Heat_Badge
	goto_if_set FLAG_BADGE03_GET, Mart_Dynamo_Badge
	goto_if_set FLAG_BADGE02_GET, Mart_Knuckle_Badge
	goto_if_set FLAG_BADGE01_GET, Mart_Stone_Badge
	pokemart PokeMart_No_Badges
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_No_Badges::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end

Mart_Stone_Badge::
	pokemart PokeMart_Stone_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Stone_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end
	
Mart_Knuckle_Badge::
	pokemart PokeMart_Knuckle_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Knuckle_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end
	
Mart_Dynamo_Badge::
	pokemart PokeMart_Dynamo_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Dynamo_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end

Mart_Heat_Badge::
	pokemart PokeMart_Heat_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Heat_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end
	
Mart_Balance_Badge::
	pokemart PokeMart_Balance_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Balance_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end
	
Mart_Feather_Badge::
	pokemart PokeMart_Feather_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Feather_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end

Mart_Mind_Badge::
	pokemart PokeMart_Mind_Badge
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_Mind_Badge::
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_LEAF_STONE
    .2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_METAL_COAT
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_RAZOR_FANG
    .2byte ITEM_RAZOR_CLAW
    .2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_NONE
	release
	end
