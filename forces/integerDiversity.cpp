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
        int n;
        cin >> n;
        int x;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (m[x])
            {
                if (m[x] == 1)
                    m[x]++;
            }
            else if (m[-x])
            {
            }
        }
        cout << n << "\n";
    }

    return 0;
}