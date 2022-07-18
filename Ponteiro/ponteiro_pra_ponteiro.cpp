#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

enum Boolean{
	False, 
	True
};

class String{
	private:
		char *str;
	public:
		int getname() {
			char nome[100];
			gets(nome);
			str = new char [strlen(nome)+1];
			strcpy(str, nome);
			
			return strcmp(str, "");
		}
		
		Boolean operator > (String s) {
			return (strcmp(str, s.str) > 0)? True : False;
		}
		
		void print() {
			cout << str;
		}
};

void ordena(String **p, int n) {
	String *temp;
	
	for (int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++){
			if(*(*(p+i)) > *(*(p+j))){
				//ou if (*p[i]>*p[j])
				temp = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
}

int main() {
	String *p[100];
	int n, i;
	
	for (n=0; ; n++){
		cout << "\nDigite nome ou [ENTER] para fim: ";
		p[n] = new String;
		if(p[n]->getname() == 0) break;
	}
	
	cout << "\n\nLista original: ";
	for (int i=0; i < n; i++) {
		cout << "\n"; p[i]->print();
	}
	
	ordena(p, n);
	
	cout << "\n\nLista ordenada: ";
	for (int i=0; i < n; i++) {
		cout << "\n"; p[i]->print();
	}
}

