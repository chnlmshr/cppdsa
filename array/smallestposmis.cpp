#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    const int N = 1e6 + 2;
    bool check[N];
    for (int i = 0; i < N; i++)
        check[i] = false;
    for (int i = 0; i < n; i++)
        if (a[i] >= 0)
            check[a[i]] = true;
    for (int i = 0; i < N; i++)
        if (!check[i])
        {
            cout << i;
            break;
        }
    return 0;
}