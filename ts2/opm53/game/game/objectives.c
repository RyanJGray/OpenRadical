// STATUS: NOT STARTED

#include "objectives.h"

// warning: multiple differing types with the same name (#42,  not equal)
enum {
	OBJECTIVE_DAM_DESTROY_RADAR = 0,
	OBJECTIVE_DAM_REACH_SITE = 1,
	OBJECTIVE_DAM_DESTROY_CONTAINER = 2,
	OBJECTIVE_DAM_ACTIVATE_TURBINES = 3,
	OBJECTIVE_DAM_REACH_TOP = 4,
	OBJECTIVE_DAM_DESTROY_COPTER = 5,
	OBJECTIVE_DAM_DESTROY_CABINETS = 6,
	OBJECTIVE_DAM_KILL_MUTANTS = 7,
	OBJECTIVE_RFACTORY_ACTIVATE_BRIDGE = 8,
	OBJECTIVE_RFACTORY_FIND_ELECTROGUN = 9,
	OBJECTIVE_RFACTORY_DESTROY_POWERTOWERS = 10,
	OBJECTIVE_TOTAL = 11
};

static objective objectivesInfo[11] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

static checkrect dam_tunnelSteamRect = {
	/* .min = */ {
		/* [0] = */ 80.f,
		/* [1] = */ 28.f,
		/* [2] = */ 35.2f
	},
	/* .max = */ {
		/* [0] = */ 83.f,
		/* [1] = */ 28.4f,
		/* [2] = */ 39.5f
	}
};

static checkrect dam_staircaseSteamRect = {
	/* .min = */ {
		/* [0] = */ 14.5f,
		/* [1] = */ 4.f,
		/* [2] = */ 27.5f
	},
	/* .max = */ {
		/* [0] = */ 15.5f,
		/* [1] = */ 4.4f,
		/* [2] = */ 31.f
	}
};

static CamDef steamCam = {
	/* .Type = */ 3,
	/* .Min = */ {
		/* [0] = */ 74.38f,
		/* [1] = */ 32.05f,
		/* [2] = */ 37.15f
	},
	/* .Max = */ {
		/* [0] = */ 75.25f,
		/* [1] = */ 31.5f,
		/* [2] = */ 37.3f
	},
	/* .Offset = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	}
};

static CamDef liftCam = {
	/* .Type = */ 3,
	/* .Min = */ {
		/* [0] = */ 80.2f,
		/* [1] = */ 0.2f,
		/* [2] = */ 25.8f
	},
	/* .Max = */ {
		/* [0] = */ 79.4f,
		/* [1] = */ -1.f,
		/* [2] = */ 30.9f
	},
	/* .Offset = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	}
};

static CamDef laserCam = {
	/* .Type = */ 3,
	/* .Min = */ {
		/* [0] = */ 95.6f,
		/* [1] = */ -10.2f,
		/* [2] = */ 15.4f
	},
	/* .Max = */ {
		/* [0] = */ 95.9f,
		/* [1] = */ -12.f,
		/* [2] = */ 30.49f
	},
	/* .Offset = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	}
};

static CamDef siteCam = {
	/* .Type = */ 3,
	/* .Min = */ {
		/* [0] = */ 93.7f,
		/* [1] = */ -16.23f,
		/* [2] = */ -8.45f
	},
	/* .Max = */ {
		/* [0] = */ 103.4f,
		/* [1] = */ -18.f,
		/* [2] = */ -6.92f
	},
	/* .Offset = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	}
};

int numCurrentObjectives = 0;

int numObjectives[3] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0
};

int currentObjectives[10] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0,
	/* [6] = */ 0,
	/* [7] = */ 0,
	/* [8] = */ 0,
	/* [9] = */ 0
};

static prop *dam_apache;
static prop *dam_radar;
static int dam_numLifts;
static prop *dam_lifts[2];
static prop *dam_cave;
static prop *dam_cage;
static prop *dam_cageSwitch;
static int dam_cageMines;
static prop *dam_computer;
static prop *dam_main_turbine;
static prop *dam_backup_turbine;
static int dam_numWheels;
static prop *dam_pipeWheels[3];
static int dam_numDials;
static prop *dam_pipeDials[3];
static boolean dam_steamCamDone;
static int dam_numSteam;
static specialfx *dam_steam[2];
static int dam_siteExplosions;
static prop *dam_laser1;
static prop *dam_laser2;
static int dam_numCabinets;
static prop *dam_cabinets[6];
static int dam_totalMutants;
static int dam_numMutantsRemain;
static boolean dam_siteMinesDeployed;

u8* objectivesGetBriefing() {}

u8* objectivesGetText(objective *obj) {}

u8* objectivesGetSubtitle(int type) {}

void objectivesGetCounters(objective *obj, int *c1, int *c2) {}

boolean objectivesIsChrInCheckpoint(int chrid, checkpoint *point) {
	chrdata *cd;
	prop *cdprop;
	float diff[3];
	float total;
}

boolean objectivesIsPosInCheckpoint(float *pos, checkpoint *point) {
	float diff[3];
	float total;
}

boolean objectivesIsChrInCheckrect(int chrid, checkrect *rect) {
	chrdata *cd;
	prop *cdprop;
}

int objectivesGetType(int id) {}

boolean objectiveIsComplete(int id) {
	objective *obj;
}

void objectivesTellHud(objective *obj) {
	int pl;
	player *ply;
}

void objectiveComplete(int id) {
	objective *obj;
}

void objectiveSetUnRevealed(int id) {
	objective *obj;
}

void objectiveReveal(int id) {
	objective *obj;
}

void objectiveFail(int id) {
	objective *obj;
}

void objectivesAdd(int id) {
	int type;
	objective *obj;
}

int objectivesGetNum() {}

int objectivesGetNumOfType(int type) {}

int objectivesGetNumMain() {}

int objectivesGetNumSecondary() {}

int objectivesGetNumBonus() {}

objective* objectivesGetUsingType(int index, int type) {
	int o;
	int count;
}

objective* objectivesGetMain(int index) {}

objective* objectivesGetSecondary(int index) {}

objective* objectivesGetBonus(int index) {}

void objectivesReset() {}

void objectivesRestart() {
	level_info *info;
	int type;
	int id;
}

void objectivesTick() {
	level_info *info;
	boolean alive;
	int i;
	int o;
	boolean complete;
	objective *obj;
	int i;
}

void objectivesProcessDeath(prop *p) {}

void objectivesProcessLift(prop *p) {}

void objectivesMineExplosion(bullet *b) {}

void damObjectivesSetup() {}

void damObjectivesApache(prop *p) {}

static void damObjectivesLift(prop *p) {}

void damObjectivesSteam(specialfx *spfx) {}

void damObjectivesRadar(prop *p) {}

void damObjectivesCave(prop *p) {}

void damObjectivesCage(prop *p) {}

void damObjectivesCageSwitch(prop *p) {}

void damObjectivesLaser1(prop *p) {}

void damObjectivesLaser2(prop *p) {}

static void damMineExplosion(bullet *b) {}

void damObjectivesPipeWheel(prop *p) {}

void damObjectivesPipeDial(prop *p) {}

void damObjectivesMainTurbine(prop *p) {
	specialdata *data;
}

void damObjectivesBackupTurbine(prop *p) {
	specialdata *data;
}

void damObjectivesFileCabinetDestroyed(prop *p, prop *actor) {
	int i;
	int remaining;
}

void damObjectivesCabinet(prop *p) {}

void damObjectivesSetLiftView() {}

void damObjectivesSetLaserView() {}

void damObjectivesLaserPowerOn() {}

void damObjectivesSetSiteView() {}

void damObjectivesSitePowerOn() {}

void damObjectivesCageSwitchActivate(lvbuttondata *bd) {}

void damObjectivesPowerOn() {}

void damObjectivesRevealSite() {}

void damObjectivesComputerActivate(prop *p, prop *actor) {
	chrdata *cd;
}

void damObjectivesComputerTurbinesDestroyed(prop *notused1, prop *notused2) {}

void damObjectivesComputer(prop *p) {}

static void damObjectivesProcessDeath(prop *p) {
	chrdata *cd;
}

void damObjectivesRevealCopter() {}

void damObjectivesRevealPower() {}

static int damObjectivesGetTotalCabinets() {}

static int damObjectivesGetNumCabinetsDestroyed() {
	int count;
	int c;
}

static int damObjectivesGetTotalMutants() {}

static int damObjectivesGetMutantsDestroyed() {}

void damObjectivesRevealPressure(prop *actor) {
	int numWheelsOff;
	int e;
	int pressure;
}

void damObjectivesTick() {
	int pl;
	int remotes;
	int proximity;
	int timed;
	int numWheelsOff;
	int e;
	player *ply;
	chrdata *cd;
	int padnum;
}
