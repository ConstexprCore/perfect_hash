#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#ifdef __FILC__
// Fil-C rejects the stack-allocated sigaltstack that doctest's crash handler uses.
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#endif
#include <doctest/doctest.h>
