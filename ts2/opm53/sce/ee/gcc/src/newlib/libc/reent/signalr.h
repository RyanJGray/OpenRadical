// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBC_REENT_SIGNALR_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBC_REENT_SIGNALR_H

int _kill_r(_reent *ptr, int pid, int sig);
int _getpid_r(_reent *ptr);

#endif // SCE_EE_GCC_SRC_NEWLIB_LIBC_REENT_SIGNALR_H
