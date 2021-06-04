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
    int m = a[0] - 1, c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
            if (i == n - 1 || a[i] > a[i + 1])
            {
                c++;
            }
        }
    }
    cout << c;
    return 0;
}