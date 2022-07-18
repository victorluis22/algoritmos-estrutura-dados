#include <iostream>

using namespace std;

int main() {
	int mat[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	
	cout << *(mat++);
	return 0;
}
