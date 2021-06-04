#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = 0, sum = a[0];
    while (r < n && l <= r)
    {
        if (sum < s)
            sum += a[++r];
        else if (sum > s)
            sum -= a[l++];
        else
        {
            cout << l << " to " << r;
            return 0;
        }
    }
    cout << "No matching subarray!";
    return 0;
}