#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, priority, size;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        priority = rand();
        size = 1;
        left = right = nullptr;
    }

    ~Node() {
        delete left;
        delete right;
    }

    void updateSize() {
        size = 1 + (left ? left->size : 0) + (right ? right->size : 0);
    }
};

Node* merge(Node* L, Node* R) {
    if (!L) return R;
    if (!R) return L;
    if (L->priority > R->priority) {
        L->right = merge(L->right, R);
        L->updateSize();
        return L;
    } else {
        R->left = merge(L, R->left);
        R->updateSize();
        return R;
    }
}

void split(Node* t, int key, Node*& L, Node*& R) {
    if (!t) L = R = nullptr;
    else if (key < t->key) {
        split(t->left, key, L, t->left);
        R = t;
        R->updateSize();
    } else {
        split(t->right, key, t->right, R);
        L = t;
        L->updateSize();
    }
}

bool find(Node* t, int key) {
    if (!t) return false;
    if (key == t->key) return true;
    if (key < t->key) return find(t->left, key);
    return find(t->right, key);
}

int count(Node* t, int key) {
    if (!t) return 0;
    if (key == t->key) return t->left ? t->left->size : 0;
    if (key < t->key) return count(t->left, key);
    return (t->left ? t->left->size : 0) + 1 + count(t->right, key);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Node* treap = nullptr;

    while (n--) {
        int x;
        cin >> x;
        if (!find(treap, x)) {
            Node* new_node = new Node(x);
            treap = merge(treap, new_node);
        }
    }

    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            cout << (find(treap, x) ? "1" : "0") << "\n";
        } else if (t == 1) {
            if (!find(treap, x)) {
                Node* new_node = new Node(x);
                treap = merge(treap, new_node);
            }
        } else {
            int cnt = count(treap, x);
            Node* left, * mid, * right;
            split(treap, x, left, mid);
            split(mid, x + cnt, mid, right);
            delete mid;
            treap = merge(left, right);
        }
    }

    delete treap;

    return 0;
}
