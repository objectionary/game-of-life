#!/usr/bin/env bash
# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

set -euo pipefail

for args in 'put' 'size 3x3 put' 'put 1x1 put'; do
  # Split each case into its command-line arguments.
  read -r -a options <<< "$args"
  if output=$("$@" dataize conway.life "${options[@]}" 2>&1); then
    echo "Expected an error for: $args" >&2
    exit 1
  fi
  if ! grep -Fq "Option 'put' requires a coordinate" <<< "$output"; then
    echo "Expected a missing-coordinate error for: $args" >&2
    echo "$output" >&2
    exit 1
  fi
done
