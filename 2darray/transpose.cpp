#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n;
    cin >> m;
    n = m;
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
         << "Transpose: " << endl;

    for (int i = 0; i < m; i++)
        for (int j = i; j < n; j++)
        {
            int t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}