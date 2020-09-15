#include <string>
#include <iostream>
#include <fstream>
#include "device.h"

using namespace std;

int main(int argc,  char* argv[]){
    string file = "", linea = "";
    if(argc > 1 && argc < 3)
        file = argv[1];
    else {
        cout << "Falta el path del archivo de entrada" << endl;
        return 1;
    }


    ifstream archIn;
    Device me;
    Device other;

    for(;;){
        archIn.open( file );

        me.leerCoordenadas();

        if( archIn.is_open()){
            while( getline( archIn, linea ) ){
                cout << linea << endl;
                other.asignar( linea );
                if( me.alerta( other ) ){
                    me.vibrar();
                }
            }
        }

        cout << endl;
        archIn.close();
        me.esperar();
    }
    return 0;
}
