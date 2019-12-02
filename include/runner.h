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

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();



    std::cout << microseconds << " " << a;
  }

  static void run2(std::string funcName, double (*f)(std::vector<point>), std::vector<point> *points) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string tp = "microseconds";

    double a = f(*points);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout << microseconds << " " << a;
  }
};

