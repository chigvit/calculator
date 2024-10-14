#!/bin/bash

cd ../..
rm -rf build
mkdir build
cd build
cmake -DBULD_GPROF=ON ..
make -j 4

./calculator "48*77+55-(9/3)"
gprof calculator gmon.out --width=120  > ../tests/gprof/gprof-report.log 