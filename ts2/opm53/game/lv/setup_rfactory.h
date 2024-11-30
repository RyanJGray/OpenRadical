//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_LV_SETUP_RFACTORY_H
#define GAME_LV_SETUP_RFACTORY_H

#include "lvsetup.h"

struct laserBeam_s {
	float startpos[3];
	float endpos[3];
	float glowscalar[2];
	float glowspeed[2];
};

typedef laserBeam_s laserBeam;

struct laserBeamInfo_s {
	float wallmin[3];
	float wallmax[3];
	float starttime;
	void (*activate)(/* parameters unknown */);
	laserBeam *beams;
	int numBeams;
};

typedef laserBeamInfo_s laserBeamInfo;
extern setupprop rfactory_props[0];
extern setuppropspawn rfactory_propsspawns[0];
extern setuppickup rfactory_pickups_1up[0];
extern setupspawn rfactory_spawns_1up[0];
extern setupNPC rfactory_NPCs_1up[0];
extern setupPatrolRoutes rfactory_patrolroutes_1up[0];
extern aihandler rfactory_AIHandlers_1up[0];
extern setupNPC rfactory_spawninfos_1up[0];
extern setupdoor rfactory_doors[0];
extern laserBeam rfactory_beams_test[0];
extern laserBeamInfo rfactory_beamInfo_test;
extern laserBeam rfactory_beams_pipeGrid1[0];
extern laserBeamInfo rfactory_beamInfo_pipeGrid1;
extern laserBeam rfactory_beams_pipeGrid2[0];
extern laserBeamInfo rfactory_beamInfo_pipeGrid2;
extern laserBeam rfactory_beams_pipeGrid3[0];
extern laserBeamInfo rfactory_beamInfo_pipeGrid3;
extern setupspecialfx rfactory_fx[0];
extern setupremote rfactory_remotes_1up[0];
extern setupalarm rfactory_alarms_1up[0];
extern setupbutton rfactory_buttons_1up[0];
extern setupheader setup_rfactory_1up;
extern setuppickup rfactory_pickups_arcade[0];
extern setupspawn rfactory_spawns_arcade[0];
extern setupdoor rfactory_doors_arcade[0];
extern setupheader setup_rfactory_arcade;

void laserBeamTestActivated(specialfx *spfx, prop *actor);

#endif // GAME_LV_SETUP_RFACTORY_H
