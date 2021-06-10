// Two Unique numbers in an array if others are present twice except the required numbers

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
        cin >> a[i];

    int xorsum = 0;
    for (int i = 0; i < n; i++)
        xorsum ^= a[i];
    int tempxorsum = xorsum;
    int setbit = 0, pos = 0;
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxorsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] & (1 << (pos - 1)))
        {
            newxorsum ^= a[i];
        }
    }
    cout << newxorsum << " " << (newxorsum ^ tempxorsum);

    return 0;
}