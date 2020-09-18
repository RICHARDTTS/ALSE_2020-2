#include "device.h"
#include <math.h>
#include <iostream>

using namespace std;

Device::Device(){
    _x =_y = _temp = 0.;
}

Device::Device(double x, double y, double temp){
    _x = x;
    _y = y;
    temp = _temp;
}

void Device::leerCoordenadas(){
    // Aquí se leen los datos del GPS o sistema que brinda las coordenadas.
    // Aunque no se especifica tambien se leerá el sensor de temperatura.
    _x = 45.;
    _y = 45.;
}

void Device::asignar(std::string l){
    // l es un texto que traera "coordx coordy temp"
    size_t pos = 0, ant = 0;
    pos = l.find( " ", pos );
    _x = atof( l.substr(0, pos ).c_str() );
    ant = pos + 1;
    pos = l.find( " ", ant );
    _y = atof( l.substr(ant, pos ).c_str() );
    _temp = atof( l.substr(pos +1 , l.size() ).c_str()  );
}

bool Device::alerta(Device &d){
    double dx, dy;
    dx = d._x - _x;
    dy = d._y - _y;
    dx = sqrt(dx*dx + dy*dy);

    if ( dx == 0. )return false;

    if( dx < 3 && d._temp >= 38 )

    if( dx < 3 ){
        if( d._temp >= 38 )
            return true;
        else
            if( d._temp > 36 && dx <= 2)
                return true;
    }
    return false;
}

void Device::vibrar(){
    // Aquí enciendo el vibrador
    cout << "Vibrando" << endl;
}

void Device::esperar(){
    // Aqui hay que contar el tiempo que falta para ajustar 400 ms.
}
