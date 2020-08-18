#include <iostream>

using namespace std;

int main(){

  char c = 70;
  int a = 50;
  float b = 50.;
  double d = 50.;

  char *p = NULL;

  cout << "Char: " << c << endl;
  cout << "Int: " << a << endl;
  cout << "Float: " << b << endl;
  cout << "Double: " << d << endl;

  p = &c;
  cout <<  "Dirección de c: " << *p << endl;

//  p = &a;
//  cout << "Dirección de a: " << p << endl;

  return 0;
}

