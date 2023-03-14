#include <bits/stdc++.h>
using namespace std;

//Juan Angel Lopez Delgadillo


//Estructura del nodo para el Treap Implicito 
struct Node {
    int x, p, cnt;
    Node *left, *right;

    //Constructor
    Node(long long _x) : x(_x), p(rand()), cnt(1), left(nullptr), right(nullptr) {}
   
   //Destructor
    ~Node() { delete left; delete right; }
    void recalc() {
        cnt = 1;                //actualiza el cnt de los subarboles
        if (left) cnt += left->cnt;        //izquierda
        if (right) cnt += right->cnt;       //deecha
    }
};
typedef Node;

//Estructura del treap con sus operaciones xddd
class Treap {
public:
    Treap() : root(nullptr) {}
    void insert(int x) {
        Node* left, *right;
        splitByValue(root, x, left, right);
        root = merge(merge(left, new Node(x)), right);
    }
    void erase(int x) {
        Node* left, *mid, *right;
        splitByValue(root, x, left, mid);
        splitByValue(mid, x + 1, mid, right);
        delete mid;
        root = merge(left, right);
    }
    int count(int x) {
        return count(root, x);
    }
private:
    Node* root;
    void splitByValue(Node* n, int d, Node*& left, Node*& right) {
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
    int count(Node* n, int x) {
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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Treap t;
    for (int i = 0; i < q - 1; ++i) {
        t.insert(a[i]);
    }
    long long ans = 0;
    for (int i = q - 1; i < n; ++i) {
        t.insert(a[i]);
        ans += t.count(a[i] - 1);
        t.erase(a[i - q + 1]);
    }
    cout << ans << "\n";
    return 0;
}
