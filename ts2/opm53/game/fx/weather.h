//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FX_WEATHER_H
#define GAME_FX_WEATHER_H

#include "common.h"

typedef struct weatherdata_s {
	int type;
	int magnitude;
	float wind[3];
	float windvariation[3];
	int precipitationalpha;
	int splashalpha;
} weatherdata;

typedef struct weatherdef_s {
	float bb[2][3];
} weatherdef;

typedef struct weatherinfo_s {
	int numweatherdata;
	struct weatherdata_s *data;
	int currentweather;
	int destweather;
	float ratio;
	float windspeed[3];
	float windtime;
} weatherinfo;

typedef struct fireFlyParticle_s {
	float pos[3];
	float velocity[3];
	float destPos[3];
	float timeThisWay;
	float lifetime;
	float totalLifetime;
} fireFlyParticle;

typedef struct snowParticle_s {
	float pos[3];
	float velocity[3];
	float wind;
} snowParticle;

typedef struct precBlockPrecalc_s {
	float blockPos[3];
	boolean autopass;
} precBlockPrecalc;

typedef struct weatherBoundsData_s {
	float distsqFromPlayer[4];
	float precipitationScale[4];
	fireFlyParticle fireFlies[2];
	int blocksx;
	int blocksy;
	int blocksz;
	float *clippingx;
	float *clippingy;
	float *clippingz;
	precBlockPrecalc *blocks;
} weatherBoundsData;

typedef struct weatherRoomData_s {
	float distsqFromPlayer[4];
	float splashScale[4];
	int fxUsage;
	int numBounds;
	weatherBoundsData *bounds;
} weatherRoomData;

extern snowParticle *snowBlockParticles;
extern weatherRoomData *weatherRooms;
extern weatherdata defaultweather;
extern weatherinfo weather;

weatherdata* weatherGetCurrentWeatherData();
float weatherCalcPositionalTime(float *pos);
void weatherCalcWindAtTime(float *wind, float time);
void weatherGetWindAtPosition(float *pos, int room, float *wind);
float weatherCalcWindStrengthInDir(float *pos, int room, float *dir);
void weatherWindTick();
void weatherPrecipitationReset();
void weatherPrecipitationEnd();
void weatherBlockPrecalc(float blocksizex, float blocksizey, float blocksizez);
void weatherSnowPreload();
void weatherSnowRestart();
void weatherSnowReset();
void weatherSnowEnd();
void weatherSnowTick();
void weatherSnowGfx();
void weatherRainPreload();
void weatherRainRestart();
void weatherRainReset();
void weatherRainEnd();
void weatherRainTick();
void weatherRainGfx();
void weatherFireFlyPreload();
void weatherFireFlyRestart();
void weatherFireFlyReset();
void weatherFireFlyEnd();
void weatherFireFlyGetPos(float *pos, weatherdef *wdef);
void weatherFireFlyTick();
void weatherFireFlyGfx();
void weatherPreload();
void weatherRestart();
void weatherReset();
void weatherEnd();
void weatherSet(int numweatherdata, weatherdata *weatherdat);
void weatherTick();
void weatherGfx();
boolean weatherIsInsideWeatherBounds(float *pos, int numRooms, int *rooms);
int weatherGetCurrentWeather();
void weatherSetSnow(boolean state);

#endif // GAME_FX_WEATHER_H
