#include<bits/stdc++.h>

//Juan Angel Lopez Delgadillo 
//UVA 255 Correct Move
using namespace std;


int main() {
    int diff, reina, rey, reina_move, diff;

    while (std::cin>>rey>>reina>>reina_move)
    {
        if(rey == reina){

            std::cout<<"Illegal state\n"; 
            continue;
        }
        if(((reina_move - reina) % 8 != 0 && reina_move / 8 != reina/8) || reina == reina_move){

            std::cout<<"Illegal move\n";
            continue;
        }

        if(((rey - reina) % 8 == 0 && (rey-reina) % 8 == 0) || (rey / 8 == reina /  8 && rey / 8 == reina_move / 8)){
            if(rey <= max(reina, reina_move) && rey >= min(reina, reina_move)) {
                std::cout<<("Illegal move\n");
                continue;
            }
        }

        diff = max(rey, reina_move) - min(rey, reina_move);

        if(diff == 8 || (diff == 1 && rey / 8 == reina_move / 8)){
            std::cout<<"Move not allowed\n";
            continue;
        }

        if((rey == 0 && reina_move == 0) || (rey == 7 && reina_move == 14) || (rey == 56 && reina_move == 49) || (rey == 63 && reina_move == 54)){
            std::cout<<"Stop\n";
        }else{
            std::cout<<("Continue\n");
        }
    }
    
}