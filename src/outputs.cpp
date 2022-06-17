#include "config.cpp"
#pragma once
class Outputs {
protected:
    static void getSize() {
        cout << "Input the size of the square grid: ";
    }

protected:
    static void askCords(int sz) {
        cout << "Enter the number of coordinates and coordinates of the beginning cells (numbers from 1 to " << sz
             << ")" << "\n";
    }
};
