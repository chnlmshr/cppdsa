// https://www.codechef.com/SNCKQL21/submit/MAXDISTKT

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i].first;
            b[i].second = i;
        }

        sort(b.begin(), b.end());
        int mn = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i].first > mn)
            {
                a[b[i].second] = mn;
                mn++;
            }
            else if (b[i].first == mn)
                a[b[i].second] = mn;
            else
                a[b[i].second] = b[i].first;
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
