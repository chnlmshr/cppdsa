#include <bits/stdc++.h>

using namespace std;

int divisors[1000001];

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../input.txt", "r", stdin);
    //     freopen("../../output.txt", "w", stdout);
    // #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = 1; j * j <= x; j++)
            if (x % j == 0)
            {
                divisors[j]++;
                if (x / j != j)
                    divisors[x / j]++;
            }
    }

    for (int i = 1000000; i >= 1; i--)
        if (divisors[i] >= 2)
        {
            cout << i;
            break;
        }

    return 0;
}