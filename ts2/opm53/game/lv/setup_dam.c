// STATUS: NOT STARTED

#include "setup_dam.h"

flycameradata dam_still1[0] = {
};

flycameradata dam_flycamera[0] = {
};

cameradata dam_camera[0] = {
};

weatherdata dam_weather[0] = {
};

setuplift dam_lifts[0];

setupprop dam_props[0] = {
};

setuppickup dam_pickups_1up[0] = {
};

setupspawn dam_spawns_1up[0] = {
};

setupNPC dam_NPCs_1up[0];

static int dam_patrol0_1up[0] = {
};

static int dam_patrol1_1up[0] = {
};

static int dam_patrol2_1up[0] = {
};

static int dam_patrol3_1up[0] = {
};

static int dam_patrol4_1up[0] = {
};

static int dam_patrol5_1up[0] = {
};

static int dam_patrol6_1up[0] = {
};

static int dam_patrol7_1up[0] = {
};

static int dam_patrol8_1up[0] = {
};

setupPatrolRoutes dam_patrolroutes_1up[0] = {
};

aihandler dam_AIHandlers_1up[0] = {
};

setupNPC dam_spawninfos_1up[0];

setupdoor dam_doors_1up[0] = {
};

setupremote dam_remotes_1up[0] = {
};

setupalarm dam_alarms_1up[0] = {
};

static int doorlist1[0] = {
};

static int doorlist2[0] = {
};

setupbutton dam_buttons_1up[0] = {
};

setupspecialfx dam_fx[0] = {
};

setupheader setup_dam_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 0,
	/* .props = */ dam_props,
	/* .numprops = */ 140,
	/* .pickups = */ dam_pickups_1up,
	/* .numpickups = */ 13,
	/* .doors = */ dam_doors_1up,
	/* .numdoors = */ 22,
	/* .spawnpads = */ dam_spawns_1up,
	/* .numspawnpads = */ 2,
	/* .NPCsetup = */ dam_NPCs_1up,
	/* .numNPCs = */ 4,
	/* .setupPatrolRoutes = */ dam_patrolroutes_1up,
	/* .numPatrolroutes = */ 9,
	/* .AIEventHandlers = */ dam_AIHandlers_1up,
	/* .numAIEventHandlers = */ 2,
	/* .si = */ dam_spawninfos_1up,
	/* .numNPCspawns = */ 64,
	/* .cars = */ NULL,
	/* .numcars = */ 0,
	/* .sr = */ dam_remotes_1up,
	/* .numremotes = */ 16,
	/* .specialfx = */ dam_fx,
	/* .numspecialfx = */ 3,
	/* .weatherdat = */ dam_weather,
	/* .numweatherdata = */ 1,
	/* .lsphases = */ NULL,
	/* .numlsphases = */ 0,
	/* .lssnipergrps = */ NULL,
	/* .numlssnipergrps = */ 0,
	/* .alarms = */ dam_alarms_1up,
	/* .numalarms = */ 3,
	/* .lifts = */ dam_lifts,
	/* .numlifts = */ 2,
	/* .lvbuttons = */ dam_buttons_1up,
	/* .numlvbuttons = */ 10,
	/* .lvcameradata = */ dam_camera,
	/* .numcamera = */ 2,
	/* .lvpropspawn = */ NULL,
	/* .numpropspawns = */ 0
};

setuppickup dam_pickups_arcade[0] = {
};

setupspawn dam_spawns_arcade[0] = {
};

setupheader setup_dam_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 0,
	/* .props = */ dam_props,
	/* .numprops = */ 140,
	/* .pickups = */ dam_pickups_arcade,
	/* .numpickups = */ 0,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ dam_pickups_arcade,
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
	/* .weatherdat = */ dam_weather,
	/* .numweatherdata = */ 1,
	/* .lsphases = */ NULL,
	/* .numlsphases = */ 0,
	/* .lssnipergrps = */ NULL,
	/* .numlssnipergrps = */ 0,
	/* .alarms = */ NULL,
	/* .numalarms = */ 0,
	/* .lifts = */ dam_lifts,
	/* .numlifts = */ 2,
	/* .lvbuttons = */ NULL,
	/* .numlvbuttons = */ 0,
	/* .lvcameradata = */ NULL,
	/* .numcamera = */ 0,
	/* .lvpropspawn = */ NULL,
	/* .numpropspawns = */ 0
};
