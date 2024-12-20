// STATUS: NOT STARTED

#include "setup_pivotal.h"

setupprop pivotal_props[0] = {
};

setuppickup pivotal_pickups_1up[0] = {
};

setupspawn pivotal_spawns_1up[0] = {
};

setupNPC pivotal_NPCs_1up[0];

setupPatrolRoutes pivotal_patrolroutes_1up[0] = {
};

aihandler pivotal_AIHandlers_1up[0] = {
};

setupNPC pivotal_spawninfos_1up[0];

setupdoor pivotal_doors_1up[0] = {
};

setupheader setup_pivotal_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 6,
	/* .props = */ pivotal_props,
	/* .numprops = */ 0,
	/* .pickups = */ pivotal_props,
	/* .numpickups = */ 0,
	/* .doors = */ pivotal_spawninfos_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ pivotal_props,
	/* .numspawnpads = */ 0,
	/* .NPCsetup = */ pivotal_props,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ pivotal_props,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ pivotal_props,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ pivotal_spawninfos_1up,
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

setuppickup pivotal_pickups_arcade[0] = {
};

setupspawn pivotal_spawns_arcade[0] = {
};

setupremote pivotal_remotes_arcade[0] = {
};

setupheader setup_pivotal_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 12,
	/* .props = */ pivotal_props,
	/* .numprops = */ 0,
	/* .pickups = */ pivotal_pickups_arcade,
	/* .numpickups = */ 18,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ pivotal_spawns_arcade,
	/* .numspawnpads = */ 7,
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
	/* .sr = */ pivotal_remotes_arcade,
	/* .numremotes = */ 4,
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
