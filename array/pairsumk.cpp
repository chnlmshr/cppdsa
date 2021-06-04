#include <iostream>

using namespace std;

void brutePairSum(int a[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] + a[j] == k)
            {
                cout << a[i] << " + " << a[j] << " = " << k << endl;
                return;
            }
    cout << "Not Found!";
}

void fastPairSum(int a[], int n, int k)
{
    // Needs Sorted Array
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (a[l] + a[r] == k)
        {
            cout << a[l] << " + " << a[r] << " = " << k << endl;
            return;
        }
        else if (a[l] + a[r] == k)
            l++;
        else
            r--;
    }
    cout << "Not Found!";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    brutePairSum(a, n, k);
    fastPairSum(a, n, k);
    return 0;
}