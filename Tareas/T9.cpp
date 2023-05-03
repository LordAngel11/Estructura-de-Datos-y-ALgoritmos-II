#include <bits/stdc++.h>

using namespace std;

vector<int> preprocesamientoKMP(const string& patrones) {
    int m = patrones.length();
    vector<int> resets(m + 1, -1);
    int i = 0, j = -1;
    while (i < m) {
        while (j >= 0 && patrones[i] != patrones[j]) {
            j = resets[j];
        }
        i++, j++;
        resets[i] = j;
    }
    return resets;
}

int count_substrings(const string& s) {
    int n = s.length();
    vector<int> resets = preprocesamientoKMP(s);
    int count = n;
    for (int i = 1; i <= n; i++) {
        int j = resets[i];
        while (j != -1) {
            count++;
            j = resets[j];
        }
    }
    return count;
}


int main() {
    string s;
    std::cin>>s; 
    int count = count_substrings(s);
    cout << count << endl; // Imprime 15
    return 0;
}