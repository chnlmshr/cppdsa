#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long int x, y;
        cin >> x >> y;
        if (x % 2 || (!x && y % 2))
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}