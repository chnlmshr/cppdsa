#include <bits/stdc++.h>

using namespace std;
map<pair<int, int>, int> m;
int memoization(string s1, string s2)
{
    if (!s1.size() || !s2.size())
        return 0;

    int n1 = s1.size(), n2 = s2.size();
    if (m[make_pair(n1, n2)])
        return m[make_pair(n1, n2)];
    if (s1[0] == s2[0])
    {
        s1.erase(0, 1);
        s2.erase(0, 1);
        return m[make_pair(n1, n2)] = 1 + memoization(s1, s2);
    }
    else
    {
        string st1 = s1;
        s1.erase(0, 1);
        string st2 = s2;
        s2.erase(0, 1);
        return m[make_pair(n1, n2)] = max(memoization(s1, st2), memoization(st1, s2));
    }
}

int topdown(string s1, string s2)
{
    map<pair<int, int>, int> mt;

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
            }
            else
            {
                mt[make_pair(i, j)] = max(mt[make_pair(i - 1, j)], mt[make_pair(i, j - 1)]);
            }
        }
    }
    return mt[make_pair(s1.size(), s2.size())];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string s1, s2;

    cin >> s1 >> s2;

    cout << memoization(s1, s2) << endl;

    cout << topdown(s1, s2);

    return 0;
}