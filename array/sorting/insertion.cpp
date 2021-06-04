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
    for (int i = 1; i < n; i++)
    {
        int p = a[i], j = i - 1;
        while (j >= 0 && a[j] > p)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = p;
    }
    //

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}