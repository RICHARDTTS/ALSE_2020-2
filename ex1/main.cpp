#include <iostream>
#include "complex.h"


using namespace std;

int main(){
  complex a(45., 56.), b(45., -56.), c(0,0);

  complex d =  c + b;

  //d = c - a;
  cout << c << endl;

  cout << d << endl;

  cout << "Son iguales a y b?: " << ( a==b ) << endl;
  cout << "son iguales b y d?: " << ( b==d ) << endl;

// Ahora con arrglos
  complex obj[5];
  obj[0].set( 34., -4.);
  obj[1].set( 45. , 45.);
  obj[2].set( -34. , 89. );
  obj[3].set( 12. , 25. );
  obj[4].set( -56. , -56. );

  double tmp1, tmp2;
  bool cambio;

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
  
  for( int i = 0 ; i < 5; ++i )
    cout << obj[i] << endl;

  return 0;
}

