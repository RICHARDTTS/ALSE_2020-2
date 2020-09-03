#include <iostream>
#include <cmath>
#include <limits>
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

bool complex::operator<(complex &a){
  if ( angle() == a.angle() )
    return (magnitude() < ( a.magnitude() + 2 * std::numeric_limits<double>::epsilon() ) );
  else
    return angle() < ( a.angle() + 2 * numeric_limits<double>::epsilon() );
}

bool complex::operator==(complex &a){
  return (re == a.re && im == a.im);
}

double complex::angle(){
  return atan2(im, re) + M_PI;
}

double complex::magnitude(){
  return sqrt(re*re + im*im);
}

void complex::set(double a, double b){
  re = a;
  im = b;
}

void complex::setRe(double a){
  re = a;
}

void complex::setIm(double a){
  im = a;
}

double complex::getRe(){
  return re;
}

double complex::getIm(){
  return im;
}
