#include <iostream>


using namespace std;

int main() {
	int i, i1, i2, length, k, n = 8;
	int a[n] = {1, 8, 1, 2, 5, 0, 12, 11};

	for (i = 0, length = 1; i < n-1; i++) {
		for (i1 = i2 = k = i; k < n-1 && a[k] < a[k+1]; k++, i2++);
		if ( length < i2 - i1 + 1)
			length = i2 - i1 + 1;
		
	}
	
	cout << length;
	return 0;
}
