// STATUS: NOT STARTED

#ifndef GAME_LV_SETUP_DAM_H
#define GAME_LV_SETUP_DAM_H

struct setupremote_s {
	int setupref;
	int createflags;
	int propnum;
	int type;
	int data1;
	int padextref;
	float target[3];
	float innerradius;
	float outerradius;
	float minanglex;
	float maxanglex;
	float minangley;
	float maxangley;
	float sweepspeed;
	float VerticalFOV;
	float HorizontalFOV;
};

typedef setupremote_s setupremote;

struct setupalarm_s {
	int setupref;
	int createflags;
	float duration;
	int commlist;
};

typedef setupalarm_s setupalarm;

struct flycameradata_s {
	float pos[3];
	float dir[3];
	float speed;
};

typedef flycameradata_s flycameradata;
typedef cameradata_s cameradata;
extern flycameradata dam_still1[0];
extern flycameradata dam_flycamera[0];
extern cameradata dam_camera[0];
extern weatherdata dam_weather[0];
extern setuplift dam_lifts[0];
extern setupprop dam_props[0];
extern setuppickup dam_pickups_1up[0];
extern setupspawn dam_spawns_1up[0];
extern setupNPC dam_NPCs_1up[0];
extern setupPatrolRoutes dam_patrolroutes_1up[0];
extern aihandler dam_AIHandlers_1up[0];
extern setupNPC dam_spawninfos_1up[0];
extern setupdoor dam_doors_1up[0];
extern setupremote dam_remotes_1up[0];
extern setupalarm dam_alarms_1up[0];
extern setupbutton dam_buttons_1up[0];
extern setupspecialfx dam_fx[0];
extern setupheader setup_dam_1up;
extern setuppickup dam_pickups_arcade[0];
extern setupspawn dam_spawns_arcade[0];
extern setupheader setup_dam_arcade;


#endif // GAME_LV_SETUP_DAM_H
