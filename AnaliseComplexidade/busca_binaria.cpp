#include <iostream>

using namespace std;

template<class T>

int binarySearch(const T arr[], int arrSize, const T &key) {
	int lo = 0, mid, hi = arrSize-1;
	
	while(lo <= hi) {
		mid = (lo+hi)/2;
		cout << mid << endl;
		
		if(key < arr[mid]) {
			hi = mid - 1;
		}
		else if (key > arr[mid]) {
			lo = mid + 1;
		}
		else return mid;
	}
	
	return -1;
}

int main() {
	
	int n = 10;
	int matriz[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int key = 8;
	
	int index = binarySearch(matriz, n, key);
	
	if (index != -1) 
		cout << key << " encontrado em " << index;
	else 
		cout << key << " nao encontrado";
	
	return 0;
}
