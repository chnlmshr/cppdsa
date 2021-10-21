// #include <bits/stdc++.h>
// #define ll long long int

// using namespace std;

// int main()
// {
//     // #ifndef ONLINE_JUDGE
//     //     freopen("../input.txt", "r", stdin);
//     //     freopen("../output.txt", "w", stdout);
//     // #endif
//     ios_base::sync_with_stdio(false);

//     cin.tie(NULL);
//     cout.tie(NULL);

//     int T;
//     cin >> T;

//     while (T--)
//     {
//         ll n, nop = 1;
//         ;
//         cin >> n;
//         for (int i = 3; i <= 2 * n; i++)
//         {
//             nop *= i;
//             nop %= 1000000007;
//         }
//         cout << nop % 1000000007 << "\n";
//     }

//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long n, m, k;
        cin >> n >> m >> k;
        long f = sqrt(2 * (m - n) + 2.25);
        long d = n - ceil((f + 0.5));
        long c = n * (n - 1) / 2;
        if (d < k - 1 && c == m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}