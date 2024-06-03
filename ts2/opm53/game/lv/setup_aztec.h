// STATUS: NOT STARTED

#ifndef GAME_LV_SETUP_AZTEC_H
#define GAME_LV_SETUP_AZTEC_H

struct setuppickup_s {
	int createflags;
	int propnum;
	int pickuptype;
	float data;
	int data2;
	int team;
	int padextref;
	float rot[3];
	float dy;
	int realpadnum;
};

typedef setuppickup_s setuppickup;

struct setupspawn_s {
	int createflags;
	int padextref;
	int flags;
	int realpadnum;
};

typedef setupspawn_s setupspawn;
extern weatherdata aztec_weather[0];
extern setupprop aztec_props[0];
extern setuppickup aztec_pickups_arcade[0];
extern setupspawn aztec_spawns_arcade[0];
extern aihandler aztec_AIHandlers_arcade[0];
extern setupheader setup_aztec_arcade;
extern setuppickup aztec_pickups_1up[0];
extern setupspawn aztec_spawns_1up[0];
extern setupNPC aztec_NPCs_1up[0];
extern setupheader setup_aztec_1up;


#endif // GAME_LV_SETUP_AZTEC_H
