# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

# @todo #72:30min Drop the --blind option and lint the sources again, once
#  the lints that EO 0.63.2 applies stop failing on the standard objects
#  pulled from objectionary/home, see objectionary/eo#9110 and #9115.
EO := eoc --parser 0.63.2 --home-tag 0.63.2 --blind --no-color --batch

.PHONY: build test clean

all: build

build:
	$(EO) dataize conway.life cycle 0

test:
	$(EO) test

clean:
	rm -rf .eoc/
