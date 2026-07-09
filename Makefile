# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

ALL_SOURCES := $(wildcard cpp/*/src/*.cpp)
ALL_HEADERS := $(wildcard cpp/*/include/*.h cpp/*/src/*.h)

CLANG_FORMAT ?= clang-format
CLANG_TIDY ?= clang-tidy

TIDY_CHECKS := *,-readability-magic-numbers,-altera-id-dependent-backward-branch,-cert-err34-c,-cppcoreguidelines-avoid-non-const-global-variables,-readability-function-cognitive-complexity,-misc-no-recursion,-llvm-header-guard,-cppcoreguidelines-init-variables,-altera-unroll-loops,-clang-analyzer-valist.Uninitialized,-llvmlibc-callee-namespace,-cppcoreguidelines-no-malloc,-hicpp-no-malloc,-llvmlibc-implementation-in-namespace,-bugprone-easily-swappable-parameters,-llvmlibc-restrict-system-libc-headers,-llvm-include-order,-modernize-use-trailing-return-type,-cppcoreguidelines-special-member-functions,-hicpp-special-member-functions,-cppcoreguidelines-owning-memory,-cppcoreguidelines-pro-type-vararg,-hicpp-vararg,-fuchsia-default-arguments-calls,-cppcoreguidelines-pro-bounds-avoid-unchecked-container-access,-llvm-prefer-static-over-anonymous-namespace,-bugprone-exception-escape

.PHONY: all style fast fast-test slow slow-test eo clean fix test

all: style fast slow eo

fast:
	$(MAKE) -C cpp/fast

fast-test:
	$(MAKE) -C cpp/fast test

slow:
	$(MAKE) -C cpp/slow

slow-test:
	$(MAKE) -C cpp/slow test

eo:
	$(MAKE) -C eo

style:
	bash -c "diff -u <(cat $(ALL_SOURCES)) <($(CLANG_FORMAT) --style=file $(ALL_SOURCES))"
	$(CLANG_TIDY) -header-filter=none '-warnings-as-errors=*' '-checks=$(TIDY_CHECKS)' $(ALL_SOURCES)

fix:
	$(CLANG_FORMAT) -i --style=file $(ALL_SOURCES) $(ALL_HEADERS)
	$(CLANG_TIDY) -fix -header-filter=none '-warnings-as-errors=*' '-checks=$(TIDY_CHECKS)' $(ALL_SOURCES)

clean:
	$(MAKE) -C eo clean
	$(MAKE) -C cpp/fast clean
	$(MAKE) -C cpp/slow clean
