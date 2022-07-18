#include <iostream>
#include <string.h>
#define MAX 60

using namespace std;

class Pessoa{
	private:
		char nome[MAX];
	public:
		int idade;
		Pessoa() {
			cout << "\nInsira o nome da pessoa: ";
			cin >> nome;
			
			cout << "Insira a idade da pessoa: ";
			cin >> idade;
		}
		
		Pessoa(const char *name, int age) {
			strcpy(nome, name);
			idade = age;
		}
		
		void exibirDados() {
			cout << "\nNome da pessoa: " << nome << endl;
			cout << "Idade da pessoa: " << idade << endl;
		}
};

int main() {
	
	Pessoa lista[3];
	Pessoa maisVelho("None", 0);
	
	for(int i = 0; i < 3; i++) {
		lista[i];
	}
	
	for(int i = 0; i < 3; i++) {
		if (i == 0) {
			maisVelho = lista[i];
		}
		else{
			if (maisVelho.idade < lista[i].idade){
				maisVelho = lista[i];
			}
		}
	}
	
	cout << "\nPessoa mais antiga";
	maisVelho.exibirDados();
	
	
	return 0;
}
