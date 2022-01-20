#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        unordered_map<int, int> m;
        bool impossible = false;
        for (auto &i : nums)
        {
            cin >> i;
            m[i]++;
            if (m[i] > 2)
                impossible = true;
        }
        vector<int> v1, v2;
        int x, y;
        bool v1l = false;
        if (!impossible)
        {
            for (auto i : nums)
            {
                if (m[i] > 0)
                {
                    if (m[i] == 1)
                    {
                        v1.push_back(i);
                    }
                    else
                    {
                        v2.push_back(i);
                    }
                    m[i]--;
                }
            }
            x = v1.size();
            y = v2.size();
            if (x == y)
                impossible = true;
            else
            {
                if (y == 0)
                    sort(v1.rbegin(), v1.rend());
                else
                {
                    sort(v1.begin(), v1.end());
                    sort(v2.begin(), v2.end());
                    if (v1[x - 1] == v2[y - 1])
                        impossible = true;
                    else
                    {
                        for (int i = 0; i < y; i++)
                        {
                            if (v1[i] > v2[i])
                                v1l = true;
                        }
                        if (v1l)
                        {
                            reverse(v2.begin(), v2.end());
                        }
                        else
                        {
                            reverse(v1.begin(), v1.end());
                        }
                    }
                }
            }
        }
        if (impossible)
            cout << -1;
        else
        {
            if (v1l)
            {
                for (int i : v1)
                    cout << i << " ";
                for (int i : v2)
                    cout << i << " ";
            }
            else
            {
                for (int i : v2)
                    cout << i << " ";
                for (int i : v1)
                    cout << i << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}