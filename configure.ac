#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([battlecar], [1.0], [adiwang@outlook.com])
AC_CONFIG_SRCDIR([test/test_tcpserver.cpp])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE(battlecar, 1.0)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcrypto':
AC_CHECK_LIB([crypto], [main])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])
# FIXME: Replace `main' with a function in `-lssl':
AC_CHECK_LIB([ssl], [main])
# FIXME: Replace `main' with a function in `-luv':
AC_CHECK_LIB([uv], [main])
AC_PROG_RANLIB

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h memory.h netinet/in.h stdint.h stdlib.h string.h sys/file.h unistd.h])
CXXFLAGS=${CXXFLAGS--g}
AC_PROG_CXX 

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([localtime_r memchr memmove memset mkdir strerror])

AC_CONFIG_FILES([Makefile
                 common/Makefile
                 common/json/Makefile
                 pb/Makefile
                 test/Makefile
                 battleserver/Makefile])
AC_OUTPUT
