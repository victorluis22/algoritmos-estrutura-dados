#include <iostream>

using namespace std;

class REC {
	private:
		static int n;
	public:
		// Construtor
		REC() {
			n++;
		}
		// Destrutor
		~REC() {
			n--;
		}
		int getrec() {
			return n;
		}
};

int REC::n = 0;

int main() {
	
	REC r1, r2, r3;
	cout << "\nNumero de objetos: " << r1.getrec();
	
	{
		REC r4, r5;
		cout << "\nNumero de objetos: " << r1.getrec();
	}
	
	cout << "\nNumero de objetos: " << r1.getrec();
	return 0;
}
