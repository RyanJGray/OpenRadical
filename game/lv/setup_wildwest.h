// STATUS: NOT STARTED

#ifndef GAME_LV_SETUP_WILDWEST_H
#define GAME_LV_SETUP_WILDWEST_H

struct AIHandler_s {
	void (*function)(/* parameters unknown */);
};

typedef AIHandler_s aihandler;
extern setuppickup wildwest_pickups_1up[0];
extern setupspawn wildwest_spawns_1up[0];
extern setupNPC ww_NPCs_1up[0];
extern setupPatrolRoutes ww_patrolroutes_1up[0];
extern aihandler ww_AIHandlers_1up[0];
extern setupNPC ww_spawninfos_1up[0];
extern setupheader setup_wildwest_1up;
extern setuppickup wildwest_pickups_arcade[0];
extern setupspawn wildwest_spawns_arcade[0];
extern aihandler wildwest_AIHandlers_arcade[0];
extern setupheader setup_wildwest_arcade;


#endif // GAME_LV_SETUP_WILDWEST_H
