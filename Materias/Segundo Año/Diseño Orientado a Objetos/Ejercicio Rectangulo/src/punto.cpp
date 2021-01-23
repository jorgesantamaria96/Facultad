#include <iostream>

using namespace std;

class Punto {
        int m_x;    // coordenada x
        int m_y;    // coordenada y
    public:
        Punto () {
            m_x = 0;
            m_y = 0;
            cout << "Punto inicializado" << endl;
        }
        Punto (int, int);
        // resto de las funciones
};

Punto :: Punto (int x, int y) {
    m_x = x;
    m_y = y;
    cout << "(" << m_x << "," << m_y << ")" << endl;
}

class Poligono {
        int NoPuntos;
        Punto *aPuntos;
    public:
        Poligono () : NoPuntos(0), aPuntos(NULL) {};
        // Poligono () {NoPuntos(0); aPuntos(NULL);}
        ~Poligono ();
};

Poligono :: ~Poligono() {
    if (aPuntos != NULL)
        delete[] aPuntos;
}

int main () {
    Punto p1;
    Punto *pto;
    pto = new Punto(2,4);
    delete(pto);

    Poligono *poli;
    poli = new Poligono();
    

    return 0;
}