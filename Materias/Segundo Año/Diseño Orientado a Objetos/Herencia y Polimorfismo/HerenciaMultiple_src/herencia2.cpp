#include <iostream>
using namespace std;
 
class base1 {
protected:
 	int i;
 
public:
	base1(int x) { i = x; cout << "Construyendo base1\n"; }
	~base1() { cout << "Destruyendo base1\n"; }
};
 
class base2 {
protected:
	int k;
 
public:
	base2(int x) { k = x; cout << "construyendo base2\n"; }
	~base2() { cout << "Destuyendo base2\n"; }
};
 
class derivada : public base1, public base2 {
 
	int j;
 
public:
	derivada(int x, int y, int z) : base1(y), base2(z)
	{ j = x; cout << "construyendo derivada\n"; }
 
	~derivada() {  cout << "Destruyendo derivada\n"; }

	void mostrar() { cout << i << " " << j << " " << k << "\n"; }
};
 
int main()
{
	derivada obj(3, 4, 5);
 
	obj.mostrar();  // mostrar 3  4  5
 
	return 0;
}
