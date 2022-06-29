#include <iostream>


using namespace std;

// Define a classe
class Retangulo {
	private:
		// Dados da classe
		int bas, alt;
	public:
		// Fun��es-membros
		void init(int b, int h) {
			bas = b;
			alt = h;
		}
		void printdata() {
			cout << "\nBase = " << bas << "\nAltura = " << alt;
			cout << "\nArea = " << (bas*alt) << endl;
		}
};

int main() {
	Retangulo x, y;		// Declara dois objetos: x e y
	
	x.init(5, 3);		// Chama fun��o-membro que inicializa os dados
	y.init(10, 6);		// Chama fun��o-membro que inicializa os dados
	x.printdata();		// Chama a fun��o que imprime os dados e a �rea
	y.printdata();		// Chama a fun��o que imprime os dados e a �rea
	
	return 0;
}
