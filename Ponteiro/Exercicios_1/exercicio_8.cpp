#include <iostream>

using namespace std;

int main(){
	int mat[] = {4, 5, 6};
	
	for(int j = 0; j < 3; j++) {
		cout << "\n" << (mat+j);
	}
	return 0;
}
