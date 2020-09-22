#include "Polinomio.h"
#include "Termino.h"

#include <sstream>

Polinomio::Polinomio(){
    _orden = -1;
    _variable = 'X';
    _polCabeza = NULL;
}

Polinomio::Polinomio(std::string pol){
    _orden = -1;
    _variable = 'X';
    _polCabeza = NULL;
    redefinir( pol );
}

Polinomio::Polinomio(const Polinomio &p){
    if( this != &p ){
        _orden = p._orden;
        _variable = p._variable;
        _polCabeza = NULL;

        Termino *ptr = p._polCabeza;
        while( ptr != NULL ){
            nuevoTermino( ptr->getC(), ptr->getP() );
            ptr = ptr->getSiguiente();
        }
    }
}

Polinomio::~Polinomio(){
    borrar();
}

bool Polinomio::redefinir(std::string pol) {
    borrar();

    if( pol == "" ) return true;

    bool vardefinida = false;
    std::string term;
    //cout << pol << endl;

    size_t posT1, posT2, found;
    posT1 = posT2 = 0;
    float coeff = 0.;
    int power = 0;

    while( posT2 != string::npos ){
        // Encontrando cada termino
        posT2 = pol.find_first_of("+-", posT2 + 1 );

        //cout << posT1 << " " << posT2 << endl;
        term = pol.substr( posT1, posT2 - posT1 );
        posT1 = posT2;
        //cout << term << endl;

        // Porcesando el termino
        if( vardefinida == false ){
            //cout << "variable" << endl;
            found = term.find_first_not_of("+-1234567890.,");

            if (found != std::string::npos){
              //cout << term[found] << endl;
              _variable = term[found] ;
              vardefinida = true;
            }
        }

        found = term.find( _variable );
        if( found == string::npos ){
            //cout << "independiente" << endl;
            coeff = atof( term.c_str() );
            power = 0;
        }else{
            found = term.find( '^' );
            if( found != string::npos ){ // Tiene potencia > 1
                //cout << "pot >1" << endl;
                power = atoi( term.substr( found+1 ).c_str() );
                coeff = atof( term.substr( 0, term.size() - found +1 ).c_str() );
            }else{
                power = 1;
                coeff = atof( term.substr( 0, term.size() - 1 ).c_str() );
            }
        }

        //cout << "coeff: " << coeff << " y power: " << power << endl;
        // Adicionar el término encontrado
        nuevoTermino( coeff, power );
        _orden = power > _orden ? power : _orden ;
    }
    //std::cout << getString() << endl;
    return true;
}

Polinomio Polinomio::operator +(Polinomio &p){
    this->ordenar();
    p.ordenar();

    Polinomio c( this->getString() );
    Termino* temp= p._polCabeza;

    float newCoeff = 0.;
    int newPow = 0;

    while ( temp != NULL ){
        newCoeff = temp->getC();
        newPow = temp->getP();
        c.nuevoTermino( newCoeff, newPow );
        temp = temp->getSiguiente();
    }
    //cout << c.getString() << endl;
    //c.ordenar();
    //cout << c.getString() << endl;
    c.simplificar();
    //cout << c.getString() << endl;
    return c;
}

Polinomio Polinomio::operator *(Polinomio &p){
   Polinomio c;
   return c;
}

void Polinomio::operator =(Polinomio &p){
    redefinir( p.getString() );
}

Polinomio Polinomio::operator -(Polinomio &p){
    this->ordenar();
    p.ordenar();

    Polinomio c( this->getString() );
    Termino* temp= p._polCabeza;

    float newCoeff = 0.;
    int newPow = 0;

    while ( temp != NULL ){
        newCoeff = temp->getC();
        newPow = temp->getP();
        c.nuevoTermino( - newCoeff, newPow );
        temp = temp->getSiguiente();
    }
    //cout << c.getString() << endl;
    c.ordenar();
    //cout << c.getString() << endl;
    c.simplificar();
    //cout << c.getString() << endl;
    return c;
}

Polinomio Polinomio::operator /(float f){
    Polinomio c;
    Termino *temp = _polCabeza;
    while( temp != NULL ){
        c.nuevoTermino(temp->getC() / f, temp->getP() );
        temp = temp->getSiguiente();
    }
    return c;
}

std::ostream &operator <<(std::ostream &stream, Polinomio &p){
    //cout << "entrando <<" << std::endl;
    return stream << p.getString();
}

bool Polinomio::borrar(){
    Termino *ptr, *ptr2;
    ptr = _polCabeza;

    while( ptr != NULL ){
       ptr2 = ptr->getSiguiente();
       delete ptr;
       ptr = ptr2;
    }

    _polCabeza = NULL;
    _orden = -1;
}

int Polinomio::getOrden(){
   return _orden;
}

char Polinomio::getVariable(){
   return _variable;
}

void Polinomio::nuevoTermino(float c, int p){
    Termino* nuevo = new Termino(c,p);
    //cout << nuevo << endl;
    //cout << nuevo->getSiguiente() << endl;

    if( _polCabeza == NULL )
        _polCabeza = nuevo;
    else{
        Termino* temp = _polCabeza;
        while(temp->getSiguiente() != NULL){
           temp = temp->getSiguiente();
           //cout << temp << endl;
        }

        //cout << "agregando al final" << endl;

        temp->setSiguiente( nuevo );
        //cout << nuevo << " y " << temp->getSiguiente() << endl;
        //nuevo->setSiguiente( NULL );
    }
    _orden = _orden < p ? p : _orden;
}

void Polinomio::simplificar(){
    this->ordenar();
    Termino *ptr1, *ptr2;
    float coef= 0.;
    ptr1=_polCabeza;

    while( ptr1 != NULL ){
        ptr2=ptr1->getSiguiente();
        while(ptr2 != NULL ){
            if( ptr1->getP() == ptr2->getP() ){
                coef = ptr1->getC() + ptr2->getC();
                ptr1->setC( coef );
                ptr1->setSiguiente( ptr2->getSiguiente() );
                delete ptr2;
                ptr2 = ptr1;
            }
            ptr2 = ptr2->getSiguiente();
        }
        ptr1 = ptr1->getSiguiente();
    }
    return;
}

bool Polinomio::ordenar(){
    Termino *ptr1, *ptr2, *ptr3;

    bool cambio = false;
    do{
        ptr1 = _polCabeza;
        cambio = false;
        while( ptr1->getSiguiente() != NULL ){
            ptr2 = ptr1->getSiguiente();
            if( ptr1->getP() < ptr2->getP() ){ // Es necesario intercambiar
                //cout << ptr1 << " " << ptr2 <<endl;
                cambio = true;
                ptr1->setSiguiente( ptr2->getSiguiente() );
                ptr2->setSiguiente( ptr1 );
                //cout << ptr1 << " " << ptr2 <<endl;
                if( _polCabeza == ptr1 ) {
                    _polCabeza = ptr2;
                }else{
                    ptr3 = _polCabeza;
                    //cout << ptr1 << " " << ptr3 << endl;
                    //cout << _polCabeza << " " << ptr3 << endl;
                    while( ptr3->getSiguiente() != ptr1 ){
                        //cout << ptr1 << " " << ptr3 << endl;
                        ptr3 = ptr3->getSiguiente();
                    }
                    ptr3->setSiguiente( ptr2 );
                }
            }
            ptr1 = ptr2;
        }
    }while( cambio );

    return cambio;
}

std::string Polinomio::getString() {
    //cout << "Entrando a getString()" << endl;
    stringstream stream;
    Termino* temp = _polCabeza;
    while( temp != NULL ){
        if(temp != _polCabeza && temp->getC() > 0) stream << "+";
        stream << temp->getC();
        if(temp->getP() > 0 ){
            stream << _variable;
            if( temp->getP() > 1 )
                stream << "^" << temp->getP();
        }
        temp = temp->getSiguiente();
    }
    return stream.str();
}
