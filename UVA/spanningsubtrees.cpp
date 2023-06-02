#include <bits/stdc++.h>

//Juan ANgel López Delgadillo

//Uva 11697 Spanning subtree

int main() {
    int caseNum = 1;
    int n;

    while (std::cin >> n && n != 0) {
        int numOfEdges = (n * (n - 1)) / 2;

        // El número de aristas en un árbol de expansión mínima es n - 1
        int numOfSubtrees = numOfEdges / (n - 1);

        std::cout << "Case " << caseNum << ": " << numOfSubtrees << std::endl;
        caseNum++;
    }

    return 0;
}
