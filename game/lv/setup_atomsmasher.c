// STATUS: NOT STARTED

#include "setup_atomsmasher.h"

setupprop atomsmasher_props[0] = {
};

setupdoor atomsmasher_doors[0] = {
};

setuppickup atomsmasher_pickups_1up[0] = {
};

setupspawn atomsmasher_spawns_1up[0] = {
};

setupNPC atomsmasher_NPCs_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupPatrolRoutes atomsmasher_patrolroutes_1up[0] = {
};

aihandler atomsmasher_AIHandlers_1up[0] = {
};

setupNPC atomsmasher_spawninfos_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupheader setup_atomsmasher_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 12,
	/* .props = */ atomsmasher_AIHandlers_1up,
	/* .numprops = */ 0,
	/* .pickups = */ atomsmasher_AIHandlers_1up,
	/* .numpickups = */ 0,
	/* .doors = */ atomsmasher_AIHandlers_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ atomsmasher_AIHandlers_1up,
	/* .numspawnpads = */ 0,
	/* .NPCsetup = */ atomsmasher_AIHandlers_1up,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ atomsmasher_AIHandlers_1up,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ atomsmasher_AIHandlers_1up,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ &setup_atomsmasher_1up,
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

setuppickup atomsmasher_pickups_arcade[0] = {
};

setupspawn atomsmasher_spawns_arcade[0] = {
};

setupheader setup_atomsmasher_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 12,
	/* .props = */ NULL,
	/* .numprops = */ 0,
	/* .pickups = */ atomsmasher_pickups_arcade,
	/* .numpickups = */ 5,
	/* .doors = */ atomsmasher_AIHandlers_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ atomsmasher_spawns_arcade,
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
	/* .lifts = */ NULL,
	/* .numlifts = */ 0,
	/* .lvbuttons = */ NULL,
	/* .numlvbuttons = */ 0,
	/* .lvcameradata = */ NULL,
	/* .numcamera = */ 0,
	/* .lvpropspawn = */ NULL,
	/* .numpropspawns = */ 0
};
