SPECIES_VENUSAUR
{
    .name = Physical Tank
    .lvl = 0,
    .species = SPECIES_VENUSAUR, // Assault Vest Tank
    .heldItem = ITEM_LEFTOVERS,
    .ability = 0, // ABILITY_CHLOROPLAST, ABILITY_EFFECT_SPORE, ABILITY_CHLOROPHYLL},
    // .innates = {ABILITY_OVERGROW, ABILITY_THICK_FAT, ABILITY_POISON_TOUCH},
    .ivs = {31, 0, 31, 31, 31, 31},
    .evs = {252, 0, 252, 0, 4, 0},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_BOLD,
    .moves = MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_LEECH_SEED, MOVE_SLEEP_POWDER
    .tags = Singles, Defensive
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
charizard mega x
{
    name = Physical Setup Sweeper
    item = charizardite x
    ability = Tough Claws
    evs = 0, 252, 4, 0, 0, 252
    nature = Jolly
    moves = Dragon dance, Flare blitz, Dragon Rush / Dragon Claw, Dual Wingbeat
   comment = Switch in on a Pokémon incapable of effectively attacking you, then Mega Evolve and set up as much as you can, and then sweep with your STAB moves or Dual Wingbeat, which is boosted by Levitate.
    .tags = Singles, Offensive
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
    moves = megahorn, Iron Head / Close Combat / Drill Run, protect, swords dance
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
SPECIES_AERODACTYL_MEGA
{
    .name = Speed Force, 3 Moves + Roost
    .lvl = 3,
    .species = SPECIES_AERODACTYL, // Mega, Speed Force, Roost
    .heldItem = ITEM_AERODACTYLITE,
    .ability = 0, // ABILITY_SPEED_FORCE, ABILITY_PREDATOR, ABILITY_FATAL_PRECISION},
    // .innates = {ABILITY_FOSSILIZED, ABILITY_ROCK_HEAD, ABILITY_TOUGH_CLAWS},
    // Pre-Mega
    // ABILITY_SPEED_FORCE, ABILITY_PREDATOR, ABILITY_FATAL_PRECISION},
    // .innates = {ABILITY_FOSSILIZED, ABILITY_ROCK_HEAD, ABILITY_HALF_DRAKE},
    .ivs = {31, 31, 31, 31, 31, 31},
    .evs = {0, 252, 4, 0, 0, 252},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_JOLLY,
    .moves = MOVE_BRAVE_BIRD, MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_ROOST
    }
SPECIES_AERODACTYL
{
    .name = Choice Band + Predator
    .lvl = 3,
    .species = SPECIES_AERODACTYL, // Band, Predator
    .heldItem = ITEM_CHOICE_BAND,
    .ability = 1, // ABILITY_SPEED_FORCE, ABILITY_PREDATOR, ABILITY_FATAL_PRECISION},
    // .innates = {ABILITY_FOSSILIZED, ABILITY_ROCK_HEAD, ABILITY_HALF_DRAKE},
    .ivs = {31, 31, 31, 31, 31, 31},
    .evs = {0, 252, 4, 0, 0, 252},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_JOLLY,
    .moves = MOVE_BRAVE_BIRD, MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_DRAGON_RUSH
    }
SPECIES_POLIWRATH
{
    name = MAX POWER
    item = Life Orb
    ability = Power Fists
    evs = 252, 252, 0, 0, 6, 0 
    nature = Adamant
    moves = Close Combat, Frustration, Belly Drum, Hypnosis
   comment = Poliwrath here is a very flexible mon that goes all in and doesn't care about nobody except proper support to enable it to go first and destroy. 
   
   Change nature to Brave if you need it in a slow team with trick room (you may need Curse for this instead of Belly Drum to get the best of it) or add Rain Dance/Drizzle support if you need speed (this also means that replacing 252 evs in HP for Speed may be a thing needed in some cases). 
   
   Change Power Fists to Iron Fist against high spdef mons. Believe in Hypnosis to enable you to Belly Drum safe and Close Combat everything (your main move boosted by Power Fists/Iron Fists that will one-shot a lot of mons after Belly Drum).
   
   Substitute can be used instead of Hypnosis if you want something a bit more safe (hp lost hurts tho). Frustration is the cover move against most Psychic mons. Wave Crash/Waterfall/Ice Punch are good alternatives to Frustration in case you need more options.
}
Heliolisk
{
    name = Singles Invincible Lightning Rod
    item = Focus Sash
    ability = Lightning Rod
    evs = 0, 0, 6, 252, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Timid
    moves = Electrify, Parabolic Charge, Surf / Protect / Weather Ball, Earth Power / Aurasphere / Hyper Voice
   comment = Thanks to its three immunities due to its Normal typing, Dry Skin innate and Lightning Rod ability, Heliolisk can either come in after a KO or switch into certain attacks and start spamming Electrify to boost its Sp.Atk until it decides to stop.
   
   Sandstorm is also a possibility and makes it completely impossible for other Pokémon to outspeed Heliolisk. Even though this Pokémon is basically invincible, be aware of priority moves and Pokémon that ignore abilities.
   
   Stealth Rock support is also highly  appreciated in order to break Focus Sashes. Moveset can be changed depending on your preferences and the support tools that you bring.
}
Ferrothorn
{
    name = Rocky Helmet Physical Tank
    item = rocky helmet
    ability = bulletproof
    evs = 252, 0, 252, 0, 4, 0 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = bold
    moves = ingrain, curse, gyro ball, power whip
   comment = Switch in on contact attackers, set up to sweep with Power Whip and Gyro Ball
}
Gallade Mega
{
    name = Sir Galahad
    item = Galladite
    ability = Intrepid Sword
    evs = 4, 252, 0, 0, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Jolly / Adamant 
    moves =  shadow sneak, Excalibur, psycho cut, sacred sword
   comment = You can hit other Pokémon in the semi invincible turn of Fly with Fatal Precission, if it's super-effective. 
}
Feraligatr
{
    name = Bulky Quad Bite
    item = Assault Vest
    ability = Predator
    evs = 252, 252, 0, 0, 0, 4 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Adamant
    moves =  Deathroll, psychic fangs, Ice Fang, crunch
   comment = Deathroll & Crunch for STAB, Psychic Fangs to destroy screens and Ice Fang for coverage.
}
Porygon-Z
{
    name = Reverse Trick Room Analytic Nuke
    item = choice specs
    ability = twisted dimension
    evs = 4, 0, 0, 252, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = timid
    moves = techno blast, thunderbolt, ice beam, Dark Pulse / Bug Buzz
   comment = Analytic, Adaptability, and Choice Specs each boost Techno Blast by an extra 50% damage. Outspeed, go last, and blow up whatever you hit. Coverage there if you really need it but you'll mostly be using Techno Blast.
}
primeape
{
Name = Nuke Ape
Item = Choice Scarf
Ability = Gorilla Tactics
EVs = 6, 252, 0, 0, 0, 252
Nature = Adamant
Moves = Close Combat, Earthquake, Gunk Shot, Seed Bomb
comment = Thanks to the buffs received, Primeape can now be an absolute nuke with Gorilla Tactics and Hyper Agressive.
tags = Singles, Offensive
}
greninja
{
    name = Fatal and Precise
    item = choice specs
    ability = fatal precision
    evs = 0, 0, 0, 252, 4, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = timid
    moves = water shuriken / Hydro Pump, Dark Pulse, blizzard, u-turn
   comment = Fatal Precision works really well with lower accuracy moves like Hydro Pump or Blizzard, although Water Shuriken is still nice as it's also priority. Choice Specs allow Gren to dish out heavy hits with high base power moves, while U-Turn can be used to predict the opponent's check to Gren switching in. 
   tags = singles, offensive
}
greninja
{
    name = Hit the Other Side
    item = life orb
    ability = protean
    evs = 0, 80, 0, 172, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = naive
    moves = water shuriken, ice beam, Power whip / Gunk Shot / Strength, u-turn
   comment = This set allows you to hit on the physical side but mainly still focused on the special side, Life Orb helps with boosting the power. The third move is the most flexible one and for physical moves, you can choose depends on the matchup. Could also swap them on the second move slot but I like using the slot for other special moves. Now you can screw those Ground / Water or Fairy and Bug types. 
   tags = singles, offensive, mixed
}
Dragonite
{
    name = Aerilate E-Speed Sweeper
    item = weakness policy
    ability = aerilate
    evs = 0, 252, 4, 0, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = jolly
    moves = dragon dance, fire punch, extreme speed, earthquake
   comment = Dragonite, now armed with the coveted Aerilate ability, is poised to deliver powerful blows with its Extreme Speed STAB move. The inclusion of Aerilate allows Dragonite to maximize the damage output of this move, making it a formidable force to be reckoned with.

With its Multiscale ability, Dragonite possesses a unique advantage in enduring even the most devastating attacks from opposing Pokemon. In the event that Dragonite sustains damage from a super effective move, its strategic employment of the Weakness Policy item will activate, granting Dragonite a substantial boost to its offensive prowess.

This combination of abilities and items greatly enhances Dragonite's overall effectiveness in battle, making it a potent choice for any trainer seeking a powerhouse on their team.
    tags = Singles, Offensive
}
roserade
{
    .name = Rocky Helmet Defensive Wall
    .lvl = 3,
    .species = SPECIES_ROSERADE,
    .heldItem = ITEM_ROCKY_HELMET,
    .ability = 1, // ABILITY_TECHNICIAN, ABILITY_MERCILESS, ABILITY_PREDATOR},
    // .innates = {ABILITY_NATURAL_CURE, ABILITY_CHLOROPHYLL, ABILITY_POISON_POINT},
    .ivs = {31, 0, 31, 31, 31, 31},
    .evs = {252, 0, 240, 0, 0, 16},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_BOLD,
    .moves = MOVE_TOXIC_SPIKES, MOVE_GRASS_KNOT, MOVE_SYNTHESIS, MOVE_SLUDGE_BOMB
    .tags = singles, defensive
    .comment = This Roselia moveset is designed to function as a defensive wall, capable of wearing down opposing Pokémon with entry hazards and Toxic Spikes while maintaining its own longevity. With its innate Poison Point, Roselia can be a reliable nuisance on the battlefield.
    }
SPECIES_PERSIAN_ALOLAN
{
    name = Feeling Lucky?
    item = Scope Lens
    ability = Sniper
    evs = 42, 0, 252, 0, 0, 216 
    nature = Timid
    moves = Fake Out, Mud-Slap, Snarl, Parting Shot
   comment = Main job is to spam Mud-Slap to do a little trolling. You can replace Scope Lens with Bright Powder for a bit more of annoyance or continue believing in the power of critical hits and misses to win. 4-5 critical hits should take care of most mons IF you're lucky enough to get there.
   
   If you're tired of it (a.k.a. if the enemy is faster than you), you can simply do cheap damage with Fake Out plus debuff with Parting Shot to take care of those reduction damage abilities/innates/items and help the team with a debuff.
   
   Snarl is there in case you need to deal a good chunk of damage and can't do a bet on a critical hit since there aren't many good options in that department.
   tags = singles, doubles, offensive, troll
}
Incineroar
{
    name = Offensive Bulkiroar
    item = Assault Vest
    ability = Anger Point
    evs = 92, 198, 110, 0, 110, 0
    nature = Adamant 
    moves = Blaze Kick, Darkest Lariat, Fake Out, Drain Punch
   comment = A fully offensive and tanky Incineroar set. Nature can be changed to Impish for physical bulk. Blaze Kick with Striker does a LOT of damage. Same with Drain Punch with Iron Fist. If the enemy lands a critical attack on you, you can basically sweep them thanks to Anger Point.
    tags = Singles, Offensive
}
Lopunny
{
    name = Offensive Fighting Spirit
    item = Life Orb
    ability = Fighting Spirit
    evs = 0, 252, 4, 0, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Jolly / Adamant
    moves = Quick Attack / Fake Out, Mega Kick, Triple Axel, Play Rough
   comment = Fighting Spirit boosts all Normal moves by 20% and turns them into Fighting-type. Mega Kick and Triple Axel are boosted 30% by Striker.
    .tags = Singles, Offensive 
}
Ariados
{
    name = Critical Point
    item = Bug Gem / Focus Sash / Life Orb
    ability = sniper
    evs = 0, 252, 6, 0, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = jolly
    moves = fell stinger, sucker punch, cross poison, psycho cut
   comment = Use this pokemon if the enemy has less than half hitpoints (yellow). Opportunitist helps you strike first. Use Fell Stinger if possible to raise attack drasticlly. Use Sucker punch / Psycho Cut for coverage, and Cross Poison for STAB + Crit.

As for the abilities / innates, Sniper helps for extra crit damage, Spider Lair for slowing down enemies, Merciless for doing more crits, Opportunist for +1 priority if enemy health is low.
    .tags = Singles, Offensive
}
SPECIES_ZEBSTRIKA
{
   .name = Gotta Go Fast!
   .item = Choice Band / Choice Scarf / Fire Gem / Focus Sash
   .ability = Momentum
   .evs = 252, 0, 6, 0, 0, 252
   .nature = Jolly
   .moves = Flame Charge, High Jump Kick, Play Rough, Volt Tackle
   .comment = Why Momentum? It's slightly better than Speed Force, without switching in into a Grass-type move, allowing full HP EVs. Zebstrika is frail and relies on going first or surviving hits.

In terms of items, Choice Band is the best damage booster and Choice Scarf is an option against fast mons. Focus Sash is useful against priority moves.

Consider Fire Gem for flexibility and boosting Flame Charge to provide damage and speed boosts.

You can replace Play Rough or Flame Charge with Flare Blitz for more damage, or Play Rough with Quick Attack for priority.
   .tags = Singles, Offensive
}
Gardevoir Mega
{
    name = Fast Sweeper
    item = Gardevoirite
    ability = Pixilate (Psychic Surge pre-mega)
    evs = 4, 0, 0, 252, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Timid 
    moves = Hyper Voice, Expanding Force, Thunderbolt, Mystic Fire
   comment = Before being a Mega, Gardevoir needs to have Psychic Surge as ability, which prevents priority moves.
    .tags = Doubles, Offensive
}
Pinsir Mega
{
    .lvl = 3,
    .name = Deathly Mega Attacker
    .species = SPECIES_PINSIR, // Mega, Winona, Doubles, Horn Drill
    .heldItem = ITEM_PINSIRITE,
    .ability = 1, // ABILITY_HYPER_AGGRESSIVE, ABILITY_HYPER_AGGRESSIVE, ABILITY_HYPER_AGGRESSIVE},
    // .innates = {ABILITY_HYPER_CUTTER, ABILITY_GRIP_PINCER, ABILITY_AERILATE},
    // Pre-Mega
    // ABILITY_ANGER_POINT, ABILITY_VIOLENT_RUSH, ABILITY_MOXIE},
    // .innates = {ABILITY_SWARM, ABILITY_HYPER_CUTTER, ABILITY_GRIP_PINCER},
    .ivs = {31, 31, 31, 31, 31, 31},
    .evs = {52, 188, 28, 0, 4, 236},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_JOLLY,
    .moves = MOVE_HORN_DRILL, MOVE_QUICK_ATTACK, MOVE_CLOSE_COMBAT, MOVE_PROTECT
    .comment = Choose Violent Rush as pre-mega ability to profit from the first turn boosts.

    Horn Drill and Quick Attack turn into Flying-type moves thanks to Aerilate and get boosted further by 20%. Horn Drill now has 120 BP along 90% accuracy and ignores the target's stat stages and ability. Additionally, it has a high crit chance, which pairs well with Hyper Cutter's increased crit rate.

    Close Combat for strong coverage and Protect to safely Mega Evolve and useful for Doubles.

    Grip Pincer (innate) makes Horn Drill more likely to hit.
    .tags = Doubles, Offensive
    }
Dragapult
{
    .lvl = 3,
    .name = Physical Parental Bond
    .species = SPECIES_DRAGAPULT, // Drake, Colbur, Parental Bond, Physical
    .heldItem = ITEM_COLBUR_BERRY,
    .ability = 2, // ABILITY_ARTILLERY, ABILITY_SPEED_BOOST, ABILITY_PARENTAL_BOND},
    // .innates = {ABILITY_LEVITATE, ABILITY_CLEAR_BODY, ABILITY_HAUNTED_SPIRIT},
    .ivs = {31, 31, 31, 31, 31, 31},
    .evs = {4, 252, 0, 0, 0, 252},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_JOLLY,
    .moves = MOVE_POLTERGEIST, MOVE_DRAGON_DARTS, MOVE_U_TURN, MOVE_WILL_O_WISP
    .tags = Singles, Offensive
    }
Umbreon
{ 
    name = SpDef Stall Wall
    item = Leftovers / Bright Dust
    ability = bad luck
    evs = 252, 0, 4, 0, 252, 0 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Calm
    moves = foul play, protect, Moonlight / Strength Sap, toxic
   comment = A basic Toxic/Protect stall with Moonlight over Wish for instant healing (Strength Sap comes at level 60 once you can learn it off Leafeon and do the devolve/re-evolve). Foul Play does really well vs any Pokémon with more Atk than you have, which is why you pick -Atk +SpDef nature and later have Strength Sap.
    .tags = Singles, Doubles, Defensive, Mixed
}
Ledian
{
    .name = Endless Fists
    .lvl = 0,
    .species = SPECIES_LEDIAN,
    .heldItem = ITEM_LIFE_ORB,
    .ability = 1, // ABILITY_AERILATE, ABILITY_BUGINIZE, ABILITY_AERODYNAMICS},
    // .innates = {ABILITY_RAGING_BOXER, ABILITY_IRON_FIST, ABILITY_LEVITATE},
    .ivs = {31, 31, 31, 31, 31, 31},
    .evs = {0, 252, 0, 0, 4, 252},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_JOLLY,
    .moves = MOVE_MEGA_PUNCH, MOVE_DUAL_WINGBEAT, MOVE_CLOSE_COMBAT, MOVE_ICE_PUNCH
    .tags = Singles, Offensive
    .comment = Mega Punch turns into Bug-type thanks to Buginize -> also gets STAB + an additional 20% boost, which is further boosted 30% by Iron Fist. Raging Boxer makes sure it hits twice (2nd hit does 0.5x damage), which is useful to break Focus Sashes. Dual Wingbeat gets 25% boost from Levitate. Close Combat abuses Iron Fist + Raging Boxer. Ice Punch for coverage.
    }
Granbull
{
    .name = Hitting hard
    .lvl = 0,
    .species = SPECIES_GRANBULL,
    .heldItem = ITEM_CHOICE_BAND,
    .ability = 0, // ABILITY_INTIMIDATE, ABILITY_GUTS, ABILITY_VIOLENT_RUSH},
    // .innates = {ABILITY_FIGHT_SPIRIT, ABILITY_STRONG_JAW, ABILITY_QUICK_FEET},
    .ivs = {31, 31, 31, 31, 31, 31},
    .evs = {0, 252, 4, 0, 0, 252},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_ADAMANT,
    .moves = MOVE_PLAY_ROUGH, MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_HYPER_FANG
    .tags = Singles, Offensive
    .comment = Fighting Spirit turns Hyper Fang into a Fighting-type move (gets 20% boost). If you get statused, Quick Feet activates and gives you 50% more speed.
    }
Talonflame
{
    name = Nuke Pivot
    item = Heavy-Duty Boots / Choice Band
    ability = Big Pecks
    evs = 4, 252, 0, 0, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Adamant
    moves = Flare Blitz, Brave Bird, U-turn, Roost 
   comment = This set’s main purpose is to hit the field quick, deal a lot of damage, and leave the field just as fast. High BP contact moves to take advantage of Big Pecks, Flock and Violent Rush, U-turn for pivoting and Roost to stay healthy. 
   
   Heavy-Duty Boots can be exchanged for Choice Band if you feel confident that residual damage won't be a problem.
    .tags = Singles, Offensive
}
Forretress
{
    name = Steel Sentry
    item = leftovers
    ability = stamina
    evs = 252, 0, 252, 0, 4, 0 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = relaxed
    moves = body press, gyro ball, protect, toxic
   comment = Foretress embraces a Relaxed nature to excel in defensive capabilities. Its moveset further reinforces its defensive prowess, including Body Press and Gyro Ball, which take advantage of its impressive Defense stat to deal damage based on its defense and low speed stat, respectively. 
   
   Protect ensures added protection, allowing Foretress to stall for Leftovers recovery. Meanwhile, Toxic can cripple foes over time, making it an excellent choice for a defensive Pokémon that can withstand attacks and gradually wear down adversaries. 
    .tags = Singles, Defensive
}
Audino
{
   .name = Infinite HP
   .item = Audinite
   .ability = Cute Charm
   .evs = 252, 0, 124, 10, 124, 0
   .nature = Bold
   .moves = Draining Kiss, Calm Mind, Wish, Soft-Boiled / Recover
   .comment = Enter battle, use Audinite to go Mega and get ready to something really simple.

You have 2 main heals (Wish and Soft-Boiled) and a 3rd one that is also an offensive move (Draining Kiss). They all work in different ways so you can stack both for 100% in a single turn or 50%+dmg+some extra heal while you always live dangerously until you reach SpAtk levels high enough, thanks to Calm Mind, to become a real menace.

Mega Audino here is quite tanky and has a good SpAtk base so find a Pokémon that can't kill you (and those exists a lot; Mega Audino can tank a bunch of physical mons while burned and cursed(!)), and heal here and there while you use Calm Mind in the middle of those. Since you can heal for 100% after 2 turns whenever you need, you just need to make sure that you can survive the hit.
   .tags = Singles, Doubles, Troll
}
Nidoking 
{
name = Giga Sweeper
item = Focus Sash
ability = Poisonate
evs = 6, 252, 0, 0, 0, 252  // HP, Atk, Def, Sp.Atk, Sp. Def, Speed
nature = Jolly
moves = Giga Impact, High Horsepower, Dragon Dance, Wicked Blow
comment = With Giga Impact boosted by Poisonate & Rampage preventing a recharge if you get a KO.
}
SPECIES_SIRFETCHD
{
    name = Leek Hero
    item = leek
    ability = chlorophyll
    evs = 252, 252, 4, 0, 0, 0// HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = adamant
    moves = meteor assault, solar blade, Dual Wingbeat / Bave Bird, first impression
    comment = Firstly, use a Pokemon with Drought (or manually setup Sun) to activate Sirfetchds Chlorophyll, allowing it to outspeed most Pokemon. Meteor Assault as STAB. Thanks to Rampage, it has no recharge after a KO. Solar Blade, along with Dual Wingbeat / Brave Bird for coverage, and First Impression as priority move and Revenge-Killer for Psychic Types.
    tags = Singles, Offensive
}
Hydreigon
{
    name = Three Strikes, You're Out!
    item = Choice Scarf
    ability = Mega Launcher
    evs = 0, 0, 0, 252, 4, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Timid / Modest
    moves = Dark Pulse, Dragon Pulse, Flash Cannon / Focus Blast, U Turn
   comment = All moves are boosted by Mega Launcher, except U-turn. Dragon Pulse hits slightly harder than Draco Meteor (5 BP difference) without the drawback of an SpAtk drop after use. For coverage, Flash Cannon is preferable for Fairies, but if for some reason you wanted to nuke anything weak to Fighting (or just any non-Fighting resist in general), there's a 180 BP Focus Blast. ¯\_(ツ)_/¯
}
Meganium
{
    name = Nature's Medic
    item = kebia berry
    ability = triage
    evs = 252, 0, 252, 6, 0, 0// HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = modest
    moves = giga drain, draining kiss, synthesis, heal pulse
   comment = Meganium's moveset includes Giga Drain and Draining Kiss, which not only deals damage but also provides valuable sustain, making it a reliable healer. Synthesis grants it further recovery, while Heal Pulse lets it support its allies when needed. The Kebia berry helps to reduce Poison-Type moves.

Meganium is best suited with a Sun team to activate one of its innates: Big Leaves to power up SpAtk and keep harvesting Kebia berry.
    .tags =Doubles, Defensive, Mixed
}
cacturne
{ 
    name = One Punch Plant
    item = life orb 
    ability = sand rush
    evs = 0, 252, 0, 0, 4, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = adamant
    moves = wicked blow, sucker punch, needle arm, Destiny Bond / Swords Dance
   comment = Boasting one of the strongest Wicked Blows in the game while still having great speed in sandstorm, it needs no boosts outside of STAB, Nocturnal and Life Orb to one-shot anything not resisted or very defensive, but if you need that extra bit of damage you can use swords dance over destiny bond.
   
   Sucker punch is in case you can't outspeed or sandstorm is gone, and Needle Arm is for STAB Grass and flinches. Destiny bond is in case you know you can't kill with Wicked Blow and will go down that turn.
    .tags = Singles, Offensive
}
Alakazam Mega
{
name = Almighty STAB
item = Alakazite
ability = Mystic Power
evs = 0, 0, 0, 252, 4, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
nature = Timid
moves = Psyshock, Calm Mind, Shadow Ball, Focus Blast 
comment = He will always have STAB thanks to Mystic Power. Inner Focus will boost Focus Blast's accuracy to 90% instead of 70% making him an absolutely busted Glass Cannon.
}
Torterra
{
    Name = Shell Smash in the Sun
    Item = Sitrus Berry
    Ability = Stamina
    EVs = 130, 252, 0, 0, 0, 124
    Nature = Adamant
    Moves = Shell Smash, Solar Blade, Earthquake / High Horsepower, Stone Edge
    Comment = Sun is mandatory for this set to work, as otherwise, Torterra is too slow to outspeed the threats it needs to surpass. Stamina is here to make its setup easier against physical attackers and can counteract the defense drop from Shell Smash.

    Sitrus Berry is included to heal Torterra during its setup and take advantage of its innate Big Leaves ability to restore the berry. The EVs are tailored to ensure that Torterra has enough speed to outpace Chlorophyll-boosted threats and enough bulk to execute its setup.

    If Mimikyu, Focus Sash, Sturdy, or Multiscale/Shadow Shield users are a concern, Bullet Seed can replace Solar Blade. If you're playing on Grassy Terrain alongside the sun or in Doubles, High Horsepower is recommended instead of Earthquake.

    Strength is chosen for more accuracy and PP than Stone Edge, but be cautious of defense drops, which can leave you vulnerable to priority moves. Rock Slide is a safer option than Strength and Stone Edge, and it also has a chance to flinch opponents, which is advantageous. However, it's weaker unless you're using Sheer Force, in which case your setup becomes more challenging without Stamina.

    While Rough Skin can inflict chip damage on opponents, Stamina is preferred since it boosts your defense when you take hits. Sheer Force is a viable choice if you have Rock Slide; otherwise, it's not as effective.

    Regarding Berries, while Sitrus is the best option in my opinion, you can experiment with riskier yet more rewarding berries like Salac or Liechi.
    Tags = Singles, Doubles, Offensive
}
Honchkrow
{
    Name = No brain needed
    Item = Choice Band
    Ability = Moxie
    EVs = 252, 252, 0, 0, 6, 0
    Nature = Adamant
    Moves = Wicked Blow, Dual Wingbeat, Superpower, Sucker Punch
    Comment = Sucker Punch for quick knockouts, Moxie for sweeping.
    Tags = Singles, Doubles, Offensive
}
Mismagius
{
    name = Go to Therapy
    item = choice scarf
    ability = bad luck
    evs = 0, 0, 0, 252, 4, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = modest
    moves = Hyper Voice, shadow ball, dark pulse, mystical fire
   comment = A potent nuker with fairly broad coverage. Often utilizes Pixilate-boosted Hyper Voice to secure victories.
}
Trevenant
{
    Name = Please don't disturb the Tree
    Item = Aguav Berry
    Ability = Grassy Surge
    EVs = 252, 0, 0, 0, 252, 0 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    Nature = Careful
    Moves = Substitute, Leech Seed, Curse, Protect
    Comment = Watch opposing trainers become bewildered by this formidable wooden wall. Determining the optimal move sequence can be challenging, as it depends on the opposing Pokémon.

With Substitute you'll lose some HP but you'll regain them with Leech Seed in one or two turn using Protect and Grassy Surge. At this point you should be in range of using Curse, this will cost half of your HP. Since Trevenant is pretty slow you'll be able to figure out which move to use so that Trevenant doesn't get knocked out and the stall strategy continues. Once he reaches around 1/4 of his total HP Trevenant will eat his berry gaining a lot of HP (even right after he used Substitute or Curse), but thanks to Harvest among his innates, he will be able to recycle his berry with a 50% chance (100% chance under the sun, which is recommended). 
}
araquanid
{
    name = Special Attacker be-gone
    item = leftovers
    ability = Water Veil
    evs = 252, 4, 0, 0, 252, 0 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = adamant
    moves = liquidation, leech life, protect, curse
   comment = Can go in on any neutral special hit and set up with Curse to tank physical hits. Water Veil for recovery, then hit very hard with Water Bubble Liquidation with the added bonus of burn immunity.
    .tags = Singles, Mixed
}
Leafeon
{
    name = Leafeon is special!
    item = Life Orb
    ability = Avenger
    evs = 0, 0, 6, 252, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Modest
    moves = Solar Beam, Flamethrower, Giga Drain, Power Gem
   comment = Use it in a Sunny Day/Drought team. Set the weather with your lead and play cool, when your Pokémon goes down it'll be Leafeon's moment. Avenger in combination with Big Leaves and Feline Prowess will ensure a devastating first special move. Leafeon can learn Solar Beam & Giga Drain but you have to transform it into Flareon and Espeon in order to learn Flamethrower and Power Gem for a good coverage against Bug, Steel and Flying Pokémon. 
   
   Leafeon is a nice Grass cannon... get it?
}
Sunflora 
{ 
    name = Radical Red Sunflora but better 
    item = Choice Specs
    ability = Drought
    evs = 0, 0, 0, 252, 4, 252// HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = timid
    moves = solar beam, sludge bomb, mystical fire, earth power
   comment = Thanks to having permanent Drought, Chlorophyll and Solar Power all at once, it allows instant charging Solar Power, and hitting hard with the other moves with Choice Specs + Solar Power while outspeeding some threats thanks to Chlorophyll. 

Alternatively, Choice Scarf can be used instead of Choice Specs to increase the Speed even further in exchange of its power.

It's also a very important core to Sun Teams because of Drought, so that Pokémon without Chloroplast that have abilities like Solar Power, Chlorophyll or Harvest can be used to their full potential.
    .tags = Singles, Troll, Offensive
}
accelgor
{ 
    name = Mixed Momentum Attacker
    item = life orb
    ability = momentum
    evs = 252, 0, 0, 4, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = timid
    moves = leech life, frustration, sucker punch, water shuriken
    comment = Momentum coupled with it's honestly absurd Speed makes it both hit super hard and be super fast while still being able to invest in bulk to take a hit or two. Water Shuriken is there to activate Protean and take a Fire-type move you would never be able to take even when neutral.
    .tags = Singles, Offensive
}
Starmie
{
    name = Bulky Superstar
    item = Expert Belt / Choice Specs
    ability = Mystic Power
    evs = 252, 0, 0, 252, 6, 0 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = quiet
    moves = psychic, ice beam, thunderbolt, hydro pump
    comment = With Mystic Power giving BoltBeam STAB (though it can be changed to Thunder and Blizzard for more power and better accuracy because of Victory Star), 0 IVs and Quiet Nature to make the most off Analytic, this Starmie will always deal a lot of damage. Item of choice can differ between Expert Belt to deal more damage on super-effective moves, or Choice Specs to lock to one move. This is not ideal as a main Trick Room sweeper, as it is still fast enough to possibly outspeed slower threats.
    .tags = Singles, Offensive
}
Galvantula
{
    .name = Spider Lair Lead
    .lvl = 0,
    .species = SPECIES_GALVANTULA, // Wattson, Sash, Spider Lair
    .heldItem = ITEM_FOCUS_SASH,
    .ability = 2, // ABILITY_COMPOUND_EYES, ABILITY_LOOTER, ABILITY_SPIDER_LAIR},
    // .innates = {ABILITY_IMMUNITY, ABILITY_SWARM, ABILITY_OVERCOAT},
    .ivs = {31, 0, 31, 31, 31, 31},
    .evs = {0, 0, 0, 252, 4, 252},      // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
	.nature = NATURE_TIMID,
    .moves = MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL
    .comment = A true classic for Galvantula - sets up Sticky Web on entry, then decide if you want to attack normally or Volt Switch out into a better Pokémon.
    .tags = Singles, Offensive
    }
galvantula
{ 
    name = Kamikaze Spider
    item = focus sash
    ability = compound eyes
    evs = 4, 0, 0, 252, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = modest
    moves = thunder, bug buzz, protect, sticky web
    comment = Will take a hit from anything without any multi-hit abilities, moves, or Fake Out, hit something, possibly set up Sticky Webs, then die to get a safe switch into something else. Best used for Weather setters when your Weather setter is too fast to lead with. Can be Timid when opposing lead is faster than it when Modest. Protect is there to stall out Air Blower or Twist. Dimension.
    .tags = Singles, Offensive
}
lurantis
{
    name = Budget Serperior
    item = life orb
    ability = contrary
    evs = 4, 0, 0, 252, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = modest
    moves = leaf storm, hidden power ground, weather ball, air slash
   comment = What it says on the tin. Requires sun to function due to it's low base speed and reliance on Weather Ball. Has slightly more power and no quad weakness to Ice Shard but has much less bulk compared to Serperior.
    .tags = Singles, Offensive
}
seviper
{
    name = Priority Attacker
    item = dark gem 
    ability = Hyper Aggressive 
    evs = 0, 252, 4, 0, 0, 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = adamant
    moves = Crunch, Poison Fang, Sucker Punch / Dragon Dance, Fire Fang / Ice Fang / Thunder Fang / Psychic Fangs
   comment = Seviper puts its massive fangs to use in Elite Redux. It is one of two Pokemon, alongside Steelix, with the combination of Strong Jaw and Coil Up. With Strong Jaw, Crunch becomes a one-turn 120 BP priority STAB move, boosted further by Hyper Aggressive and Dark Gem. Solenoglyphs means Seviper will usually add poison to what it doesn't OHKO. Sucker Punch and Dragon Dance both give Seviper additional Speed control outside of Coil Up. The last slot is customizable based on what team you'll be facing; use it to exploit 4x weaknesses!

Seviper relies heavily on Coil Up, so it needs to weave in and out of battle. Pair it with slow pivots or Eject Button Pokemon to create opportunities to bring it in safely. Seviper uses all of its ability options well. If you have Toxic Spikes or Sticky Web support, Merciless will out-damage Hyper Aggressive. Opportunist provides the least immediate damage, but Seviper can consistently put all but the bulkiest threats in range with the first Coil Up hit, securing a second turn of priority. Seviper can also forsake the Speed EVs for HP as needed, especially on sets with Opportunist.

Watch out for Pokemon with Dazzling or Queenly Majesty. Also be wary of faster priority users, Steel-types that resist Dark like Bisharp, and other Dark/Poison-types, which may require slotting in Earthquake into the moveset.
}
Runerigus
{
    name = Your Idol sign is B
    item = leftovers
    ability = Ancient Idol
    evs = 252, 0, 252, 0, 4, 0 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Impish
    moves = earthquake, poltergeist, Will-O-Wisp, body press
   comment = With the Ancient Idol ability, Runerigus gains a significant advantage in its offensive potential, utilizing its Defense stat as its main attack stat. Runerigus can really be a great physical tank with Will-O-Wisp and Leftovers. 
}
Swellow
{ 
    name = Air Blower Sweeper
    item = choice specs
    ability = air blower
    evs = 0, 6, 0, 252, 0 , 252 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = timid
    moves = Boomburst, Hurricane, Heat Wave, U-turn
   comment = Can destroy almost any non-resistant Pokémon with Boomburst. Heat Wave is a good coverage against Steel (resists both Boomburst and Hurricane), U-turn to outspeed anything and switch out to a Pokémon that can resist/be immune to the opponent's upcoming move while doing chip damage.
    .tags = Singles, Doubles, Offensive
}
Centiskorch
{
    name = First Impression but better
    item = choice band
    ability = coil up
    evs = 252, 252, 4, 0, 0, 0 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = adamant
    moves = bug bite, fire fang, thunder fang, crunch
   comment = Coil Up in combination with Choice Band allows it to near guarantee a kill on anything that isn't a physical wall. 
    .tags = Singles, Offensive
}
Marowak
{
    name = Bonebreaker
    item = thick club
    ability = skill link
    evs = 252, 252, 0, 0, 0, 4// HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = adamant
    moves = bone rush, head smash, knock off, swords dance
   comment =Marowak's moveset includes Bone Rush which benefits from its ability to ignore immunities and deal double damage even on targets that resist bone-type moves. Bone Rush is also a +1 priority move in Elite Redux. Knock Off is a useful utility move to remove opponents' items, and Swords Dance boosts Marowak's Attack to absurdly high levels.
    .tags =Singles, Offensive
}
chansey
{
    name = Wish Pivot
    item = eviolite
    ability = regenerator
    evs = 252, 0, 252, 0, 4, 0
    nature = relaxed
    moves = wish, teleport, seismic toss, protect
   comment = With Generation 8 Teleport, Chansey makes an incredibly potent pivot. A previous upside to its main competitor, Blissey, was Blissey's ability to use Heavy Duty Boots to avoid getting chipped by Stealth Rocks. Now, due to Regenerator, Chansey has little to fear from entry hazards, resolving one of the major downsides to its use. 
   
   Wish + Teleport are the core moves of the build, allowing Chansey to pass a slow Wish to a weathered teammate, giving it another chance to sweep or maximizing its defensive utility. Seismic Toss makes Chansey slightly less passive against Taunt. Protect allows Chansey to reap the benefits of Wish without taking another attack. 
   
   However, since Chansey has Regenerator and infamously massive bulk and is still passive despite Seismic Toss, there are many other options to replace Protect or Seismic Toss that can be useful depending on its teammates. Stealth Rock allows Chansey's teammates to bypass Focus Sash and Sturdy, Thunder Wave or Toxic can neuter opposing offensive or defensive threats, Heal Bell provides its teammates valuable status removal, Light Screen or Reflect alongside a Wish can provide a teammate an important setup opportunity, and situationally against weather teams, Chansey can even use Sunny Day or Rain Dance to change the weather. 
   
   The final two move slots are highly malleable, and although Seismic Toss and Protect are the default moves given, the user can and should adapt Chansey to their playstyle, team, and opponents to maximize its effectiveness in every battle.
    .tags = Singles, Defensive
}
Torterra
{
    name = Body Press Sustain
    item = Sitrus Berry
    ability = Stamina
    evs = 252, 0, 252, 0, 4, 0// HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Bold/Calm
    moves = Leech Seed, Body Press, Synthesis, Amnesia / Stockpile
   comment = Aim of this set is to take in resisted hits while using Amnesia or Stockpile to make Torterra virtually unkillable short of a critical hit due to Big Leaves Sitrus Berry and Synthesis. Stamina will keep boosting Defenses and will continuously amp the damage from Body Press. If you don't need +6 SpDef you can opt for Stockpile so that you can reach +6 Def sooner. Because of Big Leaves, Synthesis will heal for 75% health, but be aware of the limited PP. Sitrus Berry for survival, but you can opt for things like Yache, Occa, or Coba Berry as well, which will be all be harvested due to Big Leaves. Depending on who you're fighting against, you can put EVs from Defense into SpDef.
}
Ursaring
{
    name = The Pain Train
    item = Flame Orb
    ability = Tough Claws
    evs = 6, 252, 0, 0, 0, 252
    nature = Jolly
    moves = Protect, Facade, Close Combat / Frustration, Crunch / Psychic Fang
   comment = Protect to set up burn and Facade to your heart's content. Fighting coverage will help with those pesky normal resist walls and situationally Crunch for Ghost types and Psychic Fang to break through screens.
    .tags = Singles, Offensive
}
Magcargo
{
    name = Shell Smash Sweeper
    item = Focus Sash
    ability = Simple
    evs = 6, 0, 0, 252, 0, 252
    nature = Timid
    moves = Shell Smash, Flamethrower / Heat Wave, Power Gem, Earth Power
   comment = Partnered with a Stone or Spike setter this pokemon can Decimate the opposition. Just watch out for priority after you've set up as you likely be very low if not at 1 HP after setting up and don't try to set up on anything with hyper aggressive or Opportunist. This set up only offers one chance
    .tags = Singles, Offensive, Troll
}
Umbreon
{
    name = Physical Regen Stall
    item = Leftovers
    ability = Self Sufficient 
    evs = 252, 0, 130, 0, 128, 0
    nature = Calm
    moves = Acid Armor, Aqua Ring, Leech Seed, Toxic
   comment = Can take care of a lot of targets once defenses and regeneration are up especially physical enemies but can be shut down hard by Taunt and Crit abusers as well as Grass Poison and Grass Steel types
    .tags = Singles, Defensive, Troll
}
Typhlosion
{
    name = Choice Spec Eruption
    item = Choice Spec
    ability = Earthbound
    evs = 6, 0, 0 , 252, 0, 252
    nature = Timid / Modest
    moves = Eruption, Earth Power, Extrasensory / Weatherball, Aura Sphere / Weatherball
   comment = Very simple set, send Typhlosion out and nuke things with Eruption or one of your coverage moves, watch out for Entry Hazards. You can swap Extrasensory or Aura Sphere for Weatherball if you are running a Sandstorm team.
    .tags = Single, Offensive
}
Skarmory
{
    name = Bulky Suicide Lead
    item = Leftovers
    ability = Sturdy
    evs = 188, 0, 188, 0, 0, 134
    nature = Jolly
    moves = Stealth Rocks, Spikes / Defog, Air Cutter / Body Press, Protect / Roost
   comment = This Set is almost guaranteed to set at least one this up before going down and has enough utility to do things like stalling out weather, clearing opposition entry hazards and breaking their entries Focus Sash
    .tags = Single, Doubles, Defensive
}
Espeon
{
    name = Nuclear Kitty
    item = Choice Scarf
    ability = Sage Power / Soul Heart
    evs = 0, 0, 0, 252, 6, 252
    nature = Timid
    moves = Psychic / Psyshock, Muddy Water, Shadow Ball / Dark Pulse, Freeze Dry
   comment = This Kitty will hit hard and fast. The ability is personal preference on whether you want to hit hard or if you want to build momentum.
    .tags = Singles, Offensive
} 
Furret
{
    name = The Fuzzy Wuzzy Physical Wall
    item = Leftovers / Big Root
    ability = Adaptability 
    evs = 0, 252, 252, 0, 0, 6
    nature = Impish
    moves = Coil, Drain Punch, Cut, Return
   comment = Send in on a physical attacker, Coil up and start Drain Punching if your HP starts getting too low. Great early game pokemon that can put some work in for your team.
    .tags = Single, Double, Defensive, Offensive 
} 
Furret
{
    name = The Fuzzy Wuzzy Baton Passer
    item = Leftovers
    ability = Adaptability
    evs = 0, 0, 252, 0, 252, 6
    nature = Impish
    moves = Coil, Drain Punch, Amnesia, Baton Pass
   comment = Coil on a physical attacker, Drain punch to heal as needed and Amnesia until you are ready to pass over to the wrecking ball of your choice.
    .tags = Single, Double, Defensive, Troll
}
Chandelure
{
    name = Candle of doom
    item = Choice Scarf
    ability = Flash Fire / Infiltrator
    evs = 4, 0, 0, 252, 0, 252
    nature = Timid
    moves = Fire Blast, Shadow Ball, Energy Ball, Psychic / Trick / Heat Wave
   comment = Pyromancy gives Fire Blast 50% chance to burn. Illuminate makes Fire Blast 100 accurate. Every possible speed investment + scarf allows Chandelure to outspeed a lot of things, then wreak havoc with Fire Blast. Other moves are for coverage. Psychic can be switched for Trick to cripple or Heatwave for doubles.
}
Banette-mega
{
name = Offensive PranksterBond
item = Banettite
ability = Cursed Body / Insomnia
evs = 252, 252, 0, 0, 0, 0 (0 Speed IVs but not sure where to put that)
nature = Brave
moves = Destiny Bond, Spectral Thief, Shadow Sneak, Double Edge
comment = A potent counter sweeper, Banette-Mega has the potential to force trades with Prankster Destiny Bond. It can also punish Destiny Bond counterplay by stealing boosts and punishing switches with Spectral Thief and drawbackless Double Edge.
}
Mew
{
    name = Dance Party
    item = Life Orb
    ability = Magic Guard
    evs = 0, 0, 4, 252, 0, 252
    nature = Timid
    moves = Quiver Dance, Roost, Stored Power, Aura Sphere
    comment = It's Mew with Quiver Dance, which boosts its already decent special stats. Roost keeps it healthy enough to get Stored Power to incredible levels, and Aura Sphere provides coverage. 

Alternatively, a physically defensive EV spread can be used, further easing it's setup against a wider variety of pokemon.
}
Arcanine 
{
    Name = Physical Pivot 
    Item = Heavy Duty Boots
    Ability = Intimidate 
    EVs = 252, 252, 4, 0, 0, 0 
    Nature = Adamant 
    Moves = Flare Blitz, Bulldoze, Morning Sun, Teleport 
    Comment = With access to Intimidate and Teleport, Arcanine becomes a valuable pivot against physically oriented Pokémon, while maintaining offensive presence.
}
Hoopa
{
    Name = Annoying Special Attacker 
    Item = Life Orb 
    Ability = Illusion 
    EVs = 252, 0, 0, 252, 0, 0 
    Nature = Quiet
    Moves = Destiny Bond, Hypnosis, Hyperspace Hole, Focus Blast
    Comment = Hoopa serves as a very annoying special attacker with its combination of Prankster-boosted Hypnosis, Destiny Bond, and the priority move Hyperspace Hole. Focus Blast deals with Dark-types, Hoopa's main weakness.
}
Florges
{
    Name = Specially Defensive Wall 
    Item = Leftovers
    Ability = Fairy Aura
    EVs = 248, 0, 0, 8, 252, 0 
    Nature = Calm
    Moves = Moonblast, Wish, Teleport, Toxic
    Comment = An incredibly durable special wall, Florges supports teammates by passing slow Wishes and wearing down opponents with status and potent Moonblasts.
}
Sableye Mega
{
    Name = Defensive Utility 
    Item = Sablenite 
    Ability = Soul Linker 
    EVs = 252, 4, 0, 0, 252, 0
    Nature = Careful 
    Moves = Knock Off, Wil-o-Wisp / Thunder Wave, Taunt, Recover 
    Comment = This versatile utility set uses Knock Off to deny items, spreads status with Wil-o-Wisp or Thunder Wave, and disrupts opponents' hazard setting and removal with Taunt
}
Mewtwo-mega-y
{
    Name = Nuclear Warhead
    Item = Mewtwonite Y
    Ability = Psychic Surge
    EVs = 0, 0, 4, 252, 0, 252
    Nature = Timid
    Moves = Expanding Force, Blizzard / Thunder, Shadow Ball / Focus Blast, Nasty Plot
    Comment = A formidable special attacker, Mega Mewtwo Y sets up with Nasty Plot to become a destructive force against opposing teams.
}
Slurpuff
{
    name = Suicide Lead
    item = Focus Sash
    ability = Unburden
    evs = 0, 0, 0, 252, 0, 252 (0 IVs in both Defenses)
    nature = Hasty
    moves = Sticky Web, Yawn, Endeavor, Misty Explosion
    comment = A good hazard lead that gets Sticky Web up and then cripples something on its way down.
}
Steelix
{
    name = Great Wall of Johto
    item = Leftovers
    ability = Impenetrable / Fort Knox
    evs = 252, 252, 4, 0, 0, 0
    nature = Adamant
    moves = Double Edge / Body Press, Dragon Tail, Stealth Rock, Shore Up
    comment = Nigh unbreakable physically, sets rocks and annoys things by phasing them onto said rocks. Groundate recoil-free double edge hits like a truck and punishes things that want to stay in and defog on him. Alternatively, Fort Knox and Body Press can achieve similar results, though it takes a turn of defog to set up. Replace attack EVs with defense EVs if you choose this option. Shore up keeps him healthy, allowing him to reset Stealth Rock if the opponent removes it.
}
Zapdos
{
    name = Zap Rain
    item = Heavy Duty Boots
    ability = Drizzle
    evs = 248, 0, 8, 252, 0, 0
    nature = Modest
    moves = Roost, Defog, Hurricane, Volt Switch / Thunder
    comment = Solid rain setter, hazard control, and pivot. Roost keeps him healthy, Heavy Duty Boots protect him from the rocks he wants to remove, Hurricane takes advantage of the rain, and Volt Switch allows him to pivot into a teammate ready to abuse his rain. You could run Thunder over Volt Switch for more power, but this detracts from his utility as a rain setter.
}
Giratina-Origin
{
    name = Twist Dim. Attacker
    item = Griseous Core
    ability = Twist Dimension
    evs = 252, 4, 0, 252, 0, 0 (any combination of Atk and Spa)
    nature = Quiet / Brave
    moves = Spectral Thief, Draco Meteor, Recover, Toxic
    comment = One of the few Mons capable of viably running a mixed set, Twist Dimensions allows it to run a -spe nature, letting it not have to choose between bulk or power. Toxic+Recover lets it serve as a general answer to many things, spectral thief allows it to steal boosts, and Draco Meteor offers immediate power.
}
Groudon-primal
{
    Name = THE PAIN TRAIN 
    Item = Red Orb
    Ability = Tough Claws 
    EVs = 0, 252, 0, 0, 4, 252 
    Nature = Adamant 
    Moves = Swords Dance, Rock Polish, Precipice Blades, V-create / Strength / Heat Crash 
    Comment = "And the lord wept, as he looked down upon the earth and witnessed the scorched bodies, entire towns swallowed up by the earth... and at the center of it all, a raging, primordial beast." - Book of Groudon, Chapter 0
}
Zapdos-Galar
{
    name = Swift Scarf
    item = Choice Scarf
    ability = Aerodynamics
    evs = 0, 252, 0, 0, 4, 252
    nature = Jolly
    moves = Thunderous Kick, Bolt Beak, Brave Bird, U-turn
    comment = A decent revenge killer or speed control option, capable of outspeeding all unboosted Pokémon except Deoxys-S. Thunderous Kick provides solid Fighting STAB, Bolt Beak essentially functions as a third STAB, hitting hard due to Zapdos usually moving first, and Brave Bird is present but is generally not the best choice to click. U-turn allows Gapdos to pivot against opponents that don't want to be revenge killed or can threaten it with strong priority.
}
Kyurem-Black
{
    name = DDance Sweeper
    item = Heavy Duty Boots
    ability = Refrigerate
    evs = 4, 252, 0, 0, 0, 252
    nature = Adamant
    moves = Dragon Dance, Bolt Strike, Outrage, Extreme Speed/Return
    comment = An enormously powerful sweeper, known for its incredible Ice/Electric coverage. Dragon Dance boosts its already impressive Attack to formidable levels, Bolt Strike serves as a devastating attack, and Refrigerate Extreme Speed provides excellent Ice STAB and strong priority.
}
Regigigas
{
    name = Offensive Tank
    item = Assault Vest
    ability = Raging Boxer
    evs = 252, 4, 252, 0, 0, 0
    nature = Impish
    moves = Powerup Punch, Drain Punch, Mega Punch, Frustration
    comment = Regigigas is an immensely bulky beast, capable of fully investing in bulk while still dealing significant damage due to Juggernaut and Power Core boosting its offense based on its Defense. Power-up Punch and Drain Punch offer incredible utility when combined with Raging Boxer, allowing it to boost its Attack, sustain itself, and hit Steel types it would otherwise struggle against. Frustration hits Ghost-types that otherwise counter it, and Mega Punch serves as its strongest STAB move with Raging Boxer.
}
Kyogre-Primal
{
    name = THE PAIN BOAT
    item = Blue Orb
    ability = Predator (pre-Mega)
    evs = 0, 0, 0, 252, 4, 252
    nature = Timid
    moves = Hydro Pump, Sheer Cold, Water Spout / Thunder / Substitute, Calm Mind
    comment = And the people wept with joy as the rains fell, soothing their dry, sun-scorched lands. But their joy soon turned to terror as the downpour intensified, the scalding primordial beast drowning all beneath its waves - Book of Kyogre, Chapter 0
}
Piloswine
{
    name = THICCOswine
    item = Eviolite
    ability = Fur Coat
    evs = 252, 4, 252, 0, 0, 0
    nature = Impish
    moves = Earthquake, Ice Fang, Rest, Sleep Talk
    comment = With Eviolite and Fur Coat, Piloswine becomes an absolute behemoth on the physical side, capable of walling nearly any physically oriented set it encounters. Earthquake is its strongest STAB, Ice Fang is a secondary STAB that both complements Earthquake well and allows it to set up its mediocre attack stat. Rest serves as it's only form of recovery, with Sleep Talk allowing it to potentially maintain offensive pressure. DAMN BOII HE THICC
}
Registeel
{
    name = Special Tank
    item = Leftovers
    ability = Steely Spirit
    evs = 252, 0, 4, 0, 252, 0
    nature = Calm
    moves = Recover, Stealth Rock, Toxic, Steel Beam
    comment = An extremely resilient special wall, it sets up hazards and annoys foes with Toxic, all while delivering surprisingly strong drawback-less Steel Beams.
}
Tapu-Bulu
{
  name = Regenvest Pivot
  item = Assault Vest
  ability = Grass Pelt
  evs = 252, 252, 4, 0, 0, 0
  nature = Brave
  moves = U-turn, Wood Hammer, Nature's Madness, Sucker Punch
  comment = The combination of Grass Pelt and Assault Vest transforms Tapu Bulu into a solid pivot, allowing it to switch in, absorb hits, and then perform a slow U-turn into a teammate. Wood Hammer serves as a strong Grass STAB, further boosted by Tapu Bulu's Grassy Terrain. Nature's Madness can chunk a switch-ins health, and Sucker Punch gives it priority, allowing it to bypass it's slow speed to secure the KO on weakened targets.
}
Blastoise
{
    name = Regenvest
    item = Assault Vest
    ability = Regenerator
    evs = 252, 0, 0, 252, 4, 0
    nature = Modest
    moves = Rapid Spin, Flip Turn, Water Pulse, Ice Beam
    comment = Access to valuable utility moves in Flip Turn and Rapid Spin, decent natural bulk, and Mega Launcher boosted moves come together to make Blastoise effective at hazard control while also being able to deal decent damage. Water Pulse is its most consistent STAB and Launcher boosted move, although Hydro Pump or Water Spout are alternatives, at the cost of accuracy and consistency, respectively. Ice Beam provides helpful coverage, hitting Grass-types that Blastoise otherwise struggles against. A slow Flip Turn safely brings in allies, and Rapid Spin allows it to remove hazards from its side of the field.
}
Snorlax 
{
    name = this is not ok 
    item = choice scarf 
    ability = comatose 
    evs = 252, 0, 252, 0, 4, 0 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = bold 
    moves = sleep talk, whirlwind 
   comment = idk what this does. i guess it just does stuff and things happen. definitely 0 potential to be uncompetitive here, none 
}
Magearna
{
    name = Deer Repellent
    item = Leftovers
    ability = Pixilate
    evs = 252, 0, 0, 4, 252, 0
    nature = Calm
    moves = Heart Swap, Recover, Boomburst, Flash Cannon
    comment = Serving as a solid special wall, Magearna excels in stealing boosts with Heart Swap, effectively turning the sweeper into the swept.
}
Mandibuzz
{
    Name = Defog Support
    Item = Heavy Duty Boots
    Ability =Air Blower 
    EVs = 252, 0, 252, 0, 4, 0
    Nature = Impish
    Moves = Roost, Defog, U-turn, Foul Play / Knock Off
    Comment = A solid support Pokémon, capable of setting up Tailwind and removing hazards. Roost helps maintain its health, enabling multiple opportunities to come in and defog. Defog serves its purpose of hazard removal, while U-turn permits switching to a different ally while dealing minor chip damage. Foul Play is effective against physical Pokémon, whereas Knock Off provides additional utility.
}
Empoleon
{
    name = Offensive Rocker
    item = Heavy Duty Boots/Leftovers
    ability = Competitive 
    evs = 252, 0, 252, 4, 0, 0 
    nature = Bold
    moves = Roost, Stealth Rock, Scald, Ice Beam
    comment = A very cool Pokémon for setting up rocks. Its unique typing gives it a solid matchup against many Rapid Spin users, and its ability, Competitive, allows it to punish Defog, potentially boosting its Special Attack to extreme levels. It also annoys opponents with Scald burns and has a chance to cause frostbite if you're lucky.
}
Granbull
{
    name = Guts Princess
    item = Flame Orb
    ability = Guts
    evs = 0, 252, 0, 0, 0, 252
    nature = Adamant/Jolly
    moves = Facade, Crunch, Play Rough, Bulk Up / Fire Fang
    comment = With Guts and Quick Feet, Granbull becomes an incredible wallbreaker that's also decently fast. With an excellent offensive typing and a useful third pseudo STAB in Fighting Spirit, this mon is capable of hitting the majority of Pokémon for neutral STAB damage at the very least.
}
Gardevoir-mega
{
    name = Substitute+Calm Mind 
    item = Gardevoirite
    ability = Psychic Surge
    evs = 0, 0, 4, 252, 0, 252
    nature = Timid
    moves = Calm Mind, Substitute, Future Sight / Expanding Force, Moonblast / Hyper Voice
    comment = A pretty cool mon, Substitute helps to alleviate its terrible physical bulk by limiting how much damage it takes. Calm Mind allows her to boost both her SpA and SpD, increasing both her damage output and staying power on the special side. Moonblast is her strongest Fairy STAB, although Hyper Voice can be used to bypass opposing substitutes. Future Sight allows her to attack while setting up or help overwhelm walls with multiple attacks per turn, while Expanding Force offers more immediate power.
}
Silvally
{
    name = Demi-God Ekiller
    item = Silk Scarf / Life Orb / Leftovers
    ability = Unaware
    evs = 248, 252, 0, 0, 0, 0 
    nature = Adamant
    moves = Extreme Speed, Frustration / Shadow Claw, Recover, Swords Dance / Parting Shot
    comment = An excellent selection of abilities, as well as access to STAB and Adaptability-boosted Extreme Speed, make Silvally a fantastic revenge killer. It can also function as a decent Unaware wall and pivot with Parting Shot, making this mon ideal for role compression.
}
Mew
{
    name = Cool Set, It's Mine Now
    item = Choice Scarf / Leftovers
    ability = Imposter
    evs = 252 HP, 0 Atk, 0 Def, 0 SpA, 0 SpD, 0 Spe/generally irrelevant except for HP
    nature = Irrelevant
    moves = Irrelevant
    comment = With more than double the HP of Ditto, Mew makes a far better abuser of Imposter. Its decent HP stat means it can potentially run Leftovers and make use of fatter mons' own recovery or offensive mons' setup, while a more traditional Choice Scarf allows it to easily revenge kill many boosted or weakened threats.
}
Jolteon
{
    name = Big Zaps 
    item = Choice Specs / Life Orb
    ability = Electro Surge
    evs = 0, 0, 4, 252, 0, 252
    nature = Timid
    moves = Rising Voltage, Volt Switch, Ice Beam, Earth Power
    comment = A strong Rising Voltage abuser, it also has incredible coverage options as an Eeveelution, learning Ice Beam from Glaceon and Earth Power from Leafeon.
}
Vaporeon 
{
    name = Specially Defensive 
    item = Leftovers 
    ability = Regenerator 
    evs = 252, 0, 0, 4, 252, 0 
    nature = Calm
    moves = Scald, Strength Sap, Toxic, Teleport / Ice Beam 
    comment = Vaporeon excels as a special wall due to her solid defensive stats, valuable abilities like Water Veil and Regenerator, and her reliable Water typing. Scald and Strength Sap are preferred to enhance her matchup against physical attackers by reducing their damage output. Toxic handles threats that can't be dealt with using Scald, while Teleport is useful for safely switching in an ally. Ice Beam can also be used to broaden her coverage and potentially Frostbite special targets.
}
Flareon
{
    name = Guts Attacker 
    item = Toxic Orb
    ability = Guts
    evs = 0, 252, 0, 0, 4, 252 
    nature = Adamant 
    moves = Flare Blitz / Blaze Kick, Leaf Blade / Wild Charge, Icicle Crash / Triple Axle, Swords Dance / Extreme Speed
   comment = The very definition of live fast, die hard. Flareon is an absolute monster, blowing as many holes in as many things as it can, before inevitably succumbing to it's toxic orb or recoil damage.
}
Espeon 
{
    name = Big Psychic 
    item = Choice Specs / Life Orb / Choice Scarf 
    ability = Psychic Surge
    evs = 0, 0, 4, 252, 0, 252
    nature = Modest / Timid 
    moves = Expanding Force, Moonblast / Focus Blast, Fire Blast / Flamethrower / Overheat, Volt Switch 
    comment = Similar to its cousin Jolteon, Espeon benefits from setting its own terrain for a terrain-boosted move. Being an Eeveelution grants it an extensive pool of coverage options. Its naturally high speed and ability to set Psychic Terrain make it excellent for speed and priority control, outpacing all unboosted Pokémon and suppressing priority moves. This synergy also complements its Avenger ability, allowing it to function as a potent revenge killer. Alternatively, Choice Specs or a Life Orb can significantly bolster Espeon's power, turning it into a formidable wallbreaker.
}
Umbreon 
{
    name = No Taunt Pls
    item = Leftovers 
    ability = Soul Linker
    evs = 252, 0, 252, 0, 4, 0 
    nature = Bold
    moves = Strength Sap / Wish / Moonlight, Toxic / Leech Seed, Taunt, Teleport 
   comment = Thanks to a very funny ability in Soul Linker, Umbreon essentially turns the opponents damage against them, which works well with it thanks to excellent bulk. Teleport and Taunt are mandatory, allowing Umbreon to function as both an interesting pivot and deny opponents attempts to wear it down through passive damage, or overwhelm it with boosts. The third slot should be some form of reliable recovery, as the vast majority of the damage this set inflicts mandates also receiving said damage. Strength Sap is useful to make the damage output of strong physical threats more manageable, Wish allows it to support teammates and synergizes extremely well with Teleport, while Moonlight serves as a more generally reliable and immediate option. The last slot should go to either Leech Seed or Toxic, with the former improving longevity and the latter ensuring most targets faint even if they avoid hitting Umbreon.
}
Glaceon 
{
    name = Calm Mind Sweeper 
    item = Life Orb / Shell Bell / Heavy Duty Boots
    ability = Ice Scales
    evs = 252, 0, 252, 4, 0, 0 
    nature = Bold
    moves = Calm Mind, Freeze Dry / Blizzard / Hyper Voice, Earth Power, Thunderbolt 
   comment = Excellent natural bulk combined with Ice Scales makes Glaceon extremely durable, easing it's setup with Calm Mind. Maximum defense investment is preferred, as several Calm Mind boosts alleviate the lack of SpA EVs
}
Sylveon
{
    name = Calm Mind Sweeper 
    item = Life Orb / Shell Bell
    ability = Fairy Aura 
    evs = 252, 0, 252, 4, 0, 0
    nature = Bold
    moves = Hyper Voice / Moonblast, Earth Power, Calm Mind, Wish / Draining Kiss / Fireblast / Agility 
   comment = Sylveon makes an excellent calm mind abuser thanks to her fantastic mono fairy typing, allowing her to run Earth Power to cover the majority of fairy resistant types, therefore freeing her moveslots up for other options such as Wish or Draining Kiss for recovery, Fire blast for the occasional oddball pokemon that resists both Fairy and Ground type, or Agility to fix her lacking speed stat 
}
Diancie-mega
{
    name = Calm Mind Sweeper 
    item = Diancite
    ability = Magic Guard 
    evs = 0, 0, 4, 252, 0, 252
    nature = Timid
    moves = Diamond Storm, Body Press, Moonblast / Draining Kiss, Calm Mind
   comment = Solid mixed defenses, sky high SpA, and an incredible signature move in Diamond Storm enable Diance-mega to become a powerful, bulky, and surprisingly fast sweeper. Diamond Storm has incredible synergy with Body Press, enabling her to bypass special walls that could otherwise slow her down. Calm Mind boosts her already impressive stats to monstrous levels, allowing her to tear through unprepared teams. Lastly, Moonblast or Draining Kiss provide a Fairy STAB, with the former being stronger and the latter increasing longevity.
}
Buzzwole
{
    name = BUZZ! BUZZ! BUZZ!
    item = Life Orb / Shell Bell / Leftovers 
    ability = Sheer Force 
    evs = 152, 252, 0, 0, 0, 104
    nature = Adamant 
    moves = Quiver Dance, Bulk Up, Brick Break / Close Combat, Leech Life / Fell Stinger / Poison Jab / Meteor Mash
   comment = Another Bug to be graced with the much coveted Quiver Dance, and an interesting pick for sure. 104 Speed EVs allow him to outspeed Timid base 100s at +1, while the rest goes into Attack and HP to maximize his damage output and survivability.
   Quiver Dance does wonders for him, helping to patch up his severely lacking SpD and Spe stats. Bulk Up serves as secondary set up, allowing him to further bolster his already impressive physical side. With Sheer Force and Iron Fist, Brick Break reaches an impressive base power, without having to sacrifice the bulk he dances so hard to maintain. Alternatively, Close Combat offers a significantly stronger alternative if you are willing to suffer the defense drops. For the last slot, Bug STAB is an option, however this leave Buzz quite walled by most Fairy types, so Meteor Mash or Poison Jab could provide useful coverage against them.
}
Goodra
{
    name = Bulky Curse Sweeper 
    item = Toxic Orb
    ability = Sap Sipper
    evs = 248, 252, 8, 0, 0, 0
    nature = Adamant 
    moves = Curse, Facade, Dragon Tail, Poison Tail / Power Whip / Fire Punch
   comment = With access to a phenomenal combination of abilities in Poison Heal, Hydrate, and Amphibious, Goodra is able to find itself a unique niche as a Water type Facade abuser. It's excellent special bulk compliments a Curse set well, and after a few boosts it becomes a formidable powerhouse, both eating and delivering large amounts of damage.
Facade serves as the main source of damage, with Poison Tail both providing coverage against Faeries that might try to threaten it, and potentially poisoning as well, allowing for passive damage as it boosts. Dragon Tail serves as a secondary STAB, and can be used to phase out opponents who attempt to boost up alongside Goodra. Alternatively, Power Whip or Fire Punch are options to hit oddball targets that might otherwise slow Goodra down, such as Quagsire or Ferrothorn.
}
Articuno
{
    name = North Wind Support 
    item = Heavy Duty Boots
    ability = North Wind
    evs = 248, 0, 0, 4, 252, 0
    nature = Calm
    moves = Roost, Defog, U-Turn, Ice Beam
   comment = With access to potentially the single best support ability in North Wind and a pivoting move in U-Turn, Articuno functions as excellent support, greatly reducing the damage it's team takes by setting Aurora Veil and removing hazards. Take care not to be reckless and allow it's Heavy Duty Boots to be removed, as it's poor defensive typing gives it an extreme vulnerability to Stealth Rock, greatly nullifying it's value as a defensive pivot.
}
Bastiodon
{
    name = Bastion 
    item = Leftovers / Life Orb
    ability = Stamina 
    evs = 248, 0, 8, 0, 248, 0
    nature = Calm
    moves = Stealth Rock, Shore Up, Body Press, Iron Defense / Toxic / Roar
   comment = A fantastic combination of abilities as well as ridiculous natural bulk makes Bastiodon quite hard to break on either side. Besides Stealth Rock and Recovery, Body Press synergizes well with Dauntless Shield and Stamina. For the last move, Iron Defense serves well to boost it's defense to astronomical levels in a single turn, making it's Body Press akin to a force of nature. Toxic is a decent alternative, useful for occasions where you want to keep hazards up against something spamming defog. Finally, Roar could be used, phasing moves naturally having good synergy with hazards and it allows Bastiodon to punish Ghost or Psychic types that might seek to boost up and overwhelm him.
}
Milotic 
{
    name = Mixed Wall
    item = Flame Orb
    ability = Marvel Scale 
    evs = 248, 0, 252, 8, 0, 0 
    nature = Bold
    moves = Recover, Haze, Scald, Moonblast 
   comment = A solid defensive typing, good natural bulk, and an excellent selection of abilities combine to turn Milotic into a durable wall on both sides. Haze+Recover allow it to serve as a general answer to many forms of set up, while Adaptability boosted Scald and Moonblast serve as both damage output, and a means to further bolster her bulk via Scald burns and Moonblast SpA drops.
}
Tyranitar-mega
{
    name = DDance Sweeper 
    item = Tyranitarite
    ability =  Moxie / Sand Stream
    evs = 88, 252, 0, 0, 0, 168 
    nature = Adamant 
    moves = Dragon Dance, Wicked Blow, Strength, High Horsepower
   comment = Tyranitar has been blessed with a myriad of boons, from a nuclear new Dark STAB in Wicked Blow to a more consistent(and stronger thanks to Juggernaut) Rock STAB in Strength, to slightly stronger Ground coverage thanks to Juggernaut additionally boosting High Horsepower. 168 Speed EVs outspeed Timid base 100s after a Dragon Dance, with the rest going into Attack and HP to maximize it's damage and bulk.
}
Blacephalon
{
    name = Special Scarf 
    item = Choice Scarf 
    ability = Pyromancy 
    evs = 0, 0, 4, 252, 0, 252 
    nature = Timid
    moves = Shadow Ball, Fire Blast, Mind Blown / Hidden Power(Fighting), Trick 
   comment = A good Speed tier and naturally high SpA make Blacephalon a good Choice Scarf user, outspeeding all unboosted mons and many Swift Swimmers and the like. Fire Blast serves as a strong Fire STAB, with Shadow Ball doing the same for Ghost. Mind Blown is an extremely powerful attack at the cost of cutting it's own Health, while HP Fighting hits oddball targets like Gyarados-mega or Tyranitar who resist it's STAB combination. Finally, Trick can be used to cripple opposing walls or lock offensive mons into their set up moves.
}
Heatmor
{
    name = AV Attacker
    item = Assault Vest 
    ability = Steelworker
    evs = 252, 252, 4, 0, 0, 0 
    nature = Adamant 
    moves = Fire Lash, Bullet Punch, Meteor Mash / Drain Punch, Stomping Tantrum 
   comment = A nice buff to it's bulk alongside it's already existing signature move Fire Lash(which has a 100% chance to lower the opponents defense) enable Heatmor as a viable AV abuser. Bullet Punch boosted by Tough Claws and Steelworker becomes a powerful priority move, Meteor Mash gives Heatmor the chance to boost it's attack, further increasing it's damage output alongside Fire Lash. Drain Punch could be used here instead to provide sustain, which this set notably lacks. Stomping Tantrum fills the last slot, having both good synergy with potential Meteor Mash misses, and allows Heatmor to hit fire types it would otherwise struggle against.
}
Yveltal 
{
    name = God of Death
    item = Life Orb / Shell Bell / Heavy Duty Boots
    ability = Bad Luck 
    evs = 180, 0, 0, 252, 0, 76
    nature = Modest
    moves = Nasty Plot, Taunt / Roost, Dark Pulse, Oblivion Wing / Hurricane 
   comment = Being granted access to an actually useful boosting move in addition to a plethora of fantastic abilities has made it amply clear that this mon is indeed a force of nature.
   76 EVs in Speed guarantee Yveltal is the fastest unboosted mon in the game with Air Blower active, but investing fully into Speed to outspeed boosted foes is an option as well. The rest should go into SpA, and then HP whatever you choose. Nasty Plot boosts it's already impressive SpA to nuclear levels, allowing it to shred through all save the most durable or resistant walls. Dark Pulse is a consistent STAB move, with the added benefit of potentially denying a slower opponent a move via flinch. Oblivion Wing serves as an excellent secondary STAB, and can also provide valuable sustain to variants that opt for Taunt over Roost. Hurricane is an option instead, providing higher power at the cost of accuracy and a less useful/consistent secondary effect. Taunt or Roost are the main options for the last slot, with Taunt allowing it to deny hazards or recovery and Roost providing valuable sustain in addition to removing it's Flying type for the turn, allowing it to avoid SE damage from attacks aimed at that side of it's typing.
}
Xerneas
{
    name = DEER
    item = Power Herb
    ability = Pixilate 
    evs = 0, 0, 4, 252, 0, 252 
    nature = Modest / Timid 
    moves = Geomancy, Boomburst, Earth Power, Ingrain / Substitute 
   comment = Somehow, the Deer of Life has become more terrifying than it's death and destruction inspired brother, Pixilate and Fairy Aura boosted Boomburst render all things to dust, and Earth Power provides perfect coverage, hitting Fire, Poison, and Steel types that might aim to survive more than a single Boomburst on account of their typing. Geomancy is it's signature move, and with Power Herb it becomes a single turn boosting moves that even Quiver Dancers drool over. For the last slot, Ingrain is an option to prevent opponents from phasing Xerneas out, preventing them from wasting it's Power Herb. Substitute is an option instead, allowing it to scout out how the opponent reacts, therefore allowing to to preserve it's Herb if strong counterplay that could prevent it's sweep is present.
}
Dewgong 
{
    name = The Gong :skull:
    item = Light Clay
    ability = Fur Coat / Ice Scales
    evs = 248, 0, 252, 8, 0, 0 
    nature = Relaxed 
    moves = Flip Turn, Freeze Dry, Slack Off, Toxic / Encore / Heal Bell / Scald
   comment = Thanks to a couple....minor... buffs, Dewgong manages to find use on many teams, providing valuable support with it's extremely useful ability in North Wind. It also functions as an excellent wall, becoming nigh invincible on whichever side it chooses to supplement with it's ability. Freeze Dry serves as the main source of damage, with Ice being an excellent offensive type and Freeze Dry specifically being able to hit opposing Water Types for SE damage. Flip Turn allows The Gong to pivot out of bad matchups, allowing it to safely bring in an ally. Slack Off provides sustain, as even only taking 3% from most attacks does tend to add up. The last slot is generally free, and allows it to customize to suit it's team, having such options as Scald or Toxic to further spread status among the opposing team, Heal Bell enables it to further support it's allies, and Encore allowing it to further frustrate opponents by  locking them into their status or weak attacking moves.
}
Porygon2
{
    name = Bulky Sweeper
    item = Eviolite 
    ability = Download 
    evs = 252, 0, 4, 252, 0, 0(0 spe IVs)
    nature = Quiet
    moves = Nasty Plot, Recover, Shadow Ball, Tri Attack
   comment = Decent natural bulk combined with Eviolite makes Porygon2 quite sturdy for a sweeper, allowing it to set up multiple Nasty Plot boosts to patch up it's somewhat lacking SpA stat. Tri Attack is P2s' strongest Normal STAB that doesn't have any drawbacks, with the added benefit of potentially inflicting a status upon the opponent as well. Shadow Ball is it's best option hit ghosts with. A Quiet nature and 0 Speed IVs allow Porygon to go last as often as possible, therefore activating Analytic and maximizing it's damage output. 
}
Scyther 
{
    name = Bulky Sweeper 
    item =  Eviolite 
    ability = Perfectionist 
    evs = 252, 252, 4, 0, 0, 0 
    nature = Adamant 
    moves = Swords Dance, Fury Attack, Pin Missile / U-Turn / X-Scissor, Sacred Sword 
   comment = Thanks to decent bulk with Eviolite and Perfectionist allowing him to gain priority on low BP moves, Scyther becomes a fast and durable sweeper, at the notable downside of being inconsistent due to the mechanics behind multi-hit moves.
   Fury Attack serves as the main damage output, gaining a Flying typing thanks to Aerilate while also gaining priority thanks to Perfectionist. Pin Missile can serve as a secondary STAB, although U-Turn provides valuable utility in a pivoting option and X-Scissor allows it to hit things immune to priority with STAB. Sacred Sword serves as the last attacking move, allowing Scyther to hit Steel types it's dual STAB is otherwise resisted by. Swords Dance fills the last move slot, allowing Scyther to boost it's attack and tear through teams.
}
Necrozma-Dusk-Mane
{
    name = DDance/Ultra Burst
    item = Weakness Policy 
    ability = Neuroforce
    evs = 196, 252, 0, 0, 0, 60
    nature = Adamant 
    moves = Dragon Dance, Photon Geyser, Strength / Stone Edge, Frustration / Sunsteel Strike / Outrage / Earthquake 
   comment = Thanks to the lack of Z moves and the subsequent rework of Ultra Burst into a move based Mega, NDM finds himself in the unique position of being able to combine two powerful sets, with his good bulk and Prism Armor in Dusk Mane form usually allowing him to proc his Weakness Policy, then Mega Evolve if needed to surprise threats with a drastic shift in Speed as well as a modest bump to power.
   Photon Geyser serves as the STAB for this set, as well as being mandatory to allow it to Ultra Burst. Dragon Dance is the next hard slot, allowing it to boost it's Speed and Attack, further increasing it's destructive power. The last two slots should be dedicated to coverage, as Psychic is quite a poor type and there are many threats that might aim to eat such an attack. 
   252 Attack EVs maximize Necrozmas sweeping potential, with 60 Speed EVs allowing it to outspeed pokemon with 90 base speed or below after a single Dragon Dance, without having to rely on Ultra Burst right away. The rest go into HP, to maximize it's bulk and allow it to activate it's Weakness Policy against as many threats as possible.
}
Shuckle
{
    name = Shuck
    item = Leftovers 
    ability = Contrary 
    evs = 252, 0, 252, 0, 4, 0 
    nature = Impish 
    moves = Strength, Infestation, Toxic, Pain Split / Encore 
   comment = With Contrary Strength, Shuckle gains the ability to boost both it's defenses while also delivering (extremely weak) attacks. This allows it to build into an extremely durable wall despite it's low HP stat, with it's skyhigh base defenses quickly rising to extremely high levels. Infestation and Toxic serve as passive damage, as this set is severely lacking in damage output. The last slot should go to pain split to maximize longevity and lessen Shuckle's Leftover dependency, or Encore to frustrate enemies who attempt to take advantage of Shuckle through status, boosting, etc.
}
Grimmsnarl
{
    name = Screens Support
    item = Light Clay
    ability = Prankster 
    evs = 252, 0, 252, 0, 4, 0 
    nature = Impish 
    moves = Spirit Break, Taunt, Light Screen, Reflect 
   comment = Thanks to a plethora of useful defensive abilities, Grimmsnarl becomes even more suited to it's vanilla niche as a screen setter. Light Screen and Reflect reduce all damage taken from their respective stat. Taunt allows it to deny the opponent hazards, status, or boosting. Spirit Break serves as a useful final move, as Fairy type has no immunities and the SpA drop further serves to reduce the damage it and it's team takes.
}
Snorlax 
{
    name = Slowlax
    item = Leftovers 
    ability = Comatose 
    evs = 252, 4, 0, 0, 252, 0 
    nature = Careful 
    moves = Slack Off, Curse, Body Slam / Return, Body Press / Darkest Lariat
   comment = A classic Snorlax set, enhanced thanks to his gains in reliable recovery and status immunity allowing him to function as an even better Curse user than before. Curse+Slack off allow him to setup on many things, with his high HP and SpD combining with Curse boosts to make him extremely durable while also packing quite the punch. Body Slam is a decently powerful Normal STAB with a useful secondary effect, although Return is an option for slightly more power. For the last slot, either Body Press or Darkest Lariat serve to allow it to muscle past Steel and Ghost types, respectively.
}
Pachirisu
{
    name = Regenvest 
    item = Assault Vest
    ability = Electric Surge
    evs = 252, 0, 252, 4, 0, 0 
    nature = Bold
    moves = Nuzzle, Super Fang, U-Turn / Volt Switch, Thunderbolt  / Thunder 
   comment = Thanks to a myriad of useful tools such as Nuzzle allowing it to spread status, Volt Switch or U-Turn to pivot, and Super Fang to instantly chunk a targets health, Pachirisu functions as a good defensive pivot, capable of stomaching a surprising number of hits thanks to Fur Coat and good special bulk.
}
Skarmory
{
    name = Physical Wall 
    item = Rocky Helmet 
    ability = Lead Coat 
    evs = 252, 4, 252, 0, 0, 0 
    nature = Impish
    moves = Spikes / Stealth Rock, Whirlwind / Stealth Rock / Spikes,  Roost, Steel Wing / Wing Attack / Brave Bird
   comment = An incredible typing and physical defense make Skarmory a fantastic wall, setting hazards while also wearing most physical threats down through chip damage thanks to it's Rocky Helmet. Any combination of Hazards and Whirlwind will do, while Roost is mandatory to keep Skarmory healthy and stacking hazards. The last slot should ideally go to some sort of attack to not leave Skarmory completely helpless against Taunt, although you could instead opt for dual hazards+Whirlwind if you're not worried about that.
}
Eevee
{
    name = Baby Baby Ekiller
    item = Eviolite 
    ability = Adaptability 
    evs = 252, 252, 0, 0, 4, 0
    nature = Adamant 
    moves = Curse, Substitute, Extreme Speed, Frustration 
   comment = Being a baby pokemon, Eevee is often far from the most viable or ideal choice. However, he does have the added benefit of offering an extreme amount of cuteness to teams, which can often be difficult to fit.  
}
Mew
{
    name = Degenerate Incarnate 
    item = Leftovers 
    ability = Magic Guard
    evs = 252, 0, 252, 0, 4, 0
    nature = Impish / Bold 
    moves = Imprison, Transform, Block, U-Turn
   comment = Hi there. Are you evil? Do you enjoy inflicting pain and misery upon whatever victim might be in front of you? Then look no further, as Mew apparently enjoys these things as well. Due to it's absurdly wide movepool, Mew finds itself with access to a terrifying combo. Block prevents the opposing Pokemon from switching out, while Imprison+Transform enables Mew to render the opposing Pokemon completely incapable of performing any action save struggling, allowing Mew to both easily remove it from the game, while additionally abusing whatever tools said Pokemon had to the greatest extent, allowing it to easily torment defensive pokemon through stacking their own hazards agains them, or offensive ones by setting itself up for a sweep.
   Warning: The poster of this set is not responsible for any personal injuries resulting from the usage of this Pokemon!
}
Landorus-Therian
{
    name = Boom
    item = Choice Band
    ability = Aerilate 
    evs = 0, 252, 0, 0, 4, 252
    nature = Jolly
    moves = Explosion, Stone Edge, Fissure, U-Turn
   comment = This set is incredibly simple and straightforward. Explode if you want whats in front of you dead, U-Turn otherwise. Thanks to Aerilate, Choice Band, and an incredible Attack, Explosion will do a massive amount of damage to nearly any target, resulting in a large hole in most things irregardless of the opponent attempting counterplay.
}
Coalossal
{
    name = Galvspin
    item = Heavy-Duty Boots
    ability = Galvanize
    evs = 252, 4, 0, 0, 252, 0
    nature = Calm 
    moves = Rapid Spin, Spikes / Stealth Rock, Wil-o-wisp, Flare Blitz / Fire Punch 
   comment = Thanks to a rare combination in Galvanize and Rapid Spin, Coalossal finds itself in the unique position to not be spinblocked by ghosts, allowing it to function as extremely consistent hazard removal via bypassing the typical tools used to deny Rapid Spin. Giving it a move such as Spikes or Stealth Rock allows it to set it's own hazards, allowing for valuable role compression. Wil-o-wisp allows it to cripple opposing physical attackers, greatly reducing their damage output. Finally, some sort of attacking move should be run in the last slot to prevent coalossal from being excessively passive. Generally Fire is more advisable, as it threatens many Hazard setters far more than a Rock type move would, further allowing Coalossal to excel at it's role in hazard control 
}
Aggron-mega
{
    name = Curse Sweeper 
    item = Aggronite
    ability = Juggernaut 
    evs = 248, 8, 252, 0, 0, 0
    nature = Careful 
    moves = Curse, Slack Off, Heavy Slam / Iron Head, Body Press / Earthquake 
   comment = An absurdly high Defense, mono Steel typing combined with Primal Armor, and access to reliable recovery all combine to turn Mega Aggron into a nigh unbreakable beast on the physical side, with Curse enabling it to become an even more unstoppable force. Curse functions as a boost to both Aggrons' Attack and Defense, at the generally negligible cost of lowering it's already low speed. Slack off keeps Aggron healthy, preventing it from being worn down and allowing it to easily boost it's stats to maximum against many physical threats. Heavy Slam is a reliable Steel type STAB that often reaches good base power thanks to Aggrons weight, although Iron Head could be run as a more consistent option instead. For the last slot, Body Press synergizes well with Curse, Juggernaut, and Aggron as a whole allowing him to hit opposing Steel Types for SE damage. Earthquake can provide to the same ends, but lacks the high amount of synergy Body Press offers, in return offering a situationally more powerful attack, with the added benefit of not making contact.
}
Scizor-mega
{
    name = Demon Bug
    item = Scizorite
    ability = Intimidate 
    evs = 252, 252, 0, 0, 4, 0
    nature = Adamant 
    moves = Extreme Speed, Bullet Punch, Sacred Sword / Roost, Swords Dance
   comment = Incredible Attack, excellent typing, and a ridiculous combination of abilities combine to turn Scizor-mega into one of the most threatening offensive pokemon in the entire game, capable of tearing through teams lacking strong counterplay with ease thanks to it's powerful priority moves in Extreme Speed and Bullet Punch. Sacred Sword is an option to allow it to muscle past certain Steel types, while Roost allows it to take full advantage of it's bulk and typing, allowing it to freely set up multiple Swords Dances if needed.
}
Furret 
{
    name = Subbell
    item = Shell Bell / Salac Berry (Belly Drum)
    ability = Adaptability 
    evs = 0, 252, 0, 0, 4, 252
    nature = Adamant 
    moves = Belly Drum / Coil, Substitute, Body Slam / Return / Headbutt, Drain Punch / Focus Punch / Fire Punch
   comment = Good Speed and an excellent ability combination in Adaptability+Scrappy enable Furret to skip Ghost coverage, enabling it to setup behind a Substitute, ignoring most direct attempts at inflicting it with status as well as limiting the damage it takes. Belly Drum synergizes well with Substitute, as using it after Sub will put Furret at exactly the right HP to activate Salac Berry, turning it into a fast and devestatingly strong sweeper. Alternatively, Coil takes much longer to set up, but pairs well with Shell Bell and Substitute thanks to increasing Defense alongside Attack. Normal STAB fills the next slot, which a choice few moves offering acceptable BP with useful secondary effects. For the last slot, Steel and Rock coverage such as Drain Punch, or Focus Punch with skillful Sub usage is an obvious, although Fire Punch is an option to hit more specific targets harder. 
}
Chimecho
{
    name = Calm Mind Sweeper 
    item = Leftovers / Life Orb
    ability = Mystic Power / Magic Guard 
    evs = 248, 0, 252, 8, 0, 0
    nature = Bold
    moves = Calm Mind, Recover, Stored Power / Moonblast, Boomburst / Shadow Ball / Energy Ball
   comment = A unique and useful typing complimented by workable bulk enables Chimecho as a strong Calm Mind sweeper, with access to Recover easing it's setup and allowing it to boost itself to +6 easily. Furthermore, it is graced with the choice of two excellent ability options, with Magic Guard allowing it to wield a Life Orb for free, ignore passive damage, and potentially function as an excellent Burn absorber if needed.

   Mystic Power is an equally appealing alternative, STAB offering a substantial increase in power over a Life Orb, while not giving up it's item slot, allowing it to potentially use Leftovers and lessen it's reliance on Recover, allowing it to setup faster.
}
Golisopod 
{
    name = AV Attacker 
    item = Assault Vest 
    ability = Tough Claws / Predator 
    evs = 252, 252, 0, 0, 4, 0 
    nature = Adamant 
    moves = Flip Turn, First Impression, Leech Life / X-Scissor, Knock Off
   comment = Excellent bulk further complemented by good abilities, Attack, and movepool options enable Golisopod as a solid Assault Vest user, with options such as Flip Turn to bring allies in safely, one of the most powerful priority moves in First Impression, Leech Life for sustain, and Knock Off for utility. X-Scissor is also an option over Leech Life, offering higher damage and excellent potential for Crits with Hyper Cutter.

   Golisopod also has several other viable movepool options such as Close Combat, Poison Jab, or Shadow Claw should you wish to hit a specific target harder.
}
Tauros
{
    name = Deleted by Giga Impact
    item = Choice Band
    ability = Rampage
    evs = 6, 252, 0, 0, 0, 252
    nature = Jolly
    moves = Giga Impact, Zen Headbutt, Rock Slide, High Horsepower / Earthquake
   comment = This absolute beast can destroy almost everything unresisted or that's not physical wall with Hyper Aggressive Giga Impact. Scrappy makes Giga Impact completely free against Ghost Types. Zen Headbutt, Rock Slide and High Horsepower or Earthquake (depending on the situation) for useful coverage.
}
Weavile
{ 
    name = Physical Sweeper
    item = Focus Sash
    ability = Hyper Aggressive
    evs = 0, 252, 4, 0, 0, 252
    nature = Jolly
    moves = Swords Dance, Triple Axel, Wicked Blow / Knock Off, Ice Shard
   comment = Weavile is one of the best offensive sweepers in the game. After 1 Swords Dance, anything not named steelix, aggron, and sometimes camerupt will most likely die in 1 hit. 
    .tags = Singles, Offensive
}
Milotic
{
    name = Comp Sweeper
    item = Shell Bell
    ability = Competitive
    evs = 252, 0, 4, 252, 0, 0
    nature = Modest
    moves = Scald, Moonblast, Flip Turn, Recover
   comment = Utterly destroys stuff if it gets the Competitive Boost. You can use it to punish Defog, Intimidate/Scare (to a lesser extent), or Sticky Webs (including getting it Magic Bounced to you). Flip Turn is there when they switch into a Special Wall (Mainly just Chansey) so you can Flip Turn out, deal decent damage and heal a bit with Shell Bell. You can run Quiet if you want the extra power when facing against Blissey but Modest allows you to outspeed the not super slow walls (ie. Umbreon). Scald instead of Surf or Hydro Pump so you can fish for burns and the less power doesn't matter much if you have +2 with the added power of Adaptability but Moonblast is your main STAB.
}
Dragonite
{
    name = Physical Rampage Breaker
    item = Choice Band
    ability = Aerilate
    evs = 0, 252, 4, 0, 0, 252
    nature = Adamant/Jolly
    moves = Giga Impact, Extreme Speed, Earthquake, Outrage / Fire Punch
   comment = Thanks to the incredible combination of Rampage and Aerilate, Dragonite becomes a potent wallbreaker capable of quickly and easily crushing almost any Pokemon slower than it in a single turn with Giga Impact. Extreme Speed also serves as a shockingly powerful attack to revenge kill anything faster than Dragonite. Earthquake and Fire Punch are chosen for coverage against the various Pokemon that resist Dragonite's flying STAB.
    .tags = Singles, Offensive
} 
Flapple
{
    name = Quiver Apple
    item = Focus Sash
    ability = Aerodynamics
    evs = 4, 0, 0, 252, 0, 252
    nature = Modest
    moves = Hidden Power Fire / Sludge Bomb, Energy Ball, Dragon Pulse, Quiver Dance
   comment = Great Quiver Dance sweeper when you really need a Grass Dragon type. Focus Sash almost guarantees you at least 1 Quiver Dance, 2 or more if the opponent makes a defensive switch (only applicable in Showdown). Regenerator actually allows you to still get value out of the sash even if you take a resisted hit which allows you to still use it's typing defensively. Aerodynamics can also catch Aerilate E-Speed Dragonites and the like off guard allowing you to set up for free while also allowing you free switch ins. Replace HP Fire with Sludge Bomb when (if) it gets it if you need more power to get kills on Forretress and the like.
} 
Malamar
{ 
    name =  Contrary abuse
    item = Shell bell 
    ability = Contrary 
    evs = 252, 0, 0, 0, 188, 70
    nature = Jolly
    moves = Superpower, Psycho Cut, Sucker Punch, Hypnosis
   comment =  Walls most physical pokemon while ramping up with super power. Incredible in conjunction with Tailwind support.  Near perfect accuracy hypnosis gives you even more opportunity to setup or deal with annoying stuff before you ramp up. +2 sucker punches also deal huge damage. Tailor the EV spread however you need to fit into your team.  Extremely powerful pokemon.
 } 
Kommo-o
{
    name = Mixed Shell Smash
    item = White Herb
    ability = Bulletproof
    evs = 0, 252, 0, 4, 0, 252
    nature = Lonely
    moves = Shell Smash, Close Combat, Clanging Scales, Poison Jab
   comment = An absolutely horrifying sweeper thanks to it’s extreme ease in setting up afforded by its great natural bulk combined with multiple defensively oriented innates that even allow for a setup opportunity vs many special attacking Flying or Ice-type Pokemon. Kommo-o is very unfortunately unable to learn Dragon Rush, and as a result Clanging Scales is it’s preferred Dragon STAB due to both it’s slightly higher power even through the EV difference, and it’s ability to not be stonewalled by the numerous Fur Coat Pokemon. Generally, Kommo-o prefers to be in a position where it can steamroll by just clicking +2 Close Combat a bunch of times, as this is by far it’s strongest move. Poison Jab is the most optimal anti-Fairy coverage, as only Mismagius takes more damage from Iron Head, the rest are either equivalent or weaker to Poison Jab.
} 
Quagsire
{
    name = No set up for you
    item = Leftovers
    ability = Water Veil
    evs = 252, 0, 252, 0, 4, 0
    nature = Careful
    moves = Flip Turn, Recover, Toxic, Encore
   comment = Goes in on most set up mons (excluding Raikou if Ground Shock isn't nerfed), clicks Encore, and gives a safe switch in to your big threat via Flip Turn. Toxic is there for any annoying walls you wanna chip (ie: Suicune) and Recover is for extra recover when Water Veil Leftovers with Regenerator isn't enough.
}
Electivire
{
    name = 'Mixed' Power Fists
    item = Life Orb
    ability = Power Fists
    evs = 4, 252, 0, 0, 0, 252
    nature = Jolly
    moves = Plasma Fists, Close Combat / Drain Punch, Ice Punch, Wild Charge
   comment = With Power Fists, Electivire's punching moves hit the target's Special Defense. However, the rest of its physical movepool still hits enemies in their normal Defense stat, meaning that this has the niche of being able to hit either Defense or Special Defense hard while only needing to invest in one offensive stat. The choice between Close Combat and Drain Punch depends on whether you want raw breaking power or a bit of sustain to offset the recoil from Life Orb and Wild Charge. Ice Punch is almost certainly Electivire's best coverage option, but you could theoretically replace it with another punching move, or even another physical move if you want to lean into the 'mixed' nature of the set.
    .tags = Offensive, Mixed
}
Magnezone
{
    name = Charge Specs Magnezone
    item = Choice Specs / Focus Sash
    ability = Overcharge
    evs = 0, 0, 70, 252, 188, 0
    nature = Bold
    moves = Charge Beam, Aurora Beam, Flash Cannon, Thunder / Tri Attack
   comment = Charge Beam raises Sp Atk by 3 stages thanks to Multi Headed! This alone makes Magnezone a heavy hitter. Though it's not useful against Unaware mons, use Thunder/Thunderbolt (Aurora Beam in case of Quagsire) which will also deal good amount of damage to Electric types, thanks to Overcharge.
    .tags = Offensive, Doubles
}
Mismagius
{ 
    name = Prankster Support
    item = Leftovers
    ability = Prankster
    evs = 252, 0, 4, 252, 0, 0
    nature = Modest
    moves = Will-O-Wisp, Hex, Toxic, Destiny Bond
   comment = It's main goal is to spread as many statuses as possible then take something with it via Destiny Bond. Will-O-Wisp is to cripple Physical Attackers, Toxic is for the tanks and Burn Immune, Hex is to deal big damage to statused targets, and Destiny Bond can get rid of a stacked up sweeper.
    .tags = Singles, Mixed
}
Shuckle
{ 
    name = You Already Know What It Does
    item = Iapapa Berry
    ability = Regenerator
    evs = 0, 0, 252, 4, 252, 0
    nature = Bold / Calm
    moves = Infestation, Pain Split, Toxic / Sticky Web, Stealth Rock / Sticky Web / Protect
    comment = Shuckle is a serviceable choice for wearing down tanks and walls at low risk. Also, clicking Rocks and Webs.
    Infestation stops it from being Taunt bait (rare as it is) and adds damage over time. Pain Split needs little explanation, click when your HP is low (usually) and your opponent's is high. Some mix of the four moves in the last two slots will tend to get the most mileage out of your bug. The combination of Toxic, Infestation, and Pain Split can burn through the PP of foe's recovery moves, but dual hazards may be situationally preferable. Stealth Rock does what it's done since 2006, Sticky Web suits aggressive teams, and Protect is great for doubles and racking up your damage over time ticks.
    Adjust your nature as appropriate. Zero HP EVs maximize Pain Split's effectiveness, but compromise Shuckle's full bulk. Against anything that hits harder, moving some EVs to HP and focusing on one side of defense can help it stay competitive.
    Regenerator provides a safety net and much needed utility as a pivot, but rolling the dice for defense boosts with Moody might be funny.
    Your item slot has a lot of flexibility. The 50% healing berries, Sitrus Berry or Leftovers will let Shuckle click moves other than Pain Split more often, the choice is mostly up to preference and/or what you're fighting. Mental Herb is cute if you use Shuckle against something with Taunt or Encore. Lum Berry is there if random para or sleep will ruin your day. There's probably something funny you can pull on the AI with a Red Card. That being said, it's still ultimately best as a suicide lead, so Custap Berry, the weakness berries or Focus Sash are there if that's your thing.
    .tags = Defensive
}
Musharna
{  name = The Nuclear Option
    item = Choice Specs
    ability = Psychic Surge
    evs = 252, 0, 0, 252, 4, 0
    nature = Quiet / Modest
    moves = Expanding Force, Dazzling Gleam / Moonblast, Shadow Ball, Coverage Move
   comment = This set does one thing, and that is nuke things with Expanding Force. Fairy/Ghost mixed with Psychic give you near perfect coverage, so the 4th slot can really be whatever super.effective move you might need. This set should primarily be used on a Doubles team with a Trick Room setter like Reuniclus or Haterrene as it allows you to move first and kill most things before they get a chance to move as you get to click double expanding force.
    .tags = Doubles, Offensive
} 
Azumarill 
{
    name = Shell Bell Terror
    item = Shell Bell
    ability = Sap Sipper 
    evs = 252, 252, 0, 0, 6, 0,
    nature = Adamant 
    moves = Aqua Jet, Play Rough, Belly Drum, Ice Punch
    comment = The Shell Bell will restore 1/3 of your HP after you hit the opponent each time so after you use Belly Drum, Aqua Jet will heal you up right away next turn when used.
}
Persian
{
    name = Crit Cat
    item = Scope Lens
    ability = Sniper
    evs = 4, 252, 0, 0, 0, 252
    nature = Adamant
    moves = Fake Out, Fury Swipes, Payback, Knock Off
   comment = Perfectionist with Scope Lens gives all of it's moves 50% Crit Chance excluding Knock Off because it has no other physical move 50 BP or lower that isn't either a Special Attack or Scratch and the Sniper and Technician boosts allows it to hit really hard with crit Fury Swipes.
    .tags = Singles, Offensive
}
Gallade
{ 
    name = Reversal
    item = Liechi Berry
    ability = Perfectionist
    evs = 0, 252, 4, 0, 0, 252
    nature = Adamant
    moves = Endure, Reversal, Triple Axel, Shadow Sneak
   comment = Reversal is programmed to have 1 BP, meaning it activates Perfectionist. Endure down to 1 HP and then start clicking your 200 BP priority STAB move with additional +1 priority coverage for the Flying- and Ghost-types that love to stop your Reversal spam. 

   Be careful of Rocky Helmet/Rough Skin, Dazzling/Queenly Majesty, and chip from weather or abilities like Aftermath. There is a lot of inconsistency with this kind of set, but when positioned properly with Stealth Rock to deal with Focus Sash and a way to keep Gallade safe from chip, the power of it is unmatched. Very few things can boast a 200 BP priority STAB from 125 base Attack.
    .tags = Singles, Troll
}
Braviary
{
    name = Murder Bird
    item = Choice Band
    ability = Gale Wings
    evs = 252, 4, 0, 0, 0, 252
    nature = Adamant
    moves = Dual Wingbeat, Return, Steel Wing, Close Combat / Zen Headbutt
   comment = This set takes out just about anything that doesn't resist Dual Wingbeat even if they have a Focus Sash
}
Sigilyph 
{
    name = Your dreams are mine now
    item = Shell Bell / Focus Sash
    ability = Dreamcatcher
    evs = 6, 0, 0, 252, 0, 252
    nature = Timid
    moves = Hypnosis, Shadow Ball, Dream Eater, Dazzling Gleam/Ice Beam
    comment = Sigilyph is an underrated Pokémon but in the right conditions it could do massive damages and sweep the foe's team. 

    Dreamcatcher is an ability that doubles move power if anyone in the field is asleep.
    Its base speed is really good (97) and investing 252 EV on this stat should ensure you the first move. 
    Obviously you'll use Hypnosis as first move and restore your HP with Dream Eater + Shell Bell in case you've missed the first status move or the foe is faster that Sigilyph. 
    Shadow Ball is a must pick thanks to Sigilyph's ability it gains STAB and as fourth move it could be good Dazzling Gleam in case you're facing a Dark type Pokémon but elemental moves like Heat Wave and Ice Beam should work too. 
    It can learn Solar Beam too so it's totally worth even in a Sunny Day/Drought team. 
    Show Sigilyph some love, it deserve it! 
}
Ninjask
{
    name = Fly-By
    item = Focus Sash / Heavy-Duty Boots
    ability = Speed Force
    evs = 0, 252, 6, 0, 0, 252
    nature = Adamant
    moves = Swords Dance / Protect, X-Scissor, Fly, Dig
   comment = Sash for SD, Protect for Boots. Fly is Ninjask's most powerful Flying STAB and its one turn of invulnerability allows you to get a Speed Boost to power up your attacks even more. The same goes for Dig, which is for anything its dual STABs can't handle (Steel, Rock, Fire etc.).
}
Shedinja
{
    name = Bug-Burner
    item = Heavy-Duty Boots / Focus Sash
    ability = Wonder Guard
    evs = 0, 0, 0, 252, 0, 252
    nature = Naive
    moves = Will O Wisp, Hex, Skitter Smack / Struggle Bug / Poltergeist, Swagger / Shadow Sneak / Thief
   comment = Pester physical attackers with this pesky Shedinja set. The last 2 moves can be interchanged with almost any other move in Shedinja's kit, depending on what the situation calls for. Can also be a wincon if you can manage to get rid of your opponents' Ghost and Bug coverage.
}
Excadrill
{ 
    name = Sand Rush Sweeper
    item = Life Orb / Leftovers
    ability = Tough claws
    evs = 0, 252, 0, 0, 4, 252
    nature = Jolly
    moves = High Horsepower / Drill Run, Iron Head, Strength, Swords Dance / Rapid Spin
   comment = Thanks to Tough Claws, Sand Force and Earthbound, High Horsepower hits insanely harder than Earthquake. OHKO's and outspeeds most, if not all mons in the field.
    .tags = Singles, Offensive
}
Swellow
{
    name = Biggest McBirb
    item = Normal Gem / Flying Gem
    ability = scrappy
    evs = 0, 252, 0, 252, 4, 0
    nature = mild
    moves = Extreme Speed, Boomburst, Hurricane, Brave Bird
   comment = big damage kamikaze with both attack options 
} 
Victreebel
{
    name = Fun in the Sun
    item = Petaya Berry
    ability = Harvest
    evs = 16, 0, 0, 236, 0, 252
    nature = Timid
    moves = Solar Beam, Belch, Synthesis, Weather Ball
   comment = Get sun up (Ninetales is probably Victreebel's best partner, as it negates priority moves like Ice Shard/Sucker Punch/ESpeed that would otherwise punch through its 65/70 defenses, and you can bait fire moves with Flash Fire) and click Belch to boost your Sp. Atk with Harvest Petaya Berry. With Corrosive, Victreebel hits Steels super-effectively, with Weather Ball being your best move to hit opposing Poison types. Use Synthesis to heal on a switch or after switching in yourself on a resisted hit.

   You could, theoretically, use Starf instead of Petaya to try and fish for a useful +2 boost and run Natural Gift instead of Weather Ball, which with Starf has the distinction of turning into Victreebel's only Psychic move, but a) Natural Gift is physical, necessitating split EV investment and a Mild nature or something, and b) Unless you get lucky, a random +2 boost is going to be less valuable than a definite +1 Sp. Atk boost. Still funny though!
    .tags = Singles, Offensive
}
Gallade
{ 
    name = Ronin
    item = Choice Scarf / Choice Band / Expert Belt
    ability = Sweeping Edge
    evs = 4, 252, 0, 0, 0, 252
    nature = Jolly
    moves = Psycho Cut / Night Slash , Sacred Sword, Solar Blade, Excalibur
   comment = Keen Edge boosts moves cutting moves by 30% and is awesome here because all are cutting moves coming from Gallade's excellent base 125 Atk stat.
   Excalibur will punish the dragons and fairies that woudl otherwise bother Gallade.
   Also when paired up with a Drought teammate like Torcoal or Mega Charizard Y, and Solar Blade effectively goes up to 162.5BP!
    .tags = Singles, Doubles, Offensive
}