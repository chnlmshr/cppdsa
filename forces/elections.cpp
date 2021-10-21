#include <bits/stdc++.h>

using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b && a > c)
            cout << 0 << " ";
        else
            cout << max(b, c) - a + 1 << " ";
        if (b > a && b > c)
            cout << 0 << " ";
        else
            cout << max(a, c) - b + 1 << " ";
        if (c > b && c > a)
            cout << 0 << " ";
        else
            cout << max(a, b) - c + 1 << " ";
        cout << "\n";
    }
    return 0;
}