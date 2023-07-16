// STATUS: NOT STARTED

#ifndef GAME_FX_WEATHER_H
#define GAME_FX_WEATHER_H

struct weatherdata_s {
	int type;
	int magnitude;
	float wind[3];
	float windvariation[3];
	int precipitationalpha;
	int splashalpha;
};

typedef weatherdata_s weatherdata;

struct weatherinfo_s {
	int numweatherdata;
	weatherdata_s *data;
	int currentweather;
	int destweather;
	float ratio;
	float windspeed[3];
	float windtime;
};

typedef weatherinfo_s weatherinfo;
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
