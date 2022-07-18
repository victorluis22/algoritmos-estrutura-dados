#include <iostream>

using namespace std;

int main(){
	int mat[] = {4, 5, 6};
	int *p = mat;
	
	for(int j = 0; j < 3; j++) {
		cout << "\n" << *p++;
	}
	
	return 0;
}
