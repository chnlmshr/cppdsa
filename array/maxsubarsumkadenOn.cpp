// Kaden's Algorithm

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
        cin >> a[i];

    int currSum = 0;
    int maxSum = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        if (currSum < 0)
            currSum = 0;
        maxSum = max(currSum, maxSum);
    }

    cout << maxSum;

    return 0;
}