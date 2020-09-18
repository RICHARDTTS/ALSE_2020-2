#include <string>


class Device {
public:
    Device () ;
    Device (double x, double y, double temp) ;
    void leerCoordenadas();
    void asignar(std::string l);
    bool alerta(Device &d);
    void vibrar();
    void esperar();


private:
    double _x;
    double _y;
    double _temp;
};
