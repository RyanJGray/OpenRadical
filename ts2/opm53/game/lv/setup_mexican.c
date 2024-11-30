// STATUS: NOT STARTED

#include "setup_mexican.h"

setupprop mexican_props[0] = {
};

setuppickup mexican_pickups_1up[0] = {
};

setupspawn mexican_spawns_1up[0] = {
};

setupNPC mexican_NPCs_1up[0];

static int mex_patrol0_1up[0] = {
};

static int mex_patrol1_1up[0] = {
};

static int mex_patrol2_1up[0] = {
};

setupPatrolRoutes mexican_patrolroutes_1up[0] = {
};

aihandler mexican_AIHandlers_1up[0] = {
};

setupNPC mexican_spawninfos_1up[0];

setupdoor mexican_doors_1up[0] = {
};

setupheader setup_mexican_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 1,
	/* .props = */ mexican_props,
	/* .numprops = */ 0,
	/* .pickups = */ mexican_props,
	/* .numpickups = */ 1,
	/* .doors = */ mexican_spawninfos_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ mexican_spawns_1up,
	/* .numspawnpads = */ 1,
	/* .NPCsetup = */ mexican_NPCs_1up,
	/* .numNPCs = */ 11,
	/* .setupPatrolRoutes = */ mexican_patrolroutes_1up,
	/* .numPatrolroutes = */ 3,
	/* .AIEventHandlers = */ mexican_AIHandlers_1up,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ mexican_spawninfos_1up,
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

setuppickup mexican_pickups_arcade[0] = {
};

setupspawn mexican_spawns_arcade[0] = {
};

setupheader setup_mexican_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 18,
	/* .props = */ mexican_props,
	/* .numprops = */ 0,
	/* .pickups = */ mexican_pickups_arcade,
	/* .numpickups = */ 21,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ mexican_spawns_arcade,
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
