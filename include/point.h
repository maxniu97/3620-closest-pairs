/**
 * @author max niu , matthew wilbern
 * @date Nov 22, 2019
 * @copyright 2019
*/

#ifndef POINT_H

#define POINT_H

#include <string>

class point {
 public:
  static bool compareX(point p1, point p2) {
    return p1.x < p2.x;
  }
  static bool compareY(point p1, point p2) {
    return p1.y < p2.y;
  }
  std::string to_string() {
    return "{x=" + std::to_string(x) + ",y=" + std::to_string(y) + "}";
  }
  int x;
  int y;
};

#endif // POINT_H
