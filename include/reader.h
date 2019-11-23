#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <limits>

#ifndef point
  #include "point.h"
#endif // point

void writeInfo(std::string info) {
  std::cout << info;
}

class reader {
 public:
  static int getUserInputInt(std::string question) {
    writeInfo(question + "\n> ");
    int tmp;
    std::cin >> tmp;
    while (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      writeInfo("error try again\n");
      writeInfo("> ");
      std::cin >> tmp;
    }
    return tmp;
  }

  static std::vector<point> readFile(std::string fileLoc) {
    std::vector<point> out;
    // todo: implement

    return out;
  }
};
