#include <iostream>
#include <string.h>

using namespace std;

class Motor{
	private:
		int numCilindro, potencia;
	public:
		Motor() {
			numCilindro = 0;
			potencia = 0;
		}
		
		Motor(int cilindro, int pot) {
			numCilindro = cilindro;
			potencia = pot;
		}
		
		void getData() {
			cout << "\nInsira o numero de cilindros do motor: ";
			cin >> numCilindro;
			
			cout << "Insira a pontencia do motor: ";
			cin >> potencia;
		}
		
		void putData() {
			cout << "\nNumero de cilindros do motor: " << numCilindro << endl;
			cout << "Potencia do motor: " << potencia << endl;
		}
};

class Veiculo{
	private:
		int peso, velocMax;
		float preco;
	public:
		Veiculo() {
			peso = 0;
			velocMax = 0;
			preco = 0;
		}
		
		Veiculo(int weight, int topSpeed, float price) {
			peso = weight;
			velocMax = topSpeed;
			preco = price;
		}
		
		void getData() {
			cout << "\nInsira o peso do veiculo em Kg: ";
			cin >> peso;
			
			cout << "Insira a velocidade maxima do veiculo em km/h: ";
			cin >> velocMax;
			
			cout << "Insira o preco do veiculo em US$: ";
			cin >> preco;
		}
		
		void putData() {
			cout << "\nPeso do veiculo: " << peso << " Kg" << endl;
			cout << "Velocidade maxima do veiculo: " << velocMax << " km/h" << endl;
			cout << "Preco do veiculo: " << preco << " US$" << endl;
		}
};

class CarroPasseio: public Motor, public Veiculo{
	private:
		char cor[20], modelo[20];
	public:
		CarroPasseio() {
			for(int i = 0; i < 20; i++) {
				cor[i] = '0';
				modelo[i] = '0';
			}
		}
		
		CarroPasseio(const char *color, const char *model) {
			strcpy(cor, color);
			strcpy(modelo, model);
		}
		
		void getData() {
			Motor::getData();
			Veiculo::getData();
			
			cout << "\nEntre com a cor do carro: ";
			cin >> cor;
			
			cout << "Entre com o modelo do carro: ";
			cin >> modelo;
		}
		
		void putData() {
			Motor::putData();
			Veiculo::putData();
			
			cout << "\nCor do carro: " << cor << endl;
			cout << "Modelo do carro: " << modelo << endl;
		}
};

int main() {
	
	CarroPasseio c1;
	
	c1.getData();
	c1.putData();
	
	return 0;
}
