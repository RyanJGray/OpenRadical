// STATUS: NOT STARTED

#include "lvsetup.h"

typedef enum {
	SKY_NONE = 0,
	SKY_VILLAGE = 1,
	SKY_COMPOUND = 2,
	SKY_CHINESE = 3,
	SKY_DOCKS = 4,
	SKY_STREETS = 5,
	SKY_OUTPOST = 6,
	SKY_WAREHOUSE = 7,
	SKY_PINKDAWN = 8,
	SKY_GREENDUSK = 9,
	SKY_COLDNIGHT = 10,
	SKY_CLEARDAY = 11,
	SKY_AFTERNOON = 12,
	SKY_MARS = 13,
	SKY_PURPLEHAZE = 14,
	SKY_RAINBOW = 15,
	SKY_FLAREDAWN = 16,
	SKY_ORANGE = 17,
	SKY_BRIGHTDAWN = 18,
	SKY_CRISPDAWN = 19,
	SKY_SETTINGSUN = 20,
	SKY_YELLOWAFTERNOON = 21,
	SKY_DAM = 22,
	SKY_NOTREDAME = 23,
	SKY_PIVOTAL = 24,
	SKY_PLANET2 = 25,
	SKY_RFACTORY = 26,
	SKY_MEXICAN = 27,
	SKY_NEOTOKYO = 28,
	SKY_NIGHTCLUB = 29,
	SKY_ATOMSMASHER = 30,
	SKY_MARTIAN = 31,
	SKY_HOSPITAL = 32,
	SKY_SCRAPYARD = 33,
	SKY_CIRCUS = 34,
	SKY_NUM = 35
};

int numproprefs = 0;
int numremoterefs = 0;
int story_state1 = 0;

static setupheader setup_empty = {
	/* .setupflags = */ 0,
	/* .gunset = */ 0,
	/* .props = */ NULL,
	/* .numprops = */ 0,
	/* .pickups = */ NULL,
	/* .numpickups = */ 0,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ NULL,
	/* .numspawnpads = */ 0,
	/* .NPCsetup = */ NULL,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ NULL,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ NULL,
	/* .numAIEventHandlers = */ 0,
	/* .si = */ NULL,
	/* .numNPCspawns = */ 0,
	/* .cars = */ NULL,
	/* .numcars = */ 0,
	/* .sr = */ NULL,
	/* .numremotes = */ 0,
	/* .specialfx = */ NULL,
	/* .numspecialfx = */ 0,
	/* .weatherdat = */ NULL,
	/* .numweatherdata = */ 0,
	/* .lsphases = */ NULL,
	/* .numlsphases = */ 0,
	/* .lssnipergrps = */ NULL,
	/* .numlssnipergrps = */ 0,
	/* .alarms = */ NULL,
	/* .numalarms = */ 0,
	/* .lifts = */ NULL,
	/* .numlifts = */ 0,
	/* .lvbuttons = */ NULL,
	/* .numlvbuttons = */ 0,
	/* .lvcameradata = */ NULL,
	/* .numcamera = */ 0,
	/* .lvpropspawn = */ NULL,
	/* .numpropspawns = */ 0
};

static skySetting skies[35] = {
	/* [0] = */ {
		/* .name = */ 0x45c1d0,
		/* .skypropnum = */ -1,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 0.f,
		/* .cloudheight = */ 0.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [1] = */ {
		/* .name = */ 0x441b30,
		/* .skypropnum = */ 188,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [2] = */ {
		/* .name = */ 0x441b20,
		/* .skypropnum = */ 189,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [3] = */ {
		/* .name = */ 0x441b10,
		/* .skypropnum = */ 196,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [4] = */ {
		/* .name = */ 0x441b00,
		/* .skypropnum = */ 187,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [5] = */ {
		/* .name = */ 0x441af0,
		/* .skypropnum = */ 203,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 25632,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 600.f,
		/* .cloudheight = */ 150.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [6] = */ {
		/* .name = */ 0x441ae0,
		/* .skypropnum = */ -1,
		/* .bgcol = */ 60288,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [7] = */ {
		/* .name = */ 0x441ad0,
		/* .skypropnum = */ 217,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 10048,
		/* .outercloudcol = */ 38720,
		/* .cloudradius = */ 500.f,
		/* .cloudheight = */ 125.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [8] = */ {
		/* .name = */ 0x441ac0,
		/* .skypropnum = */ 201,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 32639,
		/* .outercloudcol = */ 32639,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [9] = */ {
		/* .name = */ 0x441ab0,
		/* .skypropnum = */ 202,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 19327,
		/* .outercloudcol = */ 20500,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [10] = */ {
		/* .name = */ 0x441aa0,
		/* .skypropnum = */ 203,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 25632,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [11] = */ {
		/* .name = */ 0x441a90,
		/* .skypropnum = */ 204,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [12] = */ {
		/* .name = */ 0x441a80,
		/* .skypropnum = */ 204,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 32639,
		/* .outercloudcol = */ 32639,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [13] = */ {
		/* .name = */ 0x441a70,
		/* .skypropnum = */ 205,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 7744,
		/* .outercloudcol = */ 15424,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [14] = */ {
		/* .name = */ 0x441a60,
		/* .skypropnum = */ 206,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 25727,
		/* .outercloudcol = */ 25600,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [15] = */ {
		/* .name = */ 0x441a50,
		/* .skypropnum = */ 207,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [16] = */ {
		/* .name = */ 0x441a40,
		/* .skypropnum = */ 208,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [17] = */ {
		/* .name = */ 0x441a30,
		/* .skypropnum = */ 209,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [18] = */ {
		/* .name = */ 0x441a20,
		/* .skypropnum = */ 210,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 32639,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [19] = */ {
		/* .name = */ 0x441a10,
		/* .skypropnum = */ 211,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 32639,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [20] = */ {
		/* .name = */ 0x441a00,
		/* .skypropnum = */ 212,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [21] = */ {
		/* .name = */ 0x4419e8,
		/* .skypropnum = */ 213,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [22] = */ {
		/* .name = */ 0x45c1c8,
		/* .skypropnum = */ 213,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 500.f,
		/* .cloudheight = */ 125.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [23] = */ {
		/* .name = */ 0x4419d8,
		/* .skypropnum = */ 203,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 25632,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 450.f,
		/* .cloudheight = */ 220.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ -100.f,
		/* .skyroty = */ 180.f
	},
	/* [24] = */ {
		/* .name = */ 0x4419c8,
		/* .skypropnum = */ 214,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 450.f,
		/* .cloudheight = */ 220.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [25] = */ {
		/* .name = */ 0x4419b8,
		/* .skypropnum = */ 215,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 127,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 500.f,
		/* .cloudheight = */ 200.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [26] = */ {
		/* .name = */ 0x4419a0,
		/* .skypropnum = */ 214,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 450.f,
		/* .cloudheight = */ 220.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [27] = */ {
		/* .name = */ 0x441990,
		/* .skypropnum = */ 216,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 200.f,
		/* .cloudheight = */ 50.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ -0.2f,
		/* .skyroty = */ 0.f
	},
	/* [28] = */ {
		/* .name = */ 0x441980,
		/* .skypropnum = */ 203,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 25632,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 400.f,
		/* .cloudheight = */ 100.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [29] = */ {
		/* .name = */ 0x441970,
		/* .skypropnum = */ -1,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 400.f,
		/* .cloudheight = */ 100.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [30] = */ {
		/* .name = */ 0x441960,
		/* .skypropnum = */ 203,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 25632,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 500.f,
		/* .cloudheight = */ 125.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [31] = */ {
		/* .name = */ 0x441950,
		/* .skypropnum = */ -1,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 0.f,
		/* .cloudheight = */ 0.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [32] = */ {
		/* .name = */ 0x441940,
		/* .skypropnum = */ -1,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 0.f,
		/* .cloudheight = */ 0.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [33] = */ {
		/* .name = */ 0x441930,
		/* .skypropnum = */ 218,
		/* .bgcol = */ 128,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 0.f,
		/* .cloudheight = */ 0.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	},
	/* [34] = */ {
		/* .name = */ 0x441920,
		/* .skypropnum = */ -1,
		/* .bgcol = */ 12928,
		/* .cloudcol = */ 0,
		/* .outercloudcol = */ 0,
		/* .cloudradius = */ 0.f,
		/* .cloudheight = */ 0.f,
		/* .cloudheightadjust = */ 0.f,
		/* .skyheightadjust = */ 0.f,
		/* .skyroty = */ 0.f
	}
};

static level_info lvinfo[0] = {
};

chrset_t chrpresets[17] = {
	/* [0] = */ {
		/* .chrnums = */ {
			/* [0] = */ 2,
			/* [1] = */ 8,
			/* [2] = */ 10,
			/* [3] = */ 11,
			/* [4] = */ 9,
			/* [5] = */ 0,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [1] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [2] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [3] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [4] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [5] = */ {
		/* .chrnums = */ {
			/* [0] = */ 18,
			/* [1] = */ 28,
			/* [2] = */ 24,
			/* [3] = */ 35,
			/* [4] = */ 40,
			/* [5] = */ 22,
			/* [6] = */ 33,
			/* [7] = */ 34,
			/* [8] = */ 27,
			/* [9] = */ 39,
			/* [10] = */ 44,
			/* [11] = */ 45
		}
	},
	/* [6] = */ {
		/* .chrnums = */ {
			/* [0] = */ 47,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [7] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [8] = */ {
		/* .chrnums = */ {
			/* [0] = */ 47,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 48
		}
	},
	/* [9] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [10] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [11] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [12] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [13] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [14] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [15] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	},
	/* [16] = */ {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 10
		}
	}
};

short int arcadechrsetnames[8] = {
	/* [0] = */ 948,
	/* [1] = */ 949,
	/* [2] = */ 950,
	/* [3] = */ 951,
	/* [4] = */ 952,
	/* [5] = */ 953,
	/* [6] = */ 954,
	/* [7] = */ 955
};

gunset gunsets[19] = {
	/* [0] = */ {
		/* .name = */ 0,
		/* .numguns = */ 9,
		/* .guncombo = */ {
			/* [0] = */ 1,
			/* [1] = */ 8,
			/* [2] = */ 12,
			/* [3] = */ 9,
			/* [4] = */ 25,
			/* [5] = */ 10,
			/* [6] = */ 26,
			/* [7] = */ 7,
			/* [8] = */ 11,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [1] = */ {
		/* .name = */ 0,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 1,
			/* [1] = */ 8,
			/* [2] = */ 9,
			/* [3] = */ 28,
			/* [4] = */ 16,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [2] = */ {
		/* .name = */ 0,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 12,
			/* [1] = */ 13,
			/* [2] = */ 28,
			/* [3] = */ 35,
			/* [4] = */ 27,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [3] = */ {
		/* .name = */ 0,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 1,
			/* [1] = */ 28,
			/* [2] = */ 35,
			/* [3] = */ 30,
			/* [4] = */ 14,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [4] = */ {
		/* .name = */ 0,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 1,
			/* [1] = */ 30,
			/* [2] = */ 14,
			/* [3] = */ 35,
			/* [4] = */ 31,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [5] = */ {
		/* .name = */ 0,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 1,
			/* [1] = */ 31,
			/* [2] = */ 35,
			/* [3] = */ 9,
			/* [4] = */ 23,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [6] = */ {
		/* .name = */ 0,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 15,
			/* [1] = */ 8,
			/* [2] = */ 24,
			/* [3] = */ 19,
			/* [4] = */ 16,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [7] = */ {
		/* .name = */ 0,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 10,
			/* [1] = */ 12,
			/* [2] = */ 19,
			/* [3] = */ 3,
			/* [4] = */ 16,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [8] = */ {
		/* .name = */ 0,
		/* .numguns = */ 6,
		/* .guncombo = */ {
			/* [0] = */ 3,
			/* [1] = */ 15,
			/* [2] = */ 19,
			/* [3] = */ 14,
			/* [4] = */ 18,
			/* [5] = */ 16,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [9] = */ {
		/* .name = */ 948,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 4,
			/* [1] = */ 33,
			/* [2] = */ 5,
			/* [3] = */ 35,
			/* [4] = */ 14,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [10] = */ {
		/* .name = */ 956,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 32,
			/* [1] = */ 13,
			/* [2] = */ 28,
			/* [3] = */ 35,
			/* [4] = */ 29,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [11] = */ {
		/* .name = */ 957,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 2,
			/* [1] = */ 30,
			/* [2] = */ 14,
			/* [3] = */ 35,
			/* [4] = */ 31,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [12] = */ {
		/* .name = */ 958,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 3,
			/* [1] = */ 15,
			/* [2] = */ 18,
			/* [3] = */ 19,
			/* [4] = */ 14,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [13] = */ {
		/* .name = */ 959,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 5,
			/* [1] = */ 12,
			/* [2] = */ 1,
			/* [3] = */ 15,
			/* [4] = */ 10,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [14] = */ {
		/* .name = */ 960,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 1,
			/* [1] = */ 30,
			/* [2] = */ 25,
			/* [3] = */ 25,
			/* [4] = */ 25,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [15] = */ {
		/* .name = */ 961,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 2,
			/* [1] = */ 7,
			/* [2] = */ 24,
			/* [3] = */ 24,
			/* [4] = */ 24,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [16] = */ {
		/* .name = */ 962,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 12,
			/* [1] = */ 14,
			/* [2] = */ 26,
			/* [3] = */ 26,
			/* [4] = */ 26,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [17] = */ {
		/* .name = */ 963,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 37,
			/* [1] = */ 37,
			/* [2] = */ 37,
			/* [3] = */ 37,
			/* [4] = */ 37,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	},
	/* [18] = */ {
		/* .name = */ 0,
		/* .numguns = */ 5,
		/* .guncombo = */ {
			/* [0] = */ 1,
			/* [1] = */ 9,
			/* [2] = */ 38,
			/* [3] = */ 39,
			/* [4] = */ 38,
			/* [5] = */ 0,
			/* [6] = */ 0,
			/* [7] = */ 0,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0,
			/* [12] = */ 0,
			/* [13] = */ 0,
			/* [14] = */ 0
		}
	}
};

setupheader setup_tileset = {
	/* .setupflags = */ 0,
	/* .gunset = */ 0,
	/* .props = */ NULL,
	/* .numprops = */ 0,
	/* .pickups = */ NULL,
	/* .numpickups = */ 0,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ NULL,
	/* .numspawnpads = */ 0,
	/* .NPCsetup = */ NULL,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ NULL,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ NULL,
	/* .numAIEventHandlers = */ 0,
	/* .si = */ NULL,
	/* .numNPCspawns = */ 0,
	/* .cars = */ NULL,
	/* .numcars = */ 0,
	/* .sr = */ NULL,
	/* .numremotes = */ 0,
	/* .specialfx = */ NULL,
	/* .numspecialfx = */ 0,
	/* .weatherdat = */ NULL,
	/* .numweatherdata = */ 0,
	/* .lsphases = */ NULL,
	/* .numlsphases = */ 0,
	/* .lssnipergrps = */ NULL,
	/* .numlssnipergrps = */ 0,
	/* .alarms = */ NULL,
	/* .numalarms = */ 0,
	/* .lifts = */ NULL,
	/* .numlifts = */ 0,
	/* .lvbuttons = */ NULL,
	/* .numlvbuttons = */ 0,
	/* .lvcameradata = */ NULL,
	/* .numcamera = */ 0,
	/* .lvpropspawn = */ NULL,
	/* .numpropspawns = */ 0
};

setupref proprefs[10] = {
	/* [0] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [1] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [2] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [3] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [4] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [5] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [6] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [7] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [8] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [9] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	}
};

setupref remoterefs[5] = {
	/* [0] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [1] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [2] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [3] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	},
	/* [4] = */ {
		/* .setupref = */ 0,
		/* .data = */ NULL
	}
};

static int tmparray[256];

level_info* lvGetInfoFromNum(int levelnum) {
	int i;
}

level_info* lvGetInfo() {}

int lvGetNumFromName(char *name) {
	int i;
}

u8* lvGetNameFromNum(int levelnum) {
	int i;
}

int lvGetTuneNum() {
	int i;
	mmfileinfo *inf;
}

int lvGetSkyPropNum() {
	level_info *info;
}

u32 lvGetBgCol() {
	level_info *info;
}

skySetting* lvGetSkySetting() {
	level_info *info;
}

static void lvTileSetLevelPreload() {
	mmfileinfo *mapinfo;
	u8 *bufpos;
	mmfilechunk *chk;
	mmfiledoor *dd;
	int i;
	int numdoors;
	int preloaddoor;
	int preloadwindow;
	int i;
	int j;
	u8 *chunkpos;
	int numitems;
	int propnum;
}

static void lvAllocTileSetSetup(setupheader *setup) {
	u8 *bufpos;
	int numtiles;
	mmfilepatrol *pMMPatrols[8];
	mmfilechunk *chk;
	int i;
	int j;
	u8 *chunkpos;
	int numitems;
	int headersize;
	int totalpatrolpos;
	int i;
	int *pPatrolBuffer;
}

static int patrolAngleTurnToAnim(float angledif) {
	float adif;
}

static float mapmakerItemAngleToRotY(itemangle_t angle) {}

static void lvCreateTileSetSetup(setupheader *setup) {
	u8 *bufpos;
	int numtiles;
	int padextrefcounter;
	struct {
		u16 firstpadextref;
	} *pTileInfo;
	setuppickup *pickups;
	setupspawn *spawnpads;
	setupprop *props;
	setupremote *remotes;
	setupdoor *doors;
	setupNPC *npcs;
	setupPatrolRoutes *patrols;
	float health_amounts[2];
	float armour_amounts[2];
	mmfilechunk *chk;
	mmfiledoor *dd;
	int i;
	int doorpropnum;
	int i;
	int j;
	int k;
	int globalpadextref;
	u8 *chunkpos;
	int numitems;
	padfile *padf;
	int setuppropnum;
	float roty;
	pad *levelpad;
	pad *levelpad;
	int i;
	int extref;
	int size;
	float *pos;
	float *nextpos;
	float angle;
	mmpatrolnode_t *nextPN;
	int nextExtRef;
	float nextangle;
	float adir;
	float adif;
	int insertanim;
}

int* lvGetLevelChrTypeNums(int levelnum) {
	static chrset_t default_chrset = {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 0,
			/* [9] = */ 0,
			/* [10] = */ 0,
			/* [11] = */ 0
		}
	};
	static chrset_t challenge9c_chrset = {
		/* .chrnums = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 0
		}
	};
}

void lvGetChrTypeNumFromSetup(int setupchrnum, int *pChrTypeUse, int *pChrTypeOriginal) {}

gunset* lvGetGunSet() {
	static gunset tmpguns;
	int i;
	setupheader *setup;
	setupchallenge *ch;
	setupheader *setup;
}

int lvIsValidGunCombo(int guncombo) {
	gunset *tmpguns;
	int i;
}

setupheader* lvGetARCADESetup(int levelnum) {
	setupheader *setup;
	int i;
}

setupheader* lvGetSTORYSetup(int levelnum) {
	setupheader *setup;
	int i;
}

setupheader* lvGetLevelSetup(int levelnum) {
	setupheader *setup;
}

static int lvGetPropNum(int pickupnum) {
	int tileset;
	guncombo *gc;
	int i;
	int dropteam;
}

setupNPC* lvGetRandomLastStandNPC(int npcgroup) {
	setupNPC *npc;
	setupNPC **groupNPCs;
	setupheader *setup;
	int groupcount;
	int startnpc;
	int endnpc;
	int i;
	int padnum;
	chrdata *loopcd;
}

static int lvGetRandomPad(chrdata *chr, int spawnflags) {
	int i;
	int n;
	int padnum;
	int startpad;
	int endpad;
	setupheader *setup;
	int *pads;
	chrdata *loopcd;
}

int lvGetRandomPlayerSpawn(void *chr) {}

int lvGetRandomAiSpawn(void *chr) {}

int lvGetRandomPadExtref(int paddata, float *pos) {
	pad *pad;
	int i;
	int maxtries;
	int gotpad;
	float topad[3];
	float minsq;
	float maxsq;
	float n;
	float n;
	float disttopadsq;
}

int lvGetPseudoRandomPadExtref(int paddata) {
	pad *pad;
	int i;
	int maxtries;
	int gotpad;
	float topad[3];
	float topaddir[3];
	float minsq;
	float maxsq;
	float costheta;
	float n;
	float n;
	int testpad;
	int p;
	float disttopadsq;
	float frac;
	float frac;
	int testpad;
	int p;
	float disttopadsq;
	float frac;
	float frac;
}

int lvGetPadExtrefFromData(int paddata) {}

static void lvLevelSetPadNumbers() {
	setupheader *setup;
	int i;
	setuppickup *sp;
	setupspawn *ss;
}

void lvSetupProp(setupprop *sp) {
	prop *p;
}

prop_s* lvGetPropFromSetupRef(int setupref) {
	int i;
}

static void processRemoteSetupRef(prop *p) {
	remotedata *rd;
}

remotedata* lvGetRemoteFromSetupRef(int setupref) {
	int i;
}

boolean lvCheckCreateFlagsCore(int flags) {}

boolean lvCheckCreateFlagsRestart(int flags) {}

boolean lvCheckCreateFlagsPreload(int flags) {}

boolean lvCheckCreateFlagsChallenge(int flags) {}

void lvLevelSetupPreload() {
	setupheader *setup;
	int i;
	gunset *levelguns;
	setupprop *sp;
	setuppropspawn *sps;
	setuppickup *sp;
	int propnum;
	int gunpickupnum;
	guncombo *gc;
	setupdoor *sd;
	setupcar *sc;
	setupremote *sr;
	setuplift *sl;
}

void lvLevelSetup() {
	setupheader *setup;
	prop *pProp;
	int i;
	gunset *levelguns;
	pad *padptr;
	setupalarm *sa;
	setupprop *sp;
	setuppickup *sp;
	int propnum;
	int ammoType;
	int ammo;
	int data2;
	prop_s *p;
	int gunpickupnum;
	guncombo *gc;
	prop *pProp;
	setupdoor *sd;
	setupcar *sc;
	int data1;
	prop *p;
	setupremote *sr;
	setupspecialfx *sf;
	specialfx *spfx;
	setuplift *sl;
	setupbutton *sb;
}

void lvbtnhndAlarm(lvbuttondata *bd) {
	int alarmnum;
}

void lvbtnhndDoor(lvbuttondata *bd) {}

void lvbtnhndMultiDoor(lvbuttondata *bd) {
	int *vdata1;
}

void lvbtnhndRemote(lvbuttondata *bd) {
	remotedata *rd;
	chrdata *acd;
}

void lvbtnhndEnemyRemote(lvbuttondata *bd) {
	remotedata *rd;
}

void lvButtonChangeStatus(lvbuttondata *bd) {}

void lvButtonActivate(prop *button, prop *actor) {
	lvbuttondata *bd;
}

void lvButtonTick(int b) {
	float timeinc;
	lvbuttondata *bd;
}

prop_s* propNewLvButton(setupbutton *sb) {
	prop *p;
}

int lvGetOverseerState() {}

float lvGetOverseerBackSleepTime() {}

void lvInitStoryState() {}

void lvCheckPropStatic(prop *p, int createflags, int forcedRoom) {
	float width;
	float cp[3];
}

int lvSetupCountChrsInSetupOfType(int type) {
	int i;
	int chrtypeuse;
	int chrtypeoriginal;
	int count;
	setupheader *setup;
	setupNPC *npc;
	setupNPC *npc;
}
