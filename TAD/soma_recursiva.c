#include <stdio.h>


int soma_recursiva(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n + soma_recursiva(n-1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", soma_recursiva(n));
	
	return 0;
}
