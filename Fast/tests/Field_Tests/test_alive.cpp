// Copyright (c) 2022 Anton Shatokhin

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <boost/test/unit_test.hpp>

#include "../../include/arg_parse.h"
#include "../../include/field.h"
#include "../../include/grid.h"
#include "../../include/size.h"

void checker(const vector<string>& check, const set<pair<int, int>>& res, int n, int m,
  const string& test_case) {
  Parse p = Parse();
  vector<pair<int, int>> put = Parse::get_alive(check, n, m);
  Size sz = Size(n, m);
  Field f = Field(sz);
  f.read_and_set(put);
  Grid g = Grid(sz, f);
  g.nextGen();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g.g.f[i][j].getCurState()) {
        if (res.count({i + 1, j + 1}) == 0u) {
          BOOST_FAIL("should be  {" << i + 1 << "," << j + 1
                                    << "}, but not in test case " << test_case);
        }
        cnt++;
      }
    }
  }
  if (cnt != res.size()) {
    BOOST_FAIL("should be " << res.size() << " number of points, but get "
                            << cnt << " in test case " << test_case);
  }
}

BOOST_AUTO_TEST_CASE(test_next_gen) {
  int n = 20;
  int m = 20;
  vector<string> check1 = {"2x3", "2x4", "3x2", "3x3", "3x4", "3x5"};
  set<pair<int, int>> res1({{3, 2}, {3, 5}, {4, 3}, {4, 4}, {2, 2}, {2, 5}});
  checker(check1, res1, n, m, "first");
  vector<string> check2 = {
    "2x2", "2x3", "2x4", "3x2", "3x4", "4x2", "4x4", "5x3"};
  set<pair<int, int>> res2({{1, 3}, {2, 2}, {2, 4}, {3, 1}, {3, 2}, {3, 4},
    {3, 5}, {4, 2}, {4, 4}, {5, 3}});
  checker(check2, res2, n, m, "second");
  vector<string> check3 = {
    "1x1", "1x2", "1x3", "1x4", "1x5", "2x2", "2x3", "3x2", "3x3", "4x3"};
  set<pair<int, int>> res3({{1, 1}, {1, 4}, {3, 4}, {4, 2}, {4, 3}});
  checker(check3, res3, n, m, "third");
}