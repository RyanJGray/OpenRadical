// STATUS: NOT STARTED

#include "setup_scrapyard.h"

setupprop scrapyard_props[0] = {
};

setuppickup scrapyard_pickups_1up[0] = {
};

setupspawn scrapyard_spawns_1up[0] = {
};

setupNPC scrapyard_NPCs_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupPatrolRoutes scrapyard_patrolroutes_1up[0] = {
};

aihandler scrapyard_AIHandlers_1up[0] = {
};

setupNPC scrapyard_spawninfos_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupdoor scrapyard_doors_1up[0] = {
};

setupheader setup_scrapyard_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 6,
	/* .props = */ scrapyard_AIHandlers_1up,
	/* .numprops = */ 0,
	/* .pickups = */ scrapyard_AIHandlers_1up,
	/* .numpickups = */ 0,
	/* .doors = */ &setup_scrapyard_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ scrapyard_AIHandlers_1up,
	/* .numspawnpads = */ 0,
	/* .NPCsetup = */ scrapyard_AIHandlers_1up,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ scrapyard_AIHandlers_1up,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ scrapyard_AIHandlers_1up,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ &setup_scrapyard_1up,
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

setuppickup scrapyard_pickups_arcade[0] = {
};

setupspawn scrapyard_spawns_arcade[0] = {
};

setupheader setup_scrapyard_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 9,
	/* .props = */ scrapyard_AIHandlers_1up,
	/* .numprops = */ 0,
	/* .pickups = */ &setup_scrapyard_arcade,
	/* .numpickups = */ 0,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ &setup_scrapyard_arcade,
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
