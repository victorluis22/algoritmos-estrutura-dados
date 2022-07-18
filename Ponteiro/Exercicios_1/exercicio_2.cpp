#include <iostream>

using namespace std;

int main() {
	
	float i = 3, j = 5;
	float *p = &i, *q = &j;
	
	cout << "\n" << *p - *q;
	cout << "\n" << **&p;
	cout << "\n" << 3 * - *p / *q + 7;
	return 0;
}
