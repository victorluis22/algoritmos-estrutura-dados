#include <iostream>


using namespace std;

// Toca o auto falante duas vezes
void doisbeep() {
	cout << '\x07';
	cout << '\x07';
}

int main() {
	void (*pf)();		// Ponteiro para uma fun��o void
	pf = doisbeep;	// Atribui o endere�o da fun��o
	(*pf)();			// Chama a fun��o - equivale a doisbeep()
	
	return 0;
}
