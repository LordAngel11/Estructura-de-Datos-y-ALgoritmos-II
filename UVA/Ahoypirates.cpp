#include <bits/stdc++.h>

//JUan Angel López Delgadillo
//Uva 11402 Ahoy pirates
using namespace std;

int segmentTree[1024000 * 3]; // Segment Tree para la suma
int lazy[1024000 * 3]; // Almacena las operaciones pendientes
char str[1050000];

void buildSegmentTree(int node, int start, int end) {
    lazy[node] = 0;
    if (start > end){
        return;
    }
    if (start == end) {
        segmentTree[node] = str[start] - '0';  //Inicializamos el nodo hoja del segment con el valor correspondiente
        return;
    }
    int mid = (start + end) / 2;
    buildSegmentTree(node * 2 + 1, start, mid);  //COnstruimos la parte derecha del arboli
    buildSegmentTree(node * 2 + 2, mid + 1, end); //Construimos la parte izquierda del arbol
    segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2]; //Combinamos los subarboles
}


// Combina dos operaciones en una nueva operación
int combineOperation(int prevOp, int curOp) {
    if (curOp == 1){
        return 1;
        }
    if (curOp == 2){
        return 2;
        }
    if (prevOp == 3){
        return 0;
        }
    else if (prevOp == 1){
        return 2;
    }
    else if (prevOp == 2){
        return 1;
    }
    else{
        return 3;
    }
}


        // Actualiza el Segment Tree pendiente
void updateLazy(int node, int start, int end) {
    if (lazy[node] && start != end) {
        int mid = (start + end) / 2;
        lazy[node * 2 + 1] = combineOperation(lazy[node * 2 + 1], lazy[node]);
        lazy[node * 2 + 2] = combineOperation(lazy[node * 2 + 2], lazy[node]);
    }
    if (lazy[node] == 1) {
        segmentTree[node] = 0; //modifica el nodo actual a 0
    } else if (lazy[node] == 2) {
        segmentTree[node] = end - start + 1; //modifica el nodo actual a la cantidad total de elementos
    } else if (lazy[node] == 3) {
        segmentTree[node] = (end - start + 1) - segmentTree[node]; //invierte el nodo actual
    }
    lazy[node] = 0;
}
//Realiza una consulta en el Segment Tree
int querySegmentTree(int node, int start, int end, int queryStart, int queryEnd) {
    updateLazy(node, start, end);
    if (queryStart > end || queryEnd < start){
        return 0; //NO hay superposicion o traslape tons todo okay
    }
    else if (queryStart <= start && end <= queryEnd)
        return segmentTree[node];  //SI hay traslape tons devuelve el valor del nodo
    int mid = (start + end) / 2;
    return querySegmentTree(node * 2 + 1, start, mid, queryStart, queryEnd) +
           querySegmentTree(node * 2 + 2, mid + 1, end, queryStart, queryEnd);
}


// Actualiza el Segment Tree con una operación determinada
void updateSegmentTree(int node, int start, int end, int operation, int updateStart, int updateEnd) {
    updateLazy(node, start, end);
    if (updateStart > end || updateEnd < start){
        return;
    }
    else if (updateStart <= start && end <= updateEnd) {
        lazy[node] = operation;
        updateLazy(node, start, end); //Actualizamos el nodo del lazy tree actual
    } else {
        int mid = (start + end) / 2;
        updateSegmentTree(node * 2 + 1, start, mid, operation, updateStart, updateEnd);
        updateSegmentTree(node * 2 + 2, mid + 1, end, operation, updateStart, updateEnd);
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
    }
}

int main() {
    int t, m, r, a, b;
    char c;
    char in[100];
    cin >> t;
    int cases = 1;
    while (t--) {
        scanf("%d", &m);
        int n = 0;
        while (m--) {
            scanf("%d %s", &r, in);
            while (r--) {
                for (int i = 0; in[i]; i++, n++){
                    str[n] = in[i]; //almacenamos en el arreglo de caracteres.
                }
            }
        }
        n--;
        buildSegmentTree(0, 0, n);
        cin >> m;
        printf("Case %d:\n", cases++);
        int queryCount = 1;
        for (int i = 0; i < m; i++) {
            cin >> c >> a >> b;
            if (c == 'F') {
                updateSegmentTree(0, 0, n, 2, a, b); //Actualizamos con F
            } else if (c == 'E') {
                updateSegmentTree(0, 0, n, 1, a, b); //Actualizamos con E
            } else if (c == 'I') {
                updateSegmentTree(0, 0, n, 3, a, b); //Actualizamos con I.
            } else {
                cout << "Q" << queryCount++ << ": " << querySegmentTree(0, 0, n, a, b) << endl;
            }
        }
    }
}
