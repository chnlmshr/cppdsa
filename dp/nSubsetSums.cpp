#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> mt;
int tabulation(vector<int> v, int s)
{
    for (int i = 0; i <= v.size(); i++)
    {
        mt[make_pair(0, i)] = 0;
    }
    for (int i = 0; i <= s; i++)
    {
        mt[make_pair(i, 0)] = 1;
    }

    for (int i = 1; i <= v.size(); i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (v[i - 1] <= j)
                mt[make_pair(i, j)] = mt[make_pair(i - 1, j - v[i - 1])] + mt[make_pair(i - 1, j)];
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
    cout << tabulation(v, s);
    return 0;
}