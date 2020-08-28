#include <iostream>
#include "complex.h"
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
//  for(int i = 0; i < argc; ++i)
//    cout << argv[i] << endl;

  string filename = "";
  if( argc > 1 ) 
    filename = argv[1];
  else{
    cout << "Por favor indicar la ruta al archivo. Gracias." << endl;
    return 1;
  }
// A partir de aquí voy a abrir el archivo para leer los datos
  cout << "Se abrirá el archivo " << filename << "para leer los complejos." << endl;

  ifstream archivo;
  archivo.open( filename );
  double  a, b;
  a = b = 0.;


  complex obj[5];

  if( archivo.is_open() ){
    while( !archivo.eof() ){
       archivo >> a;
       cout << a << "; ";
       archivo >> b;
       cout << b << endl;
       obj[1].set(a, b);
    }
  }   
// Ahora con arrglos

  double tmp1, tmp2;
  bool cambio;
/*
  do{
    cambio = false;
    for (int i =0; i < 4; ++i ){
      if( obj[i] < obj[i+1] ){
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
  */
  for( int i = 0 ; i < 5; ++i )
    cout << obj[i] << endl;

  return 0;
}

