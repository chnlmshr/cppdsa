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
        int n;
        cin >> n;
        int o = 0;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            if (k % 2)
                o++;
        }
        cout << o / 2 << "\n";
    }

    return 0;
}