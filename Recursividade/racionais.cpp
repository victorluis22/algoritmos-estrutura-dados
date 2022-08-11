#include <iostream>

using namespace std;

float racionais (unsigned int num) {
    int resultado;

    if(num == 0) {
        return 1;
    }
    else{

        return racionais(num-1) + (1/racionais(num-1));
    }
}

int main() {
    int primeiros = 10;

    for (int i = 0; i <= primeiros; i++) {
        cout << i << "°: " << racionais(i) << endl;
    }


    return 0;
}
