#include <iostream>

using namespace std;

int main() {
	int x = 5, y = 6;
	int *px = &x, *py = &y; 	// Inicializa px com o endere�o de x e py com o endere�o de y
	
	// Endere�o da vari�vel apontada - valor da vari�vel apontada - endere�o do ponteiro
	cout << "\n px = " << px << ", *px = " << *px << ", &px = " << &px;	
	cout << "\n py = " << py << ", *py = " << *py << ", &py = " << &py;
	
	// Compara��es sempre entre ponteiros do mesmo tipo
	if (px < py){
		cout << "\n py-px = " << (py-px);
	}
	else{
		cout << "\n px-py = " << (px-py);
	}
	
	// Incremento de um int. Movimenta para o pr�ximo tipo apontado
	py++;
	cout << "\n\n py++";
	cout << "\n py = " << py << ", *py = " << *py << ", &py = " << &py;
	
	// Caminha 3 inteiros adiante de py
	px = py + 3;
	cout << "\n px = py + 3";
	cout << "\n px = " << px << ", *px = " << *px << ", &px = " << &px;
	cout << "\n px-py = " << (px-py);
	cout << "\n &x-&y = " << (&x-&y);
	
	px -= 3;
	cout << "\n px = " << px << ", *px = " << *px << ", &px = " << &px;
	cout << "\n px-py = " << (px-py);
	return 0;
}
