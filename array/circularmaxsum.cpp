#include <iostream>

using namespace std;
int kadane(int a[], int n)
{
    int currSum = 0;
    int maxSum = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        if (currSum < 0)
            currSum = 0;
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

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

    int totalSum = 0, nonwrapsum = kadane(a, n);

    for (int i = 0; i < n; i++)
    {
        totalSum += a[i];
        a[i] = -a[i];
    }

    cout << max(totalSum + kadane(a, n), nonwrapsum);

    return 0;
}