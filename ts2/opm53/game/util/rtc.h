// STATUS: NOT STARTED

#ifndef GAME_UTIL_RTC_H
#define GAME_UTIL_RTC_H

void getHoursMinutesSeconds(int *hours, int *minutes, int *seconds);
u32 rtcGetTime();
u8* rtcFormatTime(u32 time);

#endif // GAME_UTIL_RTC_H
