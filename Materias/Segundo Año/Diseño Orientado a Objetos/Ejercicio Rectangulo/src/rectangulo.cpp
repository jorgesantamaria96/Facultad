#include <iostream>

using namespace std;

class Punto {
        int cordx;
        int cordy;
    public:
        Punto () {
            cordx = 0;
            cordy = 0;
            cout << "Punto inicializado" << endl;
        };
        bool set (int x, int y) {
            if (valida(x) && valida(y)){
                this->cordx = x;
                this->cordy = y;
                cout << "Se setearon los valores correctamente!!" << endl;
                return true;
            }
            cout << "Ingrese enteros positivos!" << endl;
            return false;
        };
        void print () {
            cout << "(" << this->cordx << "," << this->cordy << ")  ";
        };
        bool valida(int x) {
            if (x > 0) {
                return true;
            }
            return false;
        }
};

class Rectangulo {
        Punto topeIzq;
        Punto infDer;
    public:
        Rectangulo (int x1, int y1, int x2, int y2) {
            if (topeIzq.set(x1,y1) && infDer.set(x2,y2)) {
                cout << "Tenemos un rectangulo!!!" << endl;
            } else {
                cout << "Los datos ingresados son incorrectos." << endl;
            }
        };
        void print() {
            cout << endl << "Nuestro rectangulo es:" << endl;
            topeIzq.print();
            infDer.print();
            cout << endl;
        }
};

int main () {
    Rectangulo R1(5, 4, 9, 2);
    R1.print();

    cout << endl << endl << endl;

    Rectangulo R2(5, 4, 9, -1);
    R2.print();

}