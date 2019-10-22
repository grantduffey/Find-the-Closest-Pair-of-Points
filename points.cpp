// Grant Duffey
// CPSC 2120-3
// Lab 03
// Dean
#include "points.h"

Grid::Grid() {

  // I chose this size as a result of trial and error. I tried numbers between
  // 700 and 2500, and this was the fastest size that I tested.
  size = 1200;
  grid = new Node **[size];
  for (int i = 0; i < size; ++i) {
    grid[i] = new Node *[size];
  }
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      grid[i][j] = NULL;
    }
  }

}

Grid::~Grid() {

  Node * temp = NULL;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      while (grid[i][j] != NULL) {
        temp = grid[i][j]->next;
        delete grid[i][j];
        grid[i][j] = temp;
      }
    }
  }
  for (int i = 0; i < size; ++i) {
      delete [] grid[i];
  }
  delete [] grid;
}

void Grid::read() {

  ifstream data;
  data.open("points.txt");
  double x, y = 0.0;
  int xcord, ycord = 0;
  while (data >> x >> y) {
    // multiply x and y by the size and then cast x and y to ints to hash
    // its coordinate to the correct unit in the grid
    xcord = (int)(x * size);
    ycord = (int)(y * size);
    grid[xcord][ycord] = new Node (x, y, grid[xcord][ycord]);
  }
  data.close();
}

double Grid::compare() {

  double dist = 0.0;
  double tempdist = 0.0;

  // The first two for loops iterate through the grid to find the first point of comparison,
  // then the next for loop iterates through its'linked list. The next two for loops
  // iterate around the point found in the first two for loops, and the final for loop iterates through
  // those linked lists to compare them to the linked list found before.

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      for (Node * current = grid[i][j]; current != NULL; current = current->next) {
        for (int a = (i - 1); a < (i + 1); ++a) {
          for (int b = (j - 1); b < (j + 1); ++b) {
            if (a >= 0 && b >= 0 && a < size && b < size) {
              for (Node * temp = grid[a][b]; temp != NULL; temp = temp->next) {
                if (current != temp) {
                  tempdist = calculate(current, temp);
                  if (tempdist < dist || dist == 0) {
                    dist = tempdist;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  dist = sqrt(dist);
  return dist;
}

double Grid::calculate(Node * p1, Node * p2) {

  double dist = ((pow((p1->x - p2->x),2))+pow((p1->y - p2->y),2));
  return dist;

}
