#include "../include/outputs.h"

void Outputs::getSize() {
    cout << "Input the size of the square grid: ";
}

void Outputs::askCords(int sz) {
    cout << "Enter the number of coordinates and coordinates of the beginning cells (numbers from 1 to " << sz
         << ")" << "\n";
}
