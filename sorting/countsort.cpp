#include <iostream>
#include <vector>
using namespace std;

void countSort(int ar[], int n)
{
    int m = ar[0];
    for (int i = 1; i < n; i++)
        m = max(m, ar[i]);

    int tar[10] = {0};
    for (int i = 0; i < n; i++)
        tar[ar[i]]++;

    for (int i = 1; i <= m; i++)
        tar[i] += tar[i - 1];

    int sar[n];
    for (int i = n - 1; i >= 0; i--)
        sar[--tar[ar[i]]] = ar[i];

    for (int i = 0; i < n; i++)
        ar[i] = sar[i];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    countSort(ar, n);

    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";

    return 0;
}