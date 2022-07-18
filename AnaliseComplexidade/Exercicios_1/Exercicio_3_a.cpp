#include <iostream>

using namespace std;

void exibir(const char **arr, int tamanho, int ordem) {
	int cont;
	if (ordem == 1) {
		cont = 0;
		while(cont < tamanho){
			cout << *arr << endl;
			arr++;
			cont++;
		}
	}
	else if (ordem == -1) {
		cont = tamanho-1;
		arr += cont;
		
		while(cont >= 0) {
			cout << *arr << endl;
			arr--;
			cont--;
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
