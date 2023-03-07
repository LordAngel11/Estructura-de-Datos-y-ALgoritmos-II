




void erase(int vertice, int left_t, int right_t, int left, int right){
    if (right < left || right < left_t || right_t < left) {
        // The range [left, right] is entirely outside the current segment [left_t, right_t]
        return;
    } else if (left <= left_t && right_t <= right) {
        // The range [left, right] completely covers the current segment [left_t, right_t]
        if (tree[vertice] > 0) {
            // Decrement the value of the current segment if it is greater than zero
            tree[vertice] -= 1;
            if (tree[vertice] == 0) {
                // If the value is now zero, mark the current segment as lazy
                lazy[vertice] = 0;
            }
        }
    } else {
        // The range [left, right] partially overlaps with the current segment [left_t, right_t]
        int mid = (left_t + right_t) / 2;
        erase(2 * vertice + 1, left_t, mid, left, std::min(right, mid));
        erase(2 * vertice + 2, mid + 1, right_t, std::max(left, mid + 1), right);
        tree[vertice] = combine(tree[2 * vertice + 1], tree[2 * vertice + 2]);
        lazy[vertice] = combine2(lazy[2 * vertice + 1], lazy[2 * vertice + 2]);
    }
}


int intersection(int vertice, int left_t, int right_t, int left, int right) {
    if (left > right_t || right < left_t) { // no overlap
        return 0;
    }
    if (left <= left_t && right_t <= right && tree[vertice] > 0) { // fully covered by a non-empty segment
        return right_t - left_t + 1;
    }
    int mid = (left_t + right_t) / 2;
    return max(intersection(2*vertice+1, left_t, mid, left, right),
               intersection(2*vertice+2, mid+1, right_t, left, right));
}
