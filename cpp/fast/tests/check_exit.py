# SPDX-FileCopyrightText: Copyright (c) 2026 Objectionary
# SPDX-License-Identifier: MIT

"""Exercise error exit statuses of the built fast CLI."""

from pathlib import Path
import subprocess

executable = str(Path(__file__).resolve().parents[1] / 'fast_life')
defaults = ['--size', '3x3', '--put', '1x1', '--batch', '0', '--sleep', '0']
for option, value, message in [
    ('--size', '0x3', 'Incorrect arguments in size option'),
    ('--put', '4x1', 'You entered cells out of range'),
    ('--put', 'invalid', 'You entered incorrect arguments in put option'),
    ('--batch', '-1', 'Incorrect batch option value'),
    ('--sleep', '-1', 'Incorrect sleep option value'),
]:
    arguments = defaults.copy()
    arguments[arguments.index(option) + 1] = value
    result = subprocess.run([executable, *arguments], capture_output=True, text=True, timeout=5)
    assert result.returncode != 0, (arguments, result)
    assert message in result.stderr and not result.stdout, (arguments, result)
for arguments in [defaults, ['--help']]:
    result = subprocess.run([executable, *arguments], capture_output=True, text=True, timeout=5)
    assert result.returncode == 0 and not result.stderr, (arguments, result)
