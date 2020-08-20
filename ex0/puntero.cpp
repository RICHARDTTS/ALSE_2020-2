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
  cout <<  "Dirección de c: " << (long) p << endl;

  p = (char*)&a;
  cout << "Dirección de a: " << (long) p << endl;

  p = (char*)&b;
  cout << "Dirección de b: " << (long) p << endl;

  p = (char*)&d;
  cout << "Dirección de d: " << (long) p << endl;

  p = (char*)&a;
  cout << "Dirección de p: " << (long)&p << endl;
  cout << "Contenido de p: " << (long) p << endl;

  cout << "Contenido de a donde apunta p: " << (int)*p << endl;
  cout << "Contenido del segundo byte de a: " << (int)*(++p) << endl;
  cout << "Contenido del tercer byte de a: " << (int)*(++p) << endl;
  cout << "Contenido del cuarto byte de a: " << (int)*(++p) << endl;


  // A partir de  esta línea se creará memoria dinámicamente 

  p = new char;
  *p = 71;
  cout << "Imprimiendo dirección nueva: " << (long)p << endl;
  cout << "Imprimiendo el contenido de esa memoria: "<< (int)*p << endl;

  delete p;
  cout << "Imprimiendo el contenido de p: " << (long)p << endl;
  *p = 72;

  return 0;
}

