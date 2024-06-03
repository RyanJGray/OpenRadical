// STATUS: NOT STARTED

#include "setup_neotokyo.h"

weatherdata neotokyo_weather[0] = {
};

carpath neotokyo_train_route[0] = {
};

setupcar neotokyo_cars[0] = {
};

setupprop neotokyo_props[0] = {
};

setuppickup neotokyo_pickups_1up[0] = {
};

setupspawn neotokyo_spawns_1up[0] = {
};

setupNPC neotokyo_NPCs_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupPatrolRoutes neotokyo_patrolroutes_1up[0] = {
};

aihandler neotokyo_AIHandlers_1up[0] = {
};

setupNPC neotokyo_spawninfos_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupdoor neotokyo_doors_1up[0] = {
};

setupheader setup_neotokyo_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 6,
	/* .props = */ neotokyo_props,
	/* .numprops = */ 5,
	/* .pickups = */ neotokyo_pickups_1up,
	/* .numpickups = */ 1,
	/* .doors = */ &setup_neotokyo_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ neotokyo_spawns_1up,
	/* .numspawnpads = */ 1,
	/* .NPCsetup = */ neotokyo_NPCs_1up,
	/* .numNPCs = */ 9,
	/* .setupPatrolRoutes = */ neotokyo_AIHandlers_1up,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ neotokyo_AIHandlers_1up,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ &setup_neotokyo_1up,
	/* .numNPCspawns = */ 0,
	/* .cars = */ neotokyo_cars,
	/* .numcars = */ 1,
	/* .sr = */ NULL,
	/* .numremotes = */ 0,
	/* .specialfx = */ NULL,
	/* .numspecialfx = */ 0,
	/* .weatherdat = */ neotokyo_weather,
	/* .numweatherdata = */ 1,
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

setuppickup neotokyo_pickups_arcade[0] = {
};

setupspawn neotokyo_spawns_arcade[0] = {
};

setupheader setup_neotokyo_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 9,
	/* .props = */ neotokyo_props,
	/* .numprops = */ 5,
	/* .pickups = */ neotokyo_pickups_arcade,
	/* .numpickups = */ 5,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ neotokyo_spawns_arcade,
	/* .numspawnpads = */ 2,
	/* .NPCsetup = */ NULL,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ NULL,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ NULL,
	/* .numAIEventHandlers = */ 0,
	/* .si = */ NULL,
	/* .numNPCspawns = */ 0,
	/* .cars = */ neotokyo_cars,
	/* .numcars = */ 1,
	/* .sr = */ NULL,
	/* .numremotes = */ 0,
	/* .specialfx = */ NULL,
	/* .numspecialfx = */ 0,
	/* .weatherdat = */ neotokyo_weather,
	/* .numweatherdata = */ 1,
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
