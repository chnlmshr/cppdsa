// Cumulative sum approach

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

    int currSum[n + 1];
    currSum[0] = 0;

    for (int i = 1; i <= n; i++)
        currSum[i] = currSum[i - 1] + a[i - 1];

    int maxSum = INT32_MIN;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }
    cout << maxSum;
    return 0;
}