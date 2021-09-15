#include <bits/stdc++.h>

using namespace std;

string flip(string s, int *c, int *fc)
{
    for (int i = 0; i < s.size() && *c - *fc >= 0; i++)
        if (s[i] == '1')
        {
            s[i] = '0';
            *c -= *fc;
        }
    return s;
}

string swap(string s, int *c, int *sc)
{
    int l = -1, r = s.size();
    while (l + 1 < s.size() && s[++l] != '1')
        ;
    while (r - 1 >= 0 && s[--r] != '0')
        ;
    while (l < r && *c - *sc >= 0)
    {
        s[l] = '0';
        s[r] = '1';
        *c -= *sc;
        while (s[++l] != '1')
            ;
        while (s[--r] != '0')
            ;
    }
    return s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, c, sc, fc;
    string s;
    cin >> n >> s >> c >> sc >> fc;
    if (sc < fc)
        s = flip(swap(s, &c, &sc), &c, &fc);
    else
        s = swap(flip(s, &c, &fc), &c, &sc);

    // cout << s;
    cout << stoi(s, 0, 2);

    return 0;
}