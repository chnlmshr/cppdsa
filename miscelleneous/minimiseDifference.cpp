// https://www.codechef.com/SNCKQL21/problems/MINDIFF1

#include <bits/stdc++.h>
#define shree ios_base ::sync_with_stdio(false);
#define ganeshay cin.tie(nullptr);
#define namah cout.tie(nullptr);

using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif

    shree ganeshay namah;

    int T;
    cin >> T;
    while (T--)
    {
        int nv, ne;
        cin >> nv >> ne;
        vector<vector<int>> g(nv);
        vector<pair<int, int>> d(nv, pair<int, int>(0, -1)); // degrees, index
        for (int i = 0; i < ne; i++)
        {
            int f, t;
            cin >> f >> t;
            --f;
            --t;
            g[f].push_back(t);
            g[t].push_back(f);
            if (d[f].second == -1)
                d[f].second = f;
            if (d[t].second == -1)
                d[t].second = t;
            d[f].first++;
            d[t].first++;
        }
        sort(d.begin(), d.end());
        int mn = INT_MAX, mx = INT_MIN, r = nv - 1;
        vector<int> rank(nv);
        for (int i = 0; i < nv; i++)
        {
            rank[d[i].second] = r--;
        }
        for (int i = 0; i < nv; i++)
        {
            int c = 0;
            for (int j = 0; j < g[i].size(); j++)
            {
                if (rank[i] > rank[g[i][j]])
                    c++;
            }
            mn = min(mn, c);
            mx = max(mx, c);
        }
        cout << mx - mn << "\n";
        for (int i = 0; i < nv; i++)
        {
            cout << rank[i] + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}