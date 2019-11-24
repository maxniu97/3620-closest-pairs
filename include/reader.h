#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <limits>
#include <exception>

#include "point.h"

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

    std::ifstream in(fileLoc);

    if (in.fail())
      throw "File " + fileLoc + " does not exist.";

    while (!in.eof()) {
      int x;
      in >> x;
      if (in.fail())
        break;
      int y;
      if (in.fail())
        break;
      in >> y;

      point p;
      p.x = x;
      p.y = y;

      out.push_back(p);
    }

    in.close();

    return out;
  }
};
