#include <iostream>

int main() {
	
	int i = 5, *p;
	
	p = &i;
	
	std::cout << p << '\t' << (*p+2) << '\t' << **&p << '\t' << (3**p) << '\t' << (**&p+4);
	return 0;
}
