#include <iostream>

using namespace std;

void swap(int ar[], int a, int b)
{
    int t = ar[a];
    ar[a] = ar[b];
    ar[b] = t;
}

int partition(int ar[], int l, int r)
{
    int p = ar[r], j = l - 1;
    for (int i = l; i < r; i++)
        if (ar[i] < p)
            swap(ar, ++j, i);
    swap(ar, j + 1, r);
    return j + 1;
}

void quickSort(int ar[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(ar, l, r);
        quickSort(ar, l, pi - 1);
        quickSort(ar, pi + 1, r);
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

    quickSort(ar, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";

    return 0;
}