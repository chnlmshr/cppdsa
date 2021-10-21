#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k, p = 0, res = 0;
        cin >> k >> n;
        while (n)
        {
            if (n & 1)
            {
                res = (res + (long long int)pow(k, p)) % 1000000007;
            }
            p++;
            n >>= 1;
        }
        cout << res << "\n";
    }
    return 0;
}