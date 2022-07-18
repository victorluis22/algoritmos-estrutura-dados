#include <iostream>

using namespace std;

int soma (int a, int b){
	return a+b;
}

int multiplicacao(int (*p)(int, int), int fator){
	int resultado = 0;
	
	for(int i = 0; i < fator; i++){
		resultado += (*p)(1,2);
	}
	
	return resultado;
}

int main() {
	
	int (*p)(int, int);
	
	p = soma;
	
	cout << (*p)(1,2) << endl;
	cout << multiplicacao(soma, 3);
	
	return 0;
}
