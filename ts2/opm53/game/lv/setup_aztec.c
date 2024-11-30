// STATUS: NOT STARTED

#include "setup_aztec.h"

weatherdata aztec_weather[0] = {
};

setupprop aztec_props[0] = {
};

setuppickup aztec_pickups_arcade[0] = {
};

setupspawn aztec_spawns_arcade[0] = {
};

aihandler aztec_AIHandlers_arcade[0] = {
};

setupheader setup_aztec_arcade = {
	/* .setupflags = */ 31,
	/* .gunset = */ 9,
	/* .props = */ aztec_weather,
	/* .numprops = */ 0,
	/* .pickups = */ aztec_weather,
	/* .numpickups = */ 17,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ aztec_spawns_arcade,
	/* .numspawnpads = */ 9,
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
	/* .weatherdat = */ aztec_weather,
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

setuppickup aztec_pickups_1up[0] = {
};

setupspawn aztec_spawns_1up[0] = {
};

setupNPC aztec_NPCs_1up[0];

setupheader setup_aztec_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 6,
	/* .props = */ aztec_weather,
	/* .numprops = */ 0,
	/* .pickups = */ aztec_pickups_1up,
	/* .numpickups = */ 1,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ aztec_spawns_1up,
	/* .numspawnpads = */ 2,
	/* .NPCsetup = */ aztec_NPCs_1up,
	/* .numNPCs = */ 1,
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
	/* .weatherdat = */ aztec_weather,
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
