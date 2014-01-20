AM_MAKEFLAGS			= --no-print-directory

AM_CPPFLAGS			= @DBI_INCLUDE@
LIBS				= -ldbi

libdir				= ${driverdir}
lib_LTLIBRARIES			= src/libdbdnull.la
src_libdbdnull_la_LDFLAGS	= -module -avoid-version
src_libdbdnull_la_SOURCES	= src/dbd-null.c

TESTS_ENVIRONMENT		= rootdir=${top_builddir} ${top_srcdir}/tests/runtest.sh
TESTS				= tests/test-dbd-null \
				  tests/test-dbd-null-sleep \
				  tests/test-dbd-null-error \
				  tests/test-dbd-null-log \
				  tests/test-dbd-null-error-nth
check_PROGRAMS			= ${TESTS}

EXTRA_DIST			= README.md tests/runtest.sh
