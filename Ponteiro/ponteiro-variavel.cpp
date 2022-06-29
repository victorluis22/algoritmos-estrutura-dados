#include <iostream>

using namespace std;

// Imprime os valores dos elementos de uma matriz usando um ponteiro variável

int main() {
	
	int M[5] = {92, 81, 70, 69, 58};
	
	int *p = M;
	
	for (int i = 0; i < 5; i++) {
		cout << "\n" << *(p++);
	}
	return 0;
}
