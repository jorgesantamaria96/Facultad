#include <iostream>
using namespace std;
 
class base1 {
 
public:
	base1() { cout << "Construyendo base1\n"; }
	~base1() { cout << "Desstruyendo base1\n"; }
};
 
class base2 {
 
public:
	base2() { cout << "Construyendo base2\n"; }
	~base2() { cout << "Destruyendo base2\n"; }
};
 
class derivada : public base1, public base2 {
 
public:
	derivada() { cout << "Construyendo derivada\n"; }
	~derivada() { cout << "Destruyendo derivada\n"; }
};

int main()
{
  derivada obj;
 
  // no hacer nada mas que construir y destruir obj
 
return 0;
}
