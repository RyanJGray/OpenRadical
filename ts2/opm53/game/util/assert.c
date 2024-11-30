//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "assert.h"
#include <eekernel.h>

void _game_assert_fail(char *assertion, char *file, unsigned int line, char *function) {
#if 1
    scePrintf("[OpenRadical] Assertion failure - %s, %s, %u, %s!", assertion, file, line, function);
#endif
}
