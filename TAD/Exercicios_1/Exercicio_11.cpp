#include <iostream>

using namespace std;

class Triangulo{
	private:
		float base, altura;
	public:
		float area;
		
		Triangulo() {
			cout << "\nEntre com o tamanho da base do triangulo: ";
			cin >> base;
			
			cout << "Entre com a altura do triangulo: ";
			cin >> altura;
			
			area = (base * altura) / 2;
		}
		
		void mostraDados() {
			cout << "\nBase do triangulo: " << base << endl;
			cout << "Altura do triangulo: " << altura << endl;
			cout << "Area do triangulo: " << area << endl;
		}
		
};

int main() {
	
	Triangulo t1, t2;
	
	cout << "\nA area de t1 eh: " << t1.area;
	t1.mostraDados();
	
	cout << "\nA area de t2 eh: " << t2.area;
	t2.mostraDados();
	return 0;
}
