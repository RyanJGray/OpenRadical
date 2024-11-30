// STATUS: NOT STARTED

#include "frontred.h"

struct leveldef_s {
	char *name;
	int levelnum;
};

typedef leveldef_s leveldef;

static leveldef levels[0] = {
};

static int curselect = 0;
static int numlevels;

void frontredReset() {
	return;
}

void frontredEnd() {}

void frontredTick() {}

void frontredGfx() {
	int i;
	int x;
	int y;
}
