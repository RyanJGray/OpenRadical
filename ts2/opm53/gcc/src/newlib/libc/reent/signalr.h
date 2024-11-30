// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBC_REENT_SIGNALR_H
#define GCC_SRC_NEWLIB_LIBC_REENT_SIGNALR_H

int _kill_r(_reent *ptr, int pid, int sig);
int _getpid_r(_reent *ptr);

#endif // GCC_SRC_NEWLIB_LIBC_REENT_SIGNALR_H
