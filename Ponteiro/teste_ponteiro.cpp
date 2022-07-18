#include <iostream>

using namespace std;

void printArray(int **p){
	for(int i=0; i < 3; i++) {
		cout << **(p+i) << endl;
	}
}


int main() {
	
	int a = 9;
	int *b = &a;
	int **c;
	
	int *array[3] = {b, b, b};
	
	c = array;
	
	printArray(array);
	
	c = &b;
	
	cout << **c;
	
	
	return 0;
}
