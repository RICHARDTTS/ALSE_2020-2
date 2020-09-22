#include "Termino.h"


Termino::Termino(float c, int p){
    _potencia = p;
    _coeficiente = c;
    _siguiente = NULL;
    //std::cout << "Constructor Termino con (" << _coeficiente << ", " << _potencia << ")" << std::endl;
}
