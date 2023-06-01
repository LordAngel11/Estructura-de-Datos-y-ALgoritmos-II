#include<bits/stdc++.h>

//Juan Angel Lopez Delgadillo
//Uva 10887 COncatenation language

using namespace std;

vector<string> first;
set<string> s;

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignorar el salto de línea después del número de casos de prueba

    for (int d = 1; d <= tc; d++) {
        first.clear();
        s.clear();
        int n, m;
        cin >> n >> m;
        cin.ignore(); // Ignorar el salto de línea después de n y m

        string temp;
        for (int i = 0; i < n; i++) {
            getline(cin, temp);
            first.push_back(temp);
        }

        for (int i = 0; i < m; i++) {
            getline(cin, temp);
            for (int j = 0; j < (int)first.size(); j++) {
                string concatenation = first[j] + temp;
                s.insert(concatenation);
            }
        }

        cout << "Case " << d << ": " << s.size() << endl;
    }

    return 0;
}
