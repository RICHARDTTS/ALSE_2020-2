#include <iostream>
#include "complex.h"
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
//  for(int i = 0; i < argc; ++i)
//    cout << argv[i] << endl;

  string filename = "";
  if( argc > 1 && argc < 3 ){
    filename = argv[1];
  }else{
    cout << "Por favor indicar la ruta al archivo de entrada. Gracias." << endl;
    return 1;
  }

// A partir de aquí voy a abrir el archivo para leer los datos
  cout << "Se abrirá el archivo " << filename << " para leer los complejos." << endl;

  ifstream archivo;
  archivo.open( filename );
  double  a, b;
  a = b = 0.;
  int num = 0;

// Ahora uso un arreglo estático.

  complex obj[5];

  if( archivo.is_open() ){
    while( !archivo.eof() ){
       archivo >> a;
//       cout << a << "; ";
       archivo >> b;
//       cout << b << endl;
       obj[ num ].set(a, b);
       if( num < 5) 
         num++;
       else
         break;
    }
  }

  archivo.close(); 


  double tmp1, tmp2;
  bool cambio;

  do{
    cambio = false;
    for (int i = 0; i < 4; ++i ){
      if( obj[i] < obj[i+1] ){
//	cout << obj[i] << endl;
      }else{
        tmp1 = obj[i].getRe();
        tmp2 = obj[i].getIm();
        obj[i].setRe( obj[i+1].getRe() );
        obj[i].setIm( obj[i+1].getIm() );
        obj[i+1].setRe( tmp1 );
        obj[i+1].setIm( tmp2 );
        cambio = true;
      }
    }
  }while(cambio == true);

  for( int i = 0 ; i < 5; ++i )
    cout << obj[i] << endl;

// Agregar aquí el codigo para guardarlos ordenados en el arvhivo de salida.


  return 0;
}

