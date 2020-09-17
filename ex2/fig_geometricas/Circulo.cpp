/**
 * Project Untitled
 */


#include "Circulo.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Circulo implementation
 */


/**
 * @param r
 * @param x
 * @param y
 */
Circulo::Circulo(float r, float x, float y ) {
    if ( r != 0. ) {
        _radio = r;
        _xc = x;
        _yc = y;
    }else{
        cout << "No puede crear círculos de radio 0.";
    }

}

/**
 * @return float
 */
float Circulo::area() {
    return M_PI * _radio * _radio;
}

/**
 * @return float
 */
float Circulo::perimetro() {
    return 2 * M_PI * _radio;
}

bool Circulo::intersectan(Circulo &c){
    float dx, dy;
    dx = _xc - c._xc;
    dy = _yc - c._yc;
    dx = sqrt(dx * dx + dy * dy);
    //cout << dx << " : " << _radio + c._radio << endl;
    return ( dx <= ( _radio + c._radio ) );
}


/**
 * @param stream
 * @return ostream&
 */
ostream& operator<<(ostream& stream,  Circulo &c) {
    stream  << "Soy un círculo de radio: " << c._radio << ". Mi perímetro es: " << c.perimetro() <<
               " y mi área es: " << c.area();

    return stream;
}

