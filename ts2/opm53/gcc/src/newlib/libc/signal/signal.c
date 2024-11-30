// STATUS: NOT STARTED

#include "signal.h"

int _init_signal_r(_reent *ptr) {
	int i;
}

_sig_func_ptr _signal_r(_reent *ptr, int sig, _sig_func_ptr func) {
	_sig_func_ptr old_func;
}

int _raise_r(_reent *ptr, int sig) {
	_sig_func_ptr func;
	int result;
}

int __sigtramp_r(_reent *ptr, int sig) {
	_sig_func_ptr func;
}

int raise(int sig) {}

_sig_func_ptr signal(int sig, _sig_func_ptr func) {}

int _init_signal() {}

int __sigtramp(int sig) {}
