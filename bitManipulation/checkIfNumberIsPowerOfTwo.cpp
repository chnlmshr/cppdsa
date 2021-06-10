#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    cout << ((n & (n - 1)) ? "No" : "Yes");

    return 0;
}