#include <iostream>
using namespace std;
 
class base1 {
 
protected:
 
	int i;
 
public:
	base1(int x) { i=x; cout << "Construyendo base1\n"; }
	~base1() { cout << "Destruyendo base1\n"; }
};
 
class base2 {
protected:
	int k;
 
public:
	base2(int x) { k=x; cout << "construyendo base2\n"; }
	~base2() { cout << "Destruyendo base2\n"; }
};
 
class derivada : public base1, public base2 {
 
public:
 
	/* el constructor en derivada no usa parametros,
	   pero aun asi debe ser declarado para tomarlos
	   y pasarselos a las clases base.
	*/
	derivada(int x, int y) : base1(x), base2(y) 
	  { cout << "Construyendo derivada\n"; }
 
	~derivada() { cout << "Destruyendo derivada\n"; }

	void mostrar() { cout << i << " " << k << "\n"; }
};
 
int main()
{
	derivada obj(3, 4);
 
	obj.mostrar();   // mostrar 3  4
 
	return 0;
}
