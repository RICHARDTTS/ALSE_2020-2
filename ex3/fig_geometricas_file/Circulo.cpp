/**
 * Project Untitled
 */


#include "Circulo.h"
#include <math.h>
/**
 * Circulo implementation
 */


/**
 * @param r
 * @param x
 * @param y
 */
Circulo::Circulo(float r, float x, float y) {
    _radio = r;
    _xc = x ;
    _yc = y ;
    _idTipo =  circulo ;
}

Circulo::Circulo(string parametros){
    size_t posicion = 0;
    size_t pos_ant = 0;
    posicion = parametros.find(" ");
    _radio = atof(parametros.substr(0,posicion).c_str());
    pos_ant =  posicion + 1;
    posicion = parametros.find(" ",pos_ant);
    _xc = atof(parametros.substr(0,posicion).c_str());
    pos_ant =  posicion + 1;
    posicion = parametros.find(" ",pos_ant);
    _yc = atof(parametros.substr(0,posicion).c_str());
    pos_ant =  posicion + 1;
    posicion = parametros.find(" ",pos_ant);
    _angulo = atof(parametros.substr(0,posicion).c_str());
    pos_ant =  posicion + 1;
}

Circulo::Circulo() {

}

float Circulo::area(){
    return M_PI * _radio * _radio;
}

float Circulo::perimetro(){
    return 2 * M_PI * _radio;
}

ostream& operator<<(ostream& stream, Circulo& c){
   stream << "Yo soy un círculo" ;
   return stream;
}
