#include <bits/stdc++.h>

/*Recordar que un heap es una estructura de datos lineal que 
se puede visualizar como un arbol binario casi completos
*/
template<typename T> void print_queue(T& q){
         while(!q.empty()){             //Mientras es queue no este vacio
            std::cout<< q.top() << "";  //topeamos los elementos 
            q.pop();
         }
         std::cout<< '\n';   
        }

    int main(){

        std::priority_queue<int> q; 

        for(int n: {1,8,5,6,3,4,0,9,7,2})
            q.push(n);

        print_queue(q);

        std::priority_queue<int,std::vector<int>, std::greater<int> > q2;

        for(int n: {1,8,5,6,3,4,0,9,7,2})
            q2.push(n);

            print_queue(q2);


            //Using Lambda to compare elements.

        auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};

        std::priority_queue<int, std::vector<int>, decltype(cmp) > q3(cmp);

        for(int n: {1,8,5,6,3,4,0,9,7,2})
            q3.push(n);

        print_queue(q3);

        return 0;
    }