#include "Polinomio.h"

int main(int argc, char** argv){
    Polinomio a("3X^2+5");
    Polinomio b("8X^3+6X^2-7");
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    Polinomio c = b / 8.;
    std::cout << c << std::endl;

    Polinomio d = a + b;
    std::cout << d << std::endl;

    Polinomio e = a - b;
    std::cout << e << std::endl;
    return 0;
}
