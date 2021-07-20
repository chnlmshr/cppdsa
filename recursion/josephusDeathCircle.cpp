#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> v, int k, int c)
{
    if (v.size() == 1)
        return v[0];
    c = (c + k - 1) % v.size();
    v.erase(v.begin() + c);
    return solve(v, k, c);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    cout << solve(v, k, 0);

    return 0;
}