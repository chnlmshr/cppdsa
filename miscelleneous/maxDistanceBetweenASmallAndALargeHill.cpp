#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<long int> v(n);
    for (auto &&i : v)
        cin >> i;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (v[i] <= v[j])
            {
                m = max(m, j - i);
                break;
            }
        }
    }

    cout << m;

    return 0;
}