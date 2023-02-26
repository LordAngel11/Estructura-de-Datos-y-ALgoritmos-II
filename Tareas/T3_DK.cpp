//Juan Angel López Delgadillo

#include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<int>> version_tree;

int MIN,MAX;

//funciones que regresan los nodos hijos.
int left_child(int i){
    return 2*i+1;
}
int right_child(int i){
    return 2*i+2;
}

//Vamos a usar una funcion recursiva para la elaboración del arbol de segmentos.
void build_SegmentTree(std::vector<int> &array, int left, int right, int in_vertice){

    //el vector de arreglos nos permite realizar las operaciones del segment tree
    //En este caso, cuando llegamos al fondo del arbol a cualquier hoja, insertamos un uevo elemento.
    if(left == right){
        version_tree[in_vertice].push_back(array[left]);  //insertamos 
        return;
    }
     if(left > right){
        return;         //si el elemento izquierdo es mayor que el derecho no sería un segment tree
    }
    //No tendria sentido que un nodo izquierdo sea mayor al derecho... basicamente.

    //FInalmente si no hay hojas, tons vamos a rellenar a todos los hijos usando recursión
    int mid = (left+right)/2;      //Aqui partimos el segmento a la mitad.
    build_SegmentTree(array, left, mid, left_child(in_vertice));    //volvemos a construir el segment tree con ambas partes
    build_SegmentTree(array, mid+1, right, right_child(in_vertice));


    //Una vez que tenemos esto vamos a hacer merge del nodo actual con los hijos, para esto nuestro vector de arbol debera estar ordenado.
    merge(version_tree[left_child(in_vertice)].begin(), version_tree[left_child(in_vertice)].end(),
    version_tree[right_child(in_vertice)].begin(), version_tree[right_child(in_vertice)].end(), 
    std::back_inserter(version_tree[in_vertice]));
}

void build_optimizer(std::vector<int> &array, int size){
    //version_tree.resize(4*size);   //hacemos un resize del vector del arbol
    build_SegmentTree(array, 0, size-1, 0);

    //Minimum and maximum value of the array.
    MIN = version_tree[0][0];  //raiz
    MAX = version_tree[0][size - 1];  //ultimo elemento
}

int query_helper(int in_vertice, int left, int right, int qL, int qR, int values){

    //Lo que vamos a hacer en esta función es hacer las consultas para ver si hay elementos menores o iguales en el segmento

    //En caso de que haya algo fuera del rango matamos el programa.
    if(left > right || left > qR || right < qL){
        return 0;
    }
    
    //Si el elemento vive en el rango del segmento verificamos cuantos elementos tiene
    if(left >= qL && right < qR){
        int result = (std::lower_bound(version_tree[in_vertice].begin(), version_tree[in_vertice].end(), values+1)) - version_tree[in_vertice].begin();
        return result;
    }

    //DIvidimos el segemento as always y regresamos la suma de lo obtenido.
    int mid = (left+right)/2;
    return query_helper(left_child(in_vertice), left, mid, qL, qR, values) + query_helper(right_child(in_vertice), mid+1, right, qL, qR, values);
}

int querys(int size, int qL, int qR, int nval){

    //Estas variables nos van a servir para el binary search
    int lower = MIN;
    int upper = MAX;
    int mid;

    //BUsqueda binaria.
    for(; lower != upper; mid = (lower + upper)/2){
    int aux = query_helper(0, 0, size-1, qL, qR, mid);

    if(aux <= nval){
        lower = mid+1;
    }
    else{
        upper = mid;
    }
}

    return lower;
}

void update_helper(int in_vertice, int left, int right, int index, int value, int up_value){

    if(left > right){
        return;
    }
    if(left > index){
        return;
    }
    if(right < index){
        return;
    }

    if(left == right){
        version_tree[in_vertice][0] = up_value;
        return;
    }

    int mid = (left+right)/2;
    //Bajamos en el arbol y vamos actualizando de forma recursiva
    if(index <= mid){   
        update_helper(left_child(in_vertice),left, mid,index, value, up_value);
    }
    else{
        update_helper(right_child(in_vertice), mid+1, right, index, value, up_value);
    }
    
    //Binary search para encontrar la posicion del valor del nodo y borrarlo.

    auto actual_index = std::lower_bound(version_tree[in_vertice].begin(), version_tree[in_vertice].end(), value);
        version_tree[in_vertice].erase(actual_index);

    //Binary search para insertar nuevo valor en el arbol

    auto new_index = std::upper_bound(version_tree[in_vertice].begin(), version_tree[in_vertice].end(), up_value);
        version_tree[in_vertice].insert(new_index, up_value);
}

void update(std::vector<int> &array, int size, int index, int value){
    update_helper(0,0, size-1, index, array[index], value);
    array[index] = value;
    MIN = version_tree[0][0];
    MAX = version_tree[0][size - 1];
}

int main(){
    
    int N,M;  //Constraints 1 \leq N \leq 20,000
    std::vector<int> tree;
    std::cin>>N;

    version_tree.assign(4*N, std::vector<int> ());
    
    for(int i = 0; i<N; i++){
        int temp;
        std::cin>>temp;
        tree.push_back(temp);
    }
    build_optimizer(tree, N);

        std::cin>>M;
        //Peticiones
    for(int j = 0; j<M; j++){
        int peticion;
        std::cin>>peticion;
            //petcion of type 0
            if(peticion == 0){
                int left,right, val;

                std::cin>> left >> right >> val;
                std::cout<<querys(left,right,N,val)<<std::endl;
            }
            if(peticion == 1){
                int index, value;
                std::cin>>index>>value;
                update(tree,N,index,value);
            }
    }

    return 0;
}