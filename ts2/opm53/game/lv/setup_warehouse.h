// STATUS: NOT STARTED

#ifndef GAME_LV_SETUP_WAREHOUSE_H
#define GAME_LV_SETUP_WAREHOUSE_H

typedef setupNPC_s setupNPC;

struct setupPatrolRoutes_s {
	int *patrolrt;
	int size;
};

typedef setupPatrolRoutes_s setupPatrolRoutes;

struct setupcar_s {
	int createflags;
	int propnum;
	int mode;
	int carflags;
	carpath_s *paths;
	int numpaths;
};

typedef setupcar_s setupcar;

struct setupspecialfx_s {
	int createflags;
	int type;
	int subtype;
	float pos[3];
	float param;
	void *extra;
};

typedef setupspecialfx_s setupspecialfx;

struct carpath_s {
	int type;
	float destPos[3];
	float destAng;
	float speed;
	float bankingAngle;
	float liftingAngle;
	float turningAngleAdjust;
	float turnRad;
	float turningPointAngle;
	int special;
	boolean distanceSet;
	float distance;
};

typedef carpath_s carpath;
extern float gangsterclothesaxis[0][6];
extern setupprop warehouse_props[0];
extern setupspecialfx warehouse_fx[0];
extern carpath warehouse_car_route[0];
extern carpath warehouse_train_route_start1[0];
extern carpath warehouse_train_route_start2[0];
extern carpath warehouse_train_route_hotel1[0];
extern carpath warehouse_train_route_hotel2[0];
extern carpath warehouse_train_route_curvy1[0];
extern carpath warehouse_train_route_curvy2[0];
extern carpath warehouse_airship_route[0];
extern setupcar warehouse_cars[0];
extern setuppickup warehouse_pickups_1up[0];
extern setupspawn warehouse_spawns_1up[0];
extern setupNPC warehouse_NPCs_1up[0];
extern setupPatrolRoutes warehouse_patrolroutes_1up[0];
extern aihandler warehouse_AIHandlers_1up[0];
extern setupNPC warehouse_spawninfos_1up[0];
extern setupdoor warehouse_doors_1up[0];
extern setupheader setup_warehouse_1up;
extern setuppickup warehouse_pickups_arcade[0];
extern setupspawn warehouse_spawns_arcade[0];
extern setupheader setup_warehouse_arcade;


#endif // GAME_LV_SETUP_WAREHOUSE_H
