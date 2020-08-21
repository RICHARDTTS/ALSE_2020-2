#include <iostream>

using namespace std;

class complex{
  double re;
  double im;

public:
  complex(double r =0. , double i = 0.);
  complex operator+(complex b);
  complex operator-(complex b);
};


