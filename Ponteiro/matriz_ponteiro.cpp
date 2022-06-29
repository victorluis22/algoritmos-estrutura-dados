#include <iostream>

using namespace std;

int main() {
	int M[5] = {92, 81, 70, 69, 58};
	
	cout << M;	// O nome da matriz é o endereço para o primeiro elemento da matriz
	
	cout << "\n Imprime os valores dos elementos de uma matriz.";
	for (int i = 0; i < 5; i++) {
		cout << "\n " << M[i];
	}
	
	cout << "\n Imprime com notacao de ponteiro.";
	for (int i = 0; i < 5; i++) {
		cout << "\n " << *(M+i);
	}
	return 0;
}
