#include <iostream>

using namespace std;

void exibir(const char **arr, int tamanho, int ordem) {
	if (ordem == 1) {
		for(int i = 0; i < tamanho; i++) {
			cout << *(arr+i) << endl;
		}
	}
	else if (ordem == -1) {
		for(int i = tamanho-1; i >= 0; i--){
			cout << *(arr+i) << endl;
		}
	}
}

int main() {
	const char *nome1 = "Maria";
	const char *nome2 = "Fernando";
	const char *nome3 = "Joao";
	const char *nome4 = "Joaquim";
	
	const char *nomes[4] = {nome1, nome2, nome3, nome4};
	
	exibir(nomes, 4, 1);
	cout << endl;
	exibir(nomes, 4, -1);
	
	return 0;
}
