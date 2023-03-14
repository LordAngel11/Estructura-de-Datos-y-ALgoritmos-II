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

}Node;


class TreapImplicit{
    
    public:
    TreapImplicit() : root(nullptr) {}

    void insert(long long x) {
        Node* left, * right;
        splitByValue(root, x, left, right);
        root = merge(merge(left, new Node(x)), right);
    }

    void erase(long long x) {
        Node* left, * mid, * right;
        splitByValue(root, x, left, mid);
        splitByValue(mid, x + 1, mid, right);
        delete mid;
        root = merge(left, right);
    }

    int count(long long x) {
        return count(root, x);
    }

    int size() {
        return root ? root->cnt : 0;
    }

    void printInOrder() {
        printInOrder(root);
        cout << endl;
    }

   private:
    Node* root;

    void splitByValue(Node* n, long long d, Node*& left, Node*& right) {
        if (!n) {
            left = right = nullptr;
            return;
        }
        if (n->x < d) {
            splitByValue(n->right, d, n->right, right);
            left = n;
        } else {
            splitByValue(n->left, d, left, n->left);
            right = n;
        }
        n->recalc();
    }

    Node* merge(Node* left, Node* right) {
        if (!left || !right) {
            return left ? left : right;
        }
        if (left->p > right->p) {
            left->right = merge(left->right, right);
            left->recalc();
            return left;
        } else {
            right->left = merge(left, right->left);
            right->recalc();
            return right;
        }
    }

    int count(Node* n, long long x) {
        if (!n) {
            return 0;
        }
        if (n->x == x) {
            return 1;
        } else if (n->x > x) {
            return count(n->left, x);
        } else {
            return count(n->right, x);
        }
    }

    void printInOrder(Node* n) {
        if (n) {
            printInOrder(n->left);
            cout << n->x << " ";
            printInOrder(n->right);
        }
    }
};

int main() {
    TreapImplicit treap;
    treap.insert(4);
    treap.insert(2);
    treap.insert(7);
    treap.insert(1);
    treap.insert(3);
    treap.insert(6);
    treap.insert(9);
    cout << "Size: " << treap.size() << endl;
    treap.printInOrder(); // should print 1 2 3 4 6 7 9
    cout << "Count of 4: " << treap.count(4) << endl; // should print 1
    cout << "Count of 5: " << treap.count(5) << endl; // should print 0
    treap.erase(4);
    cout << "Size: " << treap.size() << endl;
    treap.printInOrder(); // should print 1 2 3 6 7 9
    return 0;
}


