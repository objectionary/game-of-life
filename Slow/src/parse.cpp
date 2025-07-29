// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/parse.h"

int Parse::length() const { return n; }

int Parse::width() const { return m; }

vector<pair<int, int>> Parse::grid() { return points; }

po::variables_map Parse::opts() { return vm; }

bool Parse::has(const string &s, char c) {
  return s.find(c) < s.length() - 1 && s.find(c) > 0;
}

pair<int, int> Parse::split(const string &s) {
  int pos = s.find('x');
  int left = stoi(s.substr(0, pos));
  int right = stoi(s.substr(pos + 1, s.length()));
  return {left, right};
}

bool Parse::valid(string const &s) {
  pair<int, int> x = split(s);
  return x.first > 0 && x.second > 0;
}

pair<int, int> Parse::point(const string &s) const {
  if (has(s, 'x') && valid(s)) {
    auto res = split(s);
    if (res.first > n || res.second > m) {
      cout << "Incorrect input in put";
      exit(0);
    }
    return res;
  }
  cout << "Incorrect input in put";
  exit(0);
}

pair<int, int> Parse::size(const string &s) {
  if (has(s, 'x') && valid(s)) {
    return split(s);
  }
  cout << "Incorrect input in size";
  exit(0);
}

void Parse::positive() {
  if (vm["batch"].as<int>() <= 0) {
    cout << "Incorrect batch input" << endl;
    exit(0);
  }
  if (vm["sleep"].as<int>() <= 0) {
    cout << "Incorrect sleep input" << endl;
    exit(0);
  }
}

vector<pair<int, int>> Parse::rec_cells(int pos, vector<pair<int, int>> p) {
  vector<string> s = vm["put"].as<vector<string>>();
  if (pos == s.size()) {
    return p;
  }
  pair<int, int> add = point(s[pos]);
  vector<pair<int, int>> x(p.size() + 1);
  copy(p.begin(), p.end(), x.begin());
  x[p.size()] = add;
  return rec_cells(pos + 1, x);
}

void Parse::cells() {
  vector<pair<int, int>> free;
  points = rec_cells(0, free);
}

void Parse::build() {
  positive();
  pair<int, int> p = size(vm["size"].as<string>());
  n = p.first;
  m = p.second;
  cells();
}
