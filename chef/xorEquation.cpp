#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll XOR(vector<ll> &v, ll n, ll k)
{
    v[0] += k;
    ll x = v[0];
    for (ll i = 1; i < n; i++)
    {
        v[i] += k;
        x ^= v[i];
    }
    return x;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;

        ll x = 0;
        ll zor = XOR(v, n, 0);
        for (ll i = 1; i <= 61; i++)
        {
            if (zor == 0)
                break;
            ll m = 1;
            ll b = m << (i - 1);
            if (zor & b)
            {
                zor = XOR(v, n, b);
                x += (m << (i - 1));
            }
        }
        if (zor == 0)
            cout << x;
        else
            cout << -1;
        cout << "\n";
    }

    return 0;
}
