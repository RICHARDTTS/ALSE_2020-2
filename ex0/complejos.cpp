#include <iostream>

using namespace std;

struct complex{
  double re;
  double im;
};

complex operator-(complex x, complex y){
  complex w;
  w.re = x.re - y.re;
  w.im = x.im - y.im;
  return w;
}

complex operator+(complex p, complex q){
  complex r;
  r.re = p.re + q.re;
  r.im = p.im + q.im;
  return r;
}


ostream& operator<<(ostream& out, complex m){
  out << m.re << (m.im >= 0 ? " + ":" " ) << m.im << "i " ;
}


int main(){
  complex a, b, c;
  a.re = 45.;
  a.im = 56.;

  b.re = 45.;
  b.im = -56.;

  c.re = a.re + b.re;
  c.im = a.im + b.im;
  
  complex d =  c + b;

  d = c - a;
  cout << c << endl;

  cout << d << endl;

return 0;
}

