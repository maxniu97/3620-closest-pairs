/**
 * @author max niu , matthew wilbern
 * @date Nov 22, 2019
 * @copyright 2019
 */
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>

#include "point.h"
#include "runner.h"
#include "reader.h"
using namespace std;

double dist(point p1, point p2) {
  return sqrt(pow(p1.x - p2.x, 2) +  pow(p1.y - p2.y, 2) * 1.0);
}

double bruteForce(vector<point> p) {
  double dmin = 10000;
  int n = p.size();

  for(int i = 0; i< n; i++)
    for (int j =i+1; j< n; j++)
      if(dist(p.at(i),p.at(j))<dmin)
        dmin = dist(p.at(i),p.at(j));
  return dmin;
}

int main() {
  vector<point> p;

  p = reader::readFile("")

  runner::run("test", bruteForce, p);
}
