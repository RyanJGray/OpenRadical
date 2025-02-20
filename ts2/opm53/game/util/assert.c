//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "assert.h"
#include <eekernel.h>

void _game_assert_fail(char *assertion, char *file, unsigned int line, char *function) {
#if 1
    scePrintf("************************************************************************\n");
    scePrintf("ASSERT FAILED: assert(%s)\n");
    scePrintf("ASSERT FAILED: assert(%s)\nFunction: %s\nFile: %s (%d)\n\n%s");
    scePrintf("[OpenRadical] ASSERT FAILED: %s\n\t%s\n\t%u\n\t%s", assertion, file, line, function);
#endif
}
