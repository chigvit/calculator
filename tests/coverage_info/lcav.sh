#!/bin/bash

cd ../..
rm -rf build
mkdir build
cd build
cmake -DCODE_COVERAGE=ON ..
make -j 4
./utest_evaluate
lcov --capture --directory . --output-file coverage.info --exclude '/usr/*' --exclude '/opt/*' --exclude 'lib/googletest/*' --ignore-errors inconsistent --ignore-errors usage
genhtml coverage.info --output-directory ../tests/caverage_info/coverage
