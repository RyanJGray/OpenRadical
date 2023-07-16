// STATUS: NOT STARTED

#include "unlock.h"

static unlockcondition_t unlock_playable_chrs[50] = {
	/* [0] = */ {
		/* .type = */ 1,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [1] = */ {
		/* .type = */ 1,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [2] = */ {
		/* .type = */ 3,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [3] = */ {
		/* .type = */ 3,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [4] = */ {
		/* .type = */ 1,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [5] = */ {
		/* .type = */ 1,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [6] = */ {
		/* .type = */ 3,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [7] = */ {
		/* .type = */ 3,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [8] = */ {
		/* .type = */ 4,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [9] = */ {
		/* .type = */ 4,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [10] = */ {
		/* .type = */ 4,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [11] = */ {
		/* .type = */ 4,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [12] = */ {
		/* .type = */ 1,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [13] = */ {
		/* .type = */ 1,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [14] = */ {
		/* .type = */ 3,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [15] = */ {
		/* .type = */ 3,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [16] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [17] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [18] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [19] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [20] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [21] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [22] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [23] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [24] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [25] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [26] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [27] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [28] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [29] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [30] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [31] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [32] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [33] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [34] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [35] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [36] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [37] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [38] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [39] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [40] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [41] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [42] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [43] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [44] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [45] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [46] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [47] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [48] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	},
	/* [49] = */ {
		/* .type = */ 0,
		/* .data1 = */ 0,
		/* .data2type = */ 0,
		/* .data2 = */ 0
	}
};

static unlockcondition_t unlock_botsetup_duckman = {
	/* .type = */ 6,
	/* .data1 = */ 3,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botsetup_robofish = {
	/* .type = */ 6,
	/* .data1 = */ 6,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botsetup_impersonator = {
	/* .type = */ 6,
	/* .data1 = */ 12,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botsetup_gingerbread = {
	/* .type = */ 6,
	/* .data1 = */ 18,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botsetup_funbunny = {
	/* .type = */ 6,
	/* .data1 = */ 21,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_story123 = {
	/* .type = */ 3,
	/* .data1 = */ 0,
	/* .data2type = */ 0,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_story456 = {
	/* .type = */ 4,
	/* .data1 = */ 0,
	/* .data2type = */ 0,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_story789 = {
	/* .type = */ 5,
	/* .data1 = */ 0,
	/* .data2type = */ 0,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_graveyard = {
	/* .type = */ 2,
	/* .data1 = */ 1507329,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_site = {
	/* .type = */ 2,
	/* .data1 = */ 1376257,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_streets = {
	/* .type = */ 2,
	/* .data1 = */ 917505,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_lab = {
	/* .type = */ 2,
	/* .data1 = */ 131073,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_bank = {
	/* .type = */ 2,
	/* .data1 = */ 327681,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_spaceship = {
	/* .type = */ 2,
	/* .data1 = */ 589825,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_mall = {
	/* .type = */ 2,
	/* .data1 = */ 524289,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_compound = {
	/* .type = */ 2,
	/* .data1 = */ 1572865,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_future = {
	/* .type = */ 2,
	/* .data1 = */ 1769473,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botset1 = {
	/* .type = */ 2,
	/* .data1 = */ 131072,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botset2 = {
	/* .type = */ 2,
	/* .data1 = */ 327680,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botset3 = {
	/* .type = */ 2,
	/* .data1 = */ 589824,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botset4 = {
	/* .type = */ 2,
	/* .data1 = */ 524288,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botset5 = {
	/* .type = */ 2,
	/* .data1 = */ 1572864,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botset6 = {
	/* .type = */ 6,
	/* .data1 = */ 0,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_botset7 = {
	/* .type = */ 6,
	/* .data1 = */ 24,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

static unlockcondition_t unlock_challengemode = {
	/* .type = */ 2,
	/* .data1 = */ 1769472,
	/* .data2type = */ 2,
	/* .data2 = */ 0
};

boolean chrPlayable(int chrnum) {}

boolean chrAvail(int chrnum) {
	unlockcondition_t *uc;
}

boolean levelAvailSTORY(int levelnum, int use2Ptimes) {}

boolean levelAvail(int levelnum) {}

boolean botsetAvail(int arcadebotset) {}

boolean challengeModeAvail() {}

boolean challengeAvail(int challengenum) {}

boolean unlockedset(unlockconditionset_t *ucset) {
	int i;
}

boolean unlockedEx(unlockcondition_t *uc, int use2Ptimes) {
	int i;
	u32 *besttimes;
	int i;
	u32 *besttimes;
	int i;
	u32 *besttimes;
	int levelnum;
	int difficulty;
	int score;
	u32 *besttimes;
	int challengenum;
	int score;
}
