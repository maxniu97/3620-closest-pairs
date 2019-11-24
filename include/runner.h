/**
 * @author max niu , matthew wilbern
 * @date Nov 22, 2019
 * @copyright 2019
*/

#include <iostream>
#include <chrono>
#include <string>
#include <vector>

#include "point.h"

class runner {
 public:
  static void run(std::string funcName, double (*f)(std::vector<point>), std::vector<point> points) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string tp = "microseconds";

    double a = f(points);

    std::cout << "Closest pair of points are " << a << " units apart.\n";

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();


    long long t2 = microseconds;
    if (t2 > 1000000) {
      tp = "seconds";
      t2 = t2 / 1000000;
    }
    if (tp == "seconds" && t2 > 60) {
      tp = "minutes";
      t2 = t2 / 60;
    }


    std::cout << funcName << " time elapsed: " << microseconds << " microseconds (" << t2 << " " << tp << ")\n";
  }

  static void run2(std::string funcName, double (*f)(std::vector<point>), std::vector<point> *points) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string tp = "microseconds";

    double a = f(*points);

    std::cout << "Closest pair of points are " << a << " units apart.\n";

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();


    long long t2 = microseconds;
    if (t2 > 1000000) {
      tp = "seconds";
      t2 = t2 / 1000000;
    }
    if (tp == "seconds" && t2 > 60) {
      tp = "minutes";
      t2 = t2 / 60;
    }


    std::cout << funcName << " time elapsed: " << microseconds << " microseconds (" << t2 << " " << tp << ")\n";
  }
};

