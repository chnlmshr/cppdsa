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
        int l1, l2, l3;
        cin >> l1 >> l2 >> l3;
        if (l1 % 2 == 0 && l2 == l3 || (l2 % 2 == 0 && l1 == l3) || (l3 % 2 == 0 && l2 == l1) || (l1 + l2 == l3) || (l2 + l3 == l1) || (l1 + l3 == l2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}