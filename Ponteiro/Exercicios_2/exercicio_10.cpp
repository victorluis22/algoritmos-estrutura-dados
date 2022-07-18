#include <iostream>

using namespace std;

int main() {
	
	int x = 20, *px;
	
	px = &x;
	
	*px /= 5;
	
	cout << x;
	
	return 0;
}
