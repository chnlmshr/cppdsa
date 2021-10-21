// https://atcoder.jp/contests/dp/tasks/dp_n

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<ll>> dp;
vector<ll> presum;

ll sum(ll i, ll j)
{
    if (i == 0)
        return presum[j];
    else
        return presum[j] - presum[i - 1];
}

ll minCost(vector<ll> &v, ll i, ll j)
{
    if (i == j)
        return 0;
    if (i == j - 1)
        return v[i] + v[j];
    if (dp[i][j])
        return dp[i][j];
    ll mn = 1e18;
    for (ll k = i; k < j; k++)
        mn = min(mn, minCost(v, i, k) + minCost(v, k + 1, j) + sum(i, k) + sum(k + 1, j));
    return dp[i][j] = mn;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v)
        cin >> i;

    dp.resize(n + 1, vector<ll>(n + 1, 0));

    presum.push_back(v[0]);
    for (int i = 1; i < n; i++)
        presum.push_back(v[i] + presum[i - 1]);

    cout << minCost(v, 0, n - 1);

    return 0;
}