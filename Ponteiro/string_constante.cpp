#include <iostream>
#include <locale.h>

using namespace std;

// Mostra duas diferentes incializações de strings
int main() {
	setlocale(LC_ALL, "");
	char s1[] = "Saudações!";	// Primeiro constante, não pode ser alterado
	char *s2 = "Saudações!";	// Ponteiro variável
	
	cout << "\n" << s1;
	cout << "\n" << s2;
	
//	s1++;	// Erro! Não podemos incrementar uma constante
	s2++;	// Ok! Aponta para o próximo caractere
	
	cout << "\n" << s2;
	
	return 0;
}
