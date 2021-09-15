#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, s;
    cin >> n >> s;
    cout << (s - n + 1) / (n / 2 + 1);
    return 0;
}