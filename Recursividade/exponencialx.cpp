#include <iostream>

using namespace std;

int exponencialx(int base, int exp) {
    if(exp == 0) {
        return 1;
    }
    else{
        return base * exponencialx(base, exp-1);
    }
}

int main() {

    int el, x;

    cout << "Insira a base: "; cin >> x;
    cout << "Insira o expoente: "; cin >> el;

    cout << x << "^" << el << ": " << exponencialx(x, el) << endl;


    return 0;
}
