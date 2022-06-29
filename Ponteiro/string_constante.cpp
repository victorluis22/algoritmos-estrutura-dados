#include <iostream>
#include <locale.h>

using namespace std;

// Mostra duas diferentes incializa��es de strings
int main() {
	setlocale(LC_ALL, "");
	char s1[] = "Sauda��es!";	// Primeiro constante, n�o pode ser alterado
	char *s2 = "Sauda��es!";	// Ponteiro vari�vel
	
	cout << "\n" << s1;
	cout << "\n" << s2;
	
//	s1++;	// Erro! N�o podemos incrementar uma constante
	s2++;	// Ok! Aponta para o pr�ximo caractere
	
	cout << "\n" << s2;
	
	return 0;
}
