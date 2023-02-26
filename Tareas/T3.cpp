#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    Node* left_child;
    Node* right_child;
    
    Node(int value, Node* left_child = nullptr, Node* right_child = nullptr) {
        this->value = value;
        this->left_child = left_child;
        this->right_child = right_child;
    }
};

// Funcion build del segment tree
Node* build_tree(int arr[], int start, int end) {
    //Si el tree es equivalente a su fin entonces regresamos un arbol vacio.
    if (start == end) {
        return new Node(arr[start]);
    }

    int mid = (start + end) / 2;
    Node* left_child = build_tree(arr, start, mid);
    Node* right_child = build_tree(arr, mid + 1, end);

    int value = min(left_child->value, right_child->value);
    return new Node(value, left_child, right_child);
}


int query(Node* root, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return 1e9;
    }

    if (start >= left && end <= right) {
        return root->value;
    }

    int mid = (start + end) / 2;
    int left_min = query(root->left_child, start, mid, left, right);
    int right_min = query(root->right_child, mid + 1, end, left, right);

    return min(left_min, right_min);
}

// Funcion para actualizar el segment tree
void update(Node* root, int start, int end, int idx, int val) {
    if (start == end) {
        root->value = val;
        return;
    }

    int mid = (start + end) / 2;

    if (idx <= mid) {
        update(root->left_child, start, mid, idx, val);
    } else {
        update(root->right_child, mid + 1, end, idx, val);
    }

    root->value = min(root->left_child->value, root->right_child->value);
}

int main() {
    int n, m;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Creamos el Segment Tree
    Node* root = build_tree(arr, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 0) {
            int l, r, k;
            cin >> l >> r >> k;

            vector<int> values;
            for (int j = l; j <= r; j++) {
                values.push_back(arr[j]);
            }

            sort(values.begin(), values.end());
            cout << values[k] << endl;
        } else {
            int idx, v;
            cin >> idx >> v;

            update(root, 0, n - 1, idx, v);
            arr[idx] = v;
        }
    }

    return 0;
}
