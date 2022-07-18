#include <iostream>

using namespace std;

int main() {
	
	int arr[5] = {30, 20, 50, 70, 10};
	int *parr = &arr[4];
	int inx = 0;
	inx = *parr++;
	
	cout << inx;
	
}
