#include<bits/stdc++.h>
using namespace std;

//Constraints, N < 100000 y l,r < 1000000, la siguiente solución optimiza velocidad, sin embargo en memoria no mucho
int vec[1000000];



//Vamos a crear la clse de segment tree para realizar el siguiente ejercicio.
class SegmentTree{
    private:
        int Tree[4000000] = {0};
        int lazy[4000000] = {0};
        //en este caso la función nos regresa la suma, pero depende del programa
        //se puede modificar para que regrese otra operacion
        int combine(int a,int b){ return a+b; }
        //al momento de actualizar un nodo con la operacion 3, actualizamos sus hijos en
        //el lazy tree y si tenian una operacion pendiente la actualizamos
        void updateChildren(int child){
            if(child <= 4000000){
                if(lazy[child] == 0){
                    lazy[child] = 3;
                }else if(lazy[child] == 1){
                    lazy[child] = 2;
                }else if(lazy[child] == 2)
                    lazy[child] = 1;
                else if(lazy[child] == 3)
                    lazy[child] = 0;
                }
        }
        //la operacion 1 cambia los elementos del intervalo a 1, la operacion 2 los cambia a 0
        //y la 3 cambia los 0's por 1's y viceversa 
        void update(int vertex,int l,int r){
            if(lazy[vertex] != 0){
                if(lazy[vertex] == 1){
                    Tree[vertex] = abs(l-r) + 1;
                    lazy[vertex] = 0;
                    if(2*vertex + 1 <= 4000000)
                        lazy[2*vertex + 1] = 1;
                    if(2*vertex + 2 <= 4000000)    
                        lazy[2*vertex + 2] = 1;
                }else if(lazy[vertex] == 2){
                    Tree[vertex] = 0;
                    lazy[vertex] = 0;
                    if(2*vertex + 1 <= 4000000)
                        lazy[2*vertex + 1] = 2;
                    if(2*vertex + 2 <= 4000000)    
                        lazy[2*vertex + 2] = 2;
                }else if(lazy[vertex] == 3){
                    Tree[vertex] = (abs(l-r)+1) - Tree[vertex];
                    lazy[vertex] = 0;
                    updateChildren(2*vertex + 1);
                    updateChildren(2*vertex + 2);      
                }
            }
        }
    public:
        //constructor
        SegmentTree(){ }
        //funcion que construye el segment tree
        void buildTree(int* vec, int v,int L,int R){
            if(R<L){
                return;
            }else if(L==R){
                Tree[v] = vec[L];
                lazy[v] = 0;
            }else{
                int t = (L+R)/2;
                buildTree(vec,2*v+1,L,t);
                buildTree(vec,2*v+2,t+1,R);
                Tree[v] = combine(Tree[2*v+1],Tree[2*v+2]);
                lazy[v] = 0;
            }
        }    
        //funcion que cambia todos los elementos de un intervalo en 1's
        void position1(int v,int Lt,int Rt,int l,int r){
            update(v,Lt,Rt);
            if(r<l || r<Lt || Rt<l){
                return;
            }else if(Lt==l && Rt==r){
                Tree[v] = abs(r-l) + 1;
                if(2*v + 1 < 4000000)
                    lazy[2*v + 1] = 1;
                if(2*v + 2 < 4000000)
                    lazy[2*v + 2] = 1;
            }else{
                int t = (Lt+Rt)/2;
                position1(2*v+1,Lt,t,l,min(t,r));
                position1(2*v+2,t+1,Rt,max(t+1,l),r);
                Tree[v] = combine(Tree[2*v+1],Tree[2*v+2]);
            }
        }
        //funcion que cambia todos los elementos de un intervalo en 0's
        void position0(int v,int Lt,int Rt,int l,int r){
            update(v,Lt,Rt);
            if(r<l || r<Lt || Rt<l){
                return;
            }else if(Lt==l && Rt==r){
                Tree[v] = 0;
                if(2*v + 1 < 4000000)
                    lazy[2*v + 1] = 2;
                if(2*v + 2 < 4000000)
                    lazy[2*v + 2] = 2;
            }else{
                int t = (Lt+Rt)/2;
                position0(2*v+1,Lt,t,l,min(t,r));
                position0(2*v+2,t+1,Rt,max(t+1,l),r);
                Tree[v] = combine(Tree[2*v+1],Tree[2*v+2]);
            }
        }
        //funcion que cambia los 0's por 1's y viceversa
        void invert(int v,int Lt,int Rt,int l,int r){
            update(v,Lt,Rt);
            if(r<l || r<Lt || Rt<l){
                return;
            }else if(Lt==l && Rt==r){
                Tree[v] = abs(r-l) + 1 - Tree[v];
                updateChildren(2*v + 1);
                updateChildren(2*v + 2);
            }else{
                int t = (Lt+Rt)/2;
                invert(2*v+1,Lt,t,l,min(t,r));
                invert(2*v+2,t+1,Rt,max(t+1,l),r);
                Tree[v] = combine(Tree[2*v+1],Tree[2*v+2]);
            }
        }
        //funcion que regresa la cantidad de 1's en un intervalo dado
        int interval(int v,int Lt, int Rt,int l,int r){
            update(v,Lt,Rt);
            if(r<l || r<Lt || Rt<l){
                return 0;
            }else if(Lt==l && Rt==r){
                return Tree[v];
            }else{
                int t = (Lt+Rt)/2;
                return combine(interval(2*v+1,Lt,t,l,min(t,r)),interval(2*v+2,t+1,Rt,max(t+1,l),r));
            }
        }
};



int main(){
    SegmentTree Arbol;
    int T,M,Q,t;
    char letra;
    int l,r;
    string aux;
    cin >> T;
    for( int i=0;i<T;i++ ){ 
        int size = 0;
        cin >> M;
        for( int j=0;j<M;j++ ){
            cin >> t;
            cin >> aux;
            //leelos los datos y los ponemos en el arreglo
            for( int k=0;k<t;k++ ){
                for( int l=0;aux[l]!='\0';l++ ){
                    if(aux[l] == 49)
                        vec[size] = 1;
                    else
                        vec[size] = 0;    
                    size++;
                }
            }
        }
        Arbol.buildTree(vec,0,0,size);
        cin >> Q;
        for( int j=0;j<Q;j++ ){
            cin >> letra >> l >> r;
            //cambiamos todos los elementos a 1's en el intervalo [l,r]
            if(letra == 'F'){
                Arbol.position1(0,0,size,l,r);
            //cambiamos todos los elementos a 0's en el intervalo [l,r]    
            }else if(letra == 'E'){
                Arbol.position0(0,0,size,l,r);
            //cambiamos todos los elementos a su inverso en el intervalo [l,r]    
            }else if(letra == 'I'){
                Arbol.invert(0,0,size,l,r);
            //regresamos la cantidad de 1's en el intervalo [l,r]
            }else if(letra == 'S'){
                int x = Arbol.interval(0,0,size,l,r);
                cout << x << "\n";
            }
        }
    }
    return 0;
}