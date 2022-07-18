#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Nome{
	private:
		char *str;
	public:
		int getnome() {
			char nome[100];
			gets(nome);
			
			str = new char [strlen(nome)+1];
			strcpy(str, nome);
			
			return strcmp(str, "");
		}
		
		void print() {
			cout << str;
		}
};


int main() {
	
	Nome *p[80];
	int n, i;
	
	for (n=0; ; n++) {
		cout << "\nDigite nome ou [ENTER] para fim: ";
		p[n] = new Nome;
		
		if (p[n]->getnome() == 0) break;
	}
	
	cout << "\n\nLista dos nomes: ";
	for(int i=0; i < n; i++) {
		cout << "\n"; p[i]->print();
	}
	return 0;
}
