#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;
const int TAM = 80;

class conta {
	private:
		char nome[TAM];
		int Nconta;		// Número da conta
		float saldo;
	public:
		void getdata() {
			fflush(stdin);
			cout << "\n Nome: "; gets(nome);
			cout << "\n Conta: "; cin >> Nconta;
			cout << "\n Saldo: "; cin >> saldo;
		}
		void putdata() {
			cout << "\n Nome: " << nome;
			cout << "\n Conta: " << Nconta;
			cout << "\n Saldo: " << 
			setiosflags(ios::fixed) << 
			setprecision(2) <<
			saldo;
		}
		float Saldo() {return saldo;}
};

class contaSimples : public conta 
{};

class contaEspecial : public conta {
	private:
		float limite;
	public:
		void getdata() {
			conta :: getdata();
			cout << "\n Limite: "; cin >> limite;
		}
		void putdata() {
			conta :: putdata();
			cout << "\n Limite: " << limite;
			cout << "\n Saldo Total: " << 
			setiosflags(ios::fixed) << 
			setprecision(2) <<
			(Saldo()+limite);
		}
};

class contaPoupanca : public conta {
	private:
		float taxa;
	public:
		void getdata() {
			conta::getdata();
			cout << "\n Taxa: "; cin >> taxa;
		}
		void putdata() {
			conta::putdata();
			cout << "\n Taxa: " << taxa;
			cout << "\n Saldo Total: " << 
			setiosflags(ios::fixed) << 
			setprecision(2) <<
			(Saldo()*taxa);
		}	
};

int main() {
	contaSimples c1, c2;
	contaEspecial c3;
	contaPoupanca c4;
	
	cout << "\n * Digite os dados da conta simples 1:";
	c1.getdata();
	cout << "\n * Digite os dados da conta simples 2:";
	c2.getdata();
	cout << "\n * Digite os dados da conta especial:";
	c3.getdata();
	cout << "\n * Digite os dados da conta poupanca:";
	c4.getdata();
	
	cout << "\n\n * Conta Simples 1:"; c1.putdata();
	cout << "\n\n * Conta Simples 2:"; c2.putdata();
	cout << "\n\n * Conta Especial:"; c3.putdata();
	cout << "\n\n * Conta Poupanca:"; c4.putdata();
	return 0;
}
