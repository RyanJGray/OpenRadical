// STATUS: NOT STARTED

#include "setup_rfactory.h"

setupprop rfactory_props[0] = {
};

setuppropspawn rfactory_propsspawns[0] = {
};

setuppickup rfactory_pickups_1up[0] = {
};

setupspawn rfactory_spawns_1up[0] = {
};

setupNPC rfactory_NPCs_1up[0];

static int rfactory_patrol0_1up[0] = {
};

static int rfactory_patrol1_1up[0] = {
};

static int rfactory_patrol2_1up[0] = {
};

static int rfactory_patrol3_1up[0] = {
};

static int rfactory_patrol4_1up[0] = {
};

static int rfactory_patrol5_1up[0] = {
};

static int rfactory_patrol6_1up[0] = {
};

static int rfactory_patrol7_1up[0] = {
};

static int rfactory_patrol8_1up[0] = {
};

setupPatrolRoutes rfactory_patrolroutes_1up[0] = {
};

aihandler rfactory_AIHandlers_1up[0] = {
};

setupNPC rfactory_spawninfos_1up[0];

setupdoor rfactory_doors[0] = {
};

laserBeam rfactory_beams_test[0] = {
};

laserBeamInfo rfactory_beamInfo_test = {
	/* .wallmin = */ {
		/* [0] = */ -117.f,
		/* [1] = */ 0.3f,
		/* [2] = */ 104.5f
	},
	/* .wallmax = */ {
		/* [0] = */ -117.f,
		/* [1] = */ 2.8f,
		/* [2] = */ 108.6f
	},
	/* .starttime = */ 0.f,
	/* .activate = */ &laserBeamTestActivated,
	/* .beams = */ rfactory_beams_test,
	/* .numBeams = */ 6
};

laserBeam rfactory_beams_pipeGrid1[0] = {
};

laserBeamInfo rfactory_beamInfo_pipeGrid1 = {
	/* .wallmin = */ {
		/* [0] = */ -128.982f,
		/* [1] = */ 0.218f,
		/* [2] = */ 91.65f
	},
	/* .wallmax = */ {
		/* [0] = */ -119.915f,
		/* [1] = */ 1.106f,
		/* [2] = */ 91.65f
	},
	/* .starttime = */ 0.f,
	/* .activate = */ &laserBeamTestActivated,
	/* .beams = */ rfactory_beams_pipeGrid1,
	/* .numBeams = */ 3
};

laserBeam rfactory_beams_pipeGrid2[0] = {
};

laserBeamInfo rfactory_beamInfo_pipeGrid2 = {
	/* .wallmin = */ {
		/* [0] = */ -115.6f,
		/* [1] = */ 0.218f,
		/* [2] = */ 91.65f
	},
	/* .wallmax = */ {
		/* [0] = */ -100.572f,
		/* [1] = */ 1.106f,
		/* [2] = */ 91.65f
	},
	/* .starttime = */ 1.4f,
	/* .activate = */ &laserBeamTestActivated,
	/* .beams = */ rfactory_beams_pipeGrid2,
	/* .numBeams = */ 3
};

laserBeam rfactory_beams_pipeGrid3[0] = {
};

laserBeamInfo rfactory_beamInfo_pipeGrid3 = {
	/* .wallmin = */ {
		/* [0] = */ -96.095f,
		/* [1] = */ 0.218f,
		/* [2] = */ 91.65f
	},
	/* .wallmax = */ {
		/* [0] = */ -87.029f,
		/* [1] = */ 1.106f,
		/* [2] = */ 91.65f
	},
	/* .starttime = */ 0.6f,
	/* .activate = */ &laserBeamTestActivated,
	/* .beams = */ rfactory_beams_pipeGrid3,
	/* .numBeams = */ 3
};

setupspecialfx rfactory_fx[0] = {
};

setupremote rfactory_remotes_1up[0] = {
};

setupalarm rfactory_alarms_1up[0] = {
};

setupbutton rfactory_buttons_1up[0] = {
};

setupheader setup_rfactory_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 8,
	/* .props = */ rfactory_props,
	/* .numprops = */ 50,
	/* .pickups = */ rfactory_pickups_1up,
	/* .numpickups = */ 5,
	/* .doors = */ rfactory_spawninfos_1up,
	/* .numdoors = */ 14,
	/* .spawnpads = */ rfactory_spawns_1up,
	/* .numspawnpads = */ 3,
	/* .NPCsetup = */ rfactory_NPCs_1up,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ rfactory_patrolroutes_1up,
	/* .numPatrolroutes = */ 9,
	/* .AIEventHandlers = */ rfactory_AIHandlers_1up,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ rfactory_spawninfos_1up,
	/* .numNPCspawns = */ 0,
	/* .cars = */ NULL,
	/* .numcars = */ 0,
	/* .sr = */ rfactory_remotes_1up,
	/* .numremotes = */ 25,
	/* .specialfx = */ rfactory_fx,
	/* .numspecialfx = */ 4,
	/* .weatherdat = */ NULL,
	/* .numweatherdata = */ 0,
	/* .lsphases = */ NULL,
	/* .numlsphases = */ 0,
	/* .lssnipergrps = */ NULL,
	/* .numlssnipergrps = */ 0,
	/* .alarms = */ rfactory_alarms_1up,
	/* .numalarms = */ 3,
	/* .lifts = */ NULL,
	/* .numlifts = */ 0,
	/* .lvbuttons = */ rfactory_buttons_1up,
	/* .numlvbuttons = */ 0,
	/* .lvcameradata = */ NULL,
	/* .numcamera = */ 0,
	/* .lvpropspawn = */ rfactory_propsspawns,
	/* .numpropspawns = */ 4
};

setuppickup rfactory_pickups_arcade[0] = {
};

setupspawn rfactory_spawns_arcade[0] = {
};

setupdoor rfactory_doors_arcade[0] = {
};

setupheader setup_rfactory_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 9,
	/* .props = */ rfactory_props,
	/* .numprops = */ 50,
	/* .pickups = */ rfactory_pickups_arcade,
	/* .numpickups = */ 9,
	/* .doors = */ rfactory_spawninfos_1up,
	/* .numdoors = */ 14,
	/* .spawnpads = */ rfactory_spawns_arcade,
	/* .numspawnpads = */ 11,
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
	/* .specialfx = */ rfactory_fx,
	/* .numspecialfx = */ 4,
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

void laserBeamTestActivated(specialfx *spfx, prop *actor) {}
