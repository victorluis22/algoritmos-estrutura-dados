#include <iostream>


using namespace std;

// Define a classe
class Retangulo {
	private:
		// Dados da classe
		int bas, alt;
	public:
		// Funções-membros
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
	
	x.init(5, 3);		// Chama função-membro que inicializa os dados
	y.init(10, 6);		// Chama função-membro que inicializa os dados
	x.printdata();		// Chama a função que imprime os dados e a área
	y.printdata();		// Chama a função que imprime os dados e a área
	
	return 0;
}
