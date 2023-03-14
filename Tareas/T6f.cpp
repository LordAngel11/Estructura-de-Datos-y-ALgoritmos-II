#include <bits/stdc++.h>
using namespace std;

//Juan Angel Lopez Delgadillo

//una funcion para aleatorizar
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
    int val, priority, size;
    node *left, *right;

    node(int _val) {
        val = _val;
        //Aqui asignamos la prioridad de forma aleatora como en los arboles aleatorizados
        priority = rng();
        size = 1;
        left = right = nullptr;
    }
};

//Funcion que regresa el size del arbol
int getSize(node *root) {
    return root ? root->size : 0;
}

void updateSize(node *root) {
    //aqui vamos aumentando el size del Treap mientras contamos los nodos de los hijos mas el del actual
    if (root)
    root->size = getSize(root->left) + getSize(root->right) + 1;
}

//Aqui vamos a implementar las variantes de split y Merge para el uso de arreglos dinamicos

void split(node *root, int c, node *&left, node *&right) {
    //Si no hay raiz entonces los hijos no existen y son vacios
    if (!root) left = right = nullptr;
    //En cambio, si existe un nodo raiz, entonces
    else {
        //Calculamos el size de subarbol izquierdo
        int lsize = getSize(root->left) + 1;
        //Si el tamaño es menor al lado c, entonces 
        if (lsize <= c) {
            left = root;
            //Volvemos a dividir y actualizamos de forma recursiva
            split(root->right, c-lsize, left->right, right);
            updateSize(left);
        } else {
            //En cambio si el tamaño es mayor dividimos y actualizamos para el subarbol derecho
            right = root;
            split(root->left, c, left, right->left);
            updateSize(right);
        }
    }
}

//Funcion Merge para unir
node* merge(node *left, node *right) {
    //SI no hay hijo izquierdo regresas el derecho
    if (!left){
        return right;
        }
    //Si no hay hijo dereccho regresas el izquierdo in a Nutshell :v    
    if (!right){
        return left;
    }
    //En caso de no existir ambos 
    /*
    if(!left || !right){
        return -1;
    }
    */
    //Si las prioridades del lado izquierdo son mayores a las del lado derecho
    if (left->priority > right->priority) {
        //hacemos el merge de forma recursiva y actualizamos de modo que devolvemos el subarbol izquierdo
        left->right = merge(left->right, right);
        updateSize(left);
        return left;
    } else {
        //Por otro lado hacemos lo mismo, actualizamos pero devolvemos el subarbol derecho
        right->left = merge(left, right->left);
        updateSize(right);
        return right;
    }
}

//El uso de arreglos dinamicos permite la inserrcion en cualquier posición desplazando 
// a la derecha todos los elementos situados a partir de dicha posición.

//A partir de esto vamos a implementar la incersion en cualquier posicion
void insertInPosition(node *&root, int pos, int val) {
    //Declaramos 
    node *newNode = new node(val);
    node *left, *right;
    //Y llamamos de forma recursiva split y merge
    split(root, pos-1, left, right);
    root = merge(left, newNode);
    root = merge(root, right);
}

//Del mismo modo con las variantes ya hechas previamente vamos a eliminar 
//en cualquier posicion
void erasePosition(node *&root, int pos) {
    node *left, *mid, *right;
    split(root, pos-1, left, mid);
    split(mid, 1, mid, right);
    root = merge(left, right);
}

//Devuelva el valor que se encuentra en una determinada posición
int getValueInPos(node *root, int pos) {
    //Mientras tengamos una raíz
    while (root) {
        //Se consigue el tamaño del subarbol izquierdo y se almacena en lsize
        int lsize = getSize(root->left);
        //Si el tamaño es equivalente a la posicion anterior , re segresa el valor de la raiz
        if (lsize == pos-1){
            return root->val;
        }
        //Si es mayor o igual a la posicion se regresa el izquierdo.
        if (lsize >= pos){ 
            root = root->left;
        }
        //Si es menor se disminuye y regresamos el derecho
        else {
            pos -= lsize+1;
            root = root->right;
        }
    }
    return -1; // si la posición no existe en el arbol, en este caso la pelota
}

//Ahora para realizar una implementacion para el problema de las pelotas

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //numero de pelotas y q PETICIONES
    int n, q;
    cin >> n >> q;

    node *root = nullptr;

    //vamos insertando en el arbol con prioridad aleatoria
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x; //VALOR del nodo
        insertInPosition(root, i, x);
    }

    while(q--){
        int type_peticion;
        cin >> type_peticion;

        if(type_peticion == 0){
            for (int i = 1; i <= n; i++) {
                //Imprime la linea con el valor maximo de la pelota en el rango de posiciones
                cout << getValueInPos(root, i) << " ";
            }
            cout << "\n";
        }
        else if(type_peticion == 1){
            //robamos pelota
            int pos;
            cin >> pos;
            erasePosition(root, pos);
            n--; //disminuimos el numero de pelotas
        }
        else if(type_peticion == 2){
            int pos,newpos;
            cin >> pos, newpos;

            //Extraemos la pelota y luego
            int valor = getValueInPos(root, pos);
            erasePosition(root, pos);
            n--; //disminuye el numero de pelotas

            //la colocamos en la nueva posicion
            insertInPosition(root, newpos, valor);
            n++;    //aumenta, en este caso regresa al tamño original
        }
    }
    return 0;
}