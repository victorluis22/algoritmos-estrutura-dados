#include <iostream>
#include <locale.h>

using namespace std;

// Retorna o tamanho da cadeia
int strlen(char *s){
	int len = 0;
	
	while(*s){
		s++;
		len++;
	}
	
	return len;
}

// Copia a cadeia de origem na cadeia destino
void strcpy (char *dest, char *orig) {
	while(*dest++ = *orig++);
}


// Compara a cadeia s com a cadeia t
// Retorna a diferença ASCII
//		Número positivo se s>t
//		Número negativo se s<t
//		Zero se s==t
int strcmp(char *s, char *t) {
	while(*s == *t && *s && *t){
		s++;
		t++;
	}
	
	return *s - *t;
}

int main() {
	
	char s1[]= "Oi querida";
	char s2[] = "O que foi?";
	
	cout << strlen("João e Maria");
	cout << "\ns1 == s2? " << strcmp(s1,s2);
	
	strcpy(s1,s2);
	
	cout << "\n" << s1;
	cout << "\ns1 == s2? " << strcmp(s1,s2);
	
	return 0;
}
