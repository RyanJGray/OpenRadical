// STATUS: NOT STARTED

#include "gun.h"

ammoInfo_t ammoInfo[17] = {
	/* [0] = */ {
		/* .maxAmmo = */ 0,
		/* .filename = */ NULL,
		/* .name = */ 0,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [1] = */ {
		/* .maxAmmo = */ 500,
		/* .filename = */ 0x450130,
		/* .name = */ 867,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [2] = */ {
		/* .maxAmmo = */ 200,
		/* .filename = */ 0x450108,
		/* .name = */ 868,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [3] = */ {
		/* .maxAmmo = */ 100,
		/* .filename = */ 0x4500e0,
		/* .name = */ 869,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [4] = */ {
		/* .maxAmmo = */ 200,
		/* .filename = */ 0x4500b8,
		/* .name = */ 870,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [5] = */ {
		/* .maxAmmo = */ 30,
		/* .filename = */ 0x450090,
		/* .name = */ 871,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [6] = */ {
		/* .maxAmmo = */ 20,
		/* .filename = */ 0x450068,
		/* .name = */ 872,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [7] = */ {
		/* .maxAmmo = */ 20,
		/* .filename = */ 0x450040,
		/* .name = */ 873,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [8] = */ {
		/* .maxAmmo = */ 20,
		/* .filename = */ 0x450018,
		/* .name = */ 874,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [9] = */ {
		/* .maxAmmo = */ 10,
		/* .filename = */ 0x44fff0,
		/* .name = */ 875,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [10] = */ {
		/* .maxAmmo = */ 10,
		/* .filename = */ 0x44ffc8,
		/* .name = */ 876,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [11] = */ {
		/* .maxAmmo = */ 20,
		/* .filename = */ 0x44ffa0,
		/* .name = */ 877,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [12] = */ {
		/* .maxAmmo = */ 30,
		/* .filename = */ NULL,
		/* .name = */ 878,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [13] = */ {
		/* .maxAmmo = */ 100,
		/* .filename = */ NULL,
		/* .name = */ 879,
		/* .hudBar = */ 0,
		/* .barBgCol = */ 0,
		/* .barFgCol = */ 0
	},
	/* [14] = */ {
		/* .maxAmmo = */ 3000,
		/* .filename = */ NULL,
		/* .name = */ 880,
		/* .hudBar = */ 1,
		/* .barBgCol = */ 15410,
		/* .barFgCol = */ 19839
	},
	/* [15] = */ {
		/* .maxAmmo = */ 3000,
		/* .filename = */ NULL,
		/* .name = */ 881,
		/* .hudBar = */ 1,
		/* .barBgCol = */ 5170,
		/* .barFgCol = */ 5247
	},
	/* [16] = */ {
		/* .maxAmmo = */ 1500,
		/* .filename = */ NULL,
		/* .name = */ 882,
		/* .hudBar = */ 1,
		/* .barBgCol = */ 15410,
		/* .barFgCol = */ 19839
	}
};

gunInfo_t gunInfo[0] = {
};

short int fixedgunname = 826;

guncombo guncombos[40] = {
	/* [0] = */ {
		/* .priority = */ 40,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ -1
		},
		/* .name = */ 1255
	},
	/* [1] = */ {
		/* .priority = */ 33,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 0
		},
		/* .name = */ 828
	},
	/* [2] = */ {
		/* .priority = */ 32,
		/* .gunType = */ {
			/* [0] = */ 0,
			/* [1] = */ 0
		},
		/* .name = */ 829
	},
	/* [3] = */ {
		/* .priority = */ 31,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 1
		},
		/* .name = */ 830
	},
	/* [4] = */ {
		/* .priority = */ 30,
		/* .gunType = */ {
			/* [0] = */ 1,
			/* [1] = */ 1
		},
		/* .name = */ 831
	},
	/* [5] = */ {
		/* .priority = */ 35,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 2
		},
		/* .name = */ 832
	},
	/* [6] = */ {
		/* .priority = */ 34,
		/* .gunType = */ {
			/* [0] = */ 2,
			/* [1] = */ 2
		},
		/* .name = */ 833
	},
	/* [7] = */ {
		/* .priority = */ 18,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 3
		},
		/* .name = */ 834
	},
	/* [8] = */ {
		/* .priority = */ 19,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 4
		},
		/* .name = */ 857
	},
	/* [9] = */ {
		/* .priority = */ 36,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 5
		},
		/* .name = */ 835
	},
	/* [10] = */ {
		/* .priority = */ 13,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 6
		},
		/* .name = */ 836
	},
	/* [11] = */ {
		/* .priority = */ 38,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 7
		},
		/* .name = */ 837
	},
	/* [12] = */ {
		/* .priority = */ 17,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 8
		},
		/* .name = */ 838
	},
	/* [13] = */ {
		/* .priority = */ 16,
		/* .gunType = */ {
			/* [0] = */ 8,
			/* [1] = */ 8
		},
		/* .name = */ 839
	},
	/* [14] = */ {
		/* .priority = */ 8,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 9
		},
		/* .name = */ 840
	},
	/* [15] = */ {
		/* .priority = */ 12,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 10
		},
		/* .name = */ 841
	},
	/* [16] = */ {
		/* .priority = */ 2,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 11
		},
		/* .name = */ 842
	},
	/* [17] = */ {
		/* .priority = */ 1,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 12
		},
		/* .name = */ 843
	},
	/* [18] = */ {
		/* .priority = */ 7,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 13
		},
		/* .name = */ 844
	},
	/* [19] = */ {
		/* .priority = */ 11,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 14
		},
		/* .name = */ 845
	},
	/* [20] = */ {
		/* .priority = */ 10,
		/* .gunType = */ {
			/* [0] = */ 14,
			/* [1] = */ 14
		},
		/* .name = */ 846
	},
	/* [21] = */ {
		/* .priority = */ 6,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 15
		},
		/* .name = */ 847
	},
	/* [22] = */ {
		/* .priority = */ 5,
		/* .gunType = */ {
			/* [0] = */ 15,
			/* [1] = */ 15
		},
		/* .name = */ 848
	},
	/* [23] = */ {
		/* .priority = */ 4,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 16
		},
		/* .name = */ 849
	},
	/* [24] = */ {
		/* .priority = */ 39,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 18
		},
		/* .name = */ 851
	},
	/* [25] = */ {
		/* .priority = */ 39,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 19
		},
		/* .name = */ 852
	},
	/* [26] = */ {
		/* .priority = */ 39,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 20
		},
		/* .name = */ 853
	},
	/* [27] = */ {
		/* .priority = */ 38,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 21
		},
		/* .name = */ 854
	},
	/* [28] = */ {
		/* .priority = */ 28,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 22
		},
		/* .name = */ 855
	},
	/* [29] = */ {
		/* .priority = */ 27,
		/* .gunType = */ {
			/* [0] = */ 22,
			/* [1] = */ 22
		},
		/* .name = */ 856
	},
	/* [30] = */ {
		/* .priority = */ 26,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 23
		},
		/* .name = */ 858
	},
	/* [31] = */ {
		/* .priority = */ 25,
		/* .gunType = */ {
			/* [0] = */ 23,
			/* [1] = */ 23
		},
		/* .name = */ 859
	},
	/* [32] = */ {
		/* .priority = */ 37,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 24
		},
		/* .name = */ 860
	},
	/* [33] = */ {
		/* .priority = */ 24,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 25
		},
		/* .name = */ 862
	},
	/* [34] = */ {
		/* .priority = */ 23,
		/* .gunType = */ {
			/* [0] = */ 25,
			/* [1] = */ 25
		},
		/* .name = */ 863
	},
	/* [35] = */ {
		/* .priority = */ 21,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 26
		},
		/* .name = */ 864
	},
	/* [36] = */ {
		/* .priority = */ 20,
		/* .gunType = */ {
			/* [0] = */ 26,
			/* [1] = */ 26
		},
		/* .name = */ 865
	},
	/* [37] = */ {
		/* .priority = */ 38,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 27
		},
		/* .name = */ 866
	},
	/* [38] = */ {
		/* .priority = */ 1,
		/* .gunType = */ {
			/* [0] = */ -1,
			/* [1] = */ 32
		},
		/* .name = */ 827
	},
	/* [39] = */ {
		/* .priority = */ 1,
		/* .gunType = */ {
			/* [0] = */ 32,
			/* [1] = */ 32
		},
		/* .name = */ 827
	}
};

int gunsinventory[40] = {
	/* [0] = */ 0,
	/* [1] = */ 1,
	/* [2] = */ 2,
	/* [3] = */ 5,
	/* [4] = */ 6,
	/* [5] = */ 3,
	/* [6] = */ 4,
	/* [7] = */ 32,
	/* [8] = */ 28,
	/* [9] = */ 29,
	/* [10] = */ 35,
	/* [11] = */ 36,
	/* [12] = */ 8,
	/* [13] = */ 30,
	/* [14] = */ 31,
	/* [15] = */ 12,
	/* [16] = */ 13,
	/* [17] = */ 7,
	/* [18] = */ 9,
	/* [19] = */ 10,
	/* [20] = */ 11,
	/* [21] = */ 15,
	/* [22] = */ 18,
	/* [23] = */ 14,
	/* [24] = */ 19,
	/* [25] = */ 20,
	/* [26] = */ 21,
	/* [27] = */ 22,
	/* [28] = */ 33,
	/* [29] = */ 34,
	/* [30] = */ 23,
	/* [31] = */ 16,
	/* [32] = */ 17,
	/* [33] = */ 24,
	/* [34] = */ 25,
	/* [35] = */ 26,
	/* [36] = */ 27,
	/* [37] = */ 37,
	/* [38] = */ 38,
	/* [39] = */ 39
};

static int df = 0;
static int offscreenshots = 0;
static int propershots = 0;

void gunSetAmmoToMax(chrdata *cd, int gunComboIndex) {
	int hand;
	int gunType;
	int ammoType;
	int ammoTypeSecondary;
}

static void gunPreloadGunCombo(int gunComboIndex) {
	guncombo *gc;
	int hand;
	gunInfo_t *gi;
}

void gunPreload() {
	gunset *lvgunset;
	int i;
}

void gunRestart() {}

void gunReset() {}

void gunAddAmmo(chrdata *cd, int ammoType, int ammo) {
	int gunAmmo;
	int totalAmmo;
}

int gunGetGunAmmo(chrdata *cd, int ammoType) {
	int totalAmmo;
	int hand;
	chrgun *cgun;
	gunInfo_t *gi;
}

boolean gunShouldSwitchTo(chrdata *cd, int desiredGunCombo) {
	int hand;
	int totalAmmo[2];
	int curAmmo[2];
	int curAmmoType[2];
	int curAmmoSecondary[2];
	int curAmmoTypeSecondary[2];
	chrgun *cgun;
	gunInfo_t *gi;
	gunInfo_t *gi;
}

void gunPickedUpAmmo(chrdata *cd, int ammoType, int oldAmmo) {
	player *pd;
	int i;
	int sametype;
	int ammoleft;
	int ammoright;
	gunInfo_t *gi;
	gunInfo_t *gi;
}

boolean gunShouldSwitchToOnPickup(chrdata *cd, int guncombo) {
	player *pd;
	int gunoption;
}

boolean gunShouldKeepWithNoAmmo(chrdata *cd, int guncombo) {
	int e;
}

boolean gunCanDetonateMines(chrdata *cd) {
	int e;
}

boolean gunHandAble(chrdata *cd, int hand) {}

boolean gunHandActive(chrdata *cd, int hand) {}

boolean gunBothHandsActive(chrdata *cd) {}

boolean gunIsPunching(chrdata *cd) {
	player *pd;
}

boolean gunDoesAutoAim(chrdata *cd) {
	int gunComboIndex;
}

static int gunGetNextCombo(chrdata *cd) {
	int i;
	int g;
	int mincombo;
}

static int gunGetMostPowerfulCombo(chrdata *cd) {
	int i;
	int priority;
	int suitable;
}

static int gunGetPreviousCombo(chrdata *cd) {
	int i;
	int g;
	int mincombo;
}

void gunChangeToComboWithAmmo(chrdata *chrdat) {
	int guntype;
	gunInfo_s *gi;
}

boolean gunIsLeftGunVisible(playergun *plgun, chrgun *cgun) {
	chrdata *cd;
}

boolean gunHasChrAmmoForFire(chrdata *cd, chrgun *cgun, int fireMode, int repeatMode) {
	gunInfo_t *gi;
	fireInfo_t *fi;
	int ammoType;
	int totalAmmo;
	int shotAmmo;
}

boolean gunHasChrAmmoForAnyFire(chrdata *cd, chrgun *cgun, int repeatMode) {}

static int gunReloadCore(chrdata *chrdat, chrgun *cgun) {
	gunInfo_t *gi;
	int totalreloadammo;
	int reloadammo;
	int reloadammo;
}

static void gunReload(chrdata *chrdat, chrgun *cgun, playergun *plgun, int reloadMode, int hand) {
	gunInfo_t *gi;
	int ammoType;
	int ammoTypeSecondary;
	int reloadAmount;
	int othergunhasnoammoleft;
}

static void gunFireSfx(chrgun *gun, int firemode, float *origin, int repeatMode) {
	fireInfo_t *fi;
	int firesoundnum;
	int cartridgesoundnum;
	float repeatFireSoundTime;
	int voice;
}

void gunFireCartridges(playergun *plgun, chrgun *cgun, gunInfo_t *gi, fireInfo_t *fi) {
	mtx_u tmpmtx;
	mtx_u finalmtx;
	prop *pg;
	float *dof;
	float pos[3];
	float projectedPos[3];
	chrdata *cd;
	boolean DoFirstPerson;
	boolean DoThirdPerson;
	prop *p;
	obdef *ob;
	partdef *parts;
	prop *p;
	int dofID;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	int dofID;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	int dofID;
	obinst *inst;
	obdef *ob;
	partdef *parts;
}

void gunCalculateTPShootPos(chrgun *cgun, int fireMode) {
	mtx_u tmpmtx;
	mtx_u thirdpmtx;
	gunInfo_t *gi;
	float *dof;
	prop *tpgunprop;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
}

void gunCalculateFPShootPos(player *player, playergun *plgun, int fireMode) {
	float pos[3];
	mtx_u tmpmtx;
	mtx_u fpmtx;
	gunInfo_t *gi;
	prop *fpgunprop;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
}

static void gunSetMuzzleSwitchFlags(prop *gunprop, int fireMode, gunParts_t *gp) {}

void gunPlayerFireShots(playergun *plgun) {
	float dir[3];
	float noisex;
	float noisey;
	float rlen;
	gunInfo_t *gi;
	fireInfo_t *fi;
	chrdata *chrdat;
	prop *pg;
	mtx_u mat;
	float projectedPos[3];
	float rotatedRecoilVelocity[3];
	boolean DoFirstPerson;
	mtx_u mat;
	mtx_u *destmat;
	float rotang;
	int dofID;
	obdef *ob;
	partdef *parts;
	int i;
	int bullettype;
}

static void gunPlayerFire(chrgun *cgun, playergun *plgun, int fireMode, int repeatMode, int hand) {
	gunInfo_t *gi;
	chrdata *chrdat;
	fireInfo_t *fi;
	playerGunAnimationInfo_t *pgai;
	int ammotype;
	int clipCount;
	int ammo;
}

void gunDebugPrintStats() {}

void gunEnemyFire(prop *p, int hand, int fireMode, int repeatMode) {
	chrdata *cd;
	chrgun *cgun;
	gunInfo_t *gi;
	fireInfo_t *fi;
	float dir[3];
	float dir2[3];
	float rlen;
	float cpos[3];
	float dx;
	mtx_u mtx;
	mtx_u tmpmtx;
	mtx_u finalmtx;
	prop *pg;
	int i;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	int i;
	int numShots;
	float noisey;
	float noisex;
	gunInfo_t *gi;
	fireInfo_t *fi;
	int bullettype;
	int ammoType;
	int clipCount;
	int ammo;
}

void gunRemoteFire(prop *p, chrgun *gun, int fireMode, int repeatMode, int ownertype, chrdata *cd) {
	gunInfo_t *gi;
	fireInfo_t *fi;
	float dir[3];
	mtx_u tmpmtx;
	mtx_u finalmtx;
	obdef *pgun;
	partdef *parts;
	float tmpdof[3];
	float *dof;
	float shootpos[3];
	int mtxindex;
	remotedata *rd;
	int ammoType;
	prop *p;
	obdef *ob;
	partdef *parts;
	prop *p;
	obdef *ob;
	partdef *parts;
	prop *p;
	obdef *ob;
	partdef *parts;
	player *pPlayer;
	float noisex;
	float noisey;
	float rlen;
}

void gunNPCThrowGrenade(prop *p, float *dir, prop *target) {
	float dx;
	float dy;
	float dz;
	float rlen;
	chrdata *cd;
	chrgun gun;
	mtx_u mtx;
	mtx_u tmpmtx;
}

int gunGetBulletType(playergun *pGun) {}

void gunCreateBullet(prop *p, chrgun *gun, playergun *pgun, int fireMode, float *dir, int ownerType, chrdata *cd, int shellsfx) {
	gunInfo_t *gi;
	fireInfo_t *fi;
	int bullettype;
	int bulletflag;
	int repeat;
	float *fpShootPos;
}

void gunResetChrGun(chrgun *cgun) {}

void gunResetPlayerGun(playergun *plgun) {}

void gunClearPlayerGun(playergun *plgun) {}

void gunResetPlayerReload(playergun *plgun, chrgun *cgun) {
	int ammo;
	int a;
}

void gunResetPlayerChange(playergun *plgun, chrgun *cgun) {}

static void gunUpdatePlayerGunAnimation(playergun *plgun, chrgun *cgun) {
	int i;
	gunInfo_t *gi;
	fireInfo_t *fi;
	playerGunAnimationInfo_t *pgai;
	float paladjust;
	mtx_u mat;
	mtx_u *destmat;
	obdef *ob;
	partdef *parts;
	mtx_u mat;
	mtx_u *destmat;
	obdef *ob;
	partdef *parts;
	chrdata *cd;
	bullet *b;
}

static void gunUpdatePlayerShotgunReloadAnimation(playergun *plgun, chrgun *cgun) {
	mtx_u mat;
	mtx_u *destmat;
	float *dof;
	obdef *ob;
	partdef *parts;
	mtx_u mat;
	mtx_u mat2;
	prop *pg;
	float pos[3];
	float cockpos[3];
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	obinst *inst;
	obdef *ob;
	partdef *parts;
}

void gunUpdateTNTFuse(playergun *plgun, chrgun *cgun, float frac) {
	mtx_u mat;
	obdef *pgunobdef;
	float startpos[3];
	float destpos[3];
	float diff[3];
	float pos[3];
	float *dof;
	partdef *parts;
}

static void gunChrgunTick(chrgun *cgun) {}

void gunSetPlayerZoom(player *pPlayer, int GunType) {
	gunInfo_t *gi;
}

void gunDoPunch(playergun *plgun) {
	float offsetvec[3];
	static prop *pLastPropPunched[16];
	chrdata *GunCD;
	prop *pGunProp;
	chrdata *cd;
	mtx_u tmpmtx;
	mtx_u mtx;
	float Shoulder[3];
	float End[3];
	float HitPos[3];
	prop *pHitProp;
	float AnimLength;
	float AnimTime;
	float Dir[3];
	float frac;
	int NumParts;
	int i;
}

static void gunPlayerGunUpdate(playergun *plgun, int hand) {
	chrdata *cd;
	guncombo *gc;
	chrgun *cgun;
	int gcgun;
	prop *rp;
	remotedata *rd;
	gunInfo_t *gi;
	float rot;
	float oldrot;
	float zrotation;
	float sinrot;
	float sinoldrot;
	float dire;
	float sensitivity;
	float fovfrac;
	prop *pPlayerProp;
	boolean DoRemote;
	chrdata *cd;
	prop *pRemoteProp;
	chrgun *pGun;
	gunInfo_t *gi;
	int ammotype;
	int doublegunsactive;
	int rightlastshotframespassed;
	int leftlastshotframespassed;
	int otherlastshotframespassed;
	int handFiring;
	boolean leftHasAmmo;
	boolean rightHasAmmo;
	gunInfo_t *giRight;
	int ammoTypeFired;
	float lowerfrac;
	float reloadtime;
	float lowerfrac;
	float lowerfrac;
	float reloadtime;
	float lowerfrac;
	float frac;
	float frac;
	float invfrac;
	float dir;
	float dir;
	float frac;
	float frac;
	float frac;
	float invfrac;
	int ammotype;
	float frac;
	float frac;
	float burntime;
	float frac;
	float lowerfrac;
}

static void gunCreatePlayerGun(playergun *plgun, chrgun *cgun, int hand) {
	chrdata *cd;
	gunInfo_t *gi;
	int a;
}

void gunDetonateRemoteMines(chrdata *cd) {
	int e;
}

void gunEnemyUpdate(prop *p, int hand) {
	chrdata *cd;
	guncombo *gc;
	chrgun *cgun;
	int gcgun;
	gunInfo_t *gi;
	bullet *b;
}

boolean gunEnemyReload(chrdata *cd) {
	int reloadAmmo;
}

void gunPlayerTick() {
	float angx;
	float angy;
	float amplitude;
	chrdata *cd;
	int gcaxis;
	float weaponAxis;
	int nextweaponGC;
	int prevweaponGC;
}

void gunEnemyTick() {
	int i;
}

void gunPlayerGfx() {}

void gunEnd() {}

int gunGetPickupSfx(int gunComboIndex) {
	gunInfo_t *gi;
}

boolean gunIsPlayergunFiring(playergun *plgun) {}

boolean gunShouldAIAimAtFloor(int gunType, int fireMode) {
	gunInfo_t *gi;
	fireInfo_t *fi;
}

void gunGetChrFireChoices(int flags, chrdata *cd, gunChrFireChoiceTable *table) {
	int hand;
	int fireMode;
	boolean singleShotAble[2][2];
	boolean repeatShotAble[2][2];
	boolean ammoAble[2][2];
	int handOldest;
	boolean chrAmmoAble;
	chrgun *cgun;
	gunInfo_t *gi;
	int ammoType;
	int clipCount;
	fireInfo_t *fi;
	int ammo;
}

void gunReturnAmmoToChr(chrdata *cd, chrgun *cgun) {
	gunInfo_t *gi;
}

static void gunCreatePlayerGunNotLocal(playergun *plgun, chrgun *cgun, int hand) {
	chrdata *cd;
	gunInfo_t *gi;
}

static void gunPlayerFireNotLocal(chrgun *cgun, playergun *plgun, int fireMode, int repeatMode, int hand) {
	gunInfo_t *gi;
	chrdata *chrdat;
	fireInfo_t *fi;
}

static void gunPlayerGunUpdateNotLocal(playergun *plgun, int hand) {
	chrdata *cd;
	guncombo *gc;
	chrgun *cgun;
	int gcgun;
	gunInfo_t *gi;
	int doublegunsactive;
	int rightlastshotframespassed;
	int leftlastshotframespassed;
	int otherlastshotframespassed;
	int handFiring;
	float burntime;
}

void gunPlayerTickNotLocal() {
	chrdata *cd;
}

int gunGetChrLeftWristDofID(int gunType) {
	gunInfo_t *gi;
}

int gunGetChrRightWristDofID(int gunType) {
	gunInfo_t *gi;
}

int gunGetChrMuzzleDofID(int gunType, int fireMode) {
	gunInfo_t *gi;
}

int gunGetChrMuzzlePartNum(int gunType, int fireMode) {
	gunInfo_t *gi;
}

float gunGetAutoAimFovDot(int gunType) {
	gunInfo_t *gi;
}
