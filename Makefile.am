AM_MAKEFLAGS			= --no-print-directory
ACLOCAL_AMFLAGS			= -Im4

AM_CPPFLAGS			= @DBI_INCLUDE@
LIBS				= -ldbi

libdir				= ${driverdir}
lib_LTLIBRARIES			= src/libdbdnull.la
src_libdbdnull_la_LDFLAGS	= -module -avoid-version
src_libdbdnull_la_SOURCES	= src/dbd-null.c

TESTS_ENVIRONMENT		= rootdir=${top_builddir} TESTS="${check_PROGRAMS}"
check_PROGRAMS			= tests/test-dbd-null \
				  tests/test-dbd-null-sleep \
				  tests/test-dbd-null-error \
				  tests/test-dbd-null-log \
				  tests/test-dbd-null-error-nth
TESTS				= ${top_srcdir}/tests/runtest.sh

EXTRA_DIST			= README.md tests/runtest.sh
