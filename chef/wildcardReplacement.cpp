#include <bits/stdc++.h>

using namespace std;

void solve(string &s, int l, int r, map<pair<int, int>, pair<int, int>> &m)
{
    if (l == r)
        m[{l, r}] = {0, 1};
    else if (s[l + 1] == '?')
    {
        solve(s, l + 1, l + 1, m);
        solve(s, l + 3, r - 1, m);
        pair<int, int> left = m[{l + 1, l + 1}], right = m[{l + 3, r - 1}];
        if (s[l + 2] == '+')
            m[{l, r}] = {left.first + right.first, left.second + right.second};
        else
            m[{l, r}] = {left.first - right.second, left.second - right.first};
    }
    else if (s[r - 1] == '?')
    {
        solve(s, l + 1, r - 3, m);
        solve(s, r - 1, r - 1, m);
        pair<int, int> left = m[{l + 1, r - 3}], right = m[{r - 1, r - 1}];
        if (s[r - 2] == '+')
            m[{l, r}] = {left.first + right.first, left.second + right.second};
        else
            m[{l, r}] = {left.first - right.second, left.second - right.first};
    }
    else
    {
        int x = 1, i = l + 2;
        while (x)
        {
            if (s[i] == '(')
                x++;
            else if (s[i] == ')')
                x--;
            i++;
        }
        solve(s, l + 1, i - 1, m);
        solve(s, i + 1, r - 1, m);
        pair<int, int> left = m[{l + 1, i - 1}], right = m[{i + 1, r - 1}];
        if (s[i] == '+')
            m[{l, r}] = {left.first + right.first, left.second + right.second};
        else
            m[{l, r}] = {left.first - right.second, left.second - right.first};
    }
}

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
        string s;
        cin >> s;
        int q;
        cin >> q;
        int n = s.length();
        map<pair<int, int>, pair<int, int>> m;
        solve(s, 0, n - 1, m);
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << m[{l - 1, r - 1}].second << " ";
        }
        cout << "\n";
    }
    return 0;
}