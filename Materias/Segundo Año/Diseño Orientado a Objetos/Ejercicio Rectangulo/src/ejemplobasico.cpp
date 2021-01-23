#include <iostream>
#include <cstring>

using namespace std;

class Estudiante {
        char *nombre;
        int edad;
        float promedio;
    public:
        // constructor
        Estudiante(const char *nombre, int edad, float promedio) {
            this->nombre = new char[strlen(nombre) + 1];
            strcpy(this->nombre, nombre);
            this->edad = edad;
            this->promedio = promedio;
        };
        void print() {
            cout << nombre << " " << edad << " " << promedio << endl;
        }
};

int main() {
    Estudiante *P;
    P = new Estudiante("Juan", 26, 7.5);
    P->print();
    delete(P);

    Estudiante J("Pablo", 28, 8.8);
    J.print();
    

    return 0;
}