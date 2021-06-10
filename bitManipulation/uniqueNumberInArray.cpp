// Unique number in an array if others are present twice except the required number

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

    int unique = 0;
    for (int i = 0; i < n; i++)
        unique ^= a[i];
    cout << unique;

    return 0;
}