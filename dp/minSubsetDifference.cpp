#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, bool> mt;
// this function Same as isSubsetsum
void topdown(vector<int> v, int s)
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
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int vs = 0;
    vector<int> v(n);
    for (auto &&i : v)
    {
        cin >> i;
        vs += i;
    }
    topdown(v, vs / 2);
    for (int i = vs / 2; i >= 0; i--)
        if (mt[make_pair(n, i)])
        {
            cout << vs - 2 * i;
            break;
        }
    return 0;
}