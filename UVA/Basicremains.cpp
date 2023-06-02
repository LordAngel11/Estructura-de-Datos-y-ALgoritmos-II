#include<bits/stdc++.h>

//JUan Angel López Delgadill

//UVa Uhunt 10551 BasicRemains
using namespace std;

int main() {
    int base, remainder;
    char number[1001], div[20];
    
    while (cin >> base && base != 0) {
        cin >> number >> div;
        
        int i, len = strlen(div), power = 1;
        int divisor = 0;

        //coonvertir la cadena 'div' a un número entero en la base
        
        for (i = len - 1; i >= 0; i--) {
            divisor += (div[i] - '0') * power;
            power *= base;
        }
        
        //aqui convertimos la cadena number a su representación decimal
        int tmp = 0;
        for (i = 0; number[i]; i++) {
            tmp = tmp * base + (number[i] - '0');
            tmp %= divisor;
        }
        
        int result[50], at = -1;
        
        //Convertir el resto a la basee
        while (tmp) {
            result[++at] = tmp % base;
            tmp /= base;
        }
        
        //IMprimimos :D
        if (at == -1) {
            cout << "0";
        } else {
            for (i = at; i >= 0; i--) {
                cout << result[i];
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
