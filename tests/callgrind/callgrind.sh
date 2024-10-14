#!/bin/bash

cd ../..
rm -rf build
mkdir build
cd build
cmake -DBULD_GPROF=ON ..
make
ulimit -n 4096
valgrind --tool=callgrind ./calculator
mv callgrind.out.* ../tests/callgrind

#kcachegrind