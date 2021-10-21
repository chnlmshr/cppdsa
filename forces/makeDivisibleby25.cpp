#include <bits/stdc++.h>
using namespace std;

map<pair<string, int>, int> dp;

int minRemoval(string s, int i)
{
    if (i < 0)
        return -1;
    long long int n = stoll(s, nullptr, 10);
    if (n % 10 == n)
        return -1;
    if (dp[make_pair(s, i)])
        return dp[make_pair(s, i)];
    if (n % 100 == 0 || n % 100 == 25 || n % 100 == 50 || n % 100 == 75)
        return 0;
    else
    {
        // when removing ith
        string r = s;
        // cout << "here";
        s.erase(i, 1);
        int erased = minRemoval(s, i - 1);
        int unerased = minRemoval(r, i - 1);
        if (erased == -1)
            return dp[make_pair(s, i)] = unerased;
        if (unerased == -1)
            return dp[make_pair(s, i)] = 1 + erased;
        return dp[make_pair(s, i)] = min(1 + erased, unerased);
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        string s = to_string(n);
        n = s.size();
        cout << minRemoval(s, n - 1) << "\n";
    }
    return 0;
}