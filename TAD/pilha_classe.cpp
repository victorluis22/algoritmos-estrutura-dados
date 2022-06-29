#include <iostream>
#define SUCESSO 1
#define FALHA 0

using namespace std;

class pilha {
	private:
		int dados[100];
		int conta;
	public:
		pilha() {
			conta = 0;
		}
		int insere(int valor) {
			if(conta < 100) {
				dados[conta++] = valor;
				return SUCESSO;
			}
			else {
				return FALHA;
			}
		}
		int remove(int *valor) {
			if(conta == 0) {
				return FALHA;
			}
			else {
				*valor = dados[--conta];
				return SUCESSO;
			}
		} 
		void mostradados() {
			cout << "Numero de itens: " << conta << endl;
		}
		
};
int main() {
	
	pilha notas;
	int resto;
	
	notas.mostradados();
	
	notas.insere(3);
	notas.insere(89);
	
	notas.mostradados();
	
	notas.remove(&resto);
	notas.mostradados();
	
	cout << resto << endl;
	return 0;
}
