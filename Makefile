# SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
# SPDX-License-Identifier: MIT

FAST_SOURCES := $(wildcard Fast/src/*.cpp)
FAST_HEADERS := $(wildcard Fast/**/*.h)
FAST_OBJECTS := ${FAST_SOURCES:.cpp=.o}

FAST_TEST_SOURCES := $(filter-out Fast/src/main.cpp, $(shell find Fast/  -type f -name *.cpp))

FAST_TEST_OBJECTS := ${FAST_TEST_SOURCES:.cpp=.o}

all: style slow fast eo-compile

slow: slow_life slow_test

fast: fast_life fast_test

fast_life: $(FAST_OBJECTS)
	@g++ $(FAST_OBJECTS) -lboost_program_options -o fast_life

fast_test: $(FAST_TEST_OBJECTS)
	@g++ $(FAST_TEST_OBJECTS) -lboost_unit_test_framework -o fast_test
	./fast_test --log_level=all

%.o: Fast/**/%.cpp  $(FAST_HEADERS)
	@g++ $@ -o $<

SLOW_SOURCES := $(wildcard Slow/src/*.cpp)
SLOW_HEADERS := $(wildcard Slow/**/*.h)
SLOW_OBJECTS := ${SLOW_SOURCES:.cpp=.o}
SLOW_TEST_SOURCES := $(filter-out Slow/src/main.cpp, $(shell find Slow/  -type f -name *.cpp))
SLOW_TEST_OBJECTS := ${SLOW_TEST_SOURCES:.cpp=.o}

slow_life: $(SLOW_OBJECTS)
	g++ $(SLOW_OBJECTS) -lboost_program_options -o slow_life

slow_test: $(SLOW_TEST_OBJECTS)
	g++ $(SLOW_TEST_OBJECTS) -lboost_unit_test_framework -lboost_program_options -o slow_test
	./slow_test --log_level=all

%.o:  Slow/**/%.cpp  $(SLOW_HEADERS)
	g++ $@ -o $<


ALL_SOURCES := $(SLOW_SOURCES) $(FAST_SOURCES)
ALL_HEADERS := $(FAST_HEADERS) $(SLOW_HEADERS)
style:
	bash -c "diff -u <(cat $(ALL_SOURCES)) <(clang-format --style=file $(ALL_SOURCES))"
	clang-tidy -header-filter=none '-warnings-as-errors=*' '-checks=*,-readability-magic-numbers,-altera-id-dependent-backward-branch,-cert-err34-c,-cppcoreguidelines-avoid-non-const-global-variables,-readability-function-cognitive-complexity,-misc-no-recursion,-llvm-header-guard,-cppcoreguidelines-init-variables,-altera-unroll-loops,-clang-analyzer-valist.Uninitialized,-llvmlibc-callee-namespace,-cppcoreguidelines-no-malloc,-hicpp-no-malloc,-llvmlibc-implementation-in-namespace,-bugprone-easily-swappable-parameters,-llvmlibc-restrict-system-libc-headers,-llvm-include-order,-modernize-use-trailing-return-type,-cppcoreguidelines-special-member-functions,-hicpp-special-member-functions,-cppcoreguidelines-owning-memory,-cppcoreguidelines-pro-type-vararg,-hicpp-vararg,-fuchsia-default-arguments-calls' $(ALL_SOURCES)

fix:
	clang-format -i --style=file $(ALL_SOURCES) $(ALL_HEADERS)
	clang-tidy -fix -header-filter=none '-warnings-as-errors=*' '-checks=*,-readability-magic-numbers,-altera-id-dependent-backward-branch,-cert-err34-c,-cppcoreguidelines-avoid-non-const-global-variables,-readability-function-cognitive-complexity,-misc-no-recursion,-llvm-header-guard,-cppcoreguidelines-init-variables,-altera-unroll-loops,-clang-analyzer-valist.Uninitialized,-llvmlibc-callee-namespace,-cppcoreguidelines-no-malloc,-hicpp-no-malloc,-llvmlibc-implementation-in-namespace,-bugprone-easily-swappable-parameters,-llvmlibc-restrict-system-libc-headers,-llvm-include-order,-modernize-use-trailing-return-type,-cppcoreguidelines-special-member-functions,-hicpp-special-member-functions,-cppcoreguidelines-owning-memory,-cppcoreguidelines-pro-type-vararg,-hicpp-vararg,-fuchsia-default-arguments-calls' $(ALL_SOURCES)

eo-compile:
	eoc dataize life cycle 0

clean:
	rm -f **/src/*.o
	rm -f **/tests/**/*.o
	rm -f *_life
	rm -f *_test
	rm -fr .eoc/
