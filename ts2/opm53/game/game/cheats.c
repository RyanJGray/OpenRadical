// STATUS: NOT STARTED

#include "cheats.h"

static unlockconditionset_t unlock_cheat_bigheads = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_smallheads = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_bigguns = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_infiniteammo = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_paintball = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_gunsounds = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_npcrockets = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_npcbricks = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_npcbonuschr1 = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_npcbonuschr2 = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_npcbonuschr3 = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_npcbonuschr4 = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_npcbonuschr5 = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_headless = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

static unlockconditionset_t unlock_cheat_headsremovable = {
	/* .numconditions = */ 1,
	/* .conditions = */ {
	}
};

cheatdef_t cheatdefs[15] = {
	/* [0] = */ {
		/* .name = */ 724,
		/* .flags = */ 3,
		/* .unlockset = */ &unlock_cheat_bigheads
	},
	/* [1] = */ {
		/* .name = */ 725,
		/* .flags = */ 3,
		/* .unlockset = */ &unlock_cheat_smallheads
	},
	/* [2] = */ {
		/* .name = */ 726,
		/* .flags = */ 3,
		/* .unlockset = */ &unlock_cheat_bigguns
	},
	/* [3] = */ {
		/* .name = */ 727,
		/* .flags = */ 3,
		/* .unlockset = */ &unlock_cheat_infiniteammo
	},
	/* [4] = */ {
		/* .name = */ 728,
		/* .flags = */ 3,
		/* .unlockset = */ &unlock_cheat_paintball
	},
	/* [5] = */ {
		/* .name = */ 729,
		/* .flags = */ 3,
		/* .unlockset = */ &unlock_cheat_gunsounds
	},
	/* [6] = */ {
		/* .name = */ 730,
		/* .flags = */ 1,
		/* .unlockset = */ &unlock_cheat_npcrockets
	},
	/* [7] = */ {
		/* .name = */ 731,
		/* .flags = */ 1,
		/* .unlockset = */ &unlock_cheat_npcbricks
	},
	/* [8] = */ {
		/* .name = */ 732,
		/* .flags = */ 1,
		/* .unlockset = */ &unlock_cheat_npcbonuschr1
	},
	/* [9] = */ {
		/* .name = */ 733,
		/* .flags = */ 1,
		/* .unlockset = */ &unlock_cheat_npcbonuschr2
	},
	/* [10] = */ {
		/* .name = */ 734,
		/* .flags = */ 1,
		/* .unlockset = */ &unlock_cheat_npcbonuschr3
	},
	/* [11] = */ {
		/* .name = */ 735,
		/* .flags = */ 1,
		/* .unlockset = */ &unlock_cheat_npcbonuschr4
	},
	/* [12] = */ {
		/* .name = */ 736,
		/* .flags = */ 1,
		/* .unlockset = */ &unlock_cheat_npcbonuschr5
	},
	/* [13] = */ {
		/* .name = */ 737,
		/* .flags = */ 3,
		/* .unlockset = */ &unlock_cheat_headless
	},
	/* [14] = */ {
		/* .name = */ 738,
		/* .flags = */ 3,
		/* .unlockset = */ &unlock_cheat_headsremovable
	}
};

u32 unlockedcheats = 0;
u32 selectedcheats = 0;
u32 allowedcheats = 0;

void cheatsUpdate() {
	int i;
}

u32 cheatsChrSelect() {}

u32 cheatsArcade() {
	u32 cheats;
	int i;
}

u32 cheatsStory() {
	u32 cheats;
	int i;
}

void cheatsMake() {}

void cheatsReset() {}
