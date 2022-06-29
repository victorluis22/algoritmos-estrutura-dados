#include <iostream>

using namespace std;

int main() {
	int i = 5, *pi;
	
	void *pv;	// Ponteiro genérico
	pv = &i;	// Endereço de um int
	
//	cout << *pv;	//ERRO: void is not a pointer-to-object type
	pi = (int *)pv;	//Solução
	cout << *pi;
	
	return 0;
}
