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
    int pd = a[0] - a[1], cl = 2, ml = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (pd == a[i] - a[i + 1])
        {
            cl++;
        }
        else
        {
            cl = 2;
            pd = a[i] - a[i + 1];
        }
        ml = max(ml, cl);
    }
    cout << ml;
    return 0;
}