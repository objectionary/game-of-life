# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

SOURCES := $(wildcard src/*.cpp)
HEADERS := $(wildcard include/*.h src/*.h)
OBJECTS := ${SOURCES:.cpp=.o}

TEST_SOURCES := $(filter-out src/main.cpp, $(shell find . -type f -name *.cpp))
TEST_OBJECTS := ${TEST_SOURCES:.cpp=.o}

.PHONY: all fast_life fast_test clean

all: fast_life fast_test

fast_life: $(OBJECTS)
	g++ $(OBJECTS) -lboost_program_options -o fast_life

fast_test: $(TEST_OBJECTS)
	g++ $(TEST_OBJECTS) -lboost_unit_test_framework -o fast_test
	./fast_test --log_level=all

%.o: %.cpp $(HEADERS)
	g++ -c -Iinclude $< -o $@

clean:
	rm -f src/*.o tests/*.o
	rm -f fast_life fast_test
