/**
 * @author max niu , matthew wilbern
 * @date Nov 22, 2019
 * @copyright 2019
*/

#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <tuple>

#include "point.h"

class runner {
 public:
  static void run(std::string funcName, std::tuple<double, point, point> (*f)(std::vector<point>), std::vector<point> points) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string tp = "microseconds";

    std::tuple<double, point, point> a = f(points);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();



    std::cout << microseconds << " " << std::get<0>(a) << " " << std::get<1>(a).to_string() << " " << std::get<2>(a).to_string();
  }

  static void run2(std::string funcName, std::tuple<double, point, point> (*f)(std::vector<point>), std::vector<point> *points) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string tp = "microseconds";

    std::tuple<double, point, point> a = f(*points);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout << microseconds << " " << std::get<0>(a) << " " << std::get<1>(a).to_string() << " " << std::get<2>(a).to_string();
  }
};

