/**
 * @author max niu , matthew wilbern
 * @date Nov 22, 2019
 * @copyright 2019
*/

#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <tuple>

#include "runner.h"
#include "reader.h"
#include "point.h"

using namespace std;

double dist(point p1, point p2) {
  return sqrt(pow(p1.x - p2.x, 2) +  pow(p1.y - p2.y, 2) * 1.0);
}

tuple<double, point, point> bruteForce(vector<point> p) {
  double dmin = 10000;
  int n = p.size();

  point px, py;

  for(int i = 0; i< n; i++)
    for (int j =i+1; j< n; j++)
      if(dist(p.at(i),p.at(j))<dmin) {
        dmin = dist(p.at(i),p.at(j));
        px = p.at(i);
        py = p.at(j);
      }

  return tuple<double, point, point>(dmin, px, py);
}

int main(int argc, char* argv[]) {
  vector<point> p;

  //int num = reader::getUserInputInt("How many points should be read?");

  int num = atoi(argv[1]);

  string file = "output/" + string(argv[2]) + to_string(num) + ".txt";

  try {
    p = reader::readFile(file);
    if (p.size() != num)
      throw "Got the wrong amount of points returned. (" + to_string(p.size()) + ")";

    runner::run("Brute Force", bruteForce, p);
  } catch (const char* err) {
    cout << "A problem occurred while attempting to read " << file << ".\n";
    cout << "error: " << err << "\n";
  } catch (const string err) {
    cout << "A problem occurred while attempting to read " << file << ".\n";
    cout << "error: " << err << "\n";
  }
}
