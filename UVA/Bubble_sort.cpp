#include<bits/stdc++.h>

//Juan Angel Lopez Delgadillo 
//UVA 12004 Bubble Sort
using namespace std;


//Codigo proporcionado
int findSwaps(int n, int a[]){

    int count = 0, i, m , j, temp, b[100000];

    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }

    for(i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(b[j] > b[j+1]){
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;

                count++;
            }
        }
    }
    return count;
}

int main(){

    int T; //(T <= 1000) Test cases.
    long long n;

    std::cin>>T;

    for(int i = 1; i<= T; i++){
        std::cin>>n;
        n = n * (n-1)/2; 
    
        if(n & 1){
            std::cout<<"Case "<<i<<": "<< n <<"/2\n";
        }else{
            std::cout<<"Case "<<i<<": "<< n/2 << "\n";
        }
    }

    return 0;
}