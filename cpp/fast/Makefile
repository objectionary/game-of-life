# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

SOURCES := $(wildcard src/*.cpp)
HEADERS := $(wildcard include/*.h src/*.h)
OBJECTS := ${SOURCES:.cpp=.o}

LIB_SOURCES := $(filter-out src/main.cpp, $(SOURCES))
LIB_OBJECTS := ${LIB_SOURCES:.cpp=.o}

TEST_SOURCES := $(shell find tests -type f -name "*.cpp" 2>/dev/null || true)
TEST_OBJECTS := ${TEST_SOURCES:.cpp=.o}

.PHONY: all build test clean

all: build

build: $(OBJECTS)
	g++ $(OBJECTS) -lboost_program_options -o fast_life

test: $(LIB_OBJECTS) $(TEST_OBJECTS)
	g++ $(LIB_OBJECTS) $(TEST_OBJECTS) -lboost_unit_test_framework -lboost_program_options -o fast_test
	./fast_test --log_level=all

%.o: %.cpp $(HEADERS)
	g++ -c -Iinclude $< -o $@

clean:
	rm -f src/*.o tests/**/*.o
	rm -f fast_life fast_test
