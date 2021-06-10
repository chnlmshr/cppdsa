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

    int unique = 0;
    for (int i = 0; i < 64; i++)
    {
        int numberOfSetBits = 0;
        for (int j = 0; j < n; j++)
            if (a[j] & (1 << i)) //get bit
                numberOfSetBits++;
        if (numberOfSetBits % 3)
            unique |= (1 << i); //set bit
    }
    cout << unique;
    return 0;
}