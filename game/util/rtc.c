// STATUS: NOT STARTED

#include "rtc.h"

static int bcd2int(int val) {}

static int int2bcd(int val) {}

static u32 clock2u32(sceCdCLOCK *rtc) {
	u32 yearsecs;
	u32 monthsecs;
	u32 daysecs;
	u32 hoursecs;
	u32 minutesecs;
}

static void u322clock(sceCdCLOCK *rtc, u32 time) {}

void getHoursMinutesSeconds(int *hours, int *minutes, int *seconds) {
	sceCdCLOCK rtc;
}

u32 rtcGetTime() {
	sceCdCLOCK rtc;
}

u8* rtcFormatTime(u32 time) {
	static u8 *rettime = 0x452700;
	sceCdCLOCK rtc;
}
