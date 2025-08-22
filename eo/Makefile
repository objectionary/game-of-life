# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

.PHONY: compile dataize test clean

all: compile

compile:
	eoc compile life.eo

dataize:
	eoc dataize life cycle 0

clean:
	rm -rf .eoc/
