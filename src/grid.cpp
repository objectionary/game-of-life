#include "../include/grid.h"
#include "../include/cell.h"
#include "../include/outputs.h"

int Grid::count(int x, int y) {
  int cnt = 0;
  for (int i = x - 1; i <= x + 1; ++i) {
    for (int j = y - 1; j <= y + 1; ++j) {
      if (i < 0 || i > size - 1 || j < 0 || j > size - 1)
        continue;
      cnt += g[i][j].getCurState();
    }
  }
  return cnt;
}

Grid::Grid() {

  int sz;
  getSize();

  cin >> sz;
  size = sz;
  g.resize(sz);
  for (int i = 0; i < sz; ++i) {
    g[i].resize(sz);
  }
  system("cls");
}

void Grid::printGrid() {
  int sz = size;
  for (int i = 0; i < sz * 2 + 5; ++i) {
    cout << "-";
  }
  cout << endl;
  for (int i = 0; i < sz; ++i) {
    cout << "|  ";
    for (int j = 0; j < sz; ++j) {
      if (g[i][j].getCurState()) {
        cout << "o ";
      } else {
        cout << ". ";
      }
    }
    cout << " |" << endl;
  }
  for (int i = 0; i < sz * 2 + 5; ++i) {
    cout << "-";
  }
  cout << endl;
}

void Grid::Set() {
  int n;

  askCords(size);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x][y].setState(true);
  }
  system("cls");
}

void Grid::nextGen() {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      int cnt = count(i, j) - g[i][j].getCurState();
      if (g[i][j].getCurState()) {
        g[i][j].changeNewState(cnt == 2 || cnt == 3);
      } else {
        g[i][j].changeNewState(cnt == 3);
      }
    }
  }
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      g[i][j].changeCurState();
    }
  }
}
