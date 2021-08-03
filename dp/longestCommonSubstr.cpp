#include <bits/stdc++.h>

using namespace std;

int tabulation(string s1, string s2)
{
    map<pair<int, int>, int> mt;
    int m = 0;

    for (int i = 0; i < s2.size(); i++)
        mt[make_pair(0, i)] = 0;

    for (int i = 0; i < s1.size(); i++)
        mt[make_pair(i, 0)] = 0;

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                mt[make_pair(i, j)] = 1 + mt[make_pair(i - 1, j - 1)];
                m = max(m, mt[make_pair(i, j)]);
            }
        }
    }
    return m;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string s1, s2;

    cin >> s1 >> s2;

    cout << tabulation(s1, s2);

    return 0;
}