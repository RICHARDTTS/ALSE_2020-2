#include <iostream>
#include <math.h>
#include "complex.h"

using namespace std;

complex complex::operator-( complex b ){
  complex w(0,0);
  w.re = re - b.re;
  w.im = im - b.im;
  return w;
}

complex complex::operator+( complex q){
  complex r;
  r.re = re + q.re;
  r.im = im + q.im;
  return r;
}

complex::complex(double r, double i){
  re = r;
  im = i;
}

std::ostream& operator<<(std::ostream& out, complex a){
  out << a.re << (a.im >=0 ? " + ":" - ") << abs(a.im) << "i";
}
