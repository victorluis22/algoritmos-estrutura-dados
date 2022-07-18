#include <iostream>

using namespace std;

int main() {
	
	int x = 10, *px = &x;
	float y = 5.9, *py = &y;
	
	cout << x << endl;
	cout << *py << endl;
	cout << px << endl;
	cout << &y << endl;
	cout << *px << endl;
	cout << y << endl;
	cout << py << endl;
	cout << &x << endl;
	cout << px++ << endl;
	cout << *&px << endl;
	
	return 0;
}
