SPECIES_VENUSAUR
{
    .name = Assault Vest Physical Tank
    .lvl = 0,
    .species = SPECIES_VENUSAUR, // Assault Vest Tank
    .heldItem = ITEM_LEFTOVERS,
    .ability = 0, // ABILITY_CHLOROPLAST, ABILITY_EFFECT_SPORE, ABILITY_CHLOROPHYLL},
    // .innates = {ABILITY_OVERGROW, ABILITY_THICK_FAT, ABILITY_POISON_TOUCH},
    .ivs = {31, 0, 31, 31, 31, 31},
    .evs = {252, 0, 252, 0, 4, 0},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_BOLD,
    .moves = MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_LEECH_SEED, MOVE_SLEEP_POWDER
    }
venusaur
{
    .name = Wide Lens, Chloroplast
    .lvl = 0,
    .species = SPECIES_VENUSAUR, // Wide Lens, Chloroplast
    .heldItem = ITEM_WIDE_LENS,
    .ability = 0, // ABILITY_CHLOROPLAST, ABILITY_EFFECT_SPORE, ABILITY_CHLOROPHYLL},
    // .innates = {ABILITY_OVERGROW, ABILITY_THICK_FAT, ABILITY_POISON_TOUCH},
    .ivs = {31, 0, 31, 31, 31, 31},
    .evs = {252, 0, 0, 252, 0, 4},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_MODEST,
    .moves = MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_EARTH_POWER, MOVE_SLEEP_POWDER
    }
SPECIES_CHARIZARD
{
    .name = Offensive, White Herb, Burnate
    .lvl = 3,
    .species = SPECIES_CHARIZARD, // Flannery, White Herb, Burnate
    .heldItem = ITEM_WHITE_HERB,
    .ability = 0, // ABILITY_BURNATE, ABILITY_AERILATE, ABILITY_TOUGH_CLAWS},
    // .innates = {ABILITY_BLAZE, ABILITY_LEVITATE, ABILITY_SUN_WORSHIP},
    .ivs = {31, 0, 31, 31, 31, 31},
    .evs = {0, 0, 4, 252, 0, 252},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_TIMID,
    .moves = MOVE_SOLAR_BEAM, MOVE_SCORCHING_SANDS, MOVE_DRACO_METEOR, MOVE_HYPER_VOICE
    }
SPECIES_BLASTOISE_MEGA
{
    .name = Singles Shell Smash
    .species = BLASTOISE_MEGA SPECIES_BLASTOISE_MEGA,
    .heldItem = ITEM_BLASTOISINITE,
    .ability = 0, // ABILITY_TORRENT, ABILITY_SHELL_ARMOR, ABILITY_MEGA_LAUNCHER},
    .evs = {0, 0, 6, 252, 0, 252},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    .nature = NATURE_TIMID,
    .moves = MOVE_SHELL_SMASH, MOVE_HYDRO_PUMP, MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON
    .comment = Inaccurate moves cannot miss thanks to Artillery. With the added Steel type upon Mega Evolution, Blastoise gains STAB on Flash Cannon and additional resistances, so you can time the Mega Evolution well and get rewarded for it.
    }
escavalier
{
    name = Speed Boost Sweeper
    item = leftovers
    ability = no guard
    evs = 0, 252, 4, 0, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = jolly
    moves = megahorn, iron head / close combat / drill run, protect, swords dance
   comment = Use Protect to gain Speed Boost and Leftovers recovery at the same time. Ideally Protect -> Swords Dance -> Protect. Megahorn is usually strong enough, and the 2nd move depends on your opponent. 
}
golurk
{
    name = Rock Polish WP Sweeper
    item = weakness policy
    ability = no guard
    evs = 0, 252, 4, 0, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = jolly
    moves = fissure, shadow punch / poltergeist, dynamic punch / ice punch, rock polish
   comment = Shadow Shield makes sure that Golurk can always setup safely, activating Weakness Policy then sweep. The moves take advantage of Golurk's ability Iron Fist and No Guard. 
}
alakazam
{
    name = Singles Calm Mind + Substitute Sleep Chains
    item = Leftovers
    ability = Exploit Weakness
    evs = 4, 0, 0, 252, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Timid
    moves = Hypnosis, Substitute, Calm Mind, Dream Eater / Stored Power / Psychic
   comment = Thanks to Hypnosist, Alakazam can inflict sleep on the opponent 90% of the time. All it needs to do is to set up a Substitute in case the enemy wakes up early and set up some Calm Minds before attacking with a Psychic-type move. However, you should immediately switch out if you face a Dark-type Pokémon.
}
kecleon
{
    .lvl = 0,
    .species = SPECIES_KECLEON, // Troll set
    .heldItem = ITEM_MENTAL_HERB,
    .ability = 0, // ABILITY_LIMBER, ABILITY_NONE, ABILITY_NONE},
    // .innates = {ABILITY_COLOR_CHANGE, ABILITY_PROTEAN, ABILITY_NONE},
    .ivs = {31, 31, 31, 31, 31, 31},
    .evs = {252, 0, 180, 0, 76, 0},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_IMPISH,
    .moves = MOVE_PROTECT, MOVE_TOXIC, MOVE_RECOVER, MOVE_DIZZY_PUNCH
    }
WARTORTLE
{
    name = Turtle Power
    item = Eviolite
    ability = Stamina
    evs = 252, 0, 20, 216, 22, 0 
    nature = Modest
    moves = Blizzard, Hydro pump, Aura Sphere, Rapid Spin
   comment = Aura Sphere can be replaced with Protect if you don't see much use for it because of the team being used. Shell Smash isn't here because you eat damage to win. You won't one-shot after mid-game, but you still win. If you see that you got space to do anything, spin like a turtle, show that turtle power.
}