#include <iostream>

using namespace std;

class classe_1 {
	public:
		int x;
		classe_1() {
			x = 10;
		}
};

class classe_2 : public classe_1 {
	public:
		int x;
		void atribui(int valor) {
			x = valor;
		}
		int soma() {
			return (classe_1::x + x);
		}
};

int main() {
	classe_2 obj;
	obj.atribui(15);
	cout << "Soma dos valores = " << obj.soma();
	return 0;
}
