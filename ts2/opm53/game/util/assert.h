//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_UTIL_ASSERT_H
#define GAME_UTIL_ASSERT_H

void _game_assert_fail(char *assertion, char *file, unsigned int line, char *function);

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define OPENRADICAL_ASSERT_FAIL(assertion) _game_assert_fail(TOSTRING(assertion), __FILE__, __LINE__, __FUNCTION__);

#define OPENRADICAL_ASSERT_IF(assertion) if (assertion) { OPENRADICAL_ASSERT_FAIL(assertion) }

#define OPENRADICAL_ASSERT_NULL(assertion) OPENRADICAL_ASSERT_IF(assertion!=NULL)

#endif // GAME_UTIL_ASSERT_H
