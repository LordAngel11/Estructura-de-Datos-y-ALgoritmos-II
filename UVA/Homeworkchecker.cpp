#include <bits/stdc++.h>

using namespace std;

/*Aqui hago las modifcaciones cuando me sale Wrong Answer y tengo el output estandar bien xd*/

int main(){

    char operador;
    long long a,b;
    int counter = 0;
    char caracter[1000];

    while (scanf("%d%c%d=%s", &a,&operador,&b,caracter) == 4)
    {
            //cout<<"Entro todo :D"<<endl;
            if(operador == '+'){
                // Compruebo si la suma es igual al número especificado en la cadena
            if (a + b == atoi(caracter))
                if(a + b == atoi(caracter)){
                    counter++;
                }
            }else if(operador == '-'){   // Compruebo si la resta es igual al número especificado en la cadena
                if(a-b == atoi(caracter)){
                    counter++;
                }
            }
    }

    cout<<counter<<'\n';
   
   return 0;
}