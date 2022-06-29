#include <iostream>
#include <string.h>

using namespace std;

class C {
	public:
		C(char *s = "", int i = 0, double d = 1){
			strcpy(dadosMembro1, s);
			dadosMembro2 = i;
			dadosMembro3 = d;
		}
		void funcaoMembro1() {
			cout << dadosMembro1 << endl << dadosMembro2 << endl << dadosMembro3 << endl;
		}
		void funcaoMembro2(int i, char *s = "desconhecido") {
			dadosMembro2 = i;
			cout << i << " recebido de " << s << endl;
		}	
	protected:
		char dadosMembro1[20];
		int dadosMembro2;
		double dadosMembro3;
};

int main() {
	C objeto1("objeto1", 100, 2000);
	
	objeto1.funcaoMembro1();
	objeto1.funcaoMembro2(10);
	return 0;
}
