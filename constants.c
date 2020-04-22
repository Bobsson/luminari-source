/**
 * @file constants.c                                    LuminariMUD
 * Numeric and string contants used by the MUD.
 *
 * Part of the core tbaMUD source code distribution, which is a derivative
 * of, and continuation of, CircleMUD.
 *
 * All rights reserved.  See license for complete information.
 * Copyright (C) 1993, 94 by the Trustees of the Johns Hopkins University
 * CircleMUD is based on DikuMUD, Copyright (C) 1990, 1991.
 *
 * @todo Come up with a standard for descriptive arrays. Either all end with
 * newlines or all of them don not.
 */

#include "conf.h"
#include "sysdep.h"
#include "structs.h"
#include "utils.h"
#include "interpreter.h" /* alias_data */
#include "spells.h"
#include "craft.h"
#include "feats.h"
#include "domains_schools.h"
#include "handler.h"

/** Current LuminariMUD version.
 * @todo defined with _LUMINARIMUD so we don't have multiple constants to change.
 * @todo cpp_extern isn't needed here (or anywhere) as the extern reserved word
 * works correctly with C compilers (at least in my Experience)
 * Jeremy Osborne 1/28/2008 */
cpp_extern const char * const luminari_version = "LuminariMUD 2.4839 (tbaMUD 3.64)";
cpp_extern const char * const luminari_build =
#if defined(MKTIME)
    "Make time: " MKTIME "\r\n"
#endif
#if defined(BRANCH)
    "Branch: " BRANCH "\r\n"
#endif
#if defined(PARENT)
    "Parent: " PARENT "\r\n"
#endif
;

/* strings corresponding to ordinals/bitvectors in structs.h */

// npc subrace
const char *npc_subrace_types[NUM_SUB_RACES + 1] = {
    "Unknown",      /**/
    "Air",          /**/
    "Angelic",      /**/
    "Aquatic",      /**/
    "Archon",       /**/
    "Augmented",    /**/
    "Chaotic",      /**/
    "Cold",         /**/
    "Earth",        /**/
    "Evil",         /**/
    "Extraplanar",  /**/
    "Fire",         /**/
    "Goblinoid",    /**/
    "Good",         /**/
    "Incorporeal",  /**/
    "Lawful",       /**/
    "Native",       /**/
    "Reptilian",    /**/
    "Shapechanger", /**/
    "Swarm",        /**/
    "Water",        /**/
    "\n"};

// colored npc subrace abbreviations
// for now full name for effect
const char *npc_subrace_abbrevs[NUM_SUB_RACES + 1] = {
    "Unknown",
    "\tCAir\tn",
    "\tWAngelic\tn",
    "\tBAquatic\tn",
    "\trArch\tRon\tn",
    "\tYAugmented\tn",
    "\tDChaotic\tn",
    "\tbCold\tn",
    "\tGEarth\tn",
    "\trEvil\tn",
    "\tmExtraplanar\tn",
    "\tRFire\tn",
    "\tgGoblinoid\tn",
    "\tWGood\tn",
    "\tGIncorporeal\tn",
    "\twLawful\tn",
    "\tyNative\tn",
    "\tyReptilian\tn",
    "\tMShapechanger\tn",
    "\tySwarm\tn",
    "\tBWater\tn",
    "\n"};

// made this for shapechange, a tad tacky -zusuk
const char *npc_race_menu =
    "\r\n"
    "  \tbRea\tclms \tWof Lu\tcmin\tbari\tn | npc race selection\r\n"
    "---------------------+\r\n"
    "1)  \tWHumanoid\tn\r\n"
    "2)  \tDUndead\tn\r\n"
    "3)  \tgAnimal\tn\r\n"
    "4)  \trDragon\tn\r\n"
    "5)  \tYGiant\tn\r\n"
    "6)  \tRAberration\tn\r\n"
    "7)  \tcConstruct\tn\r\n"
    "8)  \tRElemental\tn\r\n"
    "9)  \tCFey\tn\r\n"
    "10) \tmMagical \tgBeast\tn\r\n"
    "11) \tBMonstrous \tWHumanoid\tn\r\n"
    "12) \tMOoze\tn\r\n"
    "13) \tDOut\twsider\tn\r\n"
    "14) \tGPlant\tn\r\n"
    "15) \tyVermin\tn\r\n";

// shapechange morph messages to_room, original system
const char *morph_to_room[NUM_RACE_TYPES + 1] = {
    /* unknown */
    " ",
    /* Humanoid */
    " ",
    /* Undead */
    "$n's flesh decays visibly, $s features becoming shallow and sunken as $e"
    "turns to the \tDundead\tn.",
    /* Animal */
    " ",
    /* Dragon */
    "$n's features lengthen, $s skin peeling back to reveal a thick, "
    "scaly hide.  Leathery wings sprout from $s shoulders and $s "
    "fingers become long, razor-sharp talons.",
    /* Giant */
    " ",
    /* Aberration */
    " ",
    /* Construct */
    " ",
    /* Elemental */
    "$n bursts into elemental energy, then becomes that element as $s form shifts to that of a "
    "\tRelemental\tn.",
    /* Fey */
    " ",
    /* Magical Beast */
    " ",
    /* Monstrous Humanoid */
    " ",
    /* Ooze */
    "$n's bones dissolve and $s flesh becomes translucent as $e changes form "
    "into an ooze!",
    /* Outsider */
    " ",
    /* Plant */
    "Thin vines and shoots curl away from $n's body as $s skin changes to a "
    "\tGmottled green plant\tn.",
    /* Vermin */
    " ",
    /*END*/ "\n"};

// shapechange morph messages to_char
const char *morph_to_char[NUM_RACE_TYPES + 1] = {
    /* unknown */
    " ",
    /* Humanoid */
    " ",
    /* Undead */
    "Your flesh decays visibly, and your features becoming shallow and sunken as"
    " you turn to the \tDundead\tn.",
    /* Animal */
    " ",
    /* Dragon */
    "Your features lengthen, your skin peeling back to reveal a thick, "
    "scaly hide.  Leathery wings sprout from your shoulders and your "
    "fingers become long, razor sharp talons.",
    /* Giant */
    " ",
    /* Aberration */
    " ",
    /* Construct */
    " ",
    /* Elemental */
    "You burst into fire, then become living flame as your form shifts to that "
    "of a \tRfire elemental\tn.",
    /* Fey */
    " ",
    /* Magical Beast */
    " ",
    /* Monstrous Humanoid */
    " ",
    /* Ooze */
    "Your bones dissolve and your flesh becomes translucent as you change form "
    "into an \tGooze\tn!",
    /* Outsider */
    " ",
    /* Plant */
    "Thin vines and shoots curl away from your body as your skin changes to a "
    "\tGmottled green plant\tn.",
    /* Vermin */
    " ",
    /*END*/ "\n"};

/* druid shape change race options */
const char *shape_types[MAX_PC_SUBRACES + 1] = {
    "Unknown",
    "badger",
    "panther",
    "bear",
    "crocodile",
    "\n"};
//5 (number of types)

/* druid shape change messages, to room */
const char *shape_to_room[MAX_PC_SUBRACES + 1] = {
    "Unknown",
    /* badger */
    "$n shrinks and suddenly grows spiky brown fur all over $s body, $s nose lengthens"
    " into a dirty snout as $s face contorts into an expression of primal"
    " rage.",
    /* panther */
    "$n's back arches into a feline form and $s teeth grow long and sharp.  "
    "Knifelike claws extend from $s newly formed paws and $s body becomes "
    "covered in sleek, dark fur.",
    /* bear */
    "$n's form swells with muscle as $s shoulders expand into a great girth.  "
    "Suddenly $s nose transforms "
    "into a short perceptive snout and $s ears become larger and rounder on the "
    "top of $s head.  Then $s teeth become sharper as claws extend from $s meaty paws.",
    /* crocodile, giant */
    "$n involuntarily drops to the ground on all fours as $s legs shorten to "
    "small stumps and a large tail extends from $s body.  Hard dark scales cover "
    "$s whole body as $s nose and mouth extend into a large tooth-filled maw.",
    /*END*/ "\n"};

/* druid shape change messages, to char */
const char *shape_to_char[MAX_PC_SUBRACES + 1] = {
    "Unknown",
    /* badger */
    "You shrink and suddenly grows spiky brown fur all over your body, your nose lengthens"
    " into a dirty snout as his face contorts into an expression of primal"
    " rage.",
    /* panther */
    "Your back arches into a feline form and your teeth grow long and sharp.  "
    "Knifelike claws extend from your newly formed paws and your body becomes "
    "covered in sleek, dark fur.",
    /* bear */
    "Your form swells with muscle as your shoulders expand into a great girth.  "
    "Suddenly you seem more aware of scents in the air as your nose transforms "
    "into a short perceptive snout.  Your ears become larger and rounder on the "
    "top of your head and your teeth become sharper as claws extend from your meaty paws.",
    /* crocodile, giant */
    "You involuntarily drop to the ground on all fours as your legs shorten to "
    "small stumps and a large tail extends from your body.  Hard dark scales cover "
    "your whole body as your nose and mouth extend into a large tooth-filled maw.",
    /*END*/ "\n"};

// colored npc race abbreviations
// for now full name for effect
const char *race_family_abbrevs[NUM_RACE_TYPES + 1] = {
    "Unknown",
    "\tWHmnd\tn",
    "\tDUndd\tn",
    "\tgAnml\tn",
    "\trDrgn\tn",
    "\tYGnt\tn",
    "\tRAbrt\tn",
    "\tcCnst\tn",
    "\tRElem\tn",
    "\tCFey\tn",
    "\tmM\tgBst\tn",
    "\tBM\tWHmn\tn",
    "\tMOoze\tn",
    "\tDOut\tws\tn",
    "\tGPlnt\tn",
    "\tyVrmn\tn",
    "\n"};
const char *race_family_short[NUM_RACE_TYPES + 1] = {
    "???",
    "Hmn",
    "Und",
    "Anm",
    "Drg",
    "Gnt",
    "Abr",
    "Con",
    "Ele",
    "Fey",
    "Bst",
    "MoH",
    "Oze",
    "Out",
    "Plt",
    "Ver",
    "\n"};
const char *race_family_types[NUM_RACE_TYPES + 1] = {
    "Unknown", //0
    "Humanoid",
    "Undead",
    "Animal",
    "Dragon",
    "Giant", //5
    "Aberration",
    "Construct",
    "Elemental",
    "Fey",
    "Magical Beast", //10
    "Monstrous Humanoid",
    "Ooze",
    "Outsider",
    "Plant",
    "Vermin", //15
    "\n"};

const char *class_names[NUM_CLASSES + 1] = {
    "Wizard", //0
    "Cleric",
    "Rogue",
    "Warrior",
    "Monk",
    "Druid", //5
    "Berserker",
    "Sorcerer",
    "Paladin",
    "Ranger",
    "Bard", //10
    "Weapon Master",
    "Arcane Archer",
    "Stalwart Defender",
    "Shifter",
    "Duelist", //15
    "Mystic Theurge",
    "Alchemist",
    "Arcane Shadow",
    "Sacred Fist",
    //  "unfinished",
    //  "unfinished",
    //  "unfinished",
    //  "Shadow Dancer", //20
    //  "Assassin",
    "\n"};

const char *attack_hit_types[NUM_ATTACK_TYPES + 1] = {
    "Hit", //0
    "Sting",
    "Whip",
    "Slash",
    "Bite",
    "Bludgeon", //5
    "Crush",
    "Pound",
    "Claw",
    "Maul",
    "Thrash", //10
    "Pierce",
    "Blast",
    "Punch",
    "Stab",
    "Slice", //15
    "Thrust",
    "Hack",
    "Rake",
    "Peck",
    "Smash", //20
    "Trample",
    "Charge",
    "Gore", //23
    /**/
    "\n"};

const char *instrument_names[MAX_INSTRUMENTS + 1] = {
    "Lyre",
    "Flute",
    "Horn",
    "Drum",
    "Harp",
    "Mandolin",
    /**/
    "\n"};

const char *spec_armor_type[NUM_SPEC_ARMOR_TYPES + 1] = {
    "Undefined",
    /**/
    "Clothing/Robes",
    "Padded Armor",
    "Leather Armor",
    "Studded Leather Armor",
    "Light Chain Armor",
    "Hide Armor",
    "Scale Armor",
    "Chainmail",
    "Piecemeal Armor",
    "Splint Armor",
    "Banded Armor",
    "Halfplate Armor",
    "Fullplate Armor",
    /**/
    "Buckler",
    "Small Shield",
    "Large Shield",
    "Tower Shield",
    /**/
    "Cloth Hood",
    "Padded Helm",
    "Leather Helm",
    "Studded Leather Helm",
    "Light Chain Helm",
    "Hide Helm",
    "Scale Helm",
    "Chainmail Helm",
    "Piecemeal Helm",
    "Splint Helm",
    "Banded Helm",
    "Halfplate Helm",
    "Fullplate Helm",
    /**/
    "Cloth Sleeves",
    "Padded Sleeves",
    "Leather Sleeves",
    "Studded Leather Sleeves",
    "Light Chain Sleeves",
    "Hide Sleeves",
    "Scale Sleeves",
    "Chainmail Sleeves",
    "Piecemeal Sleeves",
    "Splint Vambraces",
    "Banded Vambraces",
    "Halfplate Vambraces",
    "Fullplate Vambraces",
    "Fullplate Vambraces",
    /**/
    "Cloth Pants",
    "Padded Leggings",
    "Light Chain Leggings",
    "Hide Leggings",
    "Scale Leggings",
    "Chainmail Leggings",
    "Piecemeal Leggings",
    "Splint Greaves",
    "Banded Greaves",
    "Halfplate Greaves",
    "Fullplate Greaves",
    "\n"};

/* ammo types */
const char *ammo_types[NUM_AMMO_TYPES + 1] = {
    "Undefined",
    "arrow",
    "bolt",
    "sling bullet",
    "dart",
    "\n"};

/* weapon head types */
const char *weapon_head_types[NUM_WEAPON_HEAD_TYPES + 1] = {
    "Undefined",
    "Blade",
    "Head",
    "Point",
    "Bow",
    "Pouch",
    "Cord",
    "Mesh",
    "Chain",
    "Fist",
    "\n"};

/* weapon handle types */
const char *weapon_handle_types[NUM_WEAPON_HANDLE_TYPES + 1] = {
    "Undefined",
    "Shaft",
    "Hilt",
    "Strap",
    "String",
    "Grip",
    "Handle",
    "Glove",
    "\n"};

/* sizes */
const char *sizes[NUM_SIZES + 1] = {
    "Undefined",
    "Fine",
    "Diminutive",
    "Tiny",
    "Small",
    "Medium",
    "Large",
    "Huge",
    "Gargantuan",
    "Colossal",
    "\n"};
/* weapon damage types */
const char *weapon_damage_types[NUM_WEAPON_DAMAGE_TYPES + 1] = {
    "Bludgeoning",
    "Slashing",
    "Piercing",
    "Non-Lethal",
    "\n"};

/* What type of trap */
const char *trap_type[MAX_TRAP_TYPES + 1] = {
    "Leave Room",
    "Open Door",
    "Unlock Door",
    "Open Container",
    "Unlock Container",
    "Get Object",
    "Enter Room (sets off without check opportunity at least once)",
    "\n"};

/* Trap-effects, add 1000 to this value to reference the proper values in
 act.item.c */
const char *trap_effects[MAX_TRAP_EFFECTS + 1] = {
    "Wall of Flames (20d20 fire)",
    "Lightning Strike (20d20 electric)",
    "Impaling Spike (15d20 puncture, para 5 rounds)",
    "Dark Glyph (300+15d20 mental, feeblemind 25 rounds)",
    "Spike Pit (2d10 puncture)",
    "Harmful Dart (10+6d6 puncture)",
    "Poison Gas (poison 10 rounds)",
    "Dispel Magic",
    "Dark Warrior Ambush (1-3 dark warriors attack)",
    "Boulder Drop (current-hp/5 damage)",
    "Wall Smash (current-hp/5 damage)",
    "Spider Horde (current-hp/6 damage)",
    "Harmful Gas (current-hp/4 poison damage)",
    "Freezing Conditions (10d20 cold)",
    "Skeletal Hands (50% chance death or 10d40 damage)",
    "Spider Webs (web spell 20 rounds, 1d3 spiders)",
    "\n"};

/* ranged weapon types (bows, etc) */
const char *ranged_weapons[NUM_RANGED_WEAPONS + 1] = {
    "bow",
    "crossbow",
    "\n"};

/* ranged weapon missiles (arrows, etc) */
const char *ranged_missiles[NUM_RANGED_MISSILES + 1] = {
    "arrow",
    "bolt",
    "\n"};

/* note - in utils.c there are two functions for alignment as well
 * char *get_align_by_num(int align)
 * char *get_align_by_num_cnd(int align)
 */
const char *alignment_names[NUM_ALIGNMENTS + 1] = {
    "\tYLawful \tWGood\tn",
    "\tcNeutral \tWGood\tn",
    "\tRChaotic \tWGood\tn",
    "\tYLawful \tcNeutral\tn",
    "\tcTrue Neutral\tn",
    "\tRChaotic \tcNeutral\tn",
    "\tYLawful \tDEvil\tn",
    "\tcNeutral \tDEvil\tn",
    "\tRChaotic \tDEvil\tn",
    "\n"};
const char *alignment_names_nocolor[NUM_ALIGNMENTS + 1] = {
    "Lawful Good",
    "Neutral Good",
    "Chaotic Good",
    "Lawful Neutral",
    "True Neutral",
    "Chaotic Neutral",
    "Lawful Evil",
    "Neutral Evil",
    "Chaotic Evil",
    "\n"};

/* structure for immortal prefix */
const char *admin_level_names[LVL_IMPL - LVL_IMMORT + 2] = {
    "\tB[  \tC Staff   \tB ]\tn", // LVL_IMMORTAL
    "\tB[\tCSenior Staff\tB]\tn", // LVL_STAFF
    "\tB[\tCWorld Forger\tB]\tn", // LVL_GRSTAFF
    "\tB[   \tCForger\tB   ]\tn", // LVL_IMPL
    "\n",
};

const char *craft_type[NUM_CRAFT + 1] = {
    "RESERVED",
    "brew",
    "craft",
    "fletch",
    "knit",
    "mine",
    "disenchant",
    "synthesize",
    "hunt",
    "forest",
    "divide",
    "resize",
    "augment",
    "work on a supplyorder for",
    "convert",
    "restring",
    "wand-craft",
    "staff-craft",
    "\n"};

const char *size_names[NUM_SIZES + 1] = {
    "RESERVED",
    "Fine",
    "Diminutive",
    "Tiny",
    "Small",
    "Medium",
    "Large",
    "Huge",
    "Gargantuan",
    "Colossal",
    "\n"};

/* used for armor class calculations */
const int size_modifiers_inverse[NUM_SIZES] = {
    0,
    8,
    4,
    2,
    1,
    0,
    -1,
    -2,
    -4,
    -8};

/* used for attack roll calculations */
const int size_modifiers[NUM_SIZES] = {
    0,
    -8,
    -4,
    -2,
    -1,
    0,
    1,
    2,
    4,
    8};

const int grapple_size_modifiers[NUM_SIZES] = {
    0,
    -16,
    -12,
    -8,
    -4,
    0,
    4,
    8,
    12,
    16};

const char *dr_damtypes[NUM_DR_DAMTYPES + 1] = {
    "bludgeoning",
    "slashing",
    "piercing",
    "\n"};

const char *damtypes[NUM_DAM_TYPES + 1] = {
    "RESERVED",
    "fire",
    "cold",
    "air",
    "earth",
    "acid",
    "holy",
    "electric",
    "unholy",
    "slice",
    "puncture",
    "force",
    "sound",
    "poison",
    "disease",
    "negative",
    "illusion",
    "mental",
    "light",
    "energy",
    "water",
    "celestial poison",
    "\n"};

const char *damtype_display[NUM_DAM_TYPES + 1] = {
    "RESERVED",
    "Damage Fire",
    "Damage Cold",
    "Damage Air",
    "Damage Earth",
    "Damage Acid",
    "Damage Holy",
    "Damage Electric",
    "Damage Unholy",
    "Damage Slice",
    "Damage Puncture",
    "Damage Force",
    "Damage Sound",
    "Damage Poison",
    "Damage Disease",
    "Damage Negative",
    "Damage Illusion",
    "Damage Mental",
    "Damage Light",
    "Damage Energy",
    "Damage Water",
    "\n"};

/** Description of cardinal directions.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *dirs[NUM_OF_DIRS + 1] = {
    "north",
    "east",
    "south",
    "west",
    "up",
    "down",
    "northwest", /* Diagonals only used if CONFIG_DIAGONAL_DIRS is set */
    "northeast",
    "southeast",
    "southwest",
    "\n"};

const char *autoexits[NUM_OF_DIRS + 1] = {
    "N",
    "E",
    "S",
    "W",
    "U",
    "D",
    "nw",
    "ne",
    "se",
    "sw",
    "\n"};

/** Room flag descriptions.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *room_bits[NUM_ROOM_FLAGS + 1] = {
    "Dark",
    "Death-Trap",
    "No-Mob",
    "Indoors",
    "Peaceful",
    "Soundproof", //5
    "No-Track",
    "No-Magic",
    "Tunnel",
    "Private",
    "Staff-Room", //10
    "House",
    "House-Crash",
    "Atrium",
    "OLC",
    "*", /* The BFS Mark. (15) */
    "Worldmap",
    "Regenerating",
    "Fly-Needed",
    "No-Recall",
    "Singlefile", //20
    "No-Teleport",
    "Magical-Darkness",
    "Magical-Light",
    "No-Summon",
    "No-Heal", //25
    "No-Fly",
    "Fogged",
    "Airy",
    "Occupied",
    "Tiny-Sized-Room",
    "Diminutive-Sized-Room",
    "Climb-Needed",
    "Trapped",
    "Wild-Generated-Desc",
    "\n"};

// room affect effect
const char *room_affections[NUM_RAFF + 1] = {
    "Fogged",
    "Darkened",
    "Lighted",
    "Stench",
    "Billowing",
    "Anti-Magic Field",
    "Acid-Fogged",
    "Blade-Barriered",
    "Spike Growth",
    "Spike Stone",
    "Holy",
    "Unholy",
    "Obscuring-Mist",
    "\n"};

/** Room flag descriptions. (ZONE_x)
 * @pre Must be in the same order as the defines in structs.h.
 * Must end array with a single newline. */
const char *zone_bits[NUM_ZONE_FLAGS + 1] = {
    "Closed",
    "No-Immortal",
    "Quest",
    "Grid",
    "No-Build",
    "No-Teleport",
    "Worldmap",
    "Not-Claimable",
    "Astral-Plane",
    "Ethereal-Plane",
    "Elemental-Plane",
    "Wilderness",
    "\n"};

/** Exit bits for doors.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *exit_bits[NUM_EXIT_BITS + 1] = {
    "Door",
    "Closed",
    "Locked (easy)",
    "Pickproof",
    "Hidden (easy)",
    "Hidden (medium)",
    "Hidden (hard)",
    "Locked (medium)",
    "Locked (hard)"
    "\n"};

/** Description of the room sector type.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *sector_types[NUM_ROOM_SECTORS + 1] = {
    "Inside", //0
    "City",
    "Field",
    "Forest",
    "Hills",
    "Low Mountains", //5
    "Water (Swim)",
    "Water (No Swim)",
    "In Flight",
    "Underwater",
    "Zone Entrance", //10
    "Road North-South",
    "Road East-West",
    "Road Intersection",
    "Desert",
    "Ocean", //15
    "Marshland",
    "High Mountains",
    "Outer Planes",
    "Underdark - Wild",
    "Underdark - City", //20
    "Underdark - Inside",
    "Underdark - Water (Swim)",
    "Underdark - Water (No Swim)",
    "Underdark - In Flight",
    "Lava", //25
    "Dirt Road North-South",
    "Dirt Road East-West",
    "Dirt Road Intersection",
    "Cave",
    "Jungle",
    "Tundra",
    "Taiga",
    "Beach",
    "\n"};

/** Description of the room sector type.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *sector_types_readable[NUM_ROOM_SECTORS + 1] = {
    "inside", //0
    "in a city",
    "on a field",
    "among the trees",
    "in hilly terrain",
    "in low mountains", //5
    "in shallow water",
    "in deep water",
    "in the air",
    "underwater",
    "at an entrance", //10
    "on a road",
    "on a road",
    "on a road",
    "in a desert",
    "in oceanic waters", //15
    "in marshland",
    "high mountains",
    "in a planar dimension",
    "in an underground wilderness",
    "in an underground city", //20
    "underground",
    "in shallow water underground",
    "in deep water underground",
    "in the air underground",
    "in lava", //25
    "on a dirt road",
    "on a dirt road",
    "on a dirt road",
    "in a cave",
    "in a jungle",
    "on the tundra",
    "in a coniferous forest",
    "on a beach",
    "\n"};

/** How much movement is lost moving through a particular sector type. */
/* make sure it matches SECT_ */
int movement_loss[NUM_ROOM_SECTORS] = {
    1, /* Inside     */ // 0
    1,                  /* City       */
    2,                  /* Field      */
    3,                  /* Forest     */
    4,                  /* Hills      */
    7, /* Mountains  */ //5
    4,                  /* Swimming   */
    3,                  /* Unswimable */
    1,                  /* Flying     */
    5,                  /* Underwater */
    1,                  // zone entrance  10
    1,                  // road north-south
    1,                  // road east-west
    1,                  // road intersection
    3,                  // Desert
    11,                 // Ocean  15
    5,                  // Marshland
    10,                 // High Mountain
    6,                  // planes
    3,                  // ud wild
    1,                  // ud city  20
    1,                  // ud inside
    4,                  // ud swim
    3,                  // ud noswim
    1,                  // ud flying
    6,                  // lava  25
    1,                  // dirt road
    1,                  // dirt road
    1,                  // dirt road
    3,                  // caves 29
    4,                  // jungle, wet, mid elevations, hot.
    4,                  // tundra, dry, high elevations, extreme cold.
    4,                  // boreal forest, higher elevations, cold.
    2,                  // beach, borders low areas and water. 33
};

/** PC and NPC sex.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *genders[NUM_GENDERS + 1] = {
    "neutral",
    "male",
    "female",
    "\n"};

/** Character positions.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *position_types[NUM_POSITIONS + 1] = {
    "\tRDead\tn", //0
    "\tRMortally wounded\tn",
    "\tRIncapacitated\tn",
    "\tRStunned\tn",
    "\tRSleeping\tn",
    "\tRReclining\tn", //5
    "\tRResting\tn",
    "\tRSitting\tn",
    "Fighting",
    "Standing",
    "\n"};

/** Player flags.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *player_bits[NUM_PLR_BITS + 1] = {
    "KILLER", //0
    "THIEF",
    "FROZEN",
    "DONTSET",
    "WRITING",
    "MAILING", //5
    "CSH",
    "SITEOK",
    "NOSHOUT",
    "NOTITLE",
    "DELETED", //10
    "LOADRM",
    "NO_WIZL",
    "NO_DEL",
    "INVST",
    "CRYO", //15
    "DEAD", /* You should never see this flag on a character in game. */
    "IBT_BUG",
    "IBT_IDEA",
    "IBT_TYPO",
    "\n"};

/** Mob action flags.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *action_bits[NUM_MOB_FLAGS + 1] = {
    "<spec>",
    "Sentinel",
    "Scavenger",
    "Mob",
    "Aware",
    "Aggro", //5
    "Zone-Sentinel",
    "Wimpy",
    "Aggro-Evil",
    "Aggro-Good",
    "Aggro-Neutral", //10
    "Memory",
    "Helper",
    "Uncharmable",
    "Unsummonable",
    "Immune-Sleep", //15
    "Unbashable",
    "Unblindable",
    "Unkillable",
    "Sentient",
    "!DEAD!", /* You should never see this. (20)*/
    "Mountable",
    "Immune-Deaf",
    "Does-Not-Fight",
    "Classless",
    "Ungrappleable", //25
    "Animal-Companion",
    "Familiar",
    "Paladin-Mount",
    "Summoned-Elemental",
    "Animated-Dead", //30
    "Guard",
    "Citizen",
    "Hunter",
    "Listen",
    "Lit-Up", //35
    "Planar-Ally",
    "No-Steal",
    "Info-Kill",
    "Custom-Gold",
    "No-AI", //40
    "unused",
    "unused",
    "unused",
    "unused", //45
    "unused",
    "unused",
    "unused",
    "unused",
    "unused", //50
    "unused",
    "unused",
    "unused",
    "unused",
    "unused", //55
    "unused",
    "unused",
    "unused",
    "unused",
    "unused", //60
    "unused",
    "unused",
    "unused", /* 63 */
    "unused", /* 64 */
    "\n"};

/** PC Preference flags.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *preference_bits[NUM_PRF_FLAGS + 1] = {
    "Brief",
    "Compact",
    "Shout-Toggle",
    "Tell-Toggle",
    "Display-HP",
    "Display-PSP",
    "Display-Moves",
    "AutoExits",
    "Hassle-Toggle",
    "Quest",
    "Summon",
    "NO_REP",
    "Light",
    "C1",
    "C2",
    "Wiznet-Toggle",
    "L1",
    "L2",
    "Auction-Toggle",
    "Gossip-Toggle",
    "NO_GTZ",
    "RoomFlags",
    "Display-Auto",
    "CLS",
    "Buildwalking",
    "AFK",
    "AutoLoot",
    "AutoGold",
    "AutoSplit",
    "AutoSacrifice",
    "AutoAssist",
    "Display-Map",
    "AutoKey",
    "AutoDoors",
    "NO_CT",
    "AutoScan",
    "Display-Exp",
    "Display-Exits",
    "Display-Room",
    "Display-Memtime",
    "Display-Actions",
    "Auto-Reload",
    "Combat-Rolls",
    "GUI-Mode",
    "Hint-Display",
    "Auto-Collect",
    "Role Player",
    "Bombs are Aoe",
    "Faer-Causes-Flee",
    "PvP-Enabled",
    "Auto-Consider",
    "\n"};

/** Bonus types */
const char *bonus_types[NUM_BONUS_TYPES + 1] = {
    "Untyped",
    "Alchemical",
    "Armor",
    "Circumstance",
    "Competence",
    "Deflection",
    "Dodge",
    "Enhancement",
    "Inherent",
    "Insight",
    "Luck",
    "Morale",
    "Natural Armor",
    "Profane",
    "Racial",
    "Resistance",
    "Sacred",
    "Shield",
    "Size",
    "Trait",
    "\n"};

/** Affected bits.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *affected_bits[NUM_AFF_FLAGS + 1] = {
    "\0", /* DO NOT REMOVE!! */
    "Blinded",
    "Invisible",
    "Detect-Alignment",
    "Detect-Invisible",
    "Detect-Magic", //5
    "Sense-Life",
    "Water-Walk",
    "Sanctuary",
    "OnLoad MobGroup",
    "Cursed", //10
    "Infra-Vision",
    "Poison",
    "Protect-Evil",
    "Protect-Good",
    "Sleep", //15
    "Not-Trackable",
    "Flying",
    "Underwater-Breathing",
    "Sneaking",
    "Hiding", //20
    "Vampiric-Curse",
    "Charmed",
    "Blurred",
    "Mode-PowerAttack",
    "Mode-Expertise", //25
    "Hasted",
    "Mode-Total-Defense",
    "Protect-Elements",
    "Deaf",
    "Fear", //30
    "Stunned",
    "Paralyzed",
    "Ultra-Vision",
    "Grappled",
    "Tamed", //35
    "Climb",
    "Nauseated",
    "Non-Detection",
    "Slowed",
    "Fire-Shielded", //40
    "Cold-Shielded",
    "Minor-Globed",
    "Acid-Shielded",
    "Size-Changed",
    "True-Sight", //45
    "Spot-Mode",
    "Fatigued",
    "Regenerating",
    "Diseased",
    "T-Transform", //50
    "Globe-of-Invuln",
    "Listen-Mode",
    "Displaced",
    "Spell-Mantled",
    "Confused", //55
    "Refuged",
    "Spell-Turning",
    "Mind-Blanked",
    "Shadow-Shielded",
    "Time-Stopped", //60
    "Bravery",
    "Free-Movement",
    "Faerie-Fired",
    "Battletide",
    "Spell-Resistant", //65
    "Dimensional-Locked",
    "Death-Ward",
    "Mode-Spellbattle",
    "Vampiric-Touch",
    "Blackmantled", //70
    "Danger-Sense",
    "SafeFall",
    "Tower-of-Iron-Will",
    "Inertial-Barrier",
    "Not-teleportable", //75
    "DamageBoost",      // AFF_MAX_DAMAGE
    "Incorporeal",
    "Caged",
    "Mage-Flamed",
    "Dark-Vision", //80
    "Body-Weaponry",
    "Farsee",
    "Menz-Choker",
    "Mode-RapidShot",
    "Dazed",
    "Flat-footed",
    "Dual-wield",
    "Flurry-of-Blows",
    "Counterspell",
    "Defensive-Casting", //90
    "Whirlwind-Attack",
    "Charging",
    "WildShape",
    "Feinted",
    "Pinned",
    "Mirror-Imaged",
    "Warded",
    "Entangled",
    "Acrobatic",
    "Blinking",
    "Aware",
    "Crippled-by-Critical",
    "Levitating",
    "Bleeding",
    "Staggered",
    "Dazzled",
    "Shaken",
    "\n"};

/** Affected bits descriptions.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline.
 * MUST BE 57 CHARACTERS OR LESS.
 * */
const char *affected_bit_descs[NUM_AFF_FLAGS + 1] = {
    "\0", /* DO NOT REMOVE!! */
    //|---------------------------------------------------------|
    "You can't see a thing.",
    "You are invisible.",
    "You can sense the the auras of others.",
    "You can see the invisible.",
    "You can sense the auras of object imbued with magic.", //5
    "You can sense living creatures.",
    "You can walk on water.",
    "SHOULD NOT SEE - CONTACT STAFF",
    "SHOULD NOT SEE - CONTACT STAFF",
    "You have been cursed.", //10
    "You can see in the infra-red spectrum.",
    "You have been poisoned.",
    "You are warded against evil.",
    "You are warded against good.",
    "You are afflicted with magical sleep.", //15
    "You cannot be tracked.",
    "You are flying.",
    "You can breathe underwater.",
    "You are attempting to move quietly.",
    "You are attempting to hide.", //20
    "You are afflicted with a vampiric curse.",
    "You are controlled by another.",
    "Your form is blurred.",
    "You sacrifice accuracy to inflict more damage in battle.",
    "You sacrifice accuracy to improve your defense.", //25
    "You are moving supernaturally fast.",
    "You are focusing on total defense.",
    "You are protected from the elements.",
    "You can't hear a thing.",
    "You are terrified.", //30
    "You are stunned.",
    "You can't move!",
    "You can see in the ultra-violet spectrum.",
    "You are grappled.",
    "You are tamed.", //35
    "You can climb anything.",
    "You are nauseated.",
    "You are shielded from scrying magic.",
    "You are moving more slowly than usual.",
    "You are surrounded by a shield of flames.", //40
    "You are surrounded by a shield of swirling snow.",
    "You are protected by a minor globe of invulnerability.",
    "You are surrounded by a shield of corrosive acid.",
    "You are not your usual size.",
    "Your vision is supernaturally clear.", //45
    "You are actively observing your surroundings.",
    "You are fatigued.",
    "Your body is healing at an increased rate.",
    "You are suffering from a disease.",
    "You are under the effect of Tenser's Transformation", //50
    "You are protected by a globe of invulnerability.",
    "You are actively listening to your surroundings.",
    "Your are not where you seem to be.",
    "You are protected by a spell mantle.",
    "You are confused.", //55
    "You have taken refuge.",
    "You turn magic that targets you.",
    "Your mind is blank.",
    "The shadows shield you from harm.",
    "You have stopped time.", //60
    "You feel brave.",
    "You can move freely in any environment.",
    "Your outline is highlighted by purple and pink flames.",
    "You are battle incarnate.",
    "You are resistant to spells.", //65
    "You are locked to this plane of existence.",
    "You are warded from death magic.",
    "You are under the effect of Spellbattle.",
    "You have a vampiric touch.",
    "Your body does not heal as it should.", //70
    "You can innately sense danger.",
    "You can fall from any height unharmed.",
    "You are resistant to psionic damage.",
    "SHOULD NOT SEE - CONTACT STAFF",
    "You can not be targeted by teleportation magic.", //75
    "Your next attack will deal additional damage.",   // AFF_MAX_DAMAGE
    "You are incorporeal",
    "You have been caged and can not interact with anyone.",
    "You are glowing.",
    "You can see in the dark.", //80
    "Your body is a weapon.",
    "You can see farther than others.",
    "Your items synergize with each other.",
    "You are firing your ranged weapons more quickly.",
    "You are dazed.", //85
    "You have been caught unawares.",
    "You are fighting with two weapons.",
    "You are attacking with a flurry of blows.",
    "You will counter any spell you can.",
    "You are casting defensively.", //90
    "You will spread your attacks among all of your enemies.",
    "You are charging into battle.",
    "You are shape-changed into a different race.",
    "You have been feinted in combat (flat-footed).",
    "You are pinned.", //95
    "Duplicate illusionary images of you exist.",
    "You have a powerful ward on you (melee damage absorb).",
    "You are entangled (can't move).",
    "You feel more acrobatic!",
    "You are blinking between prime and ethereal planes!", //100
    "You are aware of backstab attempts now!",
    "You have been crippled by a nasty critical attack!",
    "You are levitating above the ground!",
    "You are suffering bleed damage each round until healed!",
    "You are staggered - 50% chance to fail spells or a single melee attack!", //105
    "You are dazzled and will suffer -1 to attacks and perception checks!"
    "You are shaken: -2 to attack rolls, saves and skills checks!",
    "\n"};

/** Connection type descriptions.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *connected_types[NUM_CON_STATES + 1] = {
    "Playing", //0
    "Disconnecting",
    "Get Name",
    "Confirm Name",
    "Get Password",
    "Get New PW", //5
    "Confirm New PW",
    "Select Sex",
    "Select Class",
    "Reading MOTD",
    "Main Menu", //10
    "Get Descrip",
    "Changing PW 1",
    "Changing PW 2",
    "Changing PW 3",
    "Self-Delete 1", //15
    "Self-Delete 2",
    "Disconnecting",
    "Object Edit",
    "Room Edit",
    "Zone Edit", //20
    "Mobile Edit",
    "Shop Edit",
    "Text Edit",
    "Config Edit",
    "Social Edit", //25
    "Trigger Edit",
    "Help Edit",
    "Quest Edit",
    "Preference Edit",
    "IBT Edit", //30
    "Protocol Detection",
    "Select Race",
    "Clan Edit",
    "Message Edit",
    "Spells Known Edit",   //35
    "Class Help",          //36
    "Alignment Selection", //37
    "Race Help",           // 38
    "HL Quest Edit",
    "Select Stats", //40
    "Acct Name",
    "Acct Name Confirm",
    "Acct Menu",
    "Acct Add Char",
    "Acct Char Pwd",
    "House Edit",
    "Composing Mail Message",
    "\n" /* make sure this matches NUM_CON_STATES */
};

/** Describes the position in the equipment listing.
 * @pre Must be in the same order as the defines.
 * Not used in sprinttype() so no \n. */
const char *wear_where[NUM_WEARS] = {
    "\tY{Used As Light}\tn      ", //0
    "\tY{Worn On Finger}\tn     ",
    "\tY{Worn On Finger}\tn     ",
    "\tY{Worn Around Neck}\tn   ",
    "\tY{Worn Around Neck}\tn   ",
    "\tY{Worn On Body}\tn       ", //5
    "\tY{Worn On Head}\tn       ",
    "\tY{Worn On Legs}\tn       ",
    "\tY{Worn On Feet}\tn       ",
    "\tY{Worn On Hands}\tn      ",
    "\tY{Worn On Arms}\tn       ", //10
    "\tY{Worn As Shield}\tn     ",
    "\tY{Worn About Body}\tn    ",
    "\tY{Worn About Waist}\tn   ",
    "\tY{Worn Around Wrist}\tn  ",
    "\tY{Worn Around Wrist}\tn  ", //15
    "\tY{Wielded}\tn            ",
    "\tY{Held}\tn               ",
    "\tY{Wielded Offhand}\tn    ",
    "\tY{Held Offhand}\tn       ",
    "\tY{Wielded Twohanded}\tn  ", //20
    "\tY{Held Twohanded}\tn     ",
    "\tY{Worn On Face}\tn       ",
    /* todo */
    "\tY{Worn As Ammo Pouch}\tn ",
    "\tY{Worn In Ear}\tn        ",
    "\tY{Worn In Ear}\tn        ", //25
    "\tY{Worn On Eyes}\tn       ",
    "\tY{Worn As Badge}\tn      ",
};

/* Describes where an item can be worn.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *equipment_types[NUM_WEARS + 1] = {
    "Used as light", //0
    "Worn on right finger",
    "Worn on left finger",
    "First worn around Neck",
    "Second worn around Neck",
    "Worn on body", //5
    "Worn on head",
    "Worn on legs",
    "Worn on feet",
    "Worn on hands",
    "Worn on arms", //10
    "Worn as shield",
    "Worn about body",
    "Worn around waist",
    "Worn around right wrist",
    "Worn around left wrist", //15
    "Wielded",
    "Held",
    "Wielded offhand",
    "Held offhand",
    "Wielded twohands", //20
    "Held twohands",
    "Worn on face",
    /* todo */
    "Worn as ammo pouch",
    "Worn in right ear",
    "Worn in left ear", //25
    "Worn on eyes",
    "Worn as badge",
    "\n"};

/* weapon family */
const char *weapon_family[NUM_WEAPON_FAMILIES + 1] = {
    "Monk",
    "Light-Blade",
    "Hammer",
    "Ranged",
    "Heavy-Blade",
    "Polearm",
    "Double-Weapon",
    "Axe",
    "\n"};

/* weapon flags */
const char *weapon_flags[NUM_WEAPON_FLAGS + 1] = {
    "Simple",
    "Martial",
    "Exotic",
    "Ranged",
    "Thrown",
    "Reach",
    "Entangle",
    "Trip",
    "Double",
    "Disarm",
    "Non-Lethal",
    "Slow-Reload",
    "Balanced",
    "Charge",
    "Repeating",
    "Two-Handed",
    "Light",
    "Blocking",
    "Bracing",
    "Deadly",
    "Distracting",
    "Fragile",
    "Grappling",
    "Performance",
    "Strength",
    "Sunder",
    "\n"};

const char *ability_score_names[6] = {
    "strength",
    "dexterity",
    "constitution",
    "intelligence",
    "wisdom",
    "charisma"};

/* armor type (none, light, medium, heavy, etc) */
const char *armor_type[NUM_ARMOR_TYPES + 1] = {
    "None",
    "Light Armor",
    "Medium Armor",
    "Heavy Armor",
    "Normal Shield",
    "Tower Shield",
    "\n"};

// labels for item proficiency category
const char *item_profs[NUM_ITEM_PROFS + 1] = {
    "None",
    "Minimal Weapon Proficiency",
    "Basic Weapon Proficiency",
    "Advanced Weapon Proficiency",
    "Master Weapon Proficiency",
    "Exotic Weapon Proficiency",
    "Light Armor Proficiency",
    "Medium Armor Proficiency",
    "Heavy Armor Proficiency",
    "Shield Proficiency",
    "Tower Shield Proficiency",
    "\n"};

const char *material_name[NUM_MATERIALS + 1] = {
    "RESERVED",
    "cotton",
    "leather",
    "glass",
    "gold",
    "organic",
    "paper",
    "steel",
    "wood",
    "bone",
    "crystal",
    "ether",
    "adamantine",
    "mithril",
    "iron",
    "copper",
    "ceramic",
    "satin",
    "silk",
    "dragonhide",
    "burlap",
    "velvet",
    "platinum",
    "obsidian",
    "wool",
    "onyx",
    "ivory",
    "brass",
    "marble",
    "bronze",
    "pewter",
    "ruby",
    "sapphire",
    "emerald",
    "gemstone",
    "granite",
    "stone",
    "energy",
    "hemp",
    "diamond",
    "earth",
    "silver",
    "alchemical silver",
    "cold iron",
    "darkwood",
    "\n"};

/** Describes the type of object.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *item_types[NUM_ITEM_TYPES + 1] = {
    "UNDEFINED", //0
    "Light",
    "Scroll",
    "Wand",
    "Staff",
    "Weapon", //5
    "Furniture",
    "Ranged-Weapon",
    "Treasure",
    "Armor/Shield",
    "Potion", //10
    "Wearable",
    "OTHER",
    "Trash",
    "Ammo",
    "Container", //15
    "Note",
    "Liquid-Cont",
    "Key",
    "Food",
    "Money", //20
    "Pen",
    "Boat",
    "Fountain",
    "Clan-Armor",
    "Crafting Crystal", //25
    "Essence",
    "Crafting Material",
    "Spellbook",
    "Portal",
    "Plant", //30
    /* todo list */
    "Trap",
    "Teleport",
    "Poison",
    "Summon",
    "Switch", //35
    "Ammo-Pouch",
    "Pick",
    "Instrument",
    "Disguise",
    "Wall", //40
    "Bowl",
    "Ingredient",
    "Blocker",
    "Wagon",
    "Resources", //45
    "Pet",       //46
    "Blueprint", //47 /* NewCraft */
    "Treasure Chest",
    "\n"};

/** Describes the wear flags set on an item.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *wear_bits[NUM_ITEM_WEARS + 1] = {
    "(Takeable)", //0
    "Finger",
    "Neck",
    "Body",
    "Head",
    "Legs", //5
    "Feet",
    "Hands",
    "Arms",
    "Shield",
    "About-Body", //10
    "Waist",
    "Wrist",
    "Wield",
    "Hold",
    "Face", //15
    /* todo */
    "Ammo-Pouch",
    "Ears",
    "Eyes",
    "Badge",
    "\n"};

/** Describes the extra flags applied to an item.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *extra_bits[NUM_ITEM_FLAGS + 1] = {
    "Glows", //0
    "Hums",
    "Not-Rentable",
    "Not-Donateable",
    "Immune-Invis",
    "Invisible", //5
    "Magical",
    "Not-Droppable",
    "Blessed",
    "Anti-Good",
    "Anti-Evil", //10
    "Anti-Neutral",
    "Anti-Wizard",
    "Anti-Cleric",
    "Anti-Rogue",
    "Anti-Warrior", //15
    "Not-Sellable",
    "Quest-Item",
    "Anti-Human",
    "Anti-Elf",
    "Anti-Dwarf", //20
    "Anti-Half-Troll",
    "Anti-Monk",
    "Anti-Druid",
    "Mold",
    "Anti-Crystal-Dwarf", //25
    "Anti-Halfling",
    "Anti-Half-Elf",
    "Anti-Half-Orc",
    "Anti-Gnome",
    "Anti-Berserker", //30
    "Anti-Trelux",
    "Anti-Sorcerer",
    "Decaying",
    "Anti-Paladin",
    "Anti-Ranger", //35
    "Anti-Bard",
    "Anti-Arcana-Golem",
    /* todo */
    "Floating",
    "Hidden",
    "Magical-Light", //40
    "No-Locate",
    "No-Burn",
    "Transient",
    "Auto-Proc",
    "Flaming", //45
    "Frosty",
    "Ki-Focus",
    "Anti-WeaponMaster",
    "Anti-Drow",
    "Masterwork",
    "\n"};

/** Describes the apply types.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *apply_types[NUM_APPLIES + 1] = {
    "<None>",
    "Strength",
    "Dexterity",
    "Intelligence",
    "Wisdom",
    "Constitution", /*5*/
    "Charisma",
    "Class",
    "Level",
    "Age",
    "Weight", /*10*/
    "Height",
    "Max-PSP",
    "Max-HP",
    "Max-Move",
    "Gold", /*15*/
    "Experience",
    "!Unused!",
    "Hitroll",
    "Damroll",
    "Save-Fortitude", /*20*/
    "Save-Reflex",
    "Save-Will",
    "Save-Poison",
    "Save-Death",
    "Spell-Resist", /*25*/
    "Size",
    "Armor-Class",
    "Resist-Fire",
    "Resist-Cold",
    "Resist-Air", /*30*/
    "Resist-Earth",
    "Resist-Acid",
    "Resist-Holy",
    "Resist-Electric",
    "Resist-Unholy", /*35*/
    "Resist-Slice",
    "Resist-Puncture",
    "Resist-Force",
    "Resist-Sound",
    "Resist-Poison", /*40*/
    "Resist-Disease",
    "Resist-Negative",
    "Resist-Illusion",
    "Resist-Mental",
    "Resist-Light", /*45*/
    "Resist-Energy",
    "Resist-Water",
    "Damage-Reduction",
    "Grant-Feat",
    "Skill-Bonus",
    "\n" /*51*/
};

/** Matrix to show which bonus types are allowed for which apply locations */
/* "Untyped",
  "Alchemical",
  "Armor",
  "Circumstance",
  "Competence",
  "Deflection",
  "Dodge",
  "Enhancement",
  "Inherent",
  "Insight",
  "Luck",
  "Morale",
  "Natural Armor",
  "Profane",
  "Racial",
  "Resistance",
  "Sacred",
  "Shield",
  "Size",
  "Trait",
  "\n"
 */
const int valid_bonus_types[NUM_APPLIES][NUM_BONUS_TYPES] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //<None>
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1}, //Strength
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1}, //Dexterity
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1}, //Intelligence
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1}, //Wisdom
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1}, //Constitution
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1}, //Charisma
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //Class
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //Level
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //Age
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //Weight
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //Height
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, //Max-PSP
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, //Max-HP
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, //Max-Move
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //Gold
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //Experience
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //!Unused!
    {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1}, //Hitroll
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1}, //Damroll
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1}, //Save-Fortitude
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1}, //Save-Reflex
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1}, //Save-Will
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1}, //Save-Poison
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1}, //Save-Death
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, //Spell-Resist
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, //Size
    {1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1}, //Armor-Class
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Fire
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Cold
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Air
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Earth
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Acid
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Holy
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Electric
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Unholy
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Slice
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Puncture
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Force
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Sound
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Poison
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Disease
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Negative
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Illusion
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Mental
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Light
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Energy
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Resist-Water
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Damage-Reduction
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //Grant-Feat
};

/** Describes the closure mechanism for a container.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *container_bits[NUM_CONT_FLAGS + 1] = {
    "Closeable",
    "Pick-Proof",
    "Closed",
    "Locked",
    "\n",
};

/** Describes the liquid description.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *drinks[NUM_LIQ_TYPES + 1] = {
    "water",
    "beer",
    "wine",
    "ale",
    "dark ale",
    "whisky",
    "lemonade",
    "firebreather",
    "local speciality",
    "slime mold juice",
    "milk",
    "tea",
    "coffee",
    "blood",
    "salt water",
    "clear water",
    "\n"};

/** Describes a one word alias for each type of liquid.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *drinknames[NUM_LIQ_TYPES + 1] = {
    "water",
    "beer",
    "wine",
    "ale",
    "ale",
    "whisky",
    "lemonade",
    "firebreather",
    "local",
    "juice",
    "milk",
    "tea",
    "coffee",
    "blood",
    "salt",
    "water",
    "\n"};

/** Define the effect of liquids on hunger, thirst, and drunkenness, in that
 * order. See values.doc for more information.
 * @pre Must be in the same order as the defines. */
int drink_aff[][3] = {
    {0, 1, 10},
    {3, 2, 5},
    {5, 2, 5},
    {2, 2, 5},
    {1, 2, 5},
    {6, 1, 4},
    {0, 1, 8},
    {10, 0, 0},
    {3, 3, 3},
    {0, 4, -8},
    {0, 3, 6},
    {0, 1, 6},
    {0, 1, 6},
    {0, 2, -1},
    {0, 1, -2},
    {0, 0, 13}};

/** Describes the color of the various drinks.
 * @pre Must be in the same order as the defines.
 * Must end array with a single newline. */
const char *color_liquid[NUM_LIQ_TYPES + 1] = {
    "clear",
    "brown",
    "clear",
    "brown",
    "dark",
    "golden",
    "red",
    "green",
    "clear",
    "light green",
    "white",
    "brown",
    "black",
    "red",
    "clear",
    "crystal clear",
    "\n"};

/** Used to describe the level of fullness of a drink container. Not used in
 * sprinttype() so no \n. */
const char *fullness[] = {
    "less than half ",
    "about half ",
    "more than half ",
    ""};

const char *portal_types[] = {
    "Normal",
    "Random",
    "CheckFlags",
    "Clanhall",
    "\n"};

const char *spell_schools[NUM_SCHOOLS + 1] = {
    "None",
    "Abjuration",
    "Conjuration",
    "Divination",
    "Enchantment",
    "Evocation",
    "Illusion",
    "Necromancy",
    "Transmutation",
    "\n"};

int spell_bonus[][NUM_CIRCLES + 1] = {
    //circle 0 1 2 3 4 5 6 7 8 9 10 number-circles
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //casting stat, 0
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //10
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //12
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //13
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //14
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //15
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, //16
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, //17
    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, //18
    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, //19
    {0, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0}, //20
    {0, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0}, //21
    {0, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0}, //22
    {0, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0}, //23
    {0, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0}, //24
    {0, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0}, //25
    {0, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0}, //26
    {0, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0}, //27
    {0, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0}, //28
    {0, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0}, //29
    {0, 3, 3, 2, 2, 2, 2, 1, 1, 1, 0}, //30
    {0, 3, 3, 2, 2, 2, 2, 1, 1, 1, 0}, //31
    {0, 3, 3, 3, 2, 2, 2, 2, 1, 1, 0}, //32
    {0, 3, 3, 3, 2, 2, 2, 2, 1, 1, 0}, //33
    {0, 3, 3, 3, 3, 2, 2, 2, 2, 1, 0}, //34
    {0, 3, 3, 3, 3, 2, 2, 2, 2, 1, 0}, //35
    {0, 4, 3, 3, 3, 3, 2, 2, 2, 2, 0}, //36
    {0, 4, 3, 3, 3, 3, 2, 2, 2, 2, 0}, //37
    {0, 4, 4, 3, 3, 3, 3, 2, 2, 2, 0}, //38
    {0, 4, 4, 3, 3, 3, 3, 2, 2, 2, 0}, //39
    {0, 4, 4, 4, 3, 3, 3, 3, 2, 2, 0}, //40
    {0, 4, 4, 4, 3, 3, 3, 3, 2, 2, 0}, //41
    {0, 4, 4, 4, 4, 3, 3, 3, 3, 2, 0}, //42
    {0, 4, 4, 4, 4, 3, 3, 3, 3, 2, 0}, //43
    {0, 5, 4, 4, 4, 4, 3, 3, 3, 3, 0}, //44
    {0, 5, 4, 4, 4, 4, 3, 3, 3, 3, 0}, //45
    {0, 5, 5, 4, 4, 4, 4, 3, 3, 3, 0}, //46
    {0, 5, 5, 4, 4, 4, 4, 3, 3, 3, 0}, //47
    {0, 5, 5, 5, 4, 4, 4, 4, 3, 3, 0}, //48
    {0, 5, 5, 5, 4, 4, 4, 4, 3, 3, 0}, //49
    {0, 5, 5, 5, 5, 4, 4, 4, 4, 3, 0}, //50
    {0, 5, 5, 5, 5, 4, 4, 4, 4, 3, 0}, //51
    {0, 5, 5, 5, 5, 4, 4, 4, 4, 4, 0}, //52
    {0, 5, 5, 5, 5, 4, 4, 4, 4, 4, 0}, //53
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, //54
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, //55
    {0, 5, 5, 5, 5, 5, 5, 4, 4, 4, 0}, //56
    {0, 5, 5, 5, 5, 5, 5, 4, 4, 4, 0}, //57
    {0, 5, 5, 5, 5, 5, 5, 5, 4, 4, 0}, //58
    {0, 5, 5, 5, 5, 5, 5, 5, 4, 4, 0}, //59
    {0, 5, 5, 5, 5, 5, 5, 5, 5, 4, 0}, //60
    {0, 5, 5, 5, 5, 5, 5, 5, 5, 4, 0}, //61
    {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0}, //62
    {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0}, //63
    {0, 6, 5, 5, 5, 5, 5, 5, 5, 5, 0}, //64
    {0, 6, 5, 5, 5, 5, 5, 5, 5, 5, 0}, //65
    {0, 6, 6, 5, 5, 5, 5, 5, 5, 5, 0}, //65
    {0, 6, 6, 5, 5, 5, 5, 5, 5, 5, 0}, //66
    {0, 6, 6, 6, 5, 5, 5, 5, 5, 5, 0}, //67
    {0, 6, 6, 6, 5, 5, 5, 5, 5, 5, 0}, //68
    {0, 6, 6, 6, 6, 5, 5, 5, 5, 5, 0}, //69
    {0, 6, 6, 6, 6, 5, 5, 5, 5, 5, 0}, //70
};

/** Strength attribute affects.
 * The fields are hit mod, damage mod, weight carried mod, and weight wielded
 * mod. */
cpp_extern const struct str_app_type str_app[] = {
    {-5, -5, 3, 1},       /* str = 0 */
    {-5, -5, 10, 1},      //1
    {-4, -4, 20, 2},      //2
    {-4, -4, 30, 3},      //3
    {-3, -3, 40, 4},      //4
    {-3, -3, 55, 5},      //5	/* str = 5 */
    {-2, -2, 80, 6},      //6
    {-2, -2, 90, 7},      //7
    {-1, -1, 100, 8},     //8
    {-1, -1, 100, 9},     //9
    {0, 0, 115, 10},      //10	/* str = 10 */
    {0, 0, 115, 11},      //11
    {1, 1, 140, 12},      //12
    {1, 1, 140, 13},      //13
    {2, 2, 170, 14},      //14
    {2, 2, 200, 15},      //15	/* str = 15 */
    {3, 3, 230, 16},      //16
    {3, 3, 300, 18},      //17
    {4, 4, 300, 20},      //18	/* str = 18 */
    {4, 4, 400, 22},      //19
    {5, 5, 400, 25},      //20	/* str = 20 */
    {5, 5, 520, 28},      //21
    {6, 6, 520, 32},      //22
    {6, 6, 700, 36},      //23
    {7, 7, 700, 40},      //24
    {7, 7, 920, 44},      //25	/* str = 25 */
    {8, 8, 920, 48},      //26
    {8, 8, 1200, 52},     //27
    {9, 9, 1200, 56},     //28
    {9, 9, 1500, 60},     //29
    {10, 10, 1500, 64},   //30
    {10, 10, 1850, 68},   //31
    {11, 11, 1850, 72},   //32
    {11, 11, 2250, 76},   //33
    {12, 12, 2250, 80},   //34
    {12, 12, 2700, 84},   //35
    {13, 13, 2700, 88},   //36
    {13, 13, 3200, 92},   //37
    {14, 14, 3200, 96},   //38
    {14, 14, 3750, 100},  //39
    {15, 15, 4300, 104},  //40
    {15, 15, 4900, 108},  //41
    {16, 16, 5400, 112},  //42
    {16, 16, 6050, 116},  //43
    {17, 17, 6700, 120},  //44
    {17, 17, 7400, 124},  //45
    {18, 18, 8100, 128},  //46
    {18, 18, 8850, 132},  //47
    {19, 19, 9600, 136},  //48
    {19, 19, 9700, 140},  //49
    {20, 20, 9800, 140},  //50
    {20, 20, 9999, 140},  //51
    {21, 21, 10500, 145}, //52
    {21, 21, 10500, 145}, //53
    {22, 22, 11000, 150}, //54
    {22, 22, 11000, 150}, //55
    {23, 23, 11500, 155}, //56
    {23, 23, 11500, 155}, //57
    {24, 24, 12000, 160}, //58
    {24, 24, 12000, 160}, //59
    {25, 25, 12500, 165}, //60
    {25, 25, 12500, 165}, //61
    {26, 26, 13000, 170}, //62
    {26, 26, 13000, 170}, //63
    {27, 27, 13500, 175}, //64
    {27, 27, 13500, 175}, //65
    {28, 28, 14000, 180}, //66
    {28, 28, 14000, 180}, //67
    {29, 29, 14500, 185}, //68
    {29, 29, 14500, 185}, //69
    {30, 30, 15000, 190}, //70
    {30, 30, 15000, 190}, //71
};

/** Dexterity skill modifiers for thieves.
 * The fields are for pick pockets, pick locks, find traps, sneak and hide. */
cpp_extern const struct dex_skill_type dex_app_skill[] = {
    {-99, -99, -90, -99, -60}, /* dex = 0 */
    {-90, -90, -60, -90, -50}, /* dex = 1 */
    {-80, -80, -40, -80, -45},
    {-70, -70, -30, -70, -40},
    {-60, -60, -30, -60, -35},
    {-50, -50, -20, -50, -30}, /* dex = 5 */
    {-40, -40, -20, -40, -25},
    {-30, -30, -15, -30, -20},
    {-20, -20, -15, -20, -15},
    {-15, -10, -10, -20, -10},
    {-10, -5, -10, -15, -5}, /* dex = 10 */
    {-5, 0, -5, -10, 0},
    {0, 0, 0, -5, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}, /* dex = 15 */
    {0, 5, 0, 0, 0},
    {5, 10, 0, 5, 5},
    {10, 15, 5, 10, 10}, /* dex = 18 */
    {15, 20, 10, 15, 15},
    {15, 20, 10, 15, 15}, /* dex = 20 */
    {20, 25, 10, 15, 20},
    {20, 25, 15, 20, 20},
    {25, 25, 15, 20, 20},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25}, /* dex = 25 */
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25}, //30
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25}, //35
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25}, //40
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25}, //45
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25}, //50
    {25, 30, 15, 25, 25},

    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},
    {25, 30, 15, 25, 25},

};

/** Dexterity attribute affects.
 * The fields are reaction, missile attacks, and defensive (armor class). */
cpp_extern const struct dex_app_type dex_app[] = {
    {-5, -5, -5}, /* dex = 0 */
    {-5, -5, -5}, /* dex = 1 */
    {-4, -4, -4}, //2
    {-4, -4, -4}, //3
    {-3, -3, -3}, //4
    {-3, -3, -3}, /* dex = 5 */
    {-2, -2, -2}, //6
    {-2, -2, -2}, //7
    {-1, -1, -1}, //8
    {-1, -1, -1}, //9
    {0, 0, 0},    /* dex = 10 */
    {0, 0, 0},    //11
    {1, 1, 1},    //12
    {1, 1, 1},    //13
    {2, 2, 2},    //14
    {2, 2, 2},    /* dex = 15 */
    {3, 3, 3},    //16
    {3, 3, 3},    //17
    {4, 4, 4},    /* dex = 18 */
    {4, 4, 4},    //19
    {5, 5, 5},    /* dex = 20 */
    {5, 5, 5},    //21
    {6, 6, 6},    //22
    {6, 6, 6},    //23
    {7, 7, 7},    //24
    {7, 7, 7},    /* dex = 25 */
    {8, 8, 8},    //26
    {8, 8, 8},    //27
    {9, 9, 9},    //28
    {9, 9, 9},    //29
    {10, 10, 10}, //30
    {10, 10, 10}, //31
    {11, 11, 11}, //32
    {11, 11, 11}, //33
    {12, 12, 12}, //34
    {12, 12, 12}, //35
    {13, 13, 13}, //36
    {13, 13, 13}, //37
    {14, 14, 14}, //38
    {14, 14, 14}, //39
    {15, 15, 15}, //40
    {15, 15, 15}, //41
    {16, 16, 16}, //42
    {16, 16, 16}, //43
    {17, 17, 17}, //44
    {17, 17, 17}, //45
    {18, 18, 18}, //46
    {18, 18, 18}, //47
    {19, 19, 19}, //48
    {19, 19, 19}, //49
    {20, 20, 20}, //50
    {20, 20, 20}, //51
    {21, 21, 21}, //52
    {21, 21, 21}, //53
    {22, 22, 22}, //54
    {22, 22, 22}, //55
    /*unfixed*/
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
    {22, 22, 22},
};

/** Constitution attribute affects.
 * The field referenced is for hitpoint bonus. */
cpp_extern const struct con_app_type con_app[] = {
    {-5}, /* con = 0 */
    {-5}, /* con = 1 */
    {-4}, // 2
    {-4}, //3
    {-3}, //4
    {-3}, /* con = 5 */
    {-2}, //6
    {-2}, //7
    {-1}, //8
    {-1}, //9
    {0},  /* con = 10 */
    {0},  //11
    {1},  //12
    {1},  //13
    {2},  //14
    {2},  /* con = 15 */
    {3},  //16
    {3},  //17
    {4},  /* con = 18 */
    {4},  //19
    {5},  /* con = 20 */
    {5},  //21
    {6},  //22
    {6},  //23
    {7},  //24
    {7},  /* con = 25 */
    {8},  /* con = 26 */
    {8},  /* con = 27 */
    {9},  //28
    {9},  //29
    {10}, //30
    {10}, //31
    {11}, //32
    {11}, //33
    {12}, //34
    {12}, //35
    {13}, //36
    {13}, //37
    {14}, //38
    {14}, //39
    {15}, //40
    {15}, //41
    {16}, //42
    {16}, //43
    {17}, //44
    {17}, //45
    {18}, //46
    {18}, //47
    {19}, //48
    {19}, //49
    {20}, //50
    {20}, //51

    {21},
    {21},
    {22},
    {22},
    {23},
    {23},
    {24},
    {24},
    {25},
    {25},
    {26},
    {26},
    {27},
    {27},
    {28},
    {28},
    {29},
    {29},
    {30},
    {30},
    {31},
    {31},
};

/** Intelligence attribute affects. */
cpp_extern const struct int_app_type int_app[] = {
    {-5}, //0
    {-5}, //1
    {-4}, // 2
    {-4}, //3
    {-3}, //4
    {-3}, //5
    {-2}, //6
    {-2}, //7
    {-1}, //8
    {-1}, //9
    {0},  //10
    {0},  //11
    {1},  //12
    {1},  //13
    {2},  //14
    {2},  //15
    {3},  //16
    {3},  //17
    {4},  //18
    {4},  //19
    {5},  //20
    {5},  //21
    {6},  //22
    {6},  //23
    {7},  //24
    {7},  //25
    {8},  //26
    {8},  //27
    {9},  //28
    {9},  //29
    {10}, //30
    {10}, //31
    {11}, //32
    {11}, //33
    {12}, //34
    {12}, //35
    {13}, //36
    {13}, //37
    {14}, //38
    {14}, //39
    {15}, //40
    {15}, //41
    {16}, //42
    {16}, //43
    {17}, //44
    {17}, //45
    {18}, //46
    {18}, //47
    {19}, //48
    {19}, //49
    {20}, //50
    {20}, //51

    {21},
    {21},
    {22},
    {22},
    {23},
    {23},
    {24},
    {24},
    {25},
    {25},
    {26},
    {26},
    {27},
    {27},
    {28},
    {28},
    {29},
    {29},
    {30},
    {30},
    {31},
    {31},
};

/** Wisdom attribute affects. */
cpp_extern const struct wis_app_type wis_app[] = {
    {-5}, /*  0 */
    {-5}, /*  1 */
    {-4}, // 2
    {-4}, //3
    {-3}, //4
    {-3}, /* 5 */
    {-2}, //6
    {-2}, //7
    {-1}, //8
    {-1}, //9
    {0},  /*  10 */
    {0},  //11
    {1},  //12
    {1},  //13
    {2},  //14
    {2},  /* 15 */
    {3},  //16
    {3},  //17
    {4},  /* 18 */
    {4},  //19
    {5},  /* 20 */
    {5},  //21
    {6},  //22
    {6},  //23
    {7},  //24
    {7},  /* 25 */
    {8},  /* 26 */
    {8},  /* 27 */
    {9},  //28
    {9},  //29
    {10}, //30
    {10}, //31
    {11}, //32
    {11}, //33
    {12}, //34
    {12}, //35
    {13}, //36
    {13}, //37
    {14}, //38
    {14}, //39
    {15}, //40
    {15}, //41
    {16}, //42
    {16}, //43
    {17}, //44
    {17}, //45
    {18}, //46
    {18}, //47
    {19}, //48
    {19}, //49
    {20}, //50
    {20}, //51

    {21},
    {21},
    {22},
    {22},
    {23},
    {23},
    {24},
    {24},
    {25},
    {25},
    {26},
    {26},
    {27},
    {27},
    {28},
    {28},
    {29},
    {29},
    {30},
    {30},
    {31},
    {31},
};

/** Charisma attribute affects. */
cpp_extern const struct cha_app_type cha_app[] = {
    {-5}, /* 0 */
    {-5}, /* 1 */
    {-4}, // 2
    {-4}, //3
    {-3}, //4
    {-3}, /* 5 */
    {-2}, //6
    {-2}, //7
    {-1}, //8
    {-1}, //9
    {0},  /* 10 */
    {0},  //11
    {1},  //12
    {1},  //13
    {2},  //14
    {2},  /*  15 */
    {3},  //16
    {3},  //17
    {4},  /* 18 */
    {4},  //19
    {5},  /* 20 */
    {5},  //21
    {6},  //22
    {6},  //23
    {7},  //24
    {7},  /* 25 */
    {8},  /* 26 */
    {8},  /* 27 */
    {9},  //28
    {9},  //29
    {10}, //30
    {10}, //31
    {11}, //32
    {11}, //33
    {12}, //34
    {12}, //35
    {13}, //36
    {13}, //37
    {14}, //38
    {14}, //39
    {15}, //40
    {15}, //41
    {16}, //42
    {16}, //43
    {17}, //44
    {17}, //45
    {18}, //46
    {18}, //47
    {19}, //48
    {19}, //49
    {20}, //50
    {20}, //51

    {21},
    {21},
    {22},
    {22},
    {23},
    {23},
    {24},
    {24},
    {25},
    {25},
    {26},
    {26},
    {27},
    {27},
    {28},
    {28},
    {29},
    {29},
    {30},
    {30},
    {31},
    {31},
};

/* lore values */
int lore_app[] = {
    0,  //0
    50, //1
    100,
    150,
    200,
    300, //5
    500,
    1000,
    2500,
    3750,
    4800, //10
    6500,
    13000,
    17000,
    20000,
    30000, //15
    40000,
    60000,
    80000,
    100000,
    150000, //20
    200000,
    250000,
    300000,
    400000,
    500000, //25
    600000,
    700000,
    800000,
    900000,
    1000000, //30
    1200000,
    1400000,
    1600000,
    1800000,
    2000000, //35
    2200000,
    2400000,
    2600000,
    2800000,
    3000000, //40
    3200000,
    3400000,
    3600000,
    3800000,
    4000000, //45
    4200000, //46
    4400000, //47
    4600000, //48
    4800000, //49
    5000000, //50
    5200000, //51
    5400000, //52
    5600000, //53
    5800000, //54
    6000000, //55
    6200000, //56
    6400000, //57
    6600000, //58
    6800000, //59
    7000000, //60
    7200000, //61
    7400000, //62
    7600000, //63
    7800000, //64
    8000000, //65
    8200000, //66
    8400000, //67
    8600000, //68
    8800000, //69
    9000000, //70
    9200000, //71
    9400000, //72
    9600000, //73
    9800000, //74
    9900000, //75
    9999999, //76
    9999999, //77
    9999999, //78
    9999999, //79
    9999999, //80
    9999999, //81
    9999999, //82
    9999999, //83
    9999999, //84
    9999999, //85
    9999999, //86
    9999999, //87
    9999999, //88
    9999999, //89
    9999999, //90
    9999999, //91
    9999999,
    9999999,
    9999999,
    9999999, //95
    9999999,
    9999999,
    9999999,
    9999999,
    9999999, //100
    9999999,
    9999999,
    9999999,
    9999999,
    9999999, //105
    9999999,
    9999999,
    9999999,
    9999999,
    9999999, //110

    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    9999999,
    /* high value for staff etc */
};

/** Define a set of opposite directions from the cardinal directions. */
int rev_dir[] = {
    SOUTH,
    WEST,
    NORTH,
    EAST,
    DOWN,
    UP,
    SOUTHEAST,
    SOUTHWEST,
    NORTHWEST,
    NORTHEAST};

/** The names of the days of the mud week. Not used in sprinttype(). */
const char *weekdays[] = {
    "the Day of the \tDMoon\tn",
    "the Day of the \tMBull\tn",
    "the Day of the \tDDeception\tn",
    "the Day of \tbThunder\tn",
    "the Day of \tWFreedom\tn",
    "the Day of the \tCGreat Powers\tn",
    "the Day of the \tYSun\tn"};

/** The names of the mud months. Not used in sprinttype(). */
const char *month_name[] = {
    "Month of \tWWinter\tn", /* 0 */
    "Month of the \tWWinter \tcWolf\tn",
    "Month of the \tWFrost \tYGiant\tn",
    "Month of the \tCOld \tDForces\tn",
    "Month of the \twGrand \tGStruggle\tn",
    "Month of the \tYSpr\tGing\tn",
    "Month of \tGN\tYa\tGt\tYu\tGr\tYe\tn",
    "Month of \tmFutility\tn",
    "Month of the \tRDragon\tn",
    "Month of the \tYSun\tn",
    "Month of the \tRHe\tYat\tn",
    "Month of the \tRBat\tDtle\tn",
    "Month of the \tDDark \twSha\tDdes\tn",
    "Month of the \tDS\tch\tDa\tcd\tDo\tcw\tDs\tn",
    "Month of the \tCLong \tDShadows\tn",
    "Month of the \tWAncient \tDDarkness\tn",
    "Month of the \trGreat \tREvil\tn"};

/** Names for mob trigger types. */
const char *trig_types[] = {
    "Global",
    "Random",
    "Command",
    "Speech",
    "Act",
    "Death",
    "Greet",
    "Greet-All",
    "Entry",
    "Receive",
    "Fight",
    "HitPrcnt",
    "Bribe",
    "Load",
    "Memory",
    "Cast",
    "Leave",
    "Door",
    "UNUSED",
    "Time",
    "\n"};

/** Names for object trigger types. */
const char *otrig_types[] = {
    "Global",
    "Random",
    "Command",
    "UNUSED1",
    "UNUSED2",
    "Timer",
    "Get",
    "Drop",
    "Give",
    "Wear",
    "UNUSED3",
    "Remove",
    "UNUSED4",
    "Load",
    "UNUSED5",
    "Cast",
    "Leave",
    "UNUSED6",
    "Consume",
    "Time",
    "\n"};

/** Names for world (room) trigger types. */
const char *wtrig_types[] = {
    "Global",
    "Random",
    "Command",
    "Speech",
    "UNUSED1",
    "Zone Reset",
    "Enter",
    "Drop",
    "UNUSED2",
    "UNUSED3",
    "UNUSED4",
    "UNUSED5",
    "UNUSED6",
    "UNUSED7",
    "UNUSED8",
    "Cast",
    "Leave",
    "Door",
    "Login",
    "Time",
    "\n"};

/** The names of the different channels that history is stored for.
 * @todo Only referenced by do_history at the moment. Should be moved local
 * to that function. */
const char *history_types[] = {
    "all",
    "say",
    "gossip/chat",
    "wiznet",
    "tell",
    "shout",
    "grats",
    "holler",
    "auction",
    "clantalk",
    "\n"};

/** Flag names for Ideas, Bugs and Typos (defined in ibt.h) */
const char *ibt_bits[] = {
    "Resolved",
    "Important",
    "InProgress",
    "\n"};

/* NewCraft */
/* Craft Flags */
const char *craft_flags[] = {
    "Needs Recipe",
    "\n"};

/* Requirement Flags */
const char *requirement_flags[] = {
    "INROOM",
    "!REMOVE",
    "SAVEonFAIL",
    "\n"};

/* Feat types  */
const char *feat_types[] = {
    "none", //0
    "general ability",
    "combat feat",
    "spellcasting feat",
    "metamagic feat",
    "craft feat", //5
    "wild feat",
    "divine feat",
    "class feat",
    "innate ability",
    "domain power",     //10
    "performance feat", //11
    "\n"};

const char *ability_names[] = {
    "RESERVED",
    "Acrobatics",
    "Stealth",
    "Unused1",
    "Perception",
    "Unused2",
    "Heal",
    "Intimidate",
    "Concentration",
    "Spellcraft",
    "Appraise",
    "Discipline",
    "Total Defense",
    "Lore",
    "Ride",
    "Unused3",
    "Climb",
    "Unused4",
    "Sleight of Hand",
    "Unused5",
    "Bluff",
    "Unused6",
    "Diplomacy",
    "Disable Device",
    "Disguise",
    "Escape Artist",
    "Handle Animal",
    "Unused7",
    "Sense Motive",
    "Survival",
    "Swim",
    "Use Magic Device",
    "Unused8",
    "Perform",
    /*crafting*/
    "woodworking",
    "tailoring",
    "alchemy",
    "armorsmithing",
    "weaponsmithing",
    "bowmaking",
    "gemcutting",
    "leatherworking",
    "trapmaking",
    "poisonmaking",
    "metalworking",
    /*knowledge*/
    "arcana",
    "engineering",
    "dungeoneering",
    "geography",
    "history",
    "local",
    "nature",
    "nobility",
    "religion",
    "planes",
    "\n"};

const char *draconic_heritage_names[NUM_DRACONIC_HERITAGE_TYPES + 1] = {
    "none",
    "black",
    "blue",
    "green",
    "red",
    "white",
    "brass",
    "bronze",
    "copper",
    "silver",
    "gold",
    "\n" // always last
};

const int draconic_heritage_energy_types[NUM_DRACONIC_HERITAGE_TYPES + 1] = {
    0,            // none
    DAM_ACID,     // black
    DAM_ELECTRIC, // blue
    DAM_POISON,   // green
    DAM_FIRE,     // red
    DAM_COLD,     // white
    DAM_FIRE,     // brass
    DAM_ELECTRIC, // bronze
    DAM_ACID,     // copper
    DAM_COLD,     // silver
    DAM_FIRE,     // gold
    0             // always last
};

// the number of spells received per level for caster types
const int wizard_slots[LVL_IMPL + 1][NUM_CIRCLES + 1] = {
    //   1st,2nd,3rd,4th,5th,6th,7th,8th,9th,10th
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0}, //7
    {0, 4, 4, 3, 2, 0, 0, 0, 0, 0, 0},
    {0, 4, 4, 3, 2, 1, 0, 0, 0, 0, 0}, //9
    {0, 4, 4, 3, 3, 2, 0, 0, 0, 0, 0},
    {0, 4, 4, 4, 3, 2, 1, 0, 0, 0, 0}, //11
    {0, 4, 4, 4, 3, 3, 2, 0, 0, 0, 0},
    {0, 4, 4, 4, 4, 3, 2, 1, 0, 0, 0}, //13
    {0, 4, 4, 4, 4, 3, 3, 2, 0, 0, 0},
    {0, 4, 4, 4, 4, 4, 3, 2, 1, 0, 0}, //15
    {0, 4, 4, 4, 4, 4, 3, 3, 2, 0, 0},
    {0, 4, 4, 4, 4, 4, 4, 3, 2, 1, 0}, //17
    {0, 4, 4, 4, 4, 4, 4, 3, 3, 2, 0},
    {0, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0},
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //20
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //21
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //22
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //23
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //24
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //25
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //26
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //27
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //28
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //29
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //30
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //31
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //32
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}, //33
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}  //34
};

const int sorcerer_slots[LVL_IMPL + 1][NUM_CIRCLES + 1] = {
    // 0,1st,2nd,3rd,4th,5th,6th,7th,8th,9th,10th
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 6, 5, 3, 0, 0, 0, 0, 0, 0, 0},
    {0, 6, 6, 4, 0, 0, 0, 0, 0, 0, 0}, //7
    {0, 6, 6, 5, 3, 0, 0, 0, 0, 0, 0},
    {0, 6, 6, 6, 4, 0, 0, 0, 0, 0, 0}, //9
    {0, 6, 6, 6, 5, 3, 0, 0, 0, 0, 0},
    {0, 6, 6, 6, 6, 4, 0, 0, 0, 0, 0}, //11
    {0, 6, 6, 6, 6, 5, 3, 0, 0, 0, 0},
    {0, 6, 6, 6, 6, 6, 4, 0, 0, 0, 0}, //13
    {0, 6, 6, 6, 6, 6, 5, 3, 0, 0, 0},
    {0, 6, 6, 6, 6, 6, 6, 4, 0, 0, 0}, //15
    {0, 6, 6, 6, 6, 6, 6, 5, 3, 0, 0},
    {0, 6, 6, 6, 6, 6, 6, 6, 4, 0, 0}, //17
    {0, 6, 6, 6, 6, 6, 6, 6, 5, 3, 0},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 4, 0},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //20
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //21
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //22
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //23
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //24
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //25
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //26
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //27
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //28
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //29
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //30
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //31
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //32
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, //33
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}  //34
};

const int bard_slots[LVL_IMPL + 1][NUM_CIRCLES + 1] = {
    // 1st,2nd,3rd,4th,5th,6th,7th,8th,9th,10th
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0}, //7
    {0, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0}, //9
    {0, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0}, //11
    {0, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0},
    {0, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0}, //13
    {0, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0},
    {0, 4, 3, 3, 3, 2, 0, 0, 0, 0, 0}, //15
    {0, 4, 4, 3, 3, 2, 0, 0, 0, 0, 0},
    {0, 4, 4, 4, 3, 3, 1, 0, 0, 0, 0}, //17
    {0, 4, 4, 4, 4, 3, 2, 0, 0, 0, 0},
    {0, 4, 4, 4, 4, 4, 3, 0, 0, 0, 0},
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //20
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //21
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //22
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //23
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //24
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //25
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //26
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //27
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //28
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //29
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //30
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //31
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //32
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}, //33
    {0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0}  //34
};

/** known spells for sorcs **/
const int sorcerer_known[LVL_IMPL + 1][NUM_CIRCLES + 1] = {
    // 0,1st,2nd,3rd,4th,5th,6th,7th,8th,9th,10th
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 5, 3, 2, 0, 0, 0, 0, 0, 0, 0}, //7
    {0, 5, 3, 2, 1, 0, 0, 0, 0, 0, 0},
    {0, 5, 4, 3, 2, 0, 0, 0, 0, 0, 0}, //9
    {0, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0},
    {0, 5, 5, 4, 3, 2, 0, 0, 0, 0, 0}, //11
    {0, 5, 5, 4, 3, 2, 1, 0, 0, 0, 0},
    {0, 5, 5, 4, 4, 3, 2, 0, 0, 0, 0}, //13
    {0, 5, 5, 4, 4, 3, 2, 1, 0, 0, 0},
    {0, 5, 5, 4, 4, 4, 3, 2, 0, 0, 0}, //15
    {0, 5, 5, 4, 4, 4, 3, 2, 1, 0, 0},
    {0, 5, 5, 4, 4, 4, 3, 3, 2, 0, 0}, //17
    {0, 5, 5, 4, 4, 4, 3, 3, 2, 1, 0},
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 2, 0},
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //20
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //21
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //22
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //23
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //24
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //25
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //26
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //27
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //28
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //29
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //30
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //31
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //32
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}, //33
    {0, 5, 5, 4, 4, 4, 3, 3, 3, 3, 0}  //34
};

/** known spells for bards **/
const int bard_known[LVL_IMPL + 1][NUM_CIRCLES + 1] = {
    // 0,1st,2nd,3rd,4th,5th,6th,7th,8th,9th,10th
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0}, //7
    {0, 4, 4, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 4, 3, 0, 0, 0, 0, 0, 0, 0}, //9
    {0, 4, 4, 3, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 4, 4, 2, 0, 0, 0, 0, 0, 0}, //11
    {0, 4, 4, 4, 3, 0, 0, 0, 0, 0, 0},
    {0, 4, 4, 4, 4, 2, 0, 0, 0, 0, 0}, //13
    {0, 4, 4, 4, 4, 3, 0, 0, 0, 0, 0},
    {0, 4, 4, 4, 4, 3, 0, 0, 0, 0, 0}, //15
    {0, 5, 4, 4, 4, 4, 2, 0, 0, 0, 0},
    {0, 5, 5, 4, 4, 4, 3, 0, 0, 0, 0}, //17
    {0, 5, 5, 5, 4, 4, 3, 0, 0, 0, 0},
    {0, 5, 5, 5, 5, 4, 4, 0, 0, 0, 0},
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //20
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //21
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //22
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //23
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //24
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //25
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //26
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //27
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //28
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //29
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //30
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //31
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //32
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}, //33
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0}  //34
};

const int ranger_slots[LVL_IMPL + 1][NUM_CIRCLES + 1] = {
    // 1st,2nd,3rd,4th,5th,6th,7th,8th,9th,10th
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 11
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 12
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 13
    {0, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 14
    {0, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 15
    {0, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0}, // 16
    {0, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0}, // 17
    {0, 3, 2, 2, 1, 0, 0, 0, 0, 0, 0}, // 18
    {0, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0}, // 19
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 20
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 21
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 22
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 23
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 24
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 25
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 26
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 27
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 28
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 29
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 30
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 31
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 32
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 33
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}  // 34
};

const int paladin_slots[LVL_IMPL + 1][NUM_CIRCLES + 1] = {
    // 1st,2nd,3rd,4th,5th,6th,7th,8th,9th,10th
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 11
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 12
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 13
    {0, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 14
    {0, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 15
    {0, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0}, // 16
    {0, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0}, // 17
    {0, 3, 2, 2, 1, 0, 0, 0, 0, 0, 0}, // 18
    {0, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0}, // 19
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 20
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 21
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 22
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 23
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 24
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 25
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 26
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 27
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 28
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 29
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 30
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 31
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 32
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}, // 33
    {0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0}  // 34
};

const int cleric_slots[LVL_IMPL + 1][NUM_CIRCLES + 1] = {
    // 1st,2nd,3rd,4th,5th,6th,7th,8th,9th,10th
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0},
    {0, 4, 3, 3, 2, 0, 0, 0, 0, 0, 0},
    {0, 4, 4, 3, 2, 1, 0, 0, 0, 0, 0},
    {0, 4, 4, 3, 3, 2, 0, 0, 0, 0, 0}, // 10
    {0, 5, 4, 4, 3, 2, 1, 0, 0, 0, 0},
    {0, 5, 4, 4, 3, 3, 2, 0, 0, 0, 0},
    {0, 5, 5, 4, 4, 3, 2, 1, 0, 0, 0},
    {0, 5, 5, 4, 4, 3, 3, 2, 0, 0, 0},
    {0, 5, 5, 5, 4, 4, 3, 2, 1, 0, 0}, // 15
    {0, 5, 5, 5, 4, 4, 3, 3, 2, 0, 0},
    {0, 5, 5, 5, 5, 4, 4, 3, 2, 1, 0},
    {0, 5, 5, 5, 5, 4, 4, 3, 3, 2, 0},
    {0, 5, 5, 5, 5, 5, 4, 4, 3, 3, 0},
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 20
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 21
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 22
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 23
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 24
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 25
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 26
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 27
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 28
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 29
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 30
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 31
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 32
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 33
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}  // 34
};

const int druid_slots[LVL_IMPL + 1][NUM_CIRCLES + 1] = {
    // 1st,2nd,3rd,4th,5th,6th,7th,8th,9th,10th
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0},
    {0, 4, 3, 3, 2, 0, 0, 0, 0, 0, 0},
    {0, 4, 4, 3, 2, 1, 0, 0, 0, 0, 0},
    {0, 4, 4, 3, 3, 2, 0, 0, 0, 0, 0}, // 10
    {0, 5, 4, 4, 3, 2, 1, 0, 0, 0, 0},
    {0, 5, 4, 4, 3, 3, 2, 0, 0, 0, 0},
    {0, 5, 5, 4, 4, 3, 2, 1, 0, 0, 0},
    {0, 5, 5, 4, 4, 3, 3, 2, 0, 0, 0},
    {0, 5, 5, 5, 4, 4, 3, 2, 1, 0, 0}, // 15
    {0, 5, 5, 5, 4, 4, 3, 3, 2, 0, 0},
    {0, 5, 5, 5, 5, 4, 4, 3, 2, 1, 0},
    {0, 5, 5, 5, 5, 4, 4, 3, 3, 2, 0},
    {0, 5, 5, 5, 5, 5, 4, 4, 3, 3, 0},
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 20
    {5, 5, 5, 5, 5, 4, 4, 4, 4, 0},    // 21
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 22
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 23
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 24
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 25
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 26
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 27
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 28
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 29
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 30
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 31
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 32
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}, // 33
    {0, 5, 5, 5, 5, 5, 4, 4, 4, 4, 0}  // 34
};

const int alchemist_slots[LVL_IMPL + 1][NUM_CIRCLES + 1] = {
    // 1st,2nd,3rd,4th,5th,6th,7th,8th,9th,10th
    //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 3, 1, 0, 0, 0, 0, 0, 0, 0}, //7
    {0, 4, 4, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 5, 4, 3, 0, 0, 0, 0, 0, 0, 0}, //9
    {0, 5, 4, 3, 1, 0, 0, 0, 0, 0, 0},
    {0, 5, 4, 4, 2, 0, 0, 0, 0, 0, 0}, //11
    {0, 5, 5, 4, 3, 0, 0, 0, 0, 0, 0},
    {0, 5, 5, 4, 3, 1, 0, 0, 0, 0, 0}, //13
    {0, 5, 5, 4, 4, 2, 0, 0, 0, 0, 0},
    {0, 5, 5, 5, 4, 3, 0, 0, 0, 0, 0}, //15
    {0, 5, 5, 5, 4, 3, 1, 0, 0, 0, 0},
    {0, 5, 5, 5, 4, 4, 2, 0, 0, 0, 0}, //17
    {0, 5, 5, 5, 5, 4, 3, 0, 0, 0, 0},
    {0, 5, 5, 5, 5, 5, 4, 0, 0, 0, 0},
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //20
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //21
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //22
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //23
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //24
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //25
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //26
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //27
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //28
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //29
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //30
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //31
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //32
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}, //33
    {0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0}  //34
};

// (old) words to use for the spell preparation process for different classes.
const char *spell_prep_dictation[NUM_CASTERS][4] = {
    /* 0       1          2         3*/
    {"pray", "praying", "prayed", "prayers"},               // CLASS_CLERIC
    {"commune", "communing", "communed", "communion"},      // CLASS_DRUID
    {"memorize", "studying", "memorized", "studies"},       // CLASS_WIZARD
    {"meditate", "meditating", "meditated", "meditations"}, // CLASS_SORCERER
    {"chant", "chanting", "chanted", "petitions"},          // CLASS_PALADIN
    {"adjure", "adjuring", "adjured", "adjurations"},       // CLASS_RANGER
    {"compose", "composing", "composed", "compositions"},   // CLASS_BARD
};

/* words to use for the spell preparation process for different classes. */
const char *spell_prep_dict[NUM_CLASSES][4] = {
    /* 0           1             2            3 */
    {"memorize", "studying", "memorized", "studies"},       /* CLASS_WIZARD */
    {"pray", "praying", "prayed", "prayers"},               /* CLASS_CLERIC */
    {"", "", "", ""},                                       /* rogue 2 */
    {"", "", "", ""},                                       /* warrior 3 */
    {"", "", "", ""},                                       /* monk 4 */
    {"commune", "communing", "communed", "communion"},      // CLASS_DRUID
    {"", "", "", ""},                                       /* berserker 6 */
    {"meditate", "meditating", "meditated", "meditations"}, // CLASS_SORCERER
    {"chant", "chanting", "chanted", "petitions"},          // CLASS_PALADIN
    {"adjure", "adjuring", "adjured", "adjurations"},       // CLASS_RANGER
    {"compose", "composing", "composed", "compositions"},   // CLASS_BARD
    {"", "", "", ""},                                       /* weapon master 11 */
    {"", "", "", ""},                                       /* arcane archer 12 */
    {"", "", "", ""},                                       /* stalwart defender 13 */
    {"", "", "", ""},                                       /* shifter 14 */
    {"", "", "", ""},                                       /* duelist 15 */
    {"", "", "", ""},                                       /* mystic theurge 16 */
    {"concoct", "an extract", "concocted", "concoctions"},  /* alchemist 17 */
    {"", "", "", ""},                                       /* arcane shadow 18 */
    {"", "", "", ""},                                       /* sacred fist 19 */
    //  {"",         "",           "",          ""            }, /* psion */
    //  {"",         "",           "",          ""            }, /* psy warr */
    //  {"",         "",           "",          ""            }, /* soul knife */
    //  {"",         "",           "",          ""            }, /* wilder */
    //  {"",         "",           "",          ""            }, /* shadow dancer */
    //  {"",         "",           "",          ""            }, /* assassin */
};

/* words to use for the spell preparation process for different classes. */
const char *spell_consign_dict[NUM_CLASSES][4] = {
    /* 0           1             2            3 */
    {"forget", "forgot", "forgetting", "forgotten"},         /* CLASS_WIZARD */
    {"blank", "blanked", "blanking", "blanken"},             /* CLASS_CLERIC */
    {"", "", "", ""},                                        /* rogue 2 */
    {"", "", "", ""},                                        /* warrior 3 */
    {"", "", "", ""},                                        /* monk 4 */
    {"uncommune", "uncommuned", "uncommuned", "uncommuned"}, // CLASS_DRUID
    {"", "", "", ""},                                        /* berserker 6 */
    {"", "", "", ""},                                        // CLASS_SORCERER
    {"omit", "omitted", "omitting", "omitted"},              // CLASS_PALADIN
    {"unadjure", "unadjured", "unadjuring", "unadjured"},    // CLASS_RANGER
    {"", "", "", ""},                                        // CLASS_BARD
    {"", "", "", ""},                                        /* weapon master 11 */
    {"", "", "", ""},                                        /* arcane archer 12 */
    {"", "", "", ""},                                        /* stalwart defender 13 */
    {"", "", "", ""},                                        /* shifter 14 */
    {"", "", "", ""},                                        /* duelist 15 */
    {"", "", "", ""},                                        /* mystic theurge 16 */
    {"discard", "discarded", "discarding", "discarded"},     /* alchemist 17 */
    {"", "", "", ""},                                        /* arcane shadow 18 */
    {"", "", "", ""},                                        /* sacred fist 19 */
    //  {"",          "",            "",           ""            }, /* psion 18 */
    //  {"",          "",            "",           ""            }, /* psy warr 19 */
    //  {"",          "",            "",           ""            }, /* soul knife 20 */
    //  {"",          "",            "",           ""            }, /* wilder 21 */
    //  {"",          "",            "",           ""            }, /* shadow dancer 22 */
    //  {"",          "",            "",           ""            }, /* assassin 23 */
};

/* ... and bloodlines */
const char *bloodline_names[] = {
    "None",
    "1) Draconic Bloodline",
    "\n" /* end with this */
};

const char *do_cast_types[][6] = {
    /*0*/ /*1*/ /*2*/ /*3*/ /*4*/ /*5*/
    {"Cast", "cast", "Spell", "Magic", "magic", "caster"},
    {"Manifest", "manfest", "Manifestation", "Psionic", "psionics", "psionicist"},
    {"Imbibe", "imbibe", "Extract", "Alchemy", "extracts", "alchemist"},
    /* end with this */
    {"\n", "\n", "\n", "\n", "\n", "\n"}};

/* --- End of constants arrays. --- */

/* Various arrays we count so we can check the world files.  These
 * must be at the bottom of the file so they're pre-declared. */
/** Number of defined room bit descriptions. */
size_t room_bits_count = sizeof(room_bits) / sizeof(room_bits[0]) - 1,
       /** Number of defined action bit descriptions. */
    action_bits_count = sizeof(action_bits) / sizeof(action_bits[0]) - 1,
       /** Number of defined affected bit descriptions. */
    affected_bits_count = sizeof(affected_bits) / sizeof(affected_bits[0]) - 1,
       /** Number of defined extra bit descriptions. */
    extra_bits_count = sizeof(extra_bits) / sizeof(extra_bits[0]) - 1,
       /** Number of defined wear bit descriptions. */
    wear_bits_count = sizeof(wear_bits) / sizeof(wear_bits[0]) - 1;
