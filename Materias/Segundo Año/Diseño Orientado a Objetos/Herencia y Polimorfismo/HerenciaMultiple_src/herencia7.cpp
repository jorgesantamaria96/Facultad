// Demuestra la herencia de una clase base protegida
#include <iostream>
using namespace std;
 
class base {
	int i;
 
protected:
	int j;
 
public:
	int k;
	void seti(int a) { i = a; }
	int geti() { return i; }
};
 
// heredar 'base' como protected.
class derivada : protected base {
 
public:
	void setj(int a) { j = a; }; // j es protected aqui.
	void setk(int a) { k = a; }; // k es tambien protected. 
	int getj() { return j; }
	int getk() { return k; }
};
 
int main()
{
	derivada obj;
 
  /* La proxima linea es ilegal porque seti() es
     un miembro protegido de derivada, lo cual lo
     hace inaccesible fuera de derivada. */
  // obj.seti(10);
 
  // cout << obj.geti(); // ilegal -- geti() es protected.
  // obj.k = 10;  // tambien ilegal porque k es protected.
 
    // estas declaraciones son correctas
	obj.setk(10);
	cout << obj.getk() << " " << endl;
	obj.setj(12);
	cout << obj.getj() << " " << endl;
 
	return 0;
}
