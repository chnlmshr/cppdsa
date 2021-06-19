#include <iostream>

using namespace std;

int fibbonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibbonacci(n - 1) + fibbonacci(n - 2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    cout << fibbonacci(n);
    return 0;
}