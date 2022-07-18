#include <iostream>

using namespace std;

int main(){
	
	const char *items[5] = {
		"Abrir",
		"Fechar",
		"Salvar",
		"Imprimir",
		"Sair"
	};
	
	const char **p = items;
	
	for (int i = 0; i < 5; i++){
		cout << *(p+i) << endl;
	}
	
	return 0;
}
