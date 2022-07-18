#include <iostream>
#include <math.h>

using namespace std;

double soma(double (*f)(double), int n, int m){
	double resultado;
	
	for (int i = n; i<=m; i++) {
		resultado += (*f)(i);
	}
	
	return resultado;
}

int main() {
	
	cout << soma(sin, 1, 5) << endl;
	cout << soma(cos, 1, 5) << endl;
	
	
	return 0;
}
