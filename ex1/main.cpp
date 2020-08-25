#include <iostream>
#include "complex.h"


using namespace std;
/*
ostream& operator<<(ostream& out, complex m){
  out << m.re << (m.im >= 0 ? " + ":" " ) << m.im << "i " ;
}
*/

int main(){
  complex a(45., 56.), b(45., -56.), c(0,0);

  complex d =  c + b;

  d = c - a;
  cout << c << endl;

  cout << d << endl;

return 0;
}

