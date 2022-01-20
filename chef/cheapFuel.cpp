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
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int p = x + a * k, d = y + b * k;
        if (p < d)
            cout << "PETROL";
        else if (p > d)
            cout << "DIESEL";
        else
            cout << "SAME PRICE";
        cout << "\n";
    }

    return 0;
}