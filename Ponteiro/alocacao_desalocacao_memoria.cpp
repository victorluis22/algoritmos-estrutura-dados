#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;

// Mostra o operador new na classe String

class String {
	private: char *str;
	public:
		String() {
			str = new char[0];
			*str = '\0';
		}
		String(char *s) {
			// Retorna um pontiro para um bloco de memória
			// do tamanho exato para armazenar a cadeia s mais o '\0'
			str = new char[strlen(s)+1];
			strcpy(str, s);
		}
		~String() {
			if(str) delete str;
		}
		void print(){
			cout << str;
		}
};

int main() {
	setlocale(LC_ALL, "");
	
	String s = "A vida é para ser vivida";	// Forma alternativa de acessar o construtor
	String s1;
	
	cout << "\ns = "; s.print();
	cout << "\ns1 = "; s1.print();
	
	return 0;
}
