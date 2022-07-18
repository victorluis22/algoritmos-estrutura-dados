#include <iostream>
// Mostra a passagem de matrizes para funções como argumento

using namespace std;

float media(float *lista, int tamanho);

int main() {
	const int MAXI = 20;
	float notas[MAXI];
	int i;
	
	for(i = 0; i < MAXI; i++) {
		cout << "Digite a nota do aluno " << (i+1) << " : ";
		cin >> *(notas+i);
		if(*(notas+i) < 0) break;
	}
	
	float m = media(notas, i);
	cout << "\n\nMedia das notas: " << m;
	
	return 0;
}

float media(float *lista, int tamanho) {
	float m = 0;
	for(int i = 0; i < tamanho; i++) {
		m += *lista++;
	}
	
	return (m/tamanho);
}


