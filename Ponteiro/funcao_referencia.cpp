#include <iostream>

using namespace std;

// Reajusta o pre�o em 20%

void reajusta20(float &p, float &r) {
	r = p * 0.2;
	p *= 1.2;
}

int main() {
	float preco, valor_reajuste;
	
	do {
		cout << "\n\nInsira o preco atual: ";
		cin >> preco;
		reajusta20(preco, valor_reajuste);
		cout << "\nPreco novo: " << preco;
		cout << "\nAumento: " << valor_reajuste;
	} while(preco != 0.0);
}
