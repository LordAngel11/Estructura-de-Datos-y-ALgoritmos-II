#include <bits/stdc++.h>

//Juan Angel Lopez Delgadillo
#define MAXIMUS 400000
using namespace std;

class Segment_Tree{

    private:

    int tree[MAXIMUS] = {0};
    int lazy[MAXIMUS] = {0};

    int min_combine(int a, int b){
        return min(tree[a], tree[b]);
    }

    int lazy_combine(int a, int b){
        return lazy[a] + lazy[b];
    }
    void update(int v){}


    public:

    Segment_Tree(){

    }

    void insert(int vertice, int left_t, int right_t, int left, int right) {
    if (right < left_t || right < left || right_t < left) {
        return;
    }
    if((left_t == left && right_t == right) || right_t == left_t) {
        tree[vertice] += 1;
        lazy[vertice] = abs(right - left) + 1;
        //return;
    }else{
    int t = (left_t + right_t) / 2;
    insert(2 * vertice + 1, left_t, t, left, min(right, t));
    insert(2 * vertice + 2, t + 1, right_t, max(left, t + 1), right);
    tree[vertice] = min_combine(tree[2 * vertice + 1], tree[2 * vertice + 2]);
    lazy[vertice] = lazy_combine(lazy[2 * vertice + 1], lazy[2 * vertice + 2]);
    }
}


void erase(int vertice, int left_t, int right_t, int left, int right){
    if (right < left || right < left_t || right_t < left) {
        // el rango esta afuera del rango actual.
        return;
    } else if (left <= left_t && right <= right_t) {
        // El rango cubre completamente el segmento actual
        if (tree[vertice] > 0) {
            // Decremento
            tree[vertice] -= 1;
            if (tree[vertice] == 0) {
                // si el valor del segmento llega a cero lo declaramos como lazy
                lazy[vertice] = 0;
            }
        }
    } else {
        int mid = (left_t + right_t) / 2;
        erase(2 * vertice + 1, left_t, mid, left, std::min(right, mid));
        erase(2 * vertice + 2, mid + 1, right_t, std::max(left, mid + 1), right);
        tree[vertice] = min_combine(tree[2 * vertice + 1], tree[2 * vertice + 2]);
        lazy[vertice] = lazy_combine(lazy[2 * vertice + 1], lazy[2 * vertice + 2]);
    }
}

int intersection(int vertice, int left_t, int right_t, int left, int right){
            if(left_t<=left && right<=right_t && tree[vertice]>0){
                return abs(right-left) + 1;
            }
            if(right<left || right<left_t || right_t<left){
                return 0;
            }else if(left_t==left && right_t==right){
                return lazy[vertice];
            }else{
                int t = (left_t+right_t)/2;
                if(tree[vertice] > 0)
                    return max(abs(min(right_t,right)-max(left_t,left))+1,intersection(2*vertice+1,left_t,t,left,min(right,t)) + 
                    intersection(2*vertice+2,t+1,right_t,max(left,t+1),right));    
                else
                    return intersection(2*vertice+1,left_t,t,left,min(right,t)) + intersection(2*vertice+2,t+1,right_t,max(left,t+1),right);
            }
        }


};

int main() {
    Segment_Tree tree;
    int num_queries;
    cin >> num_queries;
    
    for (int i = 0; i < num_queries; i++) {
        char query_type;
        int left_bound, right_bound;
        cin >> query_type >> left_bound >> right_bound;
        
        if (query_type == 'I') {
            tree.insert(0, 0, 99999, left_bound, right_bound - 1);
        } else if (query_type == 'E') {
            tree.erase(0, 0, 99999, left_bound, right_bound - 1);
        } else if (query_type == 'Q') {
            if (left_bound > right_bound) {
                cout << "Error: left bound greater than right bound." << endl;
            } else {
                cout << tree.intersection(0, 0, 99999, left_bound, right_bound - 1) << "\n";
            }
        } else {
            cout << "Error: invalid query type." << endl;
        }
    }
    
    return 0;
}


