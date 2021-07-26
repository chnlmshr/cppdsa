#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, bool> m;
bool memoization(vector<int> v, int s)
{
    if (!s)
        return true;
    if (!v.size())
        return false;
    int i = v[0];
    v.erase(v.begin());
    if (m[make_pair(v.size(), s)])
        return m[make_pair(v.size(), s)];
    if (i <= s)
        return m[make_pair(v.size(), s)] = memoization(v, s - i) || memoization(v, s);
    else
        return m[make_pair(v.size(), s)] = memoization(v, s);
}

map<pair<int, int>, bool> mt;
bool topdown(vector<int> v, int s)
{
    for (int i = 0; i <= v.size(); i++)
    {
        mt[make_pair(0, i)] = false;
    }
    for (int i = 0; i <= s; i++)
    {
        mt[make_pair(i, 0)] = true;
    }

    for (int i = 1; i <= v.size(); i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (v[i - 1] <= j)
                mt[make_pair(i, j)] = mt[make_pair(i - 1, j - v[i - 1])] || mt[make_pair(i - 1, j)];
            else
                mt[make_pair(i, j)] = mt[make_pair(i - 1, j)];
        }
    }
    return mt[make_pair(v.size(), s)];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto &&i : v)
    {
        cin >> i;
    }
    cout << memoization(v, s);
    cout << topdown(v, s);
    return 0;
}