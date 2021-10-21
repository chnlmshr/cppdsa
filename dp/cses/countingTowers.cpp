// https://cses.fi/problemset/task/2413

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../input.txt", "r", stdin);
    //     freopen("../../output.txt", "w", stdout);
    // #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll curLinked = 1, curSliced = 1;
        for (int i = 2; i <= n; i++)
        {
            ll prevLinked = curLinked, prevSliced = curSliced;
            curLinked = (prevLinked * 2 + prevSliced) % 1000000007;
            curSliced = (prevLinked + prevSliced * 4) % 1000000007;
        }
        cout << (curLinked + curSliced) % 1000000007 << "\n";
    }

    return 0;
}