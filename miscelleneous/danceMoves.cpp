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

    int T;
    cin >> T;
    while (T--)
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
        {
            if ((y - x) % 2)
                cout << ((y - x) + 1) / 2 + 1 << "\n";
            else
                cout << (y - x) / 2 << "\n";
        }
        else if (x > y)
        {
            cout << x - y << "\n";
        }
        else
            cout << 0 << "\n";
    }

    return 0;
}