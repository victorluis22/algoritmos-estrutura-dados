#include <iostream>
#include <iomanip>

using namespace std;

class venda {
	private:
		int npecas;
		float preco;
	public:
		venda() {	}
		venda(int np, float p) {
			npecas = np;
			preco = p;
		}
		void getvenda() {
			cout << "Insira No.Pecas: ";
			cin >> npecas;
			cout << "Insira Preco: ";
			cin >> preco;
		}
		void printvenda() const;
		
		void add_venda(venda v1, venda v2) {
			npecas = v1.npecas + v2.npecas;
			preco = v1.preco + v2.preco;
		}
};

// Forma de declarar funções-membros fora da classe
void venda::printvenda() const {
	cout << 
	setiosflags(ios::fixed) << // Sem notação científica
	setiosflags(ios::showpoint) << // Mostrar ponto decimal
	setprecision(2) << // Mostrar duas casas decimais
	setw(10) << // Quantidade de espaços em branco
	npecas;
	
	cout << setw(10) << preco << endl;
}

int main() {
	venda a(58, 12734.53), b, total;
	
	b.getvenda();
	total.add_venda(a, b);
	
	cout << "Venda A....";
	a.printvenda();
	
	cout << "Venda B....";
	b.printvenda();
	
	cout << "Totais....";
	total.printvenda();
	return 0;
}
