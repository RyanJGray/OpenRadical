//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "bullet.h"

enum {
	LASERBOLT_GREEN = 0,
	LASERBOLT_BLUE = 1,
	LASERBOLT_PURPLE = 2,
	LASERBOLT_ORANGE = 3,
	LASERBOLT_RED = 4,
	NUM_LASERBOLT_TYPES = 5
};

enum {
	EXPLOSIONRENDER_NONE = -1,
	EXPLOSIONRENDER_NORMAL_IMPACT = 0,
	EXPLOSIONRENDER_SMALL_IMPACT = 1,
	EXPLOSIONRENDER_MUSHROOM = 2,
	EXPLOSIONRENDER_MUSHROOM2 = 3,
	EXPLOSIONRENDER_BLUEROCKET1 = 4,
	EXPLOSIONRENDER_BLUEROCKET2 = 5,
	NUM_EXPLOSION_RENDERS = 6
};

enum {
	BULLET_GROUP_NONE = -1,
	BULLET_GROUP_TYPE_BULLETS = 0,
	BULLET_GROUP_TYPE_MINES = 1,
	BULLET_GROUP_TYPE_EXPLOSIONS = 2,
	NUM_BULLET_GROUP_TYPES = 3
};

enum {
	PROXIMITY_STAGE_NOT_ARMED = 0,
	PROXIMITY_STAGE_ARMED = 1,
	PROXIMITY_STAGE_EJECT_CLIP = 2,
	PROXIMITY_STAGE_EJECT_MINE_WAIT = 3,
	PROXIMITY_STAGE_EJECT_MINE = 4,
	PROXIMITY_STAGE_DONE = 5
};

typedef struct explosionRender_s {
	boolean blast;
	u32 colour;
	float size;
} explosionRender;

laserBoltDef laserBolts[5] = {
	/* [0] = */ {
		/* .radius = */ 0.2f,
		/* .length = */ 3.f,
		/* .abgr = */ 32543,
		/* .repetitions = */ 1
	},
	/* [1] = */ {
		/* .radius = */ 0.2f,
		/* .length = */ 3.f,
		/* .abgr = */ 24383,
		/* .repetitions = */ 1
	},
	/* [2] = */ {
		/* .radius = */ 0.2f,
		/* .length = */ 3.f,
		/* .abgr = */ 12095,
		/* .repetitions = */ 1
	},
	/* [3] = */ {
		/* .radius = */ 0.1f,
		/* .length = */ 1.5f,
		/* .abgr = */ 20351,
		/* .repetitions = */ 1
	},
	/* [4] = */ {
		/* .radius = */ 0.2f,
		/* .length = */ 2.f,
		/* .abgr = */ 8063,
		/* .repetitions = */ 1
	}
};

explosionRender explosionRenders[6] = {
	/* [0] = */ {
		/* .blast = */ 0,
		/* .colour = */ 32639,
		/* .size = */ 1500.f
	},
	/* [1] = */ {
		/* .blast = */ 0,
		/* .colour = */ 24447,
		/* .size = */ 600.f
	},
	/* [2] = */ {
		/* .blast = */ 1,
		/* .colour = */ 24447,
		/* .size = */ 800.f
	},
	/* [3] = */ {
		/* .blast = */ 1,
		/* .colour = */ 24447,
		/* .size = */ 3000.f
	},
	/* [4] = */ {
		/* .blast = */ 0,
		/* .colour = */ 3855,
		/* .size = */ 1500.f
	},
	/* [5] = */ {
		/* .blast = */ 0,
		/* .colour = */ 32639,
		/* .size = */ 1100.f
	}
};

explosionDef explosionDefs[5] = {
	/* [0] = */ {
		/* .explosionRenderType1 = */ 0,
		/* .explosionRenderType2 = */ -1,
		/* .damageFactor = */ 3.3f,
		/* .damageDist = */ 4.35f
	},
	/* [1] = */ {
		/* .explosionRenderType1 = */ 1,
		/* .explosionRenderType2 = */ -1,
		/* .damageFactor = */ 2.4f,
		/* .damageDist = */ 2.4f
	},
	/* [2] = */ {
		/* .explosionRenderType1 = */ 1,
		/* .explosionRenderType2 = */ 2,
		/* .damageFactor = */ 6.f,
		/* .damageDist = */ 4.f
	},
	/* [3] = */ {
		/* .explosionRenderType1 = */ 0,
		/* .explosionRenderType2 = */ 3,
		/* .damageFactor = */ 4.f,
		/* .damageDist = */ 3.f
	},
	/* [4] = */ {
		/* .explosionRenderType1 = */ 4,
		/* .explosionRenderType2 = */ 5,
		/* .damageFactor = */ 1.5f,
		/* .damageDist = */ 3.75f
	}
};

bulletInfo bulletInfos[35] = {
	/* [0] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .dualShockDamage = */ 0.f,
		/* .dualShockSlowdown = */ 0.f,
		/* .decalType = */ 0,
		/* .decalScale = */ 0.f,
		/* .paintballabgr = */ 0,
		/* .paintballScale = */ 0.f,
		/* .flags = */ 0
	},
	/* [1] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.5f,
			/* [1] = */ 0.5f,
			/* [2] = */ 0.2f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 1,
		/* .decalScale = */ 1.f,
		/* .paintballabgr = */ 16383,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 24
	},
	/* [2] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.5f,
			/* [1] = */ 0.5f,
			/* [2] = */ 0.2f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 1,
		/* .decalScale = */ 1.f,
		/* .paintballabgr = */ 16727808,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 24
	},
	/* [3] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.5f,
			/* [1] = */ 0.5f,
			/* [2] = */ 0.2f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.8f,
		/* .decalType = */ 1,
		/* .decalScale = */ 1.f,
		/* .paintballabgr = */ 65535,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 24
	},
	/* [4] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 1.f,
			/* [1] = */ 1.f,
			/* [2] = */ 0.5f
		},
		/* .dualShockDamage = */ 1.f,
		/* .dualShockSlowdown = */ 0.8f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16711743,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [5] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 1.f,
			/* [1] = */ 1.f,
			/* [2] = */ 0.5f
		},
		/* .dualShockDamage = */ 1.f,
		/* .dualShockSlowdown = */ 0.8f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16711743,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [6] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 1.f,
			/* [1] = */ 1.f,
			/* [2] = */ 0.5f
		},
		/* .dualShockDamage = */ 1.f,
		/* .dualShockSlowdown = */ 0.8f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16711743,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [7] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 1.f,
			/* [1] = */ 1.f,
			/* [2] = */ 0.5f
		},
		/* .dualShockDamage = */ 1.f,
		/* .dualShockSlowdown = */ 0.8f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16711743,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [8] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.8f,
			/* [1] = */ 0.8f,
			/* [2] = */ 1.f
		},
		/* .dualShockDamage = */ 1.f,
		/* .dualShockSlowdown = */ 0.8f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16711743,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [9] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.3f,
			/* [2] = */ 0.1f
		},
		/* .dualShockDamage = */ 0.f,
		/* .dualShockSlowdown = */ 0.f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16711935,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [10] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.3f,
			/* [2] = */ 0.1f
		},
		/* .dualShockDamage = */ 0.f,
		/* .dualShockSlowdown = */ 0.f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16711935,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [11] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.3f,
			/* [2] = */ 0.1f
		},
		/* .dualShockDamage = */ 0.f,
		/* .dualShockSlowdown = */ 0.f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16711935,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [12] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.3f,
			/* [2] = */ 0.1f
		},
		/* .dualShockDamage = */ 0.f,
		/* .dualShockSlowdown = */ 0.f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16711935,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [13] = */ {
		/* .groupType = */ 1,
		/* .lightCol = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.3f,
			/* [2] = */ 0.1f
		},
		/* .dualShockDamage = */ 0.f,
		/* .dualShockSlowdown = */ 0.f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 4194048,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 6
	},
	/* [14] = */ {
		/* .groupType = */ 1,
		/* .lightCol = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.3f,
			/* [2] = */ 0.1f
		},
		/* .dualShockDamage = */ 0.f,
		/* .dualShockSlowdown = */ 0.f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 4194048,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 6
	},
	/* [15] = */ {
		/* .groupType = */ 1,
		/* .lightCol = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.3f,
			/* [2] = */ 0.1f
		},
		/* .dualShockDamage = */ 0.f,
		/* .dualShockSlowdown = */ 0.f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 4194048,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 6
	},
	/* [16] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.3f,
			/* [2] = */ 0.1f
		},
		/* .dualShockDamage = */ 0.f,
		/* .dualShockSlowdown = */ 0.f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16776960,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [17] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.3f,
			/* [2] = */ 0.1f
		},
		/* .dualShockDamage = */ 0.f,
		/* .dualShockSlowdown = */ 0.f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 16776960,
		/* .paintballScale = */ 2.f,
		/* .flags = */ 14
	},
	/* [18] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .dualShockDamage = */ 1.f,
		/* .dualShockSlowdown = */ 0.8f,
		/* .decalType = */ 0,
		/* .decalScale = */ 0.f,
		/* .paintballabgr = */ 0,
		/* .paintballScale = */ 0.f,
		/* .flags = */ 4
	},
	/* [19] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 1.f,
			/* [1] = */ 0.7f,
			/* [2] = */ 0.4f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 3,
		/* .decalScale = */ 1.f,
		/* .paintballabgr = */ 255,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 28
	},
	/* [20] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 1.f,
			/* [1] = */ 1.f,
			/* [2] = */ 1.f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 4,
		/* .decalScale = */ 1.f,
		/* .paintballabgr = */ 255,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 20
	},
	/* [21] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.8f,
			/* [1] = */ 0.8f,
			/* [2] = */ 1.f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 0,
		/* .decalScale = */ 1.f,
		/* .paintballabgr = */ 4153343,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 28
	},
	/* [22] = */ {
		/* .groupType = */ 2,
		/* .lightCol = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .dualShockDamage = */ 0.5f,
		/* .dualShockSlowdown = */ 0.8f,
		/* .decalType = */ 3,
		/* .decalScale = */ 2.f,
		/* .paintballabgr = */ 255,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 10
	},
	/* [23] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.5f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 16736047,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [24] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.5f
		},
		/* .dualShockDamage = */ 0.5f,
		/* .dualShockSlowdown = */ 0.6f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 16711680,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [25] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.5f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 65280,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [26] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 65535,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [27] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.5f,
			/* [2] = */ 0.f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 16711680,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [28] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.5f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 16711680,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [29] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.5f,
			/* [1] = */ 0.25f,
			/* [2] = */ 0.f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 16711680,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [30] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.5f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 16711680,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [31] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.5f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 16711680,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [32] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.5f,
			/* [1] = */ 0.5f,
			/* [2] = */ 0.f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 16711680,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [33] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.5f,
			/* [1] = */ 0.5f,
			/* [2] = */ 0.5f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 16711680,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	},
	/* [34] = */ {
		/* .groupType = */ 0,
		/* .lightCol = */ {
			/* [0] = */ 0.5f,
			/* [1] = */ 0.5f,
			/* [2] = */ 0.5f
		},
		/* .dualShockDamage = */ 0.9f,
		/* .dualShockSlowdown = */ 0.7f,
		/* .decalType = */ 2,
		/* .decalScale = */ 0.3f,
		/* .paintballabgr = */ 16711680,
		/* .paintballScale = */ 1.f,
		/* .flags = */ 8
	}
};

static int ricochetsounds_0[0] = {
};

static int ricochetsounds_wood1[0] = {
};

static int ricochetsounds_wood2[0] = {
};

static int ricochetsounds_stone[0] = {
};

static int ricochetsounds_tile[0] = {
};

static int ricochetsounds_paper1[0] = {
};

static int ricochetsounds_paper2[0] = {
};

static int ricochetsounds_glass1[0] = {
};

static int ricochetsounds_glass2[0] = {
};

static int ricochetsounds_water1[0] = {
};

static int ricochetsounds_water2[0] = {
};

static int ricochetsounds_dirtfloor[0] = {
};

static int ricochetsounds_metal1[0] = {
};

static int ricochetsounds_metal2[0] = {
};

static int ricochetsounds_metal3[0] = {
};

static int ricochetsounds_metal4[0] = {
};

static int ricochetsounds_metal5[0] = {
};

static int ricochetsounds_metal6[0] = {
};

static int ricochetsounds_metal7[0] = {
};

static int ricochetsounds_chainfence[0] = {
};

static int ricochetsounds_body[0] = {
};

static int ricochetsounds_duck[0] = {
};

static int ricochetsounds_robot1[0] = {
};

static int ricochetsounds_robot2[0] = {
};

static int ricochetsounds_robot3[0] = {
};

static int ricochetsounds_misc1[0] = {
};

static int ricochetsounds_misc2[0] = {
};

static int ricochetsounds_misc3[0] = {
};

static int ricochetsounds_misc4[0] = {
};

static int ricochetsounds_misc5[0] = {
};

static int ricochetsounds_misc6[0] = {
};

static int ricochetsounds_misc7[0] = {
};

static int ricochetsounds_misc8[0] = {
};

static int ricochetsounds_misc9[0] = {
};

static int ricochetsounds_misc10[0] = {
};

static int *ricochetsoundarrays[35] = {
	/* [0] = */ ricochetsounds_0,
	/* [1] = */ ricochetsounds_wood1,
	/* [2] = */ ricochetsounds_wood2,
	/* [3] = */ ricochetsounds_stone,
	/* [4] = */ ricochetsounds_tile,
	/* [5] = */ ricochetsounds_paper1,
	/* [6] = */ ricochetsounds_paper2,
	/* [7] = */ ricochetsounds_glass1,
	/* [8] = */ ricochetsounds_glass2,
	/* [9] = */ ricochetsounds_water1,
	/* [10] = */ ricochetsounds_water2,
	/* [11] = */ ricochetsounds_dirtfloor,
	/* [12] = */ ricochetsounds_metal1,
	/* [13] = */ ricochetsounds_metal2,
	/* [14] = */ ricochetsounds_metal3,
	/* [15] = */ ricochetsounds_metal4,
	/* [16] = */ ricochetsounds_metal5,
	/* [17] = */ ricochetsounds_metal6,
	/* [18] = */ ricochetsounds_metal7,
	/* [19] = */ ricochetsounds_chainfence,
	/* [20] = */ ricochetsounds_body,
	/* [21] = */ ricochetsounds_duck,
	/* [22] = */ ricochetsounds_robot1,
	/* [23] = */ ricochetsounds_robot2,
	/* [24] = */ ricochetsounds_robot3,
	/* [25] = */ ricochetsounds_misc1,
	/* [26] = */ ricochetsounds_misc2,
	/* [27] = */ ricochetsounds_misc3,
	/* [28] = */ ricochetsounds_misc4,
	/* [29] = */ ricochetsounds_misc5,
	/* [30] = */ ricochetsounds_misc6,
	/* [31] = */ ricochetsounds_misc7,
	/* [32] = */ ricochetsounds_misc8,
	/* [33] = */ ricochetsounds_misc9,
	/* [34] = */ ricochetsounds_misc10
};

static int retargetstart = 0;

static float electricityStartConeLength[2] = {
	/* [0] = */ 0.5f,
	/* [1] = */ 1.7f
};

static float bulletElectricityAngles[2] = {
	/* [0] = */ 0.f,
	/* [1] = */ 90.f
};

static bullet *bullets;
static int bullethead[3];
static int bullettail[3];

bullet* bulletGetFromArray(int bulletIndex) {}

static void ricochetsfx(int surfacetype, float *pos) {
	int *array;
	int num;
}

void bulletClearData(bullet *b) {
	int i;
}

void bulletRestart() {
	int i;
}

void bulletReset() {}

void bulletDetachParticlefx(bullet *b, int index) {}

void bulletFreeParticlefx(bullet *b, int index) {}

static void bulletDisconnect(int num, int grouptype) {
	bullet *b;
	int next;
	int prev;
	int i;
	int e;
}

int bulletTypeExplosive(int bullettype) {}

static void bulletAddHead(int num, int grouptype) {
	bullet *b;
}

static void bulletAddTail(int num, int grouptype) {
	bullet *b;
}

bullet* bulletNew(int type) {
	bullet *b;
	int grouptype;
	int num;
}

void bulletFree(bullet *b) {
	int grouptype;
}

void bulletNewBlood(int bloodType, prop *hitprop, float *hitpos, float *blooddir) {
	float bloodintensity[3];
}

static void bulletInitialiseStraightLineTest(bullet *pBullet) {
	HitInfoDef HitInfo;
}

static prop* bulletStraightLineTest(bullet *pBullet, float *Dir, float *HitPos, float *HitNorm, glassResults *glassRes) {
	int Flags;
	prop *pRet;
	float EyePos[3];
	float EDir[3];
	int EyeRoom;
	prop *pController;
	int ControllerFlags;
	int excludeflags;
	float Vector[3];
	int Room;
	float StartPos[3];
	int excludeFlags;
	prop *pTestProp;
	float HitPos1[3];
	float HitNorm1[3];
}

static prop* bulletNonStraightLineTest(bullet *pBullet, float *Dir, float *HitPos, float *HitNorm, glassResults *glassRes) {
	int Flags;
	prop *pRet;
	float bulletpos[3];
	int ColFlags;
	int excludeFlags;
	float EyePos[3];
	float EDir[3];
	int EyeRoom;
	prop *pController;
	int ControllerFlags;
}

void bulletExplodeMines(float *Pos, float Dist) {
	int i;
	bullet *b;
	float Dir[3];
}

void bulletGetMinesAttachedToProp(prop *p, int *proximitymines, int *remotemines, int *timedmines) {
	int i;
}

void bulletGetMinesAttachedToPropMatrix(prop *p, int matrixnum, int *proximitymines, int *remotemines, int *timedmines) {
	int i;
}

void bulletExplodeMine(bullet *b) {}

void bulletExplodeMineAtPos(bullet *b, float *pos) {}

bullet* bulletNewFromGun(int bulletType, float *fpShootPos, float *tpShootPos, float *dir, fireInfo_t *fi, prop *firedByProp, chrdata *firedByChr, int ownerType, int repeatFire, int bulletflag) {
	int repeatFire;
	int bulletflag;
	bullet *b;
	int newFlames;
	int f;
	int gunfxtype;
	float tpDir[3];
	float fpDir[3];
	float variation;
	int propNum;
	float posx;
	float rndtarget;
	float burntime;
	float timeHeldScalar;
	int e;
	float time;
	int oldest;
	int found;
}

bullet* bulletNewExplosion(int explosionType, int bulletType, float *pos, float *hitnorm, prop *attackerProp, prop *hitprop) {
	bullet *b;
	int r;
	int renderType;
}

void updateProximityProps(bullet *b, prop *owner) {
	mtx_u mat;
	obdef *bobdef;
	partdef *parts;
	float *dof;
	prop *hitprop;
	float hitpos[3];
	float hitnorm[3];
	float dist[3];
	glassResults glassRes;
	float col[3];
}

void bulletRegularTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	float rlen;
	float nbdir[3];
	float dot;
	float reflect[3];
	int hitproptype;
	HitInfoDef HitInfo;
	partdef *parts;
	partdef *part;
	int texnum;
	int soundtype;
	player *pl;
}

void bulletRocketTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	float dir[3];
	float dx;
	float dz;
	float dist;
	float rlen;
	float turnspeed;
	float targetposy;
	float bias[3];
	int hitproptype;
	float rlen;
	float nbdir[3];
	float dot;
	float reflect[3];
	player *pl;
	int i;
	float rate;
	float timescalar;
	float invscalar;
	float timescalar;
	float invscalar;
	int stripType;
}

void bulletGrenadeTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	float nbdir[3];
	float reflect[3];
	float frac;
	float rlen;
	int particleID;
	float rate;
}

void bulletTNTTick(bullet *b) {
	float burntime;
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	prop *hitprop;
	glassResults glassRes;
	float frac;
}

void bulletBrickTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	float frac;
	float rlen;
	float nbdir[3];
	float dot;
	float reflect[3];
	player *pl;
}

void bulletDiscTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	int hitproptype;
	float rlen;
	float nbdir[3];
	float dot;
	float reflect[3];
	player *pl;
	int i;
}

static void bulletInflightActivateChrs(bullet *b) {
	int i;
	float dx;
	float dy;
	float dz;
	chrdata *cd;
}

static void bulletCloseImpactActivateChrs(bullet *b) {
	player *pl;
	float dx;
	float dy;
	float dz;
	chrdata *cd;
	int i;
}

void bulletMineTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	obdef *pOb;
	partdef *pParts;
	obdef *pOb;
	partdef *pParts;
	HitInfoDef HitInfo;
	mtx_u Matrix;
	mtx_u InvMatrix;
	float frac;
	mtx_u Matrix;
	float Pos[3];
	float Norm[3];
	float trigger;
	float triggerOff;
	int trigger;
}

void bulletPetrolTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	int i;
}

void bulletPetrolGfx(bullet *b) {
	int texture;
	int texwidth;
	int texheight;
	float newpos[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float pos[3];
	float size;
}

void bulletFlameTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	float rlen;
	float nbdir[3];
	int hitproptype;
	chrdata *hitcd;
	int f;
	int gunfxtype;
	HitInfoDef HitInfo;
	float fpos[3];
	float fdir[3];
}

void bulletNewLaserCoils(bullet *b) {
	laserData *ld;
	int c;
	int n;
	float diff[3];
	prop *hitprop;
	float leninv;
	float targetoffset[3];
	glassResults glassRes;
	float hitnormal[3];
	float diff[3];
	float forward[3];
	float up[3];
	laserCoil *coil;
	float scalar;
	float scalar;
}

void bulletLaserCoilsTick(bullet *b) {
	laserData *ld;
	laserCoil *coil;
	int c;
	int n;
	laserNode *node;
	float timeScalar;
	float timeClamp;
	float scalar;
	float wave;
	float flexibility;
	float radius;
}

void bulletLaserCoilsGfx(bullet *b) {
	laserData *ld;
	int particleTexture;
	int tcount;
	int c;
	int a;
	int n;
	laserCoil *coil;
	u32 *ref;
	u32 *xyzwRef;
	u32 *stqRef;
	int totalPoints;
	int quadWordSize;
	float time;
	int qwc;
	void *addr;
	float angle;
	float cosangle;
	float sinangle;
	float cosRadius;
	float sinRadius;
	laserNode *node;
	u32 abgr;
	float pos1[3];
	float pos2[3];
	int num;
	emTexture *pTex;
	void *addr;
}

void bulletFlareTick(bullet *b) {}

void bulletElectroRocketTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	float rlen;
	float nbdir[3];
	float dot;
	float reflect[3];
	int hitproptype;
	player *pl;
}

void bulletElectricTickBefore(bullet *b) {
	electricData *ed;
	prop *hitprop;
	float leninv;
	float targetoffset[3];
	glassResults glassRes;
	float hitnormal[3];
	float diff[3];
	float forward[3];
	float up[3];
}

void bulletElectricTickAfter(bullet *b) {}

void bulletElectricGfx(bullet *b) {
	electricData *ed;
	int particleTexture;
	int n;
	int p;
	int numPoints;
	int quadWordSize;
	int tcount;
	boolean player;
	u32 *ref;
	u32 *xyzwRef;
	u32 *stqRef;
	u32 abgr;
	u32 abgrMain;
	u32 abgrCone;
	int z;
	float sizePerspect;
	float pos[3];
	float newpos[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	int texture;
	int texwidth;
	int texheight;
	u32 abgr;
	float rot;
	float s;
	float c;
	void *addr;
	int qwc;
	void *addr;
	float angle;
	float angleTranslation;
	float cosangle;
	float sinangle;
	float distance;
	float startTranslate;
	float translate;
	boolean cone;
	float radius;
	float cosRadius;
	float sinRadius;
	float centrepos[3];
	float pos1[3];
	float pos2[3];
	int num;
	emTexture *pTex;
	void *addr;
}

void bulletNewWallHugger(bullet *b) {}

void bulletWallHuggerTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	float hoverDist[3];
	float testDist[3];
	float rlen;
	float nbdir[3];
	glassResults glassRes;
	prop *hitprop;
	float bias[3];
	float diff[3];
	int e;
	float bias[3];
	float dot;
	float reflect[3];
	float hitDist[3];
	float hitlensq;
	float distMovedLensq;
	float up[3];
	float right[3];
	float axis1[3];
	float axis2[3];
	float newdir[3];
	float newrlen;
}

void bulletWallHuggerGfx(bullet *b) {
	int texture;
	int texwidth;
	int texheight;
	float newpos[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float pos[3];
	float size;
}

void bulletLaserBoltTick(bullet *b) {
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	float rlen;
	float nbdir[3];
	float dot;
	float reflect[3];
	int hitproptype;
	int particleID;
	HitInfoDef HitInfo;
	player *pl;
}

void bulletLaserBoltGfx(bullet *b) {
	int particleTexture;
	int tcount;
	int c;
	u32 bgr;
	u32 fullAlpha;
	float normal[3];
	float axis1[3];
	float axis2[3];
	float leninv;
	float maxLength;
	float boltLength;
	float forward[3];
	float up[3];
	int a;
	int n;
	u32 *ref;
	u32 *xyzwRef;
	u32 *stqRef;
	int quadWordSize;
	int qwc;
	void *addr;
	float rot;
	float angle;
	float cosangle;
	float sinangle;
	float cosRadius;
	float sinRadius;
	u32 alpha;
	u32 abgr;
	float pos1[3];
	float pos2[3];
	float pos[3];
	float scalar;
	int num;
	emTexture *pTex;
	void *addr;
}

void bulletNewArcLaser(bullet *b) {
	float leninv;
	float forward[3];
	float up[3];
}

void bulletArcLaserTick(bullet *b) {
	float newpos[3];
	float distMoved[3];
	float hitpos[3];
	float hitnorm[3];
	glassResults glassRes;
	prop *hitprop;
	int i;
	float cosangle;
	float sinangle;
	float startbtime;
	float radius;
	float cosradius;
	float sinradius;
	int hitproptype;
	float rlen;
	float nbdir[3];
	float dot;
	float reflect[3];
	player *pl;
}

void bulletArcLaserGfx(bullet *b) {
	int texture;
	int texwidth;
	int texheight;
	float newpos[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float pos[3];
	float size;
}

void bulletTickBefore() {
	int i;
	bullet *b;
	int doCollisionFlags;
	prop *attackerPropCopyPtr;
}

void bulletTickAfter() {
	int i;
	bullet *b;
}

void bulletArcadeRocketGfx(bullet *b) {
	int e;
	u32 col[3];
	u32 alpha;
	int texture;
	int texwidth;
	int texheight;
	float up[3];
	float right[3];
	float axis1[3];
	float axis2[3];
	float leninv;
	float normaldir[3];
	float pos[3];
	float newpos[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float scalar;
	float cosradius;
	float sinradius;
	int size;
	float alphascale;
}

void bulletGfx() {
	int i;
	void *addr;
	bullet *b;
}

void bulletEnd() {}

bullet* bulletFind(chrdata *firedByChr, int type) {
	int i;
}

void bulletGetBulletColour(int BulletType, float *Col) {}

void bulletGetClosestLight(obinst *inst, int InstID, float *pos, int PosRoom, bglighttest **Lights) {
	static bglighttest LightTest[6];
	bglighttest *pLightTest[5];
	bglighttest *pTest;
	int i;
	bullet *b;
	bullet *b;
	float Frac;
	float RDist;
}

void bulletProcessGlasshits(bullet *b, glassResults *glassRes) {
	float damage;
}

void bulletMakeAttachedMinesInvisible(prop *pProp) {
	int i;
}
