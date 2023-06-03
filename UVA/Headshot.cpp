#include<bits/stdc++.h>

//Juan Angel López Delgadillo

// UVA 1636 Headshot...

using namespace std;


int main() {
    string str;  //Variable para almacenar la cadena de entrada

    //while principal para procesar cada caso de prueba
    while (cin >> str) {
        int length = str.length();  // obtenemos la longitud de la cadena de entrada
        int zeroCount = 0, oneCount = 0, consecutiveZeroCount = 0;  // Variables para contar los ceros y unos
        //consecutivos....
        //recorrer la cadena de entrada
        for (int i = 0; i < length; i++) {
            if (str[i] == '1'){
                continue; } //si encuentra un 1, saltar a la siguiente iteración
            
            zeroCount++;  //incrementar el contador de ceros
            
            //verificar si el siguiente elemento tambien es un 0
            if (str[(i + 1) % length] == '0')
                consecutiveZeroCount++;  //incrementar el contador de ceros consecutivos
        }
        
        //calcular el resultado: consecutiveZeroCount - zeroCount * (zeroCount / length)
        if (consecutiveZeroCount * length == zeroCount * zeroCount){
            cout << "EQUAL" << '\n'; 
            } //imprimir EQUAL si la expresión es igual
        else if (consecutiveZeroCount * length > zeroCount * zeroCount){
            cout << "SHOOT" << '\n';
            }  //imprimir SHOOT si la expresión es mayor
        else{
            cout << "ROTATE" << '\n'; } //imprimir "ROTATE" si la expresión es menor
    }
    
    return 0;
}