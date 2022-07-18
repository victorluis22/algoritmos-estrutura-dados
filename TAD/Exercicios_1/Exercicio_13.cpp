#include <iostream>
#include <string.h>

using namespace std;

class Calculadora{
	private:
		float a, b;
	public:
		void soma() {
			cout << "\nResultado: " << a+b << endl;
		}
		
		void sub() {
			cout << "\nResultado: " << a-b << endl;
		}
		
		void mult() {
			cout << "\nResultado: " << a*b << endl;
		}
		
		void div() {
			cout << "\nResultado: " << a/b << endl;
		}
		
		void getData() {
			cout << "Entre com o primeiro numero: ";
			cin >> a;
			
			cout << "Entre com o segundo numero: ";
			cin >> b;
		}
		
};

int main() {
	
	Calculadora c1;
	int operacao;
	float a, b;
	
	while(true){
		cout << "\nEntre com a operacao desejada (1 = soma, 2 = sub, 3 = mult, 4 = div, -1 = para sair): ";
		cin >> operacao;
		
		if (operacao == -1) {
			break;
		}
		else{
			c1.getData();
		}
		
		switch(operacao) {
			case 1:
				c1.soma();
				break;
			case 2:
				c1.sub();
				break;
			case 3:
				c1.mult();
				break;
			case 4:
				c1.div();
				break;
			default:
				cout << "\nOpcao inexistente!";
		}
	}

	
	return 0;
}
