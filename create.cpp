/**
 * @author max niu , matthew wilbern
 * @date Nov 22, 2019
 * @copyright 2019
*/

#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <cstdlib>

#include "reader.h"


using namespace std;
int main (int argc, char* argv[]) {
  int num;

  ofstream myfile;


  //num = reader::getUserInputInt("Input number of points:");
  num = atoi(argv[1]);
  string file = "output/" + string(argv[2]) + to_string(num) + ".txt";

  myfile.open(file);
  random_device x;
  random_device y;
  uniform_int_distribution<int> dist(-10000,10000);
  for(int i = 0; i<num; i++) {
    cout<<dist(x)<<"   "<<dist(y)<<endl;

    myfile<<dist(x)<<"   "<<dist(y);
    if (i != num - 1)
      myfile << endl;
  }
  myfile.close();
  return 0;
}

