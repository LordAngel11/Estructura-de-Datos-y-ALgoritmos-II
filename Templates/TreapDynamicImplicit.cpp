#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long x;
    int p, cnt;
    Node *left, *right;

    Node(long long _x) : x(_x), p(rand()), cnt(1), left(nullptr), right(nullptr) {}

    ~Node() {
        delete left;
        delete right;
    }

    void recalc() {
        cnt = 1;
        if (left) {
            cnt += left->cnt;
        }
        if (right) {
            cnt += right->cnt;
        }
    }
};

class Treap {
public:
    Treap() : root(nullptr) {}

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
    Treap t;

    t.insert(10);
    t.insert(7);
    t.insert(12);
    t.insert(4);
    t.insert(8);
    t.insert(11);
    t.insert(13);

    cout << "InOrder: ";
    t.printInOrder(); // Debería imprimir "4 7 8 10 11 12 13"

    t.erase(11);
    cout << "InOrder: ";
    t
