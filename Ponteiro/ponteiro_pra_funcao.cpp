#include <iostream>


using namespace std;

// Toca o auto falante duas vezes
void doisbeep() {
	cout << '\x07';
	cout << '\x07';
}

int main() {
	void (*pf)();		// Ponteiro para uma função void
	pf = doisbeep;	// Atribui o endereço da função
	(*pf)();			// Chama a função - equivale a doisbeep()
	
	return 0;
}
