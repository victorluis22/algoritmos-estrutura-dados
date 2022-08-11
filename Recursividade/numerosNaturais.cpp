#include <iostream>

using namespace std;

int naturais(int num, int inicio) {

    if (inicio == num) {
        cout << inicio << " ";
        return inicio;
    }
    else{
        cout << inicio << " ";
        return naturais(num, inicio+1);
    }
}

int main() {

    naturais(100, 0);

    return 0;
}
