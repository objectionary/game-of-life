# John Conway's Game of Life — build & test commands
# Run `just` without arguments to see this list.

cxx_srces := "cpp/fast/src/*.cpp cpp/fast/include/*.h cpp/fast/tests/**/*.cpp cpp/slow/src/*.cpp cpp/slow/include/*.h cpp/slow/tests/**/*.cpp"

default:
    @just --list

# Build both fast and slow binaries
build: fast-life slow-life

# Build the fast version (OOP, mutable objects)
fast-life:
    cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
    cmake --build build --target fast_life

# Build the slow version (immutable objects, recursion)
slow-life:
    cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
    cmake --build build --target slow_life

# Run all tests
test: test-fast-life test-slow-life

# Build and run fast version tests
test-fast-life:
    cmake -B build -S .
    cmake --build build --target fast_test
    ctest --test-dir build -R fast_test --output-on-failure

# Build and run slow version tests
test-slow-life:
    cmake -B build -S .
    cmake --build build --target slow_test
    ctest --test-dir build -R slow_test --output-on-failure

# Check formatting (dry-run, fails on violations)
style:
    clang-format --style=file --dry-run -Werror {{ cxx_srces }}

# Auto-format all source files
fmt:
    clang-format -i --style=file {{ cxx_srces }}

# Build EO (Elegant Objects) version
eo:
    @make -C eo

# Remove build artifacts
clean:
    rm -rf build
    @make -C eo clean
