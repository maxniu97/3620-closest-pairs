#include <chrono>



class runner {
 public:
  static void run(std::string funcName, double (*f)(std::vector<point>), std::vector<point> points) {
    auto start = std::chrono::high_resolution_clock::now();

    f(points);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout << funcName << " time elapsed: " << microseconds << "\n";
  }
};
