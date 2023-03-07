#include <bits/stdc++.h>

//Juan Angel Lopez Delgadillo 

#define MAXIMUS 4000000
int vector_aux[1000000];

using namespace std; // 

class SegmentTree{

    private:
    int combine(int a,int b){ 
        return a+b; 
    }
    //Creamos una estructura de datos de puros ceros.
    int tree[MAXIMUS] = {0};
    int lazy[MAXIMUS] = {0};

        //al momento de actualizar un nodo con la operacion 3, vamos a actualizar los hijos
        //Recordemos que la regla de transition es
        //0 -> 3
        //1 -> 2
        //2 -> 1
        //3 -> 0
       void updateChildren(int child_node){
            if(child_node <= MAXIMUS){
            const int state_transitions[4] = {3, 2, 1, 0};
                lazy[child_node] = state_transitions[lazy[child_node]];
            }
        }

    void update(int vertice,int left,int right){
        // Verifica si el nodo actual tiene una operación pendiente.
            if(lazy[vertice] != 0){
                // Realiza la operación correspondiente según el valor de lazy[vertice]
                if(lazy[vertice] == 1){
                    // Si es 1, establece el valor del nodo como la longitud del segmento que representa
                    tree[vertice] = abs(left-right) + 1;
                    lazy[vertice] = 0;
                    // Establece las operaciones pendientes de los hijos del nodo
                    if(2*vertice + 1 <= MAXIMUS)
                        lazy[2*vertice + 1] = 1;
                    if(2*vertice + 2 <= MAXIMUS)    
                        lazy[2*vertice + 2] = 1;
                }else if(lazy[vertice] == 2){     // Si es 2, establece el valor del nodo como 0
                    tree[vertice] = 0;
                    lazy[vertice] = 0;
                    // Establece las operaciones pendientes de los hijos del nodo.
                    if(2*vertice + 1 <= MAXIMUS)
                        lazy[2*vertice + 1] = 2;
                    if(2*vertice + 2 <= MAXIMUS)    
                        lazy[2*vertice + 2] = 2;
                }else if(lazy[vertice] == 3){    // Si es 3, invierte el valor del nodo actual
                    tree[vertice] = (abs(left-right)+1) - tree[vertice];
                    lazy[vertice] = 0;
                    // Actualiza los hijos del nodo actual
                    updateChildren(2*vertice + 1);
                    updateChildren(2*vertice + 2);      
                }
            }
        }


    public:
        SegmentTree(){ }
    
        void buildTree(int* pointer, int vert_index, int left, int right){
            //Si sucede el sin sentido de esto se muere el asunto.
            if(right < left){
                return;
            }
            //En este caso, se guarda el valor del elemento correspondiente en el arreglo ppinter
            else if(left == right){
                tree[vert_index] = pointer[left];
                lazy[vert_index] = 0;   //Seteamos el valor del lazy en 0
            }
            else{
                int t = (left+right)/2;

                //Una vez que se han construido los árboles de segmentos para los subrangos,
                //se combina la información de ambos subárboles en el nodo actual del árbol de segmentos. 
                buildTree(pointer, 2*vert_index + 1, left, t);
                buildTree(pointer, 2*vert_index + 2, t+1, right);
                tree[vert_index] = combine(tree[2*vert_index + 1], tree[2*vert_index+2]);
                lazy[vert_index] = 0; //Seteamos el valor del lazy en 0
            }
        }


          void function_pos1(int vertice,int left_t,int right_t,int left,int right){
            //Usamos el update solo para verificar el nodo
            update(vertice,left_t,right_t);

            //Los sin sentidos que podrían ocurrir y matar el arbol
            if(right<left || right<left_t || right_t<left){
                return;
            }else if(left_t==left && right_t==right){
                tree[vertice] = abs(right-left) + 1;
                if(2*vertice + 1 < MAXIMUS)
                    lazy[2*vertice + 1] = 1;
                if(2*vertice + 2 < MAXIMUS)
                    lazy[2*vertice + 2] = 1;
            }else{

                //En caso contrario, se divide el intervalo correspondiente al nodo actual en dos y se llama recursivamente a la
                //función para cada uno de los dos subintervalos. Luego se combina el resultado de los subintervalos para 
                //actualizar el nodo actual en tree.
                int t = (left_t+right_t)/2;
                function_pos1(2*vertice+1,left_t,t,left,min(t,right));
                function_pos1(2*vertice+2,t+1,right_t,max(t+1,left),right);
                tree[vertice] = combine(tree[2*vertice+1],tree[2*vertice+2]);
            }
        }

        void function_pos0(int vert_index, int left_t, int right_t, int left, int right){
            //Nuevamente verificamos el nodo
            update(vert_index, left_t, right_t);

            //Descontamos los casos atipicos que pueden matar el arbol
            if(right < left_t || right < left  || left > right_t){
                return;
            }
            if(left <= left_t && right_t <= right){
                tree[vert_index] = 0;
                if(2*vert_index + 1 < MAXIMUS){
                    lazy[2*vert_index + 1] = 2;
                }
                if(2*vert_index + 2 < MAXIMUS){
                    lazy[2*vert_index + 2] = 2;
                }
                return;
            }else{

                //se divide el intervalo correspondiente al nodo actual en dos y se llama recursivamente a la
                //función para cada uno de los dos subintervalos.
            int t = (left_t + right_t) / 2;
            function_pos0(2*vert_index + 1, left_t, t, left, right);
            function_pos0(2*vert_index + 2, t+1, right_t, left, right);
            tree[vert_index] = combine(tree[2*vert_index + 1], tree[2*vert_index + 2]);  //Se vuelven a combinar
            }
        }

        // Esta función recibe cuatro parámetros enteros que definen el rango de un subárbol 
        //en el que se desea invertir los valores 0 y 1.
        void invert01(int vertice,int left_t,int right_t,int left,int right){

            //Verificamos los nodos y actualizamos los valores pendientes del arbol
            update(vertice,left_t,right_t);
            if(right<left || right<left_t || right_t<left){
                return;
                //Verificamos si el subarbol actual esta contenido sobre el rango especificado
            }else if(left_t==left && right_t==right){
                tree[vertice] = abs(right-left) + 1 - tree[vertice];
                updateChildren(2*vertice + 1);
                updateChildren(2*vertice + 2);
            }else{
                //Nuevamente se divide el intervalo correspondiente al nodo actual en dos y se llama recursivamente a la
                //función para cada uno de los dos subintervalos.
                int t = (left_t+right_t)/2;
                invert01(2*vertice+1,left_t,t,left,min(t,right));
                invert01(2*vertice+2,t+1,right_t,max(t+1,left),right);
                tree[vertice] = combine(tree[2*vertice+1],tree[2*vertice+2]);
            }
        }

        int interval(int vert_index, int left_t, int right_t, int left, int right){
            //Actualizamos como siempre
            update(vert_index, left_t, right_t);
            //verificamos los casos atipicos 
            if(right < left_t || right_t < left){
                return 0;
            } //Vemos si esta contenido
            if(left <= left_t && right_t <= right){
                return tree[vert_index];
            }else{
                //Partimos en dos y volvemos a combinar los subarboles.
            int t = (left_t + right_t) / 2;
            return combine(interval(2 * vert_index + 1, left_t, t, left, right), interval(2 * vert_index + 2, t + 1, right_t, left, right));
            }
        }
};


int main() {
    //Es hora de probar el codigo, declaramos un segment tree
    SegmentTree FinalTree;
    int T, M, Q, t;
    string aux;
    char word;
    int left, right;

    cin >> T;
    while (T--) {
        int size = 0;
        cin >> M;
        while (M--) {
            cin >> t >> aux;
            for (int j = 0; j < t; j++) {
                for (int ite = 0; aux[ite] != '\0'; ite++) {
                    vector_aux[size++] = (aux[ite] == '1');
                }
            }
        }
        FinalTree.buildTree(vector_aux, 0, 0, size);

        cin >> Q;
        while (Q--) {
            cin >> word >> left >> right;
            switch (word) {
                case 'F':
                    FinalTree.function_pos1(0, 0, size, left, right);
                    break;
                case 'E':
                    FinalTree.function_pos0(0, 0, size, left, right);
                    break;
                case 'I':
                    FinalTree.invert01(0, 0, size, left, right);
                    break;
                case 'S':
                    int ans = FinalTree.interval(0, 0, size, left, right);
                    cout << ans << "\n";
                    break;
            }
        }
    }

    return 0;
}

