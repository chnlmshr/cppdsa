#include <bits/stdc++.h>

using namespace std;

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
        int n, m, rb, cb, rd, cd, nd = 1, md = 1, secs = 0;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        while (rb != rd && cb != cd)
        {
            if (rb == n)
                nd = -nd;
            if (cb == m)
                md = -md;
            rb += nd;
            cb += md;
            secs++;
        }
        cout << secs << "\n";
    }

    return 0;
}