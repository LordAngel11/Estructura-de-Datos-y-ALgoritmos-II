#include<bits/stdc++.h>

//Juan ANgel Lopez Delgadillo
//Uva 11997 K smallestsums


using namespace std;

typedef pair<int, int> ii;

const int MAXK = 750 + 3;

void merge(int a[], int b[], int c[], int k)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq; // Every pair contains value and position.

    for (int i = 0; i < k; ++i)
        pq.push(make_pair(a[i] + b[0], 0));

    int idx = 0;

    while (!pq.empty())
    {
        ii t = pq.top();
        pq.pop();
        c[idx++] = t.first;

        if (t.second + 1 < k)
            pq.push(make_pair(t.first - b[t.second] + b[t.second + 1], t.second + 1));

        if (idx == k)
            break;
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int k, arr1[MAXK], arr2[MAXK];

    while (~scanf("%d", &k))
    {
        for (int i = 0; i < k; ++i)
            scanf("%d", &arr1[i]);
        sort(arr1, arr1 + k);

        for (int i = 1; i < k; ++i)
        {
            for (int j = 0; j < k; ++j)
                scanf("%d", &arr2[j]);
            sort(arr2, arr2 + k);
            merge(arr1, arr2, arr1, k);
        }

        printf("%d", arr1[0]);
        for (int i = 1; i < k; ++i)
            printf(" %d", arr1[i]);
        putchar('\n');
    }

    return 0;
}