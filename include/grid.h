
#ifndef LIFE_GRID_H
#define LIFE_GRID_H

#include "../include/cell.h"
#include "../include/config.h"
#include "../include/outputs.h"

class Grid : public Outputs {

public:
  int size;
  vector<vector<Cell>> g;

  int count(int x, int y);

  Grid();

  void printGrid();

  void Set();

  void nextGen();
};

#endif // LIFE_GRID_H
