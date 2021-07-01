#include <iostream>

using namespace std;

void merge(int ar[], int l, int r, int m)
{
    int n1 = m - l + 1, n2 = r - m;
    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = ar[i + l];
    for (int i = 0; i < n2; i++)
        b[i] = ar[i + m + 1];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[i])
        {
            ar[k] = a[i];
            k++;
            i++;
        }
        else
        {
            ar[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        ar[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        ar[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int ar[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(ar, l, m);
        mergeSort(ar, m + 1, r);
        merge(ar, l, r, m);
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
    mergeSort(ar, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";

    return 0;
}