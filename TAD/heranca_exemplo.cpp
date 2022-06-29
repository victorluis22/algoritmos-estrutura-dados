#include <iostream>

class BASE {
	protected: int secreto;
	private: int ultra-secreto;
	public: int publico;
};

class DERIV1 : public BASE {
	public:
		int a = secreto;	// OK
		int b = ultra-secreto;	//Erro: não acessível
		int c = publico;	// Ok
};

class DERIV2 : private BASE {
	public:
		int a = secreto;	// OK
		int b = ultra-secreto;	//Erro: não acessível
		int c = publico;	// Ok
};

int main() {
	int x;
	
	DERIV1 obj1;	// DERIV1 é public
	DERIV2 obj2;	// DERIV2 é private
	
	x = obj1.a;		// Erro: não é acessível
	x = obj1.b;		// Erro: não é acessível
	x = obj1.c;		// Ok
	
	x = obj2.a;		// Erro: não é acessível
	x = obj2.b;		// Erro: não é acessível
	x = obj2.c;		// Erro: não é acessível
}
