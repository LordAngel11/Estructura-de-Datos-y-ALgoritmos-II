#include <bits/stdc++.h>

//Juan Angel López Delgadillo

using namespace std;

//Uva 12545 Bits Equalizer

int main()
{
    int n, no = 0;
    char s[10000], t[10000], temp;
    std::cin >> n;
    while (n--)
    {
        std::cin >> s >> t;
        int l1 = strlen(s);
        int l2 = strlen(t);
        if (l1 > l2 || l1 < l2)
        {
            std::cout << "Case " << ++no << ": -1\n";
            continue;
        }
        int ws = 0, wt = 0, zs = 0, zt = 0, os = 0, ot = 0, c = 0, d = 0;
        for (int i = 0; i < l1; i++)
        {
            if (s[i] == '?')
                ws++;
            if (s[i] == '0')
                c++;
            if (s[i] == '1')
                d++;
            if (s[i] == '0' && t[i] == '1')
                zs++;
            if (s[i] == '1' && t[i] == '0')
                os++;
            if (t[i] == '0')
                zt++;
            if (t[i] == '1')
                ot++;
        }
        if (d > ot)
        {
            std::cout << "Case " << ++no << ": -1\n";
        }
        else
        {
            std::cout << "Case " << ++no << ": " << zs + os - std::min(zs, os) + ws << '\n';
        }
    }
    return 0;
}