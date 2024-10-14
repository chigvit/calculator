#!/bin/bash

clang-tidy --checks=*,-modernize*,-llvmlibc*,-cppcoreguidelines* ../../src/functions.cpp > clang-tidy-report.txt