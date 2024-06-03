// STATUS: NOT STARTED

#ifndef GAME_PROP_DOOR_H
#define GAME_PROP_DOOR_H

struct doordata_s {
	int id;
	u16 type;
	u16 key;
	float pos[3];
	int opening;
	int opentime;
	float openfrac;
	float travel;
	int linknum;
	prop *myprop;
	int doorflags;
};

typedef doordata_s doordata;
extern doordata *leveldoors;
extern int numdoors;
extern prop *doors[40];

void restartDoors();
prop* doorNewInVolume(int propnum, int volnum, int id, int key, int extrefpadnum, int doorflags);
prop* doorNew(int propnum, int id, int key, float x, float y, float z, int extrefpadnum, int doorflags);
boolean doorActivate(prop *p, prop *actor);
void doorPropTick(prop *p);
void doorLock(int id);
void doorUnlock(int id);
void doorOpen(int id);
void doorClose(int id);
doordata* doorIDgetData(int doorid);
prop* doorIDgetProp(int doorid);
int doorIDisOpen(int doorid);

#endif // GAME_PROP_DOOR_H
