# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

EO := eoc --parser 0.61.3 --home-tag 0.61.3 --no-color --batch

.PHONY: build test clean

all: build

build:
	$(EO) dataize conway.life cycle 0

test:
	$(EO) test

clean:
	rm -rf .eoc/
