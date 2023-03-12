#include <bits/stdc++.h>


using namespace std;

typedef struct _Node
{
    long long x, p, cnt; //clave, prioridad, y elementos en subarbol
    _Node *left, *right; //punteros a subarboles

    _Node(long long _x) : x(_x), p(((long long)(rand()) << 32)^ rand()), 
                                cnt(1), left(NULL), right(NULL) {}

    ~_Node() { delete left; delete right;}

    void recalc(){
        cnt = 1;
        cnt += ((left)?(left -> cnt): 0);
        cnt += ((right)?(right -> cnt): 0);
    }

}* Node;

Node root = NULL;

Node merge(Node left, Node right){
    if(!left || !right) return left ? left : right;
    if(left->p > right->p){
        left -> right = merge(left -> right, right);
        left -> recalc();
        return left;
    }else{
        right -> left = merge(left, right -> left);
        right -> recalc();
        return right;
    }
}

void splitByvalue(Node n, long long d, Node &left, Node &right){
    left = right = NULL;
    if(!n) return;
    if(n -> x < d){
        splitByvalue(n->right, d, n->right, right);
        left = n;
    } else {
        splitByvalue(n->left, d, left, n->left);
        right = n;
    }
    n -> recalc();
}

void insertOrderedByValue(long long x){
    Node left, right;
    splitByvalue(root, x, left, right);
    root = merge(merge(left, new _Node(x)), right);
}

void eraseByValue(long long x){
    Node left, mid, right;
    splitByvalue(root, x, left, mid);
    splitByvalue(mid, x+1, mid, right);
    delete mid;
    root = merge(left, right);
}