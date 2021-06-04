#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 0;
    const int N = 1e6 + 2;
    cin >> n;
    int a[n], b[N], c = INT32_MAX;
    for (int i = 0; i < N; i++)
        b[i] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (b[a[i]] != -1)
            c = min(c, b[a[i]]);
        else
            b[a[i]] = i;
    }
    cout << c << " " << a[c];
    return 0;
}