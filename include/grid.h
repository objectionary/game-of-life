
#ifndef LIFE_GRID_H
#define LIFE_GRID_H

#include "../include/outputs.h"
#include "../include/cell.h"
#include "../include/config.h"
class Grid : public Outputs
{

public:
    int size;
    vector<vector<Cell>> g;
    fstream my_file;

    void close();

    int count(int x, int y);

    Grid(string filename);

    void printGrid();
    void Set(string filename); 
    void nextGen();
};

#endif //LIFE_GRID_H
