#include <bits/stdc++.h>

using namespace std;

//Juan Angel Lopez Delgadillo
// UVA 11682-Laser Sculpture Lv. 3

/*Vamos a escribir un programa que dada la altura y la longitud del bloque,
y su formato final, encuentre el numero total de veces que el laser fue encendido*/

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A, C; // Altura y Longitud del bloque

    do{
        cin>>A;
        if(A == 0){
            break;
        }
        cin>>C;
        //Inicializamos
        int A_last = A;
        int A_Update;
        int cortes = 0;

        
    //Vamos a leer cada altura de cada nivel
        do{
            cin >> A_Update;
            //Calculamos la diferenciaa
            if(A_last > A_Update){
                cortes += A_last - A_Update;
            }

            //Aqui actualizamos la altura
            A_last = A_Update;
            //Avanzamos el laser
            /*--------------------------------------
                    |
                    | A A A
                    A A A A
                  A A A A A      (Dinujo imaginacion)
            ---------------------------------------*/
            C--;
        }while(C > 0);
        
        //Una vez que termino de recorrer el rasho laser el bloque imprimo los cortes

        cout<<cortes<<'\n';
    }while (true);
    
    return 0;
}