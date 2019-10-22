// Grant Duffey
// CPSC 2120-3
// Lab 03
// Dean
#include "points.h"

using namespace std;


int main(void) {

  Grid g;
  g.read();
  cout << "The shortest distance between two points is "<< g.compare() << endl;

  return 0;
}
