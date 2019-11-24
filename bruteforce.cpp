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

#include "runner.h"
#include "reader.h"
#include "point.h"

using namespace std;

double dist(point p1, point p2) {
  return sqrt(pow(p1.x - p2.x, 2) +  pow(p1.y - p2.y, 2) * 1.0);
}

double bruteForce(vector<point> p) {
  double dmin = 10000;
  point p1, p2;
  int n = p.size();

  for(int i = 0; i< n; i++)
    for (int j =i+1; j< n; j++)
      if(dist(p.at(i),p.at(j))<dmin) {
        dmin = dist(p.at(i),p.at(j));
        p1 = p.at(i);
        p2 = p.at(j);
      }

  cout << "Closest points at: \n"
       << "1:\n"
       << "  x: " << p1.x << endl
       << "  y: " << p1.y << endl
       << "2:\n"
       << "  x: " << p2.x << endl
       << "  y: " << p2.y << endl;

  return dmin;
}

int main() {
  vector<point> p;

  int num = reader::getUserInputInt("How many points should be read?");
  string file = "output/output" + to_string(num) + ".txt";

  try {
    p = reader::readFile(file);
    if (p.size() != num)
      throw "Got the wrong amount of points returned. (" + to_string(p.size()) + ")";

    runner::run("test", bruteForce, p);
  } catch (const char* err) {
    cout << "A problem occurred while attempting to read " << file << ".\n";
    cout << "error: " << err << "\n";
  } catch (const string err) {
    cout << "A problem occurred while attempting to read " << file << ".\n";
    cout << "error: " << err << "\n";
  }
}
