#include <iostream>
#include "complex.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

  string filename = "";
  string output = "";

  if( argc > 1 && argc < 4 ){
    filename = argv[1];
    output = argv[2];
  }else{
    cout << "Por favor indicar la ruta al archivo de entrada y salida. Gracias." << endl;
    return 1;
  }

// A partir de aquí voy a abrir el archivo para leer los datos
  cout << "Se abrirá el archivo " << filename << " para leer los complejos." << endl;

  ifstream archivo;
  archivo.open( filename );
  double  a, b;
  a = b = 0.;
  complex tmp;

// Ahora uso un vector de la librería estándar.

  vector<complex> obj;

  if( archivo.is_open() ){
    while( archivo >> a ){
      if ( archivo >> b ){
//        cout << a << " ; " << b << endl;
        tmp.set(a, b);
        obj.push_back( tmp );
      }
    }
  }

  archivo.close();

  bool cambio;

  do{
    cambio = false;
    for( int i = 0; i < obj.size() - 1; ++i ){
      if( obj[i+1] < obj[i] ){
        tmp = obj[i];
        obj[i] = obj[i+1];
        obj[i+1] = tmp;
        cambio = true;
      }
    }
  }while(cambio == true);

  for( int i = 0 ; i < obj.size(); ++i )
    cout << obj[i] << endl;

// Agregar aquí el codigo para guardarlos ordenados en el arvhivo de salida.
  ofstream archiSal( output );

  if( archiSal.is_open() )
    for( int i = 0; i < obj.size(); ++i )
      archiSal << obj[i] << endl ;

  archiSal.close();

  return 0;
}

