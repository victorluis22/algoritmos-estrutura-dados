#include <iostream>

using namespace std;

long double fatorial(unsigned int num) {
    long double resultado;

    if (num == 0) {
        resultado = 1;

        cout << "Fatorial de " << num << ": " << resultado << endl;

        return resultado;
    }
    else{
        resultado = fatorial(num-1) * num;

        cout << "Fatorial de " << num << ": " << resultado << endl;

        return resultado;
    }

}


int main() {
    int el;

    cout << "Insira um número inteiro: "; cin >> el;

    fatorial(el);

    return 0;

}

