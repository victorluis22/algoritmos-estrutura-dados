#include <iostream>

using namespace std;

int exponencial3(int num) {
    if(num == 0) {
        return 1;
    }
    else{
        return 3 * exponencial3(num-1);
    }
}

int main() {

    int el;

    cout << "Insira um número inteiro: "; cin >> el;

    cout << "3^" << el << ": " << exponencial3(el) << endl;


    return 0;
}
