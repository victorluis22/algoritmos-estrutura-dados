#include <iostream>

using namespace std;

int nat(int n) {
    int f;

    if(n == 1) {
        cout << n << endl;
        return n;
    }

    f = 2 + nat(n - 1);

    cout << f << endl;

    return f;
}

int main() {

    int el;

    cout << "Insira um número inteiro: "; cin >> el;

    if (el % 2 == 0) {
        el--;
    }

    nat(el);

    return 0;
}
