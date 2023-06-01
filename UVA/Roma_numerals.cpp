#include<bits/stdc++.h>

//Juan Angel López Delgadillo
//Uva 11616 Roman Numerals

using namespace std;

// Función para convertir un número romano en decimal
int romanToDecimal(string roman) {
    map<char, int> romanValues;
    romanValues['I'] = 1;
    romanValues['V'] = 5;
    romanValues['X'] = 10;
    romanValues['L'] = 50;
    romanValues['C'] = 100;
    romanValues['D'] = 500;
    romanValues['M'] = 1000;

    int decimal = 0;
    int prevValue = 0;

    // Iterar a través de los dígitos romanos de derecha a izquierda
    for (int i = roman.length() - 1; i >= 0; i--) {
        int currentValue = romanValues[roman[i]];

        // Si el valor actual es mayor o igual al valor anterior, se suma al decimal
        if (currentValue >= prevValue) {
            decimal += currentValue;
        } else {
            // Si el valor actual es menor que el valor anterior, se resta al decimal
            decimal -= currentValue;
        }

        prevValue = currentValue;
    }

    return decimal;
}

// Función para convertir un número decimal en romano
string decimalToRoman(int decimal) {
    map<int, string> romanValues;
    romanValues[1] = "I";
    romanValues[4] = "IV";
    romanValues[5] = "V";
    romanValues[9] = "IX";
    romanValues[10] = "X";
    romanValues[40] = "XL";
    romanValues[50] = "L";
    romanValues[90] = "XC";
    romanValues[100] = "C";
    romanValues[400] = "CD";
    romanValues[500] = "D";
    romanValues[900] = "CM";
    romanValues[1000] = "M";

    string roman;

    // Iterar a través de los valores romanos en orden descendente
    auto it = romanValues.rbegin();

    // Mientras el número decimal sea mayor que 0 y existan valores romanos
    while (decimal > 0 && it != romanValues.rend()) {
        if (decimal >= it->first) {
            // Si el número decimal es mayor o igual al valor romano actual, se agrega al resultado y se resta del decimal
            roman += it->second;
            decimal -= it->first;
        } else {
            // Si el número decimal es menor que el valor romano actual, se pasa al siguiente valor romano
            ++it;
        }
    }

    return roman;
}

int main() {
    string input;

    // Leer la entrada mientras haya valores para procesar
    while (cin >> input) {
        if (isdigit(input[0])) {
            // Si el primer carácter de la entrada es un dígito, se asume que es un número decimal
            int decimal = stoi(input);
            cout << decimalToRoman(decimal) << endl;
        } else {
            // De lo contrario, se asume que es un número romano
            int decimal = romanToDecimal(input);
            cout << decimal << endl;
        }
    }

    return 0;
}
