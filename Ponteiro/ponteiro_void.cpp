#include <iostream>

using namespace std;

int main() {
	int i = 5, *pi;
	
	void *pv;	// Ponteiro gen�rico
	pv = &i;	// Endere�o de um int
	
//	cout << *pv;	//ERRO: void is not a pointer-to-object type
	pi = (int *)pv;	//Solu��o
	cout << *pi;
	
	return 0;
}
