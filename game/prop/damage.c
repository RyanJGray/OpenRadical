// STATUS: NOT STARTED

#include "damage.h"

static float playerStoryMaxHealth[3] = {
	/* [0] = */ 30.f,
	/* [1] = */ 15.f,
	/* [2] = */ 10.f
};

static float enemyStoryMaxHealth[3] = {
	/* [0] = */ 1.f,
	/* [1] = */ 1.f,
	/* [2] = */ 1.f
};

static float arcadeMaxHealth = 10.f;

static float playerStoryMaxArmour[3] = {
	/* [0] = */ 20.f,
	/* [1] = */ 15.f,
	/* [2] = */ 10.f
};

static float enemyStoryMaxArmour[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f
};

static float arcadeMaxArmour = 10.f;

damageInfo damageInfos[15] = {
	/* [0] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 1.3f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.5f
			},
			/* [1] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.35f
			},
			/* [2] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.2f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.4f
	},
	/* [1] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 1.6f,
				/* [1] = */ 0.9f,
				/* [2] = */ 0.75f
			},
			/* [1] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.5f
			},
			/* [2] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.55f,
				/* [2] = */ 0.3f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.4f
	},
	/* [2] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 0.8f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.3f
			},
			/* [1] = */ {
				/* [0] = */ 0.6f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.2f
			},
			/* [2] = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.2f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.4f
	},
	/* [3] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 1.3f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.5f
			},
			/* [1] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.35f
			},
			/* [2] = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.2f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.4f
	},
	/* [4] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 1.3f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.5f
			},
			/* [1] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.35f
			},
			/* [2] = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.2f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.4f
	},
	/* [5] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 1.3f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.5f
			},
			/* [1] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.35f
			},
			/* [2] = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.2f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.4f
	},
	/* [6] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 1.3f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.5f
			},
			/* [1] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.35f
			},
			/* [2] = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.2f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.4f
	},
	/* [7] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 1.3f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.5f
			},
			/* [1] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.35f
			},
			/* [2] = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.2f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.4f
	},
	/* [8] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 1.3f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.5f
			},
			/* [1] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.35f
			},
			/* [2] = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.2f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.4f
	},
	/* [9] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 1.5f,
				/* [1] = */ 1.5f,
				/* [2] = */ 1.5f
			},
			/* [1] = */ {
				/* [0] = */ 2.f,
				/* [1] = */ 2.f,
				/* [2] = */ 2.f
			},
			/* [2] = */ {
				/* [0] = */ 2.5f,
				/* [1] = */ 2.5f,
				/* [2] = */ 2.5f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 2.f
	},
	/* [10] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 0.4f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.4f
			},
			/* [1] = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.5f
			},
			/* [2] = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.7f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 1.f
	},
	/* [11] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 2.5f,
				/* [1] = */ 2.5f,
				/* [2] = */ 2.5f
			},
			/* [1] = */ {
				/* [0] = */ 2.5f,
				/* [1] = */ 2.5f,
				/* [2] = */ 2.5f
			},
			/* [2] = */ {
				/* [0] = */ 2.5f,
				/* [1] = */ 2.5f,
				/* [2] = */ 2.5f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 5.f,
		/* .obDamage = */ 5.f
	},
	/* [12] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.5f
			},
			/* [1] = */ {
				/* [0] = */ 0.4f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.4f
			},
			/* [2] = */ {
				/* [0] = */ 0.3f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.3f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.03f
	},
	/* [13] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* [1] = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* [2] = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .backgroundDamage = */ 0.1f,
		/* .glassDamage = */ 0.1f,
		/* .obDamage = */ 0.1f
	},
	/* [14] = */ {
		/* .characterDamageStory = */ {
			/* [0] = */ {
				/* [0] = */ 1.3f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.5f
			},
			/* [1] = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.35f
			},
			/* [2] = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.4f,
				/* [2] = */ 0.2f
			}
		},
		/* .characterDamageArcade = */ {
			/* [0] = */ 0.3f,
			/* [1] = */ 0.2f,
			/* [2] = */ 0.1f
		},
		/* .backgroundDamage = */ 0.4f,
		/* .glassDamage = */ 0.4f,
		/* .obDamage = */ 0.4f
	}
};

static float handicapmods[7] = {
	/* [0] = */ 0.161505535f,
	/* [1] = */ 0.401877493f,
	/* [2] = */ 0.833333313f,
	/* [3] = */ 1.f,
	/* [4] = */ 1.2f,
	/* [5] = */ 2.48832035f,
	/* [6] = */ 6.19173861f
};

static void propStoryDamage(prop *target, prop *attacker, float amount, int bullettype, float *bulletnorm) {
	chrdata *targetchr;
	float saved;
}

static void propArcadeDamage(prop *target, prop *attacker, float amount, int bullettype, float *bulletnorm) {
	chrdata *targetchr;
	float saved;
}

static void propPlayerDamageDualShock(player *play, int bullettype, float originalAmount) {}

static void propChrDamageSfx(int bullettype, prop *target, prop *attacker, float *hitpos, int deathflag) {
	chrdata *targetchr;
	chrsoundgroup *sg;
	int numsounds;
	chrsoundgroup *sg;
	int numsounds;
}

static void propChrDamageHandleHitStats(chrdata *targetchr, chrdata *attackerdata, bullet *b, int bullettype) {}

void propKillChrNoBullet(prop *target) {
	chrdata *targetchr;
}

void propKillChr(prop *target, prop *attacker, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed, int parthit, int deathflag) {
	chrdata *targetchr;
	chrdata *attackerchr;
}

static int propGetChrDamagePartGroup(int bodypart) {}

static int propChrDamageBodyPart(prop *target, prop *attacker, int bullettype, float *bulletnorm, float bulletspeed, int *animreacthit) {
	chrdata *targetchr;
	chrdata *attackerdata;
	int parthit;
	int bodypart;
	prop *limbprop;
	static float bd[3] = {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	};
}

static boolean propDamageIsInvincible(prop *target, prop *attacker, int deathflag) {
	chrdata *targetchr;
	chrdata *attackerdata;
}

static void propPlayerDamage(player *player, float damage, int bullettype, float *bulletnorm) {}

static void propChrDamage(prop *target, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed, bullet *b, int deathflag) {
	int parthit;
	int animreacthit;
	player *targetplay;
	chrdata *targetchr;
	chrdata *attackerdata;
}

float propGetChrDamageAmountFromType(prop *target, int damageType, int bullettype) {
	float amount;
	int partgroup;
}

void propDamageType(prop *target, prop *attacker, int damageType, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed, bullet *b, int deathflag) {
	float amount;
}

void propDamageAmount(prop *target, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed, bullet *b, int deathflag) {}

void propExplosionDamage(prop *hitprop, prop *bulletowner, int bullettype, float *pos, float time, float explosionDamageFactor, float explosionDamageDist) {
	float DamageScale;
	int i;
	int j;
	int TotalFramesPassed;
	int deathflag;
	int rooms[21];
	int numrooms;
	float bb[2][3];
	prop *p;
	float Dist;
	float Dir[3];
	float StartPos[3];
	boolean DoTest;
	chrdata *cd;
	float explosionDamageDistAdj;
	float explosionDamageDistAdjSq;
	float distDamageRatio;
	float Damage;
	float explosiondir[3];
	float rDist;
}

float propDamageGetBackgroundDamage(int damageType) {
	float damage;
}

float propDamageGetGlassDamage(int damageType) {
	float damage;
}

float propDamageGetObDamage(int damageType) {
	float damage;
}

float damageGetPlayerMaxHealth() {}

float damageGetEnemyMaxHealth() {}

float damageGetPlayerMaxArmour() {}

float damageGetEnemyMaxArmour() {}
