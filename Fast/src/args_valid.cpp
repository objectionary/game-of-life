// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/args_valid.h"

#include "../include/args_check.h"
#include "../include/args_process.h"

bool Valid::is_valid(string const &str) {
  if (Check::has_x(str)) {
    return Check::is_d(Process::split(str));
  }
  return false;
}
