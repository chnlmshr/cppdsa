#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long k, n;
    cin >> n >> k;
    set<long long> s;
    for (int i = 0; i < k; i++)
    {
        cin >> k;
        for (int j = k; j <= n; j += k)
            s.emplace(j);
    }

    cout << s.size();

    return 0;
}