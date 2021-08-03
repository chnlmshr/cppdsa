#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> tdp;

int tabulation(vector<pair<int, int>> a, int c)
{
    for (int i = 0; i <= a.size() + 1; i++)
    {
        pair<int, int> p;
        p.first = i;
        p.second = 0;
        tdp[p] = 0;
    }

    for (int i = 0; i <= c + 1; i++)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = i;
        tdp[p] = 0;
    }

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= c; j++)
        {
            pair<int, int> p;
            p.first = i;
            p.second = j;

            if (a[i - 1].first <= j)
                tdp[p] = max(a[i - 1].second + tdp[make_pair(i, j - a[i - 1].first)], tdp[make_pair(i - 1, j)]);
            else
                tdp[p] = tdp[make_pair(i - 1, j)];
        }
    }

    return tdp[make_pair(a.size(), c)];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> a(n);
    int w, v;
    for (auto &&i : a)
        cin >> i.first >> i.second;

    cout << tabulation(a, c);

    return 0;
}