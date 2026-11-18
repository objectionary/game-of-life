#!/usr/bin/env bash
# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

set -euo pipefail

for cycles in -1 -5; do
  if output=$("$@" dataize conway.life -- size 3x3 cycle "$cycles" 2>&1); then
    echo "Expected an error for cycle $cycles" >&2
    exit 1
  fi
  if ! grep -Fq "Cycle count must be non-negative" <<< "$output"; then
    echo "Expected a negative-cycle error for cycle $cycles" >&2
    echo "$output" >&2
    exit 1
  fi
done
