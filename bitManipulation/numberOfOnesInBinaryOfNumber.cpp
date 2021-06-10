#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, count = 0;
    cin >> n;
    while (n)
    {
        count++;
        n &= n - 1;
    }
    cout << count;
    return 0;
}