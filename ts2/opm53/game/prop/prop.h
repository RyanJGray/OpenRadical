//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_PROP_PROP_H
#define GAME_PROP_PROP_H

#include "common.h"
#include "fx/particle.h"
#include "fx/specialfx.h"
#include "util/matrix.h"

// Forward-declarations.
struct chrdata_s;
struct chrgun_s;
struct floordef_s;
struct hudHealthArmourData_s;
struct obdef_s;
struct player_s;
struct prop_s;
struct setuppropspawn_s;
struct skelmatrices_s;
struct walldef_s;

enum {
  PROP_NULL = -1,
  PROP_CHR01 = 0,
  PROP_CHR02 = 1,
  PROP_CHR03 = 2,
  PROP_CHR04 = 3,
  PROP_CHR05 = 4,
  PROP_CHR06 = 5,
  PROP_CHR07 = 6,
  PROP_CHR08 = 7,
  PROP_CHR09 = 8,
  PROP_CHR10 = 9,
  PROP_CHR11 = 10,
  PROP_CHR12 = 11,
  PROP_CHR13 = 12,
  PROP_CHR14 = 13,
  PROP_CHR15 = 14,
  PROP_CHR16 = 15,
  PROP_CHR17 = 16,
  PROP_CHR18 = 17,
  PROP_CHR19 = 18,
  PROP_CHR20 = 19,
  PROP_CHR21 = 20,
  PROP_CHR22 = 21,
  PROP_CHR23 = 22,
  PROP_CHR24 = 23,
  PROP_CHR25 = 24,
  PROP_CHR26 = 25,
  PROP_CHR27 = 26,
  PROP_CHR28 = 27,
  PROP_CHR29 = 28,
  PROP_CHR30 = 29,
  PROP_CHR31 = 30,
  PROP_CHR32 = 31,
  PROP_CHR33 = 32,
  PROP_CHR34 = 33,
  PROP_CHR35 = 34,
  PROP_CHR36 = 35,
  PROP_CHR37 = 36,
  PROP_CHR38 = 37,
  PROP_CHR39 = 38,
  PROP_CHR40 = 39,
  PROP_CHR41 = 40,
  PROP_CHR42 = 41,
  PROP_CHR43 = 42,
  PROP_CHR44 = 43,
  PROP_CHR45 = 44,
  PROP_CHR46 = 45,
  PROP_CHR47 = 46,
  PROP_CHR48 = 47,
  PROP_CHR49 = 48,
  PROP_CHR50 = 49,
  PROP_RAILSPIDER = 50,
  PROP_RAILBOT = 51,
  PROP_CHR23_H = 52,
  PROP_CHR23_LA = 53,
  PROP_CHR23_RA = 54,
  PROP_CHR23_LL = 55,
  PROP_CHR23_RL = 56,
  PROP_CHR28_H = 57,
  PROP_CHR28_LA = 58,
  PROP_CHR28_RA = 59,
  PROP_CHR34_H = 60,
  PROP_CHR34_LA = 61,
  PROP_CHR34_RA = 62,
  PROP_CHR35_H = 63,
  PROP_CHR40_H = 64,
  PROP_CHR40_LA = 65,
  PROP_CHR40_RA = 66,
  PROP_CHR45_H = 67,
  PROP_CHR45_LA = 68,
  PROP_CHR45_RA = 69,
  PROP_CHR46_H = 70,
  PROP_CHR46_LA = 71,
  PROP_CHR46_RA = 72,
  PROP_CHR23_HAT = 73,
  PROP_DOOR1 = 74,
  PROP_DOOR2 = 75,
  PROP_DOOR3 = 76,
  PROP_DOOR4 = 77,
  PROP_DOOR5 = 78,
  PROP_DOOR6 = 79,
  PROP_DOOR7 = 80,
  PROP_DOOR8 = 81,
  PROP_DOOR9 = 82,
  PROP_DOOR10 = 83,
  PROP_DOOR_SCIFI_1 = 84,
  PROP_MANSIONDOOR1 = 85,
  PROP_MANSIONDOOR2 = 86,
  PROP_MANSIONDOOR3 = 87,
  PROP_MANSIONDOOR4 = 88,
  PROP_MANSIONDOOR5 = 89,
  PROP_MANSIONDOOR6 = 90,
  PROP_MANSIONDOOR7 = 91,
  PROP_MANSIONDOOR8 = 92,
  PROP_MANSIONDOOR9 = 93,
  PROP_MANSIONDOOR10 = 94,
  PROP_MANSIONDOOR11 = 95,
  PROP_MANSIONDOOR12 = 96,
  PROP_MANSIONDOOR13 = 97,
  PROP_VILLAGEDOOR1 = 98,
  PROP_ATOMSMASHERDOOR1 = 99,
  PROP_DAMDOOR01 = 100,
  PROP_DAMDOOR01R = 101,
  PROP_DAMDOOR02 = 102,
  PROP_DAMDOOR02R = 103,
  PROP_DAMDOOR03 = 104,
  PROP_DAMDOOR04 = 105,
  PROP_DAMDOOR05 = 106,
  PROP_DAMDOOR05R = 107,
  PROP_DAMDOOR06 = 108,
  PROP_DAMDOOR07 = 109,
  PROP_DAMDOOR09 = 110,
  PROP_DAMDOOR10 = 111,
  PROP_DAMAPACHE = 112,
  PROP_DAMDOOR02A = 113,
  PROP_DAMDOOR11 = 114,
  PROP_DAMDOOR12 = 115,
  PROP_DAMDOOR13 = 116,
  PROP_DAMSECDOOR1 = 117,
  PROP_RFDOOR01 = 118,
  PROP_RFDOOR02 = 119,
  PROP_DAMRADAR = 120,
  PROP_DAMRADARDISH = 121,
  PROP_DAMRADARSWITCH = 122,
  PROP_DAMELECTRICALSWITCH = 123,
  PROP_DAMTURBINE = 124,
  PROP_DAMCAGE = 125,
  PROP_DAMCAVE = 126,
  PROP_DAMUNDERGROUNDSWITCH = 127,
  PROP_DAMKEYPAD = 128,
  PROP_DAMSECBUTTON1 = 129,
  PROP_DAMSECBUTTON2 = 130,
  PROP_DAMSECBUTTON3 = 131,
  PROP_DAMLASERDOOR = 132,
  PROP_DAMBED = 133,
  PROP_DAMCARDBOARDBOX1 = 134,
  PROP_DAMCARDBOARDBOX2 = 135,
  PROP_DAMCOMPUTERDESK = 136,
  PROP_DAMCONTROLPANEL = 137,
  PROP_DAMDUMPSTER = 138,
  PROP_DAMFILECABINET = 139,
  PROP_DAMMETALSHELVES = 140,
  PROP_DAMSHOWERBENCH = 141,
  PROP_DAMTABLE = 142,
  PROP_DAMWHISKYGLASS = 143,
  PROP_DAMWOODCRATEBIG = 144,
  PROP_DAMWOODCRATESMALL = 145,
  PROP_DAMDRUM = 146,
  PROP_DAMMETALCRATE = 147,
  PROP_DAMOPTABLE = 148,
  PROP_DAMREDLIGHT = 149,
  PROP_DAMFUSEBOX = 150,
  PROP_DAMWALLMONITOR1 = 151,
  PROP_DAMWALLMONITOR2 = 152,
  PROP_DAMVENT = 153,
  PROP_DAMPIPEWHEEL = 154,
  PROP_DAMPIPEDIAL = 155,
  PROP_CS_LENSEFLARE1 = 156,
  PROP_CS_LENSEFLARE2 = 157,
  PROP_CS_LENSEFLARE3 = 158,
  PROP_CS_LENSEFLARE4 = 159,
  PROP_CS_LENSEFLARE5 = 160,
  PROP_CS_LENSEFLARE6 = 161,
  PROP_CS_LENSEFLARE7 = 162,
  PROP_CS_LENSEFLARE8 = 163,
  PROP_TORCHBEAM = 164,
  PROP_RFPOPUPLAUNCHER = 165,
  PROP_RFBRIDGEDYNAMO = 166,
  PROP_RFBRIDGESWITCH = 167,
  PROP_RFPOWERTOWER = 168,
  PROP_RFCRATE = 169,
  PROP_RFCAMERA = 170,
  PROP_RFFLOORGUN = 171,
  PROP_RFROBOTTOOL = 172,
  PROP_RFCONTROLPANEL = 173,
  PROP_CRATE1 = 174,
  PROP_CRATE2 = 175,
  PROP_CHAIR1 = 176,
  PROP_DRUM1 = 177,
  PROP_DRUM2 = 178,
  PROP_TOMBBOX = 179,
  PROP_CASK1 = 180,
  PROP_PLANT1 = 181,
  PROP_FRUIT1 = 182,
  PROP_POPUPBOT = 183,
  PROP_BOMBBOT = 184,
  PROP_CRYSTAL = 185,
  PROP_TOXICBARREL = 186,
  PROP_SKY1 = 187,
  PROP_SKY2 = 188,
  PROP_SKY3 = 189,
  PROP_SKY4 = 190,
  PROP_SKY5 = 191,
  PROP_SKY6 = 192,
  PROP_SKY7 = 193,
  PROP_SKY8 = 194,
  PROP_SKY9 = 195,
  PROP_SKY10 = 196,
  PROP_SKY11 = 197,
  PROP_SKY12 = 198,
  PROP_SKY13 = 199,
  PROP_SKY14 = 200,
  PROP_SKY_PINKDAWN = 201,
  PROP_SKY_GREENDUSK = 202,
  PROP_SKY_COLDNIGHT = 203,
  PROP_SKY_CLEARDAY = 204,
  PROP_SKY_MARS = 205,
  PROP_SKY_PURPLEHAZE = 206,
  PROP_SKY_RAINBOW = 207,
  PROP_SKY_FLAREDAWN = 208,
  PROP_SKY_ORANGE = 209,
  PROP_SKY_BRIGHTDAWN = 210,
  PROP_SKY_CRISPDAWN = 211,
  PROP_SKY_SETTINGSUN = 212,
  PROP_SKY_YELLOWAFTERNOON = 213,
  PROP_SKY_SPACE = 214,
  PROP_SKY_PLANET2 = 215,
  PROP_SKY_MEX = 216,
  PROP_SKY_GANGSTER = 217,
  PROP_SKY_SCRAPYARD = 218,
  PROP_CARTRIDGE1 = 219,
  PROP_CARTRIDGE2 = 220,
  PROP_CARTRIDGE3 = 221,
  PROP_CARTRIDGE4 = 222,
  PROP_CARTRIDGE5 = 223,
  PROP_ROCKET1 = 224,
  PROP_MISSILE = 225,
  PROP_GRENADE1 = 226,
  PROP_GRENADE2 = 227,
  PROP_PROXIMITYMINE = 228,
  PROP_PROXIMITYMINEBASE = 229,
  PROP_PROXIMITYMINEMINE = 230,
  PROP_PROXIMITYMINECLIP = 231,
  PROP_REMOTEMINE = 232,
  PROP_TIMEDMINE = 233,
  PROP_TNT = 234,
  PROP_BRICK = 235,
  PROP_SCANNER = 236,
  PROP_CLOCK = 237,
  PROP_PUBSIGN = 238,
  PROP_BOATSIGN = 239,
  PROP_GONG = 240,
  PROP_FAN = 241,
  PROP_FANSHADOW = 242,
  PROP_FANSCIFI = 243,
  PROP_BANNER = 244,
  PROP_STREAMERS = 245,
  PROP_LANTERN = 246,
  PROP_BLOODYCHAIR = 247,
  PROP_ELECTRICITY = 248,
  PROP_LAB_OUTERWHEELS = 249,
  PROP_LAB_INNERWHEELSA = 250,
  PROP_LAB_INNERWHEELSB = 251,
  PROP_LAB_INNERWHEELSC = 252,
  PROP_LAB_INNERWHEELSD = 253,
  PROP_LAB_POLE = 254,
  PROP_SPACESHIP1 = 255,
  PROP_SPACESHIP2 = 256,
  PROP_SPACESHIP3 = 257,
  PROP_GREENTHING = 258,
  PROP_BIGSHIP = 259,
  PROP_CHANDELIER = 260,
  PROP_MALLCLOCK = 261,
  PROP_GRAVEYARDMOON = 262,
  PROP_CHINESEFAN = 263,
  PROP_HOLOGRAM = 264,
  PROP_LASER = 265,
  PROP_WATERFALL = 266,
  PROP_WATERFALL2 = 267,
  PROP_SPACESTATIONLIFT = 268,
  PROP_PLANETDOOR = 269,
  PROP_SPACEWAYSDOOR = 270,
  PROP_DOCKSDOOR = 271,
  PROP_TOMBXTRADOOR = 272,
  PROP_PLANETMOON = 273,
  PROP_TOMBSUN = 274,
  PROP_TOMBFLARE = 275,
  PROP_DAMLIFT = 276,
  PROP_DAMLIFT_BUTTONUP = 277,
  PROP_DAMLIFT_BUTTONDOWN = 278,
  PROP_DAMLIFT_DOORLEFT = 279,
  PROP_DAMLIFT_DOORRIGHT = 280,
  PROP_CONTROL = 281,
  PROP_CRATE3 = 282,
  PROP_MALLFAN1 = 283,
  PROP_MALLFAN2 = 284,
  PROP_CRATE4 = 285,
  PROP_CRATE5 = 286,
  PROP_CRATE6 = 287,
  PROP_WOODGIB1 = 288,
  PROP_WOODGIB2 = 289,
  PROP_METALGIB1 = 290,
  PROP_METALGIB2 = 291,
  PROP_GLASSGIB1 = 292,
  PROP_GLASSGIB2 = 293,
  PROP_CARDGIB1 = 294,
  PROP_CARDGIB2 = 295,
  PROP_LEAFGIB1 = 296,
  PROP_LEAFGIB2 = 297,
  PROP_STONEGIB1 = 298,
  PROP_STONEGIB2 = 299,
  PROP_FRUITGIB = 300,
  PROP_NEOTOKYOSIGN1 = 301,
  PROP_NEOTOKYOSIGN2 = 302,
  PROP_NEOTOKYOSIGN3 = 303,
  PROP_NEOTOKYOTRAFFICLIGHTS = 304,
  PROP_NEOTOKYOTRAFFICLIGHTS2 = 305,
  PROP_GANGSTERTSHIRT1 = 306,
  PROP_GANGSTERTSHIRT2 = 307,
  PROP_GANGSTERSKIRT1 = 308,
  PROP_GANGSTERSKIRT2 = 309,
  PROP_GANGSTERSKIRT3 = 310,
  PROP_GANGSTERPAPER1 = 311,
  PROP_PLANETSPAWN = 312,
  PROP_PLANETSPAWN2 = 313,
  PROP_ROTATESPAWNR = 314,
  PROP_ROTATESPAWNY = 315,
  PROP_ROTATESPAWNB = 316,
  PROP_ROTATESPAWNG = 317,
  PROP_BLASTSPAWNR = 318,
  PROP_BLASTSPAWNY = 319,
  PROP_BLASTSPAWNB = 320,
  PROP_BLASTSPAWNG = 321,
  PROP_RINGSPAWNR = 322,
  PROP_RINGSPAWNY = 323,
  PROP_RINGSPAWNB = 324,
  PROP_RINGSPAWNG = 325,
  PROP_JEEP1 = 326,
  PROP_LORRY = 327,
  PROP_TAXI = 328,
  PROP_COPTER = 329,
  PROP_PLANE = 330,
  PROP_GANGSTERCAR = 331,
  PROP_CRANE = 332,
  PROP_GANGSTERTRAIN = 333,
  PROP_GANGSTERTRAINCHEAP = 334,
  PROP_AIRSHIP = 335,
  PROP_NEOTOKYOTRAIN = 336,
  PROP_BOAT = 337,
  PROP_WATER1 = 338,
  PROP_WATER2 = 339,
  PROP_WATER3 = 340,
  PROP_DOCKS_MOON = 341,
  PROP_REFLECTIONS = 342,
  PROP_PKUP_BAG1 = 343,
  PROP_PKUP_BAG2 = 344,
  PROP_PKUP_BAG3 = 345,
  PROP_PKUP_BAG4 = 346,
  PROP_PKUP_BAG5 = 347,
  PROP_PKUP_BAG6 = 348,
  PROP_PKUP_BAG7 = 349,
  PROP_PKUP_BAG8 = 350,
  PROP_PKUP_BAG9 = 351,
  PROP_PKUP_BAG10 = 352,
  PROP_PKUP_FILES = 353,
  PROP_PKUP_PLANS = 354,
  PROP_PKUP_ARTEFACT = 355,
  PROP_PKUP_JEWELS = 356,
  PROP_PKUP_BRAIN = 357,
  PROP_PKUP_REMAINS = 358,
  PROP_PKUP_RANSOM = 359,
  PROP_PKUP_DUTYFREE = 360,
  PROP_PKUP_DROP1 = 361,
  PROP_PKUP_DROP2 = 362,
  PROP_PKUP_DROP3 = 363,
  PROP_PKUP_DROP4 = 364,
  PROP_PKUP_KEYCARD1 = 365,
  PROP_PKUP_KEYCARD2 = 366,
  PROP_PKUP_KEYCARD3 = 367,
  PROP_PKUP_KEYCARD4 = 368,
  PROP_PKUP_POWERUP = 369,
  PROP_PKUP_AMMOSMALL = 370,
  PROP_PKUP_AMMOBIG = 371,
  PROP_PKUP_AMMOSHELL = 372,
  PROP_PKUP_AMMOPLASMA = 373,
  PROP_PKUP_AMMOROCKET = 374,
  PROP_PKUP_AMMOGRENADE = 375,
  PROP_PKUP_AMMOBRICK = 376,
  PROP_PKUP_AMMOREMOTE = 377,
  PROP_PKUP_AMMOTIMED = 378,
  PROP_PKUP_AMMOPROXIMITY = 379,
  PROP_PKUP_AMMOTNT = 380,
  PROP_PKUP_HEALTH1 = 381,
  PROP_PKUP_HORROR_ARMOUR1 = 382,
  PROP_PKUP_HORROR_ARMOUR2 = 383,
  PROP_PKUP_PERIOD_ARMOUR1 = 384,
  PROP_PKUP_PERIOD_ARMOUR2 = 385,
  PROP_PKUP_SCIFI_ARMOUR1 = 386,
  PROP_PKUP_SCIFI_ARMOUR2 = 387,
  PROP_PKUP_DAMDISK = 388,
  PROP_CHRGUN1 = 389,
  PROP_CHRGUN2 = 390,
  PROP_CHRGUN3 = 391,
  PROP_CHRGUN4 = 392,
  PROP_CHRGUN5 = 393,
  PROP_CHRGUN6 = 394,
  PROP_CHRGUN7 = 395,
  PROP_CHRGUN8 = 396,
  PROP_CHRGUN9 = 397,
  PROP_CHRGUN10 = 398,
  PROP_CHRGUN11 = 399,
  PROP_CHRGUN12 = 400,
  PROP_CHRGUN13 = 401,
  PROP_CHRGUN14 = 402,
  PROP_CHRGUN15 = 403,
  PROP_CHRGUN16 = 404,
  PROP_CHRGUN17 = 405,
  PROP_CHRGUN18 = 406,
  PROP_CHRGUN19 = 407,
  PROP_CHRGUN20 = 408,
  PROP_CHRGUN21 = 409,
  PROP_CHRGUN22 = 410,
  PROP_CHRGUN23 = 411,
  PROP_CHRGUN24 = 412,
  PROP_CHRGUN25 = 413,
  PROP_CHRGUN26 = 414,
  PROP_CHRGUN27 = 415,
  PROP_CHRGUN28 = 416,
  PROP_CHRGUN29 = 417,
  PROP_CHRGUN30 = 418,
  PROP_GUN1 = 419,
  PROP_GUN2 = 420,
  PROP_GUN3 = 421,
  PROP_GUN4 = 422,
  PROP_GUN5 = 423,
  PROP_GUN6 = 424,
  PROP_GUN7 = 425,
  PROP_GUN8 = 426,
  PROP_GUN9 = 427,
  PROP_GUN10 = 428,
  PROP_GUN11 = 429,
  PROP_GUN12 = 430,
  PROP_GUN13 = 431,
  PROP_GUN14 = 432,
  PROP_GUN15 = 433,
  PROP_GUN16 = 434,
  PROP_GUN17 = 435,
  PROP_GUN18 = 436,
  PROP_GUN19 = 437,
  PROP_GUN20 = 438,
  PROP_GUN21 = 439,
  PROP_GUN22 = 440,
  PROP_GUN23 = 441,
  PROP_GUN24 = 442,
  PROP_GUN25 = 443,
  PROP_GUN26 = 444,
  PROP_GUN27 = 445,
  PROP_GUN28 = 446,
  PROP_GUNDEFAULT_PH = 447,
  PROP_GUNDEFAULT_CL = 448,
  PROP_GUNDEFAULT_PROMO = 449,
  PROP_ASSAULTRIFLE_PH = 450,
  PROP_ASSAULTRIFLE_CL = 451,
  PROP_ASSAULTRIFLE_PROMO = 452,
  PROP_ASSAULTSHOTGUN_PH = 453,
  PROP_ASSAULTSHOTGUN_CL = 454,
  PROP_ASSAULTSHOTGUN_PROMO = 455,
  PROP_SILENCEDPISTOL_PH = 456,
  PROP_SILENCEDPISTOL_CL = 457,
  PROP_SILENCEDPISTOL_PROMO = 458,
  PROP_ELECTROGUN_PH = 459,
  PROP_ELECTROGUN_CL = 460,
  PROP_ELECTROGUN_PROMO = 461,
  PROP_FLAMETHROWER_PH = 462,
  PROP_FLAMETHROWER_CL = 463,
  PROP_FLAMETHROWER_PROMO = 464,
  PROP_SNIPERRIFLE_PH = 465,
  PROP_SNIPERRIFLE_CL = 466,
  PROP_SNIPERRIFLE_PROMO = 467,
  PROP_AK47_PH = 468,
  PROP_AK47_CL = 469,
  PROP_AK47_PROMO = 470,
  PROP_FIRE_EXTINGUISHER_PH = 471,
  PROP_FIRE_EXTINGUISHER_CL = 472,
  PROP_FIRE_EXTINGUISHER_PROMO = 473,
  PROP_FIRE_EXTINGUISHER_PICKUP = 474,
  PROP_LASERGUN_PH = 475,
  PROP_LASERGUN_CL = 476,
  PROP_LASERGUN_PROMO = 477,
  PROP_PLASMAMACHINEGUN_PH = 478,
  PROP_PLASMAMACHINEGUN_CL = 479,
  PROP_PLASMAMACHINEGUN_PROMO = 480,
  PROP_ROCKETLAUNCHER_PH = 481,
  PROP_ROCKETLAUNCHER_CL = 482,
  PROP_ROCKETLAUNCHER_PROMO = 483,
  PROP_HOMINGROCKETLAUNCHER_PH = 484,
  PROP_HOMINGROCKETLAUNCHER_CL = 485,
  PROP_HOMINGROCKETLAUNCHER_PROMO = 486,
  PROP_GRENADELAUNCHER_PH = 487,
  PROP_GRENADELAUNCHER_CL = 488,
  PROP_GRENADELAUNCHER_PROMO = 489,
  PROP_REMOTEMINE_PH = 490,
  PROP_REMOTEMINE_CL = 491,
  PROP_REMOTEMINE_PROMO = 492,
  PROP_TIMEDMINE_PH = 493,
  PROP_TIMEDMINE_CL = 494,
  PROP_TIMEDMINE_PROMO = 495,
  PROP_PROXIMITYMINE_PH = 496,
  PROP_PROXIMITYMINE_CL = 497,
  PROP_PROXIMITYMINE_PROMO = 498,
  PROP_TOMMYGUN_PH = 499,
  PROP_TOMMYGUN_CL = 500,
  PROP_TOMMYGUN_PROMO = 501,
  PROP_DOUBLEBARRELSHOTGUN_PH = 502,
  PROP_DOUBLEBARRELSHOTGUN_CL = 503,
  PROP_DOUBLEBARRELSHOTGUN_PROMO = 504,
  PROP_GATLINGGUN_PH = 505,
  PROP_GATLINGGUN_CL = 506,
  PROP_GATLINGGUN_PROMO = 507,
  PROP_MAGNUM_PH = 508,
  PROP_MAGNUM_CL = 509,
  PROP_MAGNUM_PROMO = 510,
  PROP_SCIFIHANDGUN_PH = 511,
  PROP_SCIFIHANDGUN_CL = 512,
  PROP_SCIFIHANDGUN_PROMO = 513,
  PROP_DISCTHROWER_PH = 514,
  PROP_DISCTHROWER_CL = 515,
  PROP_DISCTHROWER_PROMO = 516,
  PROP_UZI_PH = 517,
  PROP_UZI_CL = 518,
  PROP_UZI_PROMO = 519,
  PROP_FLAREPISTOL_PH = 520,
  PROP_FLAREPISTOL_CL = 521,
  PROP_FLAREPISTOL_PROMO = 522,
  PROP_AUTOGUN1 = 523,
  PROP_AUTOGUN1DAM = 524,
  PROP_AUTOGUN2 = 525,
  PROP_AUTODEER = 526,
  PROP_AUTODEERDAM = 527,
  PROP_FIXEDGUN = 528,
  PROP_CAMERA1 = 529,
  PROP_CCTV_CEILING1 = 530,
  PROP_CCTV_WALL1 = 531,
  PROP_REMOTEGUN_TEMP = 532,
  PROP_REMOTEGUN1 = 533,
  PROP_REMOTEGUN2 = 534,
  PROP_HAT_RED = 535,
  PROP_HAT_YELLOW = 536,
  PROP_HAT_BLUE = 537,
  PROP_HAT_GREEN = 538,
  PROP_HEAD_CHR01 = 539,
  PROP_HEAD_CHR02 = 540,
  PROP_HEAD_CHR03 = 541,
  PROP_HEAD_CHR04 = 542,
  PROP_HEAD_CHR05 = 543,
  PROP_HEAD_CHR06 = 544,
  PROP_HEAD_CHR07 = 545,
  PROP_HEAD_CHR08 = 546,
  PROP_HEAD_CHR09 = 547,
  PROP_HEAD_CHR10 = 548,
  PROP_HEAD_CHR11 = 549,
  PROP_HEAD_CHR12 = 550,
  PROP_HEAD_CHR13 = 551,
  PROP_HEAD_CHR14 = 552,
  PROP_HEAD_CHR15 = 553,
  PROP_HEAD_CHR16 = 554,
  PROP_FENCE1 = 555,
  PROP_FENCE2 = 556,
  PROP_DAMTREE = 557,
  PROP_FRONTSTAGE = 558,
  PROP_MM_ICON_O = 559,
  PROP_MM_ICON_X = 560,
  PROP_MM_ICON_GUN = 561,
  PROP_MM_ICON_AMMO = 562,
  PROP_MM_ICON_BAG = 563,
  PROP_MM_ICON_START = 564,
  PROP_MM_ICON_HEALTH = 565,
  PROP_MM_ICON_ARMOUR_LOW = 566,
  PROP_MM_ICON_ARMOUR_HIGH = 567,
  PROP_MM_ICON_DROP1 = 568,
  PROP_MM_ICON_DROP2 = 569,
  PROP_MM_ICON_DROP3 = 570,
  PROP_MM_ICON_DROP4 = 571,
  PROP_MM_ICON_KEY1 = 572,
  PROP_MM_ICON_KEY2 = 573,
  PROP_MM_ICON_KEY3 = 574,
  PROP_MM_ICON_KEY4 = 575,
  PROP_MM_ICON_POWERUP = 576,
  PROP_MM_ICON_AUTOGUN = 577,
  PROP_MM_ICON_FIXEDGUN = 578,
  PROP_MM_ICON_NPC = 579,
  PROP_TILE1 = 580,
  PROP_TILE2 = 581,
  PROP_TILE3 = 582,
  PROP_TILE4 = 583,
  PROP_TILE5 = 584,
  PROP_TILE6 = 585,
  PROP_TILE7 = 586,
  PROP_TILE8 = 587,
  PROP_TILE9 = 588,
  PROP_TILE10 = 589,
  PROP_TILE11 = 590,
  PROP_TILE12 = 591,
  PROP_TILE13 = 592,
  PROP_TILE14 = 593,
  PROP_TILE15 = 594,
  PROP_TILE16 = 595,
  PROP_TILE17 = 596,
  PROP_TILE18 = 597,
  PROP_TILE19 = 598,
  PROP_TILE20 = 599,
  PROP_TILE21 = 600,
  PROP_TILE22 = 601,
  PROP_TILE23 = 602,
  PROP_TILE24 = 603,
  PROP_TILE25 = 604,
  PROP_TILE26 = 605,
  PROP_TILE27 = 606,
  PROP_TILE28 = 607,
  PROP_TILE29 = 608,
  PROP_TILE30 = 609,
  PROP_TILESETDOOR1 = 610,
  PROP_TILESETWINDOW1 = 611,
  PROP_ROOM1 = 612,
  PROP_ROOM2 = 613,
  PROP_ROOM3 = 614,
  PROP_ROOM4 = 615,
  PROP_ROOM5 = 616,
  PROP_ROOM6 = 617,
  PROP_ROOM7 = 618,
  PROP_ROOM8 = 619,
  PROP_ROOM9 = 620,
  PROP_ROOM10 = 621,
  PROP_ROOM11 = 622,
  PROP_ROOM12 = 623,
  PROP_ROOM13 = 624,
  PROP_ROOM14 = 625,
  PROP_ROOM15 = 626,
  PROP_ROOM16 = 627,
  PROP_ROOM17 = 628,
  PROP_ROOM18 = 629,
  PROP_ROOM19 = 630,
  PROP_ROOM20 = 631,
  PROP_ROOM21 = 632,
  PROP_ROOM22 = 633,
  PROP_ROOM23 = 634,
  PROP_ROOM24 = 635,
  PROP_ROOM25 = 636,
  PROP_ROOM26 = 637,
  PROP_ROOM27 = 638,
  PROP_ROOM28 = 639,
  PROP_ROOM29 = 640,
  PROP_ROOM30 = 641,
  PROP_ROOM31 = 642,
  PROP_ROOM32 = 643,
  PROP_ROOM33 = 644,
  PROP_ROOM34 = 645,
  PROP_ROOM35 = 646,
  PROP_ROOM36 = 647,
  PROP_ROOM37 = 648,
  PROP_ROOM38 = 649,
  PROP_ROOM39 = 650,
  PROP_ROOM40 = 651,
  PROP_ROOM41 = 652,
  PROP_ROOM42 = 653,
  PROP_ROOM43 = 654,
  PROP_ROOM44 = 655,
  PROP_ROOM45 = 656,
  PROP_ROOM46 = 657,
  PROP_ROOM47 = 658,
  PROP_ROOM48 = 659,
  PROP_ROOM49 = 660,
  PROP_ROOM50 = 661,
  PROP_ROOM51 = 662,
  PROP_ROOM52 = 663,
  PROP_ROOM53 = 664,
  PROP_ROOM54 = 665,
  PROP_ROOM55 = 666,
  PROP_ROOM56 = 667,
  PROP_ROOM57 = 668,
  PROP_ROOM58 = 669,
  PROP_ROOM59 = 670,
  PROP_ROOM60 = 671,
  PROP_ROOM61 = 672,
  PROP_ROOM62 = 673,
  PROP_ROOM63 = 674,
  PROP_ROOM64 = 675,
  PROP_ROOM65 = 676,
  PROP_ROOM66 = 677,
  PROP_ROOM67 = 678,
  PROP_ROOM68 = 679,
  PROP_ROOM69 = 680,
  PROP_ROOM70 = 681,
  PROP_ROOM71 = 682,
  PROP_ROOM72 = 683,
  PROP_ROOM73 = 684,
  PROP_ROOM74 = 685,
  PROP_ROOM75 = 686,
  PROP_ROOM76 = 687,
  PROP_ROOM77 = 688,
  PROP_ROOM78 = 689,
  PROP_ROOM79 = 690,
  PROP_ROOM80 = 691,
  PROP_ROOM81 = 692,
  PROP_ROOM82 = 693,
  PROP_ROOM83 = 694,
  PROP_ROOM84 = 695,
  PROP_ROOM85 = 696,
  PROP_ROOM86 = 697,
  PROP_ROOM87 = 698,
  PROP_ROOM88 = 699,
  PROP_ROOM89 = 700,
  PROP_ROOM90 = 701,
  PROP_ROOM91 = 702,
  PROP_ROOM92 = 703,
  PROP_ROOM93 = 704,
  PROP_ROOM94 = 705,
  PROP_ROOM95 = 706,
  PROP_ROOM96 = 707,
  PROP_ROOM97 = 708,
  PROP_ROOM98 = 709,
  PROP_ROOM99 = 710,
  PROP_ROOM100 = 711,
  PROP_ROOM101 = 712,
  PROP_ROOM102 = 713,
  PROP_ROOM103 = 714,
  PROP_ROOM104 = 715,
  PROP_ROOM105 = 716,
  PROP_ROOM106 = 717,
  PROP_ROOM107 = 718,
  PROP_ROOM108 = 719,
  PROP_ROOM109 = 720,
  PROP_ROOM110 = 721,
  PROP_ROOM111 = 722,
  PROP_ROOM112 = 723,
  PROP_ROOM113 = 724,
  PROP_ROOM114 = 725,
  PROP_ROOM115 = 726,
  PROP_ROOM116 = 727,
  PROP_ROOM117 = 728,
  PROP_ROOM118 = 729,
  PROP_ROOM119 = 730,
  PROP_ROOM120 = 731,
  PROP_ROOM121 = 732,
  PROP_ROOM122 = 733,
  PROP_ROOM123 = 734,
  PROP_ROOM124 = 735,
  PROP_ROOM125 = 736,
  PROP_ROOM126 = 737,
  PROP_ROOM127 = 738,
  PROP_ROOM128 = 739,
  PROP_ROOM129 = 740,
  PROP_ROOM130 = 741,
  PROP_ROOM131 = 742,
  PROP_ROOM132 = 743,
  PROP_ROOM133 = 744,
  PROP_ROOM134 = 745,
  PROP_ROOM135 = 746,
  PROP_ROOM136 = 747,
  PROP_ROOM137 = 748,
  PROP_ROOM138 = 749,
  PROP_ROOM139 = 750,
  PROP_ROOM140 = 751,
  PROP_ROOM141 = 752,
  PROP_ROOM142 = 753,
  PROP_ROOM143 = 754,
  PROP_ROOM144 = 755,
  PROP_ROOM145 = 756,
  PROP_ROOM146 = 757,
  PROP_ROOM147 = 758,
  PROP_ROOM148 = 759,
  PROP_ROOM149 = 760,
  PROP_ROOM150 = 761,
  PROP_ROOM151 = 762,
  PROP_ROOM152 = 763,
  PROP_ROOM153 = 764,
  PROP_ROOM154 = 765,
  PROP_ROOM155 = 766,
  PROP_ROOM156 = 767,
  PROP_ROOM157 = 768,
  PROP_ROOM158 = 769,
  PROP_ROOM159 = 770,
  PROP_ROOM160 = 771,
  PROP_ROOM161 = 772,
  PROP_ROOM162 = 773,
  PROP_ROOM163 = 774,
  PROP_ROOM164 = 775,
  PROP_ROOM165 = 776,
  PROP_ROOM166 = 777,
  PROP_ROOM167 = 778,
  PROP_ROOM168 = 779,
  PROP_ROOM169 = 780,
  PROP_ROOM170 = 781,
  PROP_ROOM171 = 782,
  PROP_ROOM172 = 783,
  PROP_ROOM173 = 784,
  PROP_ROOM174 = 785,
  PROP_ROOM175 = 786,
  PROP_ROOM176 = 787,
  PROP_ROOM177 = 788,
  PROP_ROOM178 = 789,
  PROP_ROOM179 = 790,
  PROP_ROOM180 = 791,
  PROP_ROOM181 = 792,
  PROP_ROOM182 = 793,
  PROP_ROOM183 = 794,
  PROP_ROOM184 = 795,
  PROP_ROOM185 = 796,
  PROP_ROOM186 = 797,
  PROP_ROOM187 = 798,
  PROP_ROOM188 = 799,
  PROP_ROOM189 = 800,
  PROP_ROOM190 = 801,
  PROP_ROOM191 = 802,
  PROP_ROOM192 = 803,
  PROP_ROOM193 = 804,
  PROP_ROOM194 = 805,
  PROP_ROOM195 = 806,
  PROP_ROOM196 = 807,
  PROP_ROOM197 = 808,
  PROP_ROOM198 = 809,
  PROP_ROOM199 = 810,
  PROP_ROOM200 = 811,
  PROP_NUM = 812
};

enum {
  PROP_TYPE_OB = 1,
  PROP_TYPE_ROOM = 2,
  PROP_TYPE_DOOR = 4,
  PROP_TYPE_CHR = 8,
  PROP_TYPE_GUN = 16,
  PROP_TYPE_CHRGUN = 32,
  PROP_TYPE_PICKUP = 64,
  PROP_TYPE_SPECIAL = 128,
  PROP_TYPE_CAR = 256,
  PROP_TYPE_REMOTE = 512,
  PROP_TYPE_WATER = 1024,
  PROP_TYPE_LIMB = 2048,
  PROP_TYPE_CORPSE = 4096,
  PROP_TYPE_BASE = 8192,
  PROP_TYPE_LIFT = 16384,
  PROP_TYPE_LIFTOB = 32768,
  PROP_TYPE_NOHITS = 65536,
  PROP_TYPE_LVBUTTON = 131072,
  PROP_TYPE_POPUPBOT = 262144
};

enum { PROPATTACHFLAG_RIGHTHAND = 1, PROPATTACHFLAG_LEFTHAND = 2 };

typedef struct glassHit_s {
  struct prop_s *prop;
  float hitpos[3];
  float hitdir[3];
  float hitnorm[3];
  int room;
  glassdef *glass;
} glassHit;

typedef struct glassResults_s {
  int numHits;
  int hitReverse;
  glassHit hits[5];
} glassResults;

typedef struct s_PropBoundingBox {
  boolean calculated;
  float CentrePos[3];
  float Radius[3];
} PropBoundingBox;

typedef struct PropBoundingInfo_s {
  PropBoundingBox overallBounds;
  int numExtraBounds;
  PropBoundingBox *extraBounds;
} PropBoundingInfo;

typedef void (*handlerfunc)(/* parameters unknown */);

typedef struct handler_s {
  handlerfunc function;
} handler;

typedef struct prop_s {
  int id;
  int num;
  int type;
  int subtype;
  int room;
  int LastTickFrame;
  u32 flags;
  u32 lastflags;
  u32 damageflags;
  u32 frameflags;
  u32 drawflags;
  u32 framedrawflags;
  struct obinst_s *inst;
  struct obinst_s *swapinst;
  float startpos[3];
  float pos[3];
  float vel[3];
  float rotx;
  float roty;
  float newroty;
  float rotz;
  float rotaxial;
  float rotinc;
  float rotaxis[3];
  float rotvel[3];
  float lastpos[3];
  float moveRate[3];
  float lastrotx;
  float lastroty;
  float lastrotz;
  int posmode;
  int rotmode;
  int rooms[10];
  int numrooms;
  float scrmin[2];
  float scrmax[2];
  struct obinst_s *attachobinst;
  int attachmtxnum;
  int attachflag;
  float hitreacttime;
  mtx tmat1;
  mtx tmat2;
  int tmatindex1;
  int tmatindex2;
  void *data;
  struct player_s *player;
  handler handlers[11];
  void (*damageHandler)(/* parameters unknown */);
  int usingdisappearancetimer;
  int disappearancetimer;
  float CentrePos[3];
  float CentrePosAtStart[3];
  float Radius[3];
  float health;
  float maxHealth;
  float damageLevel;
  int numTransformedFloors;
  int numTransformedWalls;
  int numTransformedGlass;
  int numTransformedSpecial;
  struct floordef_s **transformedFloors;
  struct walldef_s **transformedWalls;
  glassdef **transformedGlass;
  specialdef **transformedSpecial;
  struct prop_s *otherprop;
  struct prop_s *MyAttacker;
  float FloorLevel;
  float RockingDisp;
  float RockingVel;
  float BurnSFXTimer;
  s16 ClosestLight[9];
  float attachobworldpos[3];
  int manualLightIndex;
  int NetLifeCounter;
  float activationdistsq;
  float activationdot;
  struct hudHealthArmourData_s *hudHealthArmourPtr;
  int activationdata;
  int alarmnumber;
} prop;

typedef struct propdef_s {
  int type;
  struct obdef_s *ob;
  u8 *propname;
  u8 *filename;
  int skeletontype;
  struct skelmatrices_s *skelmtx;
  int OffScreenTickTime;
  int Flags;
} propdef;

typedef struct pickupdata_s {
  int dataID;
  int type;
  int status;
  float data;
  int data2;
  int team;
  float dy;
  float homepos[3];
  float floorrotx;
  float floorrotz;
  int padnum;
  int homepadnum;
  int ammotype;
  int ammo;
  float targetpos[3];
  int destpad;
  int droppedstate;
  int dropperid;
  int framesleft;
  float rotvel[3];
  int pickupposindex;
  float pickupscale;
  float unique;
  float tailRotation;
  float lefthandRotation;
  float righthandRotation;
} pickupdata;

extern propdef proptable[812];
extern int lastreactionframenum;
extern prop *p_roomprops[226][100];
extern int p_numroomprops[226];
extern pickupdata tmpPickupData[20];
extern int tmpPickupDataUsed[20];
extern prop *tmpPickupDataProp[20];
extern int tmpPickupDataFramenum[20];
extern PropBoundingInfo *propBoundingInfo[812];
extern int num_props;
extern int num_deleted_props;
extern int num_activate_props;
extern prop *ActiveProps[400];
extern int NumActiveProps;
extern boolean DrawBoundsRoom[225];

int propGetPropIndex(prop *p);
prop *propGetPropPtr(int p);
prop *propGetPropPtrAttachTo(int p, int m);
void propCollisionPreProcess();
void propDump(prop *pr, int n);
void propRestart();
void propReset();
void propEnd();
char *propGetName(int num);
void propSetOb(int num, struct obdef_s *ob);
void propSetHandler(prop *p, int event, handlerfunc pFunc);
void propSetDamageHandler(prop *p,
                          void (*damageHandler)(/* parameters unknown */));
int getPropType(int propnum);
void propAddPreLoad(int num);
boolean propIsRoomsDrawnByAnyPlayer(prop *p);
boolean propIsOverPortal(prop *p);
prop *propGetAimProp();
void propCalcBoundsForPart(prop *pProp, int PartNum, float *Min, float *Max);
void propSetRadiusCentrePos(prop *pProp, float *Min, float *Max, float *Radius,
                            float *CentrePos);
void propTransformBoundingBox(prop *pProp, int partNum, PropBoundingBox *box,
                              float *Radius, float *CentrePos);
void propCalculateCentrePos(prop *pProp);
void propAllocateWallsFloorsGlassSpecial(prop *p);
void propSetupWallsFloorsGlassSpecial(prop *thisprop);
void propSetupBoundingInfo(prop *p);
prop *propNew(int num, float x, float y, float z, float roty);
prop *propXZRotNew(int num, float x, float y, float z, float *rot);
void propSwapNew(prop *p, int num);
void propChangeMesh(prop *p);
void propSetupSpecialfx(prop *p);
void propSetupMisc(prop *thisprop);
int getPropViewportDrawFlags();
void WritePropKeyFile();
void propDelete(prop *p);
void propDeleteCore(prop *p);
void propGlassTick(prop *p);
void propGlassGfx(prop *p);
prop *gunNew(int num, float x, float y, float z, float roty);
void propCalcRooms(prop *p);
void propSetRoom(prop *p);
void propUpdateRooms();
void tlhSwapDropColour(struct obinst_s *oi, int pdef);
boolean pickupChrProcess(prop *pickup, prop *chrprop);
void propEvictLimb(prop *p);
void propDeleteLimb(prop *p);
prop *propNewLimb(prop *chrattach, float *bulletnorm, float bulletspeed,
                  int limbtype);
void propDrop(prop *oldprop, struct chrdata_s *cd, struct chrgun_s *cgun);
void propSetDrawFlags();
int propGetPopupbotListIndex();
void propSetupPopupbot(prop *p, int cindex);
void propSpawnProp(struct setuppropspawn_s *sps);
void propAlarmInform(int alarmnum);
void propCheckSpawnProp();
void propTickBefore();
void propTickAfter();
void propTickPlayer();
void propSetMatrices(prop *p);
void propGfxRoomPreproc();
void propGfxRoomClipProps(int room);
void propDrawLine(mtx *pView, float *v1, float *v2, int rgba);
void propDrawRec(mtx *pView, float *v1, float *v2, float *v3, float *v4,
                 int rgba);
void propDrawBounds(prop *p);
void propDrawWalls(prop *p);
void propDrawFloors(prop *p);
void propDrawDebug();
void propGfxRoom(int room, int gfxtype);
void propSetAttached(prop *p, struct obinst_s *ob, int mtxnum, int flag);
void propSetMtxRoll(prop *p, struct obinst_s *ob, float *vel, float rotinc);
prop *propGetNext(prop *start, int proptype);
prop *propGetNum(int num);
prop *propLineTestRoom(int room, float *startpos, float *dir, int infinite,
                       float *hitpos, float *hitnorm, int excludeflag,
                       int CollisionTypeFlag, glassResults *glassRes);
int propMoveTestRoom(int Chr, int Room, float *bb[3], float *StartPos,
                     float Radius, float Height, float *MoveDirXZ,
                     float *pHitFrac, float *HitNormFrac, float *pHitDist,
                     float *HitNormDist, boolean CanNotPush, int ExcludeFlag);
float propFindFloorHeightRoom(int Room, float *Pos, struct floordef_s **ppFloor,
                              prop **ppProp);
prop *propSwipeTest(prop *pSwipeProp, float *SwipePosCentre,
                    float *SwipePosStart, float *SwipePosEnd, float *HitPos,
                    float *HitNorm);
void propGlassLineTest(prop *p, float *startpos, float *dir, int infinite,
                       glassResults *glassRes);
void propGlassSwipeTest(prop *testProp, prop *pSwipeProp, float *SwipePosCentre,
                        float *SwipePosStart, float *SwipePosEnd);
void propGlassSwipeTestRoom(int room, prop *pSwipeProp, float *SwipePosCentre,
                            float *SwipePosStart, float *SwipePosEnd);
void propGlassMoveTest(int Chr, prop *p, float *StartPos, float *EndPos,
                       float Height, float Radius);
void propGlassMoveTestRoom(int Chr, int room, float *StartPos, float *EndPos,
                           float Height, float Radius);
void glassSmash(prop *p, glassdef *pGlass, float *HitPos, float *HitNorm,
                float *HitDir, float Amount, float *Col);
void glassProcessHits(glassResults *glassRes, int bullettype, float amount,
                      float *col);
int propInPropList(prop *p);
prop *propNewPickupOnPadExtref(int propnum, int type, float data, int data2,
                               int team, int extref, float rx, float ry,
                               float rz, float dy, int ammotype, int ammo,
                               int temporary);
void pickupposRestart();
void pickupposReset();
int pickupposAdd(float *pos);
void pickupposGfx();
float propPickupGetZRotation(prop *p, boolean dropped);
prop *propNewPickup(int propnum, int type, float data, int data2, int team,
                    float x, float y, float z, float rx, float ry, float rz,
                    float dy, int ammotype, int ammo, int temporary);
void propDeletePickup(prop *p);
void propMakeVisible(void *pickup);
void animMtxTick();
boolean propMovingPropInRange(float *Pos, int Room, float Dist);
void drumDamage(prop *p, prop *attacker, float amount, int bullettype,
                float *hitpos, float *bulletnorm, float bulletspeed);
void plantDamage(prop *p, prop *attacker, float amount, int bullettype,
                 float *hitpos, float *bulletnorm, float bulletspeed);
void fruitDamage(prop *p, prop *attacker, float amount, int bullettype,
                 float *hitpos, float *bulletnorm, float bulletspeed);
void popupbotDamage(prop *p, prop *attacker, float amount, int bullettype,
                    float *hitpos, float *bulletnorm, float bulletspeed);
void crateDamage(prop *p, prop *attacker, float amount, int bullettype,
                 float *hitpos, float *bulletnorm, float bulletspeed);
void metalcrateDamage(prop *p, prop *attacker, float amount, int bullettype,
                      float *hitpos, float *bulletnorm, float bulletspeed);
void baseDamage(prop *p, prop *attacker, float amount, int bullettype,
                float *hitpos, float *bulletnorm, float bulletspeed);
void damRadarDamage(prop *p, prop *attacker, float amount, int bullettype,
                    float *hitpos, float *bulletnorm, float bulletspeed);
void fileCabinetDamage(prop *p, prop *attacker, float amount, int bullettype,
                       float *hitpos, float *bulletnorm, float bulletspeed);
void propGenericTwoStateDamage(prop *p, prop *attacker, float amount,
                               int bullettype, float *hitpos, float *bulletnorm,
                               float bulletspeed);
void propGenericThreeStateDamage(prop *p, prop *attacker, float amount,
                                 int bullettype, float *hitpos,
                                 float *bulletnorm, float bulletspeed);
int propNumBallelsNotBlownUp();
int propAllBallelsBlownUp();
void propBurningTick(prop *p);
void propRockingTick(prop *p);
void setupRockingProp(prop *p, float UpPulse);
boolean propRoomForMoreProps(int n);
void propSetFloorLevelForAllProps();
boolean propIsCloseToFloor(prop *p);

#endif // GAME_PROP_PROP_H
