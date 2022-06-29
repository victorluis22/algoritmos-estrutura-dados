#include <stdio.h>


int soma_iterativa(int n) {
	int i, soma = 0;
	
	for(i = 1; i <= n; i++) {
		soma += i;
	}
	
	return soma;
}
int main() {
	
	int n;
	
	scanf("%d", &n);
	printf("%d", soma_iterativa(n));
	
	return 0;
}
