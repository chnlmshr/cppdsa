#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Normal: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    cout << endl
         << "Spiral: " << endl;
    int l = 0, u = 0, r = n - 1, d = m - 1;
    while (l <= r && u <= r)
    {
        for (int i = l; i <= r; i++)
            cout << a[u][i] << " ";
        u++;
        for (int i = u; i <= d; i++)
            cout << a[i][r] << " ";
        r--;
        for (int i = r; i >= l; i--)
            cout << a[d][i] << " ";
        d--;
        for (int i = d; i >= u; i--)
            cout << a[i][l] << " ";
        l++;
    }
    return 0;
}