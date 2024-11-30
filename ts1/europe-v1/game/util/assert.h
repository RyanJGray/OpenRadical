//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS1 Europe-v1 Tree
//

#ifndef GAME_UTIL_ASSERT_H
#define GAME_UTIL_ASSERT_H

void _game_assert_fail(char *assertion, char *file, unsigned int line, char *function);

#define OPENRADICAL_ASSERT_NULL(assertion) {\
    if (assertion != NULL) {\
        _game_assert_fail(assertion, __FILE__, __LINE__, __FUNCTION__);\
    }\
}

#endif // GAME_UTIL_ASSERT_H
