#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, mw, mv = 0; // no. of items, maximum weight possible, maximum value possible
    cin >> n >> mw;

    vector<pair<int, int>> v; // values, weights

    for (auto &&i : v)
        cin >> i.first >> i.second;

    sort(v.begin(), v.end());

    for (auto i : v)
    {
        if (i.second <= mw)
        {
            mv += i.first;
            mw -= i.second;
        }
        else
        {
            mv += i.first * mw / i.second;
            mw = 0;
        }
    }

    cout << mv;

    return 0;
}