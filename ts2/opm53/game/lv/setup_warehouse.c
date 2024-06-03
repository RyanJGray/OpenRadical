// STATUS: NOT STARTED

#include "setup_warehouse.h"

float gangsterclothesaxis[0][6] = {
};

setupprop warehouse_props[0] = {
};

setupspecialfx warehouse_fx[0] = {
};

carpath warehouse_car_route[0] = {
};

carpath warehouse_train_route_start1[0] = {
};

carpath warehouse_train_route_start2[0] = {
};

carpath warehouse_train_route_hotel1[0] = {
};

carpath warehouse_train_route_hotel2[0] = {
};

carpath warehouse_train_route_curvy1[0] = {
};

carpath warehouse_train_route_curvy2[0] = {
};

carpath warehouse_airship_route[0] = {
};

setupcar warehouse_cars[0] = {
};

setuppickup warehouse_pickups_1up[0] = {
};

setupspawn warehouse_spawns_1up[0] = {
};

setupNPC warehouse_NPCs_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupPatrolRoutes warehouse_patrolroutes_1up[0] = {
};

aihandler warehouse_AIHandlers_1up[0] = {
};

setupNPC warehouse_spawninfos_1up[0] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

setupdoor warehouse_doors_1up[0] = {
};

setupheader setup_warehouse_1up = {
	/* .setupflags = */ 128,
	/* .gunset = */ 6,
	/* .props = */ warehouse_props,
	/* .numprops = */ 7,
	/* .pickups = */ warehouse_AIHandlers_1up,
	/* .numpickups = */ 0,
	/* .doors = */ &setup_warehouse_1up,
	/* .numdoors = */ 0,
	/* .spawnpads = */ warehouse_AIHandlers_1up,
	/* .numspawnpads = */ 0,
	/* .NPCsetup = */ warehouse_AIHandlers_1up,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ warehouse_AIHandlers_1up,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ warehouse_AIHandlers_1up,
	/* .numAIEventHandlers = */ 1,
	/* .si = */ &setup_warehouse_1up,
	/* .numNPCspawns = */ 0,
	/* .cars = */ warehouse_cars,
	/* .numcars = */ 8,
	/* .sr = */ NULL,
	/* .numremotes = */ 0,
	/* .specialfx = */ warehouse_car_route,
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

setuppickup warehouse_pickups_arcade[0] = {
};

setupspawn warehouse_spawns_arcade[0] = {
};

setupheader setup_warehouse_arcade = {
	/* .setupflags = */ 4,
	/* .gunset = */ 9,
	/* .props = */ warehouse_props,
	/* .numprops = */ 7,
	/* .pickups = */ warehouse_pickups_arcade,
	/* .numpickups = */ 20,
	/* .doors = */ NULL,
	/* .numdoors = */ 0,
	/* .spawnpads = */ warehouse_spawns_arcade,
	/* .numspawnpads = */ 5,
	/* .NPCsetup = */ NULL,
	/* .numNPCs = */ 0,
	/* .setupPatrolRoutes = */ NULL,
	/* .numPatrolroutes = */ 0,
	/* .AIEventHandlers = */ NULL,
	/* .numAIEventHandlers = */ 0,
	/* .si = */ NULL,
	/* .numNPCspawns = */ 0,
	/* .cars = */ warehouse_cars,
	/* .numcars = */ 8,
	/* .sr = */ warehouse_car_route,
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
