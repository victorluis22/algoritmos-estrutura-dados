#include <iostream>
#include <stdio.h>
#include <locale.h>

using namespace std;

char *procura (char *s, char ch) {
	while(*s != ch && *s != '\0') s++;
	if(*s != '\0') return s;
	return (char *)0;
}

int main() {
	setlocale(LC_ALL, "");
	char ch, str[81], *ptr, letra;
	int M[10] = {1, 2, 3, 4};
	
	cout << "\nDigite uma frase: ";
	gets(str);
	cout << "\nDigite um caractere: ";
	cin >> letra;
	
	for(int i = 0; i < 81; i++) {
		cout << "\n" << str;
	}
	
	for(int i = 0; i < 81; i++) {
		cout << "\n" << ptr;
	}
	for(int i = 0; i < 10; i++) {
		cout << "\n" << M;
	}
	
	ptr = procura(str, letra);
	cout << "\nA frase come�a no endere�o: " << &str;
	
	if(ptr){
		cout << "\nA primeira ocorr�ncia do caractere " << letra << ": " << &ptr;
		cout << "\nA sua posi��o �: " << ptr-str;
	}
	else{
		cout << "\nO caractere " << letra << " n�o existe nessa frase.";
	}
}


