#include <iostream>
#define MAX 60

using namespace std;

class Aluno{
	private:
		char nome[MAX];
		int serie;
		int grau;
		static int alunosCadastrados;
	public:
		
		Aluno() {
			alunosCadastrados++;
		}
		
		void getData() {
			cout << "\nInsira o primeiro nome do aluno: ";
			cin >> nome;
			
			cout << "Insira a serie do aluno: ";
			cin >> serie;
			
			cout << "Insira o grau do aluno: ";
			cin >> grau;
		}
		
		void printData() {
			cout << "\nNome do aluno: " << nome << endl;
			cout << "Serie do aluno: " << serie << endl;
			cout << "Grau do aluno: " << grau << endl;
		}
		
		void printAlunosCadastrados() {
			cout <<"\nAlunos cadastrados: " << alunosCadastrados << endl;
		}
		
		~Aluno() {
			alunosCadastrados--;
		}
};

int Aluno::alunosCadastrados = 0;

int main() {
	
	Aluno alu1;
	alu1.getData();
	alu1.printData();
	alu1.printAlunosCadastrados();
	
	Aluno matriz[10];
	
	for(int i = 0; i < 10; i++) {
		matriz[i].getData();
	}
	
	for(int i = 0; i < 10; i++) {
		matriz[i].printData();
	}
	
	alu1.printAlunosCadastrados();
	return 0;
}
