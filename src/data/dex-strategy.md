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
    name = Dundee All Bites
    item = Assault Vest
    ability = Predator
    evs = 252, 252, 0, 0, 0, 4 // HP, Atk, Def, Sp.Atk, Sp.Def, Speed
    nature = Jolly or Adamant
    moves =  fishious Rend, psychic fang, Ice fang, crunch
   comment = Works better with Sticky Web; heals itself with Predator and if you outspeed something, you can KO a lot with Fishious Rend.
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
   .evs = 252, 0, 128, 10, 128, 0
   .nature = Bold
   .moves = Draining Kiss, Calm Mind, Wish, Soft-Boiled / Recover
   .comment = Enter battle, use Audinite to go Mega and get ready to something really simple.

You have 2 main heals (Wish and Soft-Boiled) and a 3rd one that is also an offensive move (Draining Kiss). They all work in different ways so you can stack both for 100% in a single turn or 50%+dmg+some extra heal while you always live dangerously until you reach SpAtk levels high enough, thanks to Calm Mind, to become a real menace.

Mega Audino here is quite tanky and has a good SpAtk base so find a Pokémon that can't kill you (and those exists a lot; Mega Audino can tank a bunch of physical mons while burned and cursed(!)), and heal here and there while you use Calm Mind in the middle of those. Since you can heal for 100% after 2 turns whenever you need, you just need to make sure that you can survive the hit.
   .tags = Singles, Doubles, Troll
}