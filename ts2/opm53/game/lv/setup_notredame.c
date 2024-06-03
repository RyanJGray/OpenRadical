// STATUS: NOT STARTED

#include "setup_notredame.h"

setupprop notredame_props[0] = {
};

setuppickup notredame_pickups_1up[0] = {
};

setupspawn notredame_spawns_1up[0] = {
};

setupNPC notredame_NPCs_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupPatrolRoutes notredame_patrolroutes_1up[0] = {
};

aihandler notredame_AIHandlers_1up[0] = {
};

setupNPC notredame_spawninfos_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupdoor notredame_doors_1up[0] = {
};

setupheader setup_notredame_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 6,
	/* .props = */ notredame_AIHandlers_1up,
	/* .numprops = */ 0,
	/* .pickups = */ notredame_AIHandlers_1up,
	/* .numpickups = */ 0,
	/* .doors = */ &setup_notredame_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ notredame_AIHandlers_1up,
	/* .numspawnpads = */ 0,
	/* .NPCsetup = */ notredame_AIHandlers_1up,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ notredame_AIHandlers_1up,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ notredame_AIHandlers_1up,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ &setup_notredame_1up,
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

setuppickup notredame_pickups_arcade[0] = {
};

setupspawn notredame_spawns_arcade[0] = {
};

setupheader setup_notredame_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 9,
	/* .props = */ notredame_AIHandlers_1up,
	/* .numprops = */ 0,
	/* .pickups = */ notredame_pickups_arcade,
	/* .numpickups = */ 5,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ notredame_spawns_arcade,
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