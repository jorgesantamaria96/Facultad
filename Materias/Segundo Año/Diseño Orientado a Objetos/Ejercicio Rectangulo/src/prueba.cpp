#include <iostream>

using namespace std;

class prueba {
    public: int x;
};

class Costo {
        int valor;
    public:
        void setValor (int);
        Costo &incremento ();
};

void Costo :: setValor (int valor) {
    this->valor = valor;
}

Costo& Costo :: incremento () {
    valor++;
    cout << valor << "\n";
    return *this;
}

int main () {
    prueba X;
    X.x = 0;

    Costo c;
    c.setValor(20);
    c.incremento();
    c.incremento();

    return 0;
}
