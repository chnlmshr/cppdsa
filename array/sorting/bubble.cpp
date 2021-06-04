#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // sorting
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j + 1];
                a[j + 1] = a[j];
                a[j] = t;
            }
        }
    }
    //

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}