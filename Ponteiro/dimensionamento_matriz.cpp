#include <iostream>

using namespace std;

float media(float *lista, int tamanho) {
	float m = 0;
	
	for (int i = 0; i < tamanho; i++) {
		m += *(lista+i);	// Ou m += *lista++
	}
	
	return m/tamanho;
}

int main() {
	
	int tamanho;
	float *notas, m;
	
	cout << "\nQual o numero de notas? ";
	cin >> tamanho;
	
	notas = new float[tamanho];
	
	for(int i = 0; i < tamanho; i++) {
		cout << "Digite a nota do aluno " << (i+1) << ": ";
		cin >> *(notas+i);
	}
	
	m = media(notas, tamanho);
	
	cout << "\n\nMedia das notas: " << m;
	delete [] notas;
	
	return 0;
}
