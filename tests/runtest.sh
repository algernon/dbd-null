#! /bin/sh
set -e

if [ -e "${rootdir}/src/libdbdnull.so" ]; then
        libdir="${rootdir}/src"
else
        libdir="${rootdir}/src/.libs"
fi

for t in ${TESTS}; do
        $t ${libdir}
done
