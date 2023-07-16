// STATUS: NOT STARTED

#include "setup_spacestation.h"

setuplift spacestation_lifts[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupprop spacestation_props[0] = {
};

setuppickup spacestation_pickups_1up[0] = {
};

setupspawn spacestation_spawns_1up[0] = {
};

setupNPC spacestation_NPCs_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupPatrolRoutes spacestation_patrolroutes_1up[0] = {
};

aihandler spacestation_AIHandlers_1up[0] = {
};

setupNPC spacestation_spawninfos_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupdoor spacestation_doors_1up[0] = {
};

setupheader setup_spacestation_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 6,
	/* .props = */ spacestation_AIHandlers_1up,
	/* .numprops = */ 0,
	/* .pickups = */ spacestation_AIHandlers_1up,
	/* .numpickups = */ 0,
	/* .doors = */ &setup_spacestation_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ spacestation_AIHandlers_1up,
	/* .numspawnpads = */ 0,
	/* .NPCsetup = */ spacestation_AIHandlers_1up,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ spacestation_AIHandlers_1up,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ spacestation_AIHandlers_1up,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ &setup_spacestation_1up,
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
	/* .lifts = */ spacestation_lifts,
	/* .numlifts = */ 1,
	/* .lvbuttons = */ NULL,
	/* .numlvbuttons = */ 0,
	/* .lvcameradata = */ NULL,
	/* .numcamera = */ 0,
	/* .lvpropspawn = */ NULL,
	/* .numpropspawns = */ 0
};

setuppickup spacestation_pickups_arcade[0] = {
};

setupspawn spacestation_spawns_arcade[0] = {
};

setupheader setup_spacestation_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 18,
	/* .props = */ spacestation_AIHandlers_1up,
	/* .numprops = */ 0,
	/* .pickups = */ spacestation_pickups_arcade,
	/* .numpickups = */ 5,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ spacestation_spawns_arcade,
	/* .numspawnpads = */ 2,
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
	/* .lifts = */ spacestation_lifts,
	/* .numlifts = */ 1,
	/* .lvbuttons = */ NULL,
	/* .numlvbuttons = */ 0,
	/* .lvcameradata = */ NULL,
	/* .numcamera = */ 0,
	/* .lvpropspawn = */ NULL,
	/* .numpropspawns = */ 0
};
