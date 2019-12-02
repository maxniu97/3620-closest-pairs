#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <tuple>

#include "point.h"
#include "reader.h"
#include "runner.h"

using namespace std;

void print(string out) {
  cout << out << "\n";
}


double dist(point p1, point p2) {
  return sqrt(pow(p1.x - p2.x, 2) +  pow(p1.y - p2.y, 2) * 1.0);
}

tuple<double, point, point> bruteForce(vector<point> *p) {
  double dmin = 10000;
  int n = p->size();

  point px, py;

  for(int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if(dist(p->at(i), p->at(j)) < dmin) {
        dmin = dist(p->at(i), p->at(j));
        px = p->at(i);
        py = p->at(j);
      }

  return tuple<double, point, point>(dmin, px, py);
}

tuple<double, point, point> yClosest(vector<point> *p, double d) {
  double minn = d; // initialize our min as d

  sort(p->begin(), p->end(), point::compareY);

  point px, py;

  // check if diff between y is smaller than d
  // inner loop only runs maximum 6 times (On time)
  for (int i = 0; i < p->size(); i++) {
    for (int j = i + 1; j < p->size() && (p->at(j).y - p->at(i).y) < minn; j++) {
      double diss = dist(p->at(i), p->at(j));
      if (diss < minn)
        minn = diss;
        px = p->at(i);
        py = p->at(j);
    }
  }
  return tuple<double, point, point>(minn, px, py);
}

tuple<double, point, point> _divideConquer(vector<point> *p) {
  size_t const mid = p->size() / 2;
  point midpoint = p->at(mid);

  point px, py;

  // If there are 2 or 3 points, then use brute force
  if (p->size() <= 3)
    return bruteForce(p);

  vector<point> lh(p->begin(), p->begin() + mid);
  vector<point> rh(p->begin() + mid + 1, p->end());\

  auto ldt = _divideConquer(&lh);
  auto rdt = _divideConquer(&rh);
  double ld = get<0>(ldt);
  double rd = get<0>(rdt);
  double d = min(ld, rd);

  vector<point> strip;
  int j = 0;
  for (int i = 0; i < p->size(); i++) {
    if (abs(p->at(i).x - midpoint.x) < d) {
      strip.push_back(p->at(i));
      j++;
    }
  }

  tuple<double, point, point> rt = yClosest(&strip, d);
  double r = get<0>(rt);
  double ret = min(d, r);

  // get the points that are closest
  if (ret == d) {
    if (ret == ld) { // if in left half
      px = get<1>(ldt);
      py = get<2>(ldt);
    } else { // if in right half
      px = get<1>(rdt);
      py = get<2>(rdt);
    }
  } else { // if in yClosest
    px = get<1>(rt);
    py = get<2>(rt);
  }

  return tuple<double, point, point>(ret, px, py);
}

tuple<double, point, point> divideConquer(vector<point> p) {
  sort(p.begin(), p.end(), point::compareX);

  return _divideConquer(&p);
}

int main(int argc, char* argv[]) {
  vector<point> p;

  //int num = reader::getUserInputInt("How many points should be read?");
  int num = atoi(argv[1]);
  string file = "output/" + string(argv[2])  + to_string(num) + ".txt";

  try {
    p = reader::readFile(file);
    if (p.size() != num)
      throw "Got the wrong amount of points returned. (" + to_string(p.size()) + ")";

    runner::run2("Divide Conquer", divideConquer, &p);
  } catch (const char* err) {
    cout << "A problem occurred while attempting to read " << file << ".\n";
    cout << "error: " << err << "\n";
  } catch (const string err) {
    cout << "A problem occurred while attempting to read " << file << ".\n";
    cout << "error: " << err << "\n";
  }
}
