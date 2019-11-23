/**
 * @author max niu , matthew wilbern
 * @date Nov 22, 2019
 * @copyright 2019
 */
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


struct point{
    int x;
    int y;};

double dist(point,point);
int main() {

}

double bruteForce(vector<point> p) {
   double dmin = 10000;
   int n = p.size();

    for(int i = 0; i< n; i++)
        for (int j =i+1; j< n; j++)
            if(dist(p.at(i),p.at(j))<dmin)
                dmin = dist(p.at(i),p.at(j));
    return dmin;
    }

double dist(point p1, point p2) {

    return sqrt(pow(p1.x - p2.x, 2) +  pow(p1.y - p2.y, 2) * 1.0);

}
