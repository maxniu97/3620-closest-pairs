#ifndef POINT_H

#define POINT_H
class point {
 public:
  static bool compareX(p1, p2) {
    return p1.x < p2.x;
  }
  static bool compareY(p1, p2) {
    return p1.y < p2.y;
  }
  int x;
  int y;
};

#endif // POINT_H
