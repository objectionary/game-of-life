# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

SOURCES := $(wildcard src/*.cpp)
HEADERS := $(wildcard include/*.h src/*.h)
OBJECTS := ${SOURCES:.cpp=.o}

TEST_SOURCES := $(filter-out src/main.cpp, $(shell find . -type f -name *.cpp))
TEST_OBJECTS := ${TEST_SOURCES:.cpp=.o}

.PHONY: all slow_life slow_test test clean

all: slow_life slow_test

slow_life: $(OBJECTS)
	g++ $(OBJECTS) -lboost_program_options -o slow_life

slow_test: $(TEST_OBJECTS)
	g++ $(TEST_OBJECTS) -lboost_unit_test_framework -lboost_program_options -o slow_test
	./slow_test --log_level=all

test: slow_test

%.o: %.cpp $(HEADERS)
	g++ -c -Iinclude $< -o $@

clean:
	rm -f src/*.o tests/*.o
	rm -f slow_life slow_test
