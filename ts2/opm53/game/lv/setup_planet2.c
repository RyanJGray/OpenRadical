// STATUS: NOT STARTED

#include "setup_planet2.h"

setupprop planet2_props[0] = {
};

setuppickup planet2_pickups_1up[0] = {
};

setupspawn planet2_spawns_1up[0] = {
};

setupNPC planet2_NPCs_1up[0];

static int ww_patrol0_1up[0] = {
};

setupPatrolRoutes planet2_patrolroutes_1up[0] = {
};

aihandler planet2_AIHandlers_1up[0] = {
};

setupNPC planet2_spawninfos_1up[0];

setupdoor planet2_doors_1up[0] = {
};

setupheader setup_planet2_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 6,
	/* .props = */ planet2_props,
	/* .numprops = */ 0,
	/* .pickups = */ planet2_props,
	/* .numpickups = */ 1,
	/* .doors = */ planet2_spawninfos_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ planet2_spawns_1up,
	/* .numspawnpads = */ 1,
	/* .NPCsetup = */ planet2_NPCs_1up,
	/* .numNPCs = */ 1,
	/* .setupPatrolRoutes = */ planet2_patrolroutes_1up,
	/* .numPatrolroutes = */ 1,
	/* .AIEventHandlers = */ planet2_AIHandlers_1up,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ planet2_spawninfos_1up,
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

setuppickup planet2_pickups_arcade[0] = {
};

setupspawn planet2_spawns_arcade[0] = {
};

setupheader setup_planet2_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 12,
	/* .props = */ planet2_props,
	/* .numprops = */ 0,
	/* .pickups = */ planet2_pickups_arcade,
	/* .numpickups = */ 0,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ planet2_pickups_arcade,
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
