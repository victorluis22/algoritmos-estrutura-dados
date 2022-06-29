#include <iostream>

using namespace std;

int main() {
	int n = 5, *p = &n, &r = n;  //&r = n, mesma variável, nomes diferentes
	
	cout << n << ' ' << *p << ' ' << r << endl;
	n = 7;
	cout << n << ' ' << *p << ' ' << r << endl;
	*p = 9;
	cout << n << ' ' << *p << ' ' << r << endl;
	r = 10;
	cout << n << ' ' << *p << ' ' << r << endl;
	return 0;
}
