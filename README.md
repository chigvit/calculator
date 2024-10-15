Ось оновлений README, що включає опис папки `tests`:

---

# Calculator Project

This project implements a calculator that evaluates mathematical expressions. The project includes profiling support using `gprof`, `valgrind`, and code coverage analysis. It also provides static code analysis using `clang-tidy`.

## Project Structure

```
calculator/
├── include/              # Header files
│   └── functions.h       # Function declarations
├── src/                  # Source files
│   ├── main.cpp          # Main function
│   └── functions.cpp     # Function implementations
├── build/                # Build directory (created during compilation)
├── tests/                # Tests and profiling tools
│   ├── callgrind/        # Callgrind output files profiling
│   │   └─ callgrind.sh   # Script for profiling with valgrind callgrind
│   ├── code_review/      # Static analysis and code coverage Clang-tidy
│   │   └── clang-tidy.sh
│   ├── gprof/            # gprof profiling output
│   │   └── gprof_gen.sh  # Script for compiling and profiling with gprof
│   ├── coverage_info/    # Main directory for coverage information
│   │   ├── coverage/     # Subdirectory for storing coverage data (e.g., reports, coverage files)
│   │   └── lcav.sh       # Shell script (possibly for generating or cleaning coverage data)
│   ├── gtest/            # Unit tests
│   │   └── utest_evaluate.cpp
└── CMakeLists.txt        # CMake configuration file
```

## Requirements

To build and profile the project, ensure that the following software is installed on your system:

- GCC (g++) >= 7.0
- CMake >= 3.10
- Valgrind >= 3.14
- binutils
- lcov
- clang-tidy
- kcachegrind 

On Debian-based systems (Ubuntu, Kali Linux), you can install these packages with:

```bash
sudo apt update
sudo apt install g++ cmake valgrind binutils clang-tidy
```

## Build Instructions

1. Create the `build` directory and navigate to it:
   ```bash
   mkdir build
   cd build
   ```

2. Run CMake to configure the project:
   ```bash
   cmake ..
   ```
    For gprof
   ```bash
   cmake -BUILD_GPROF=ON ..
   ```
   For lcov
   ```bash
   cmake -CODE_COVERAGE=ON ..
   ```

3. Compile the project:
   ```bash
   make
   ```

This will generate an executable named `calculator` in the `build` directory.

## Profiling and Testing

### Profiling with gprof

To generate a performance profile using `gprof`:

1. Run the `gprof_gen.sh` script:
   ```bash
   ../gprof_gen.sh
   ```

2. The profiling report will be written to `../tests/gprof/gprof-report.log`.

### Profiling with Valgrind (callgrind)

To analyze the program's call graph:

1. Run the `callgrind.sh` script:
   ```bash
   ../callgrind.sh
   ```

2. Callgrind outputs will be saved in the `tests/callgrind` directory, which can be viewed with tools like `kcachegrind`.

### Static Code Analysis with Clang-tidy

To perform static code analysis using `clang-tidy`:

1. Navigate to the `code_review` folder and run `clang-tidy.sh`:
   ```bash
   ../tests/code_review/clang-tidy.sh
   ```

2. The report will be saved in `clang-tidy-report.txt`.

### Code Coverage

To generate code coverage reports:
1. Build the project with code coverage enabled:
   ```bash
   cmake -DCODE_COVERAGE=ON ..
   make
   ```

2. Run the following script for code coverage analysis:
   ```bash
   ../tests/code_review/lcov.sh
   ```

2. Coverage results will be saved in the `tests/caverage_info/coverage` directory, and the coverage information can be viewed using a browser.

### Unit Testing

Unit tests for the calculator are located in the `tests/gtest` directory. To execute the tests, follow these steps:

1. Run the unit tests:
   ```bash
   ./utest_evaluate
   ```

## Troubleshooting

- If you encounter file descriptor limits during `valgrind` profiling, increase the limit with:
  ```bash
  ulimit -n 4096
  ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Цей README включає основні кроки по збірці, профілюванню, аналізу коду і тестуванню, включаючи опис папки `tests`.
