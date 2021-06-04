#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n, f;
    cin >> m >> n >> f;
    int a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    int i = 0, j = n - 1;
    bool found = false;

    while (i < m && j >= 0)
    {
        if (a[i][j] > f)
            j--;
        else if (a[i][j] < f)
            i++;
        else
        {
            found = true;
            cout << endl
                 << "Matrix(" << i + 1 << ", " << j + 1 << ") = " << f;
            break;
        }
    }
    if (!found)
        cout << "Not Found!";
}