#include <iostream>

using namespace std;

void swap(int ar[], int a, int b)
{
    int t = ar[a];
    ar[a] = ar[b];
    ar[b] = t;
}

void waveSort(int ar[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (ar[i] > ar[i - 1])
        {
            swap(ar, i, i - 1);
        }
        if (ar[i] > ar[i + 1] && i < n - 2)
        {
            swap(ar, i, i + 1);
        }
    }
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

    waveSort(ar, n);

    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";

    return 0;
}