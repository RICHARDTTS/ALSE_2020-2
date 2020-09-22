/**
 * Project Untitled
 */

#include <iostream>
#include <sstream>

using namespace std;
#include "Polinomio.h"

/**
 * Polinomio implementation
 */


Polinomio::Polinomio() {
    _orden = -1;
    _variable = 0;
    _polCabeza = NULL;
}

Polinomio::Polinomio(string pol) {
    _orden = -1;
    _variable = 0;
    _polCabeza = NULL;
    redefinir( pol );
}

Polinomio::Polinomio(Polinomio& pol) {
    redefinir( pol.getString() );
}

Polinomio::~Polinomio() {
    borrar();
}

void Polinomio::nuevoTermino(float c, int p) {
    Termino* nuevo = new Termino(c,p);
    //cout << nuevo << endl;

    if(_polCabeza == NULL )
        _polCabeza = nuevo;
    else{
        Termino* temp = _polCabeza;
        while(temp->getSiguiente() != NULL)
           temp = temp->getSiguiente();     

       // cout << "agregando al final" << endl;

        temp->setSiguiente( nuevo );
        //cout << nuevo << " y " << temp->getSiguiente() << endl;
    }

    return;
}

void Polinomio::simplificar() {
/*    this->ordenar();
    Termino *ptr1, *ptr2, *ptr3;
    float coef= 0.;
    int pot= 0;
    ptr1=_polCabeza;
    ptr2=ptr1->getSiguiente();
    while( ptr1->getSiguiente() != NULL ){
        if( ptr1->getP() == ptr2->getP() ){
            coef = ptr1->getC() + ptr2->getC();
            pot = ptr1->getP();
            ptr1->setCP( coef, pot );
            ptr3 = ptr1->getSiguiente();
        }
        else{

        }
        ptr1=ptr2;

        }
*/
    return;
}

bool Polinomio::ordenar() {
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

Polinomio& Polinomio::operator +(Polinomio& p) {
    this->ordenar();
    p.ordenar();
    Polinomio* res = new Polinomio(*this);
    //Polinomio* res1 = new Polinomio(p);
    Termino* temp = res->_polCabeza;
    Termino* temp1= p._polCabeza;

   if(temp != NULL){
        float newCoeff = 0.;
        int newPow = 0;

        while ( temp != NULL ){
            if ( temp->getP() == temp1->getP() ){
                newCoeff = temp->getC() + temp1->getC();
                newPow = temp->getP();
                temp->setCP( newCoeff, newPow );
                //temp = temp->getSiguiente();
                temp1= temp1->getSiguiente();
            }
            temp = temp->getSiguiente();
       }
   }
   return *res;
}

/**
 * @param p
 * @return Polinomio&
 */
Polinomio& Polinomio::operator -(Polinomio& p) {
    this->ordenar();
    p.ordenar();
    Polinomio* res = new Polinomio(*this);
    //Polinomio* res1 = new Polinomio(p);
    Termino* temp = res->_polCabeza;
    Termino* temp1= p._polCabeza;

   if(temp != NULL){
        float newCoeff = 0.;
        int newPow = 0;

        while ( temp != NULL ){
            if (temp->getP()==temp1->getP()){
                newCoeff = temp->getC() - temp1->getC();
                newPow = temp->getP();
                temp->setCP( newCoeff, newPow );
                //temp = temp->getSiguiente();
                temp1= temp1->getSiguiente();
            }
            temp = temp->getSiguiente();
       }
   }
   return *res;
}

/**
 * @param p
 * @return Polinomio&
 */
Polinomio& Polinomio::operator  *(Polinomio& p) {
    Polinomio* res = new Polinomio();
    return *res;
}

/**
 * @param f
 * @return Polinomio&
 */
Polinomio& Polinomio::operator /(float f) {
    Polinomio* res = new Polinomio(*this);
    Termino* temp = res->_polCabeza;
    if(temp != NULL){
        float newCoeff = 0.;
        int newPow = 0;

        while ( temp->getSiguiente() != NULL ){
            newCoeff = temp->getC() / f;
            newPow = temp->getP();
            temp->setCP( newCoeff, newPow );
            temp = temp->getSiguiente();
        }

    }

    return *res;
}

ostream& operator << (ostream& stream, Polinomio& p){
    return stream << p.getString();
}
/**
 * @return bool
 */
bool Polinomio::borrar() {
    try{
        Termino *ptr1, *ptr2;
        ptr1 = _polCabeza;
        _polCabeza = NULL;
        while(ptr1 != NULL ){
            //cout << "borrando" << endl;
            ptr2 = ptr1->getSiguiente();
            delete ptr1;
            ptr1 = ptr2;
        }
        return true;
    }catch(...){
        return false;
    }

}

/**
 * @param pol
 * @return bool
 */
bool Polinomio::redefinir(string pol) {
    borrar();
    string term;
    //cout << pol << endl;
    size_t posM, posm, posT1, posT2, found;
    posT1 = posT2 = 0;
    float coeff = 0.;
    int power = 0;

    while( posT2 != string::npos ){
        // Encontrando cada termino
        posM = pol.find("+", posT1 + 1 );
        posm = pol.find("-", posT1 + 1);
        // cout << posM << " " << posm << endl;
        if( posM != string::npos && posm != string::npos )
            posT2 = min( posM, posm );
        else if( posM == string::npos )
            posT2 = posm;
        else
            posT2 = posM;

        //cout << posT1 << " " << posT2 << endl;
        term = pol.substr( posT1, posT2 - posT1 );
        posT1 = posT2;
       // cout << term << endl;

        // Porcesando el termino
        if(_variable == 0){
            //cout << "variable" << endl;
            found = term.find_first_not_of("+-1234567890.,");
            //cout << term[found] << endl;
            if (found != std::string::npos)
              _variable = term[found] ;
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
    //cout << getString() << endl;
    return true;
}

string  Polinomio::getString(){
    stringstream stream;
    Termino* temp = _polCabeza;
    while( temp != NULL ){
        if( temp->getC() != 0 ) {
            if(temp->getC() > 0) stream << "+";
            stream << temp->getC();
            if(temp->getP() > 0 ){
                stream << _variable;
                if( temp->getP() > 1 )
                    stream << "^" << temp->getP();
            }
        }
        temp = temp->getSiguiente();
    }
    return stream.str();
}

int Polinomio::getOrden() {
    return _orden;
}

char Polinomio::getVariable() {
    //cout << "Leyendo la variable" << endl;
    return _variable;
}

void Polinomio::setVariable(char value) {
    //cout << "Asignando la variable" << endl;
    _variable = value;
}

