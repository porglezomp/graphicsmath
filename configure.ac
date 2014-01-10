#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([graphicsmath], [0.7.2], [bugs.adventurous@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AC_REQUIRE_AUX_FILE([tap-driver.sh])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_HEADERS([config.h])

# Put the name of the library to install
AC_SUBST([libfilename], [graphicsmath0])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AR
AC_PROG_AWK
AC_PATH_PROG(DOXYGEN, doxygen)
if test -z "$DOXYGEN";
	then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi

# Checks for libraries.
AC_SEARCH_LIBS([sqrtf], [m])
AC_SEARCH_LIBS([sinf], [m])
AC_SEARCH_LIBS([cosf], [m])
AC_SEARCH_LIBS([atan2f], [m])

# Checks for header files.
AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([string])
AC_CHECK_HEADERS([stdexcept])
AC_CHECK_HEADERS([math.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

# If we have Doxygen, add the doxygen file
AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])
AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([docs/Doxyfile])])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 tests/Makefile
                 docs/Makefile
				 docs/${libfilename}.pc:docs/graphicsmath.pc.in])

AC_OUTPUT
