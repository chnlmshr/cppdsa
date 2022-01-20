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
        int n, e;
        cin >> n >> e;
        for (int i = 1; i < n; i++)
            cout << i << " " << i + 1 << "\n";
        e -= n - 1;
        int i = 1, k = 3;
        while (e--)
        {
            if (k - i > 1)
            {
                cout << i++ << " " << k << "\n";
            }
            else
            {
                i = 1;
                k++;
                e++;
            }
        }
    }

    return 0;
}