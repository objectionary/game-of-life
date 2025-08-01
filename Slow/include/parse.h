// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef _OOP_PARSE_H_
#define _OOP_PARSE_H_

#include <boost/program_options.hpp>
#include <string>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::vector;

namespace po = boost::program_options;
class Parse {
private:
  int numberN = 100000;
  int numberM = 100000;
  vector<pair<int, int>> points;
  po::variables_map vm;

public:
  Parse() : Parse(nullptr) {}
  Parse(po::variables_map vmp) : vm(vmp) {}  // constructor

  int length() const;
  int width() const;
  vector<pair<int, int>> grid();
  po::variables_map opts();  // getters

  vector<pair<int, int>> rec_cells(int pos, vector<pair<int, int>> rec);
  static bool has(const string &str, char val);
  static bool valid(string const &s);
  pair<int, int> point(const string &s) const;
  static pair<int, int> size(const string &s);
  static pair<int, int> split(const string &s);
  void positive();
  void cells();
  void build();  // builders and checkers
};

#endif  //_OOP_PARSE_H_
