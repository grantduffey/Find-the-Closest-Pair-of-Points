// Grant Duffey
// CPSC 2120-3
// Lab 03
// Dean
#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Grid {

  private:
    struct Node {
      double x;
      double y;
      Node *next;
      Node(double xcord, double ycord, Node *n) { x = xcord; y = ycord; next = n; }
    };

    Node ***grid;
    int size;

  public:
    Grid();
    ~Grid();
    void read();
    double compare();
    double calculate(Node *, Node *);
};

#endif
