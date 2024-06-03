// STATUS: NOT STARTED

#include "setup_nightclub.h"

weatherdata nightclub_weather[0] = {
};

setupprop nightclub_props[0] = {
};

setupspecialfx nightclub_fx[0] = {
};

setuppickup nightclub_pickups_1up[0] = {
};

setupspawn nightclub_spawns_1up[0] = {
};

setupNPC nightclub_NPCs_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupPatrolRoutes nightclub_patrolroutes_1up[0] = {
};

aihandler nightclub_AIHandlers_1up[0] = {
};

setupNPC nightclub_spawninfos_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupdoor nightclub_doors_1up[0] = {
};

setupheader setup_nightclub_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 9,
	/* .props = */ nightclub_fx,
	/* .numprops = */ 0,
	/* .pickups = */ nightclub_pickups_1up,
	/* .numpickups = */ 2,
	/* .doors = */ &setup_nightclub_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ nightclub_spawns_1up,
	/* .numspawnpads = */ 1,
	/* .NPCsetup = */ nightclub_AIHandlers_1up,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ nightclub_AIHandlers_1up,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ nightclub_AIHandlers_1up,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ &setup_nightclub_1up,
	/* .numNPCspawns = */ 0,
	/* .cars = */ NULL,
	/* .numcars = */ 0,
	/* .sr = */ NULL,
	/* .numremotes = */ 0,
	/* .specialfx = */ nightclub_fx,
	/* .numspecialfx = */ 1,
	/* .weatherdat = */ nightclub_weather,
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

setuppickup nightclub_pickups_arcade[0] = {
};

setupspawn nightclub_spawns_arcade[0] = {
};

setupheader setup_nightclub_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 9,
	/* .props = */ nightclub_fx,
	/* .numprops = */ 0,
	/* .pickups = */ nightclub_pickups_arcade,
	/* .numpickups = */ 25,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ nightclub_spawns_arcade,
	/* .numspawnpads = */ 14,
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
	/* .specialfx = */ nightclub_fx,
	/* .numspecialfx = */ 1,
	/* .weatherdat = */ nightclub_weather,
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
