// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/parse.h"

#include <boost/program_options/variables_map.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

using boost::program_options::variables_map;
using std::cout;
using std::stoi;

int Parse::length() const { return numberN; }

int Parse::width() const { return numberM; }

vector<pair<int, int>> Parse::grid() { return points; }

variables_map Parse::opts() { return vm; }

bool Parse::has(const string &str, char val) {
  return str.find(val) < str.length() - 1 && str.find(val) > 0;
}

pair<int, int> Parse::split(const string &str) {
  const int pos = static_cast<int>(str.find('x'));
  const int left = stoi(str.substr(0, pos));
  const int right = stoi(str.substr(pos + 1, str.length()));
  return {left, right};
}

bool Parse::valid(string const &str) {
  const pair<int, int> val = split(str);
  return val.first > 0 && val.second > 0;
}

pair<int, int> Parse::point(const string &str) const {
  if (has(str, 'x') && valid(str)) {
    auto res = split(str);
    if (res.first > numberN || res.second > numberM) {
      cout << "Incorrect input in put";
      exit(0);  // NOLINT(concurrency-mt-unsafe)
    }
    return res;
  }
  cout << "Incorrect input in put";
  exit(0);  // NOLINT(concurrency-mt-unsafe)
}

pair<int, int> Parse::size(const string &str) {
  if (has(str, 'x') && valid(str)) {
    return split(str);
  }
  cout << "Incorrect input in size";
  exit(0);  // NOLINT(concurrency-mt-unsafe)
}

void Parse::positive() {
  if (vm["batch"].as<int>() <= 0) {
    cout << "Incorrect batch input" << "\n";
    exit(0);  // NOLINT(concurrency-mt-unsafe)
  }
  if (vm["sleep"].as<int>() <= 0) {
    cout << "Incorrect sleep input" << "\n";
    exit(0);  // NOLINT(concurrency-mt-unsafe)
  }
}

vector<pair<int, int>> Parse::rec_cells(int pos, vector<pair<int, int>> rec) {
  vector<string> strs = vm["put"].as<vector<string>>();
  if (pos == strs.size()) {
    return rec;
  }
  const pair<int, int> add = point(strs[pos]);
  vector<pair<int, int>> recs(rec.size() + 1);
  boost::copy(rec, recs.begin());
  recs[rec.size()] = add;
  return rec_cells(pos + 1, recs);
}

void Parse::cells() {
  const vector<pair<int, int>> free;
  points = rec_cells(0, free);
}

void Parse::build() {
  positive();
  const pair<int, int> data = size(vm["size"].as<string>());
  numberN = data.first;
  numberM = data.second;
  cells();
}
