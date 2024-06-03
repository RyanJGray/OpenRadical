// STATUS: NOT STARTED

#include "loadbar.h"

static boolean s_BarActive = 0;
static int s_BarX = 75;
static int s_BarY = 350;
static int s_BarWidth = 362;
static int s_BarHeight = 15;
static float s_BarAmount = 0.f;
static float s_BarLastAmount = 0.f;
static float s_BarNextAmount = 0.f;
static float s_BarAmountFileDone = 0.f;
static float barStageScalar[3];
static int barStage;

void loadbarSetActive(boolean Active) {}

void loadbarSetAmount(float Amount) {}

void loadbarSetNextAmount(float Amount) {}

void loadbarSetAmountFileDone(float Amount) {}

void loadbarSetPos(int x, int y, int Width, int Height) {}

void loadbarSetStageScalar(int stage, float startscalar) {}

void loadbarStartStage(int stage) {}

void loadbarGfx() {
	float NewAmount;
	dlDmaTag dma[10];
	u32 Init[12];
	u32 Bar1[16];
	u32 Bar2[16];
	u32 Signal[8];
	u32 *ref;
	int x1;
	int y1;
	int x2;
	int y2;
	float stageDiff;
	dlDmaTag *tmp;
	void *addr;
	void *addr;
	void *addr;
	void *addr;
}
