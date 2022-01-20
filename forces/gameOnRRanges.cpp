#include <bits/stdc++.h>

using namespace std;

bool comp(pair<pair<int, int>, int> i1, pair<pair<int, int>, int> i2)
{
    return (i1.first.second - i1.first.first < i2.first.second - i2.first.first);
}

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
        vector<pair<pair<int, int>, int>> ranges;
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            ranges.push_back({{l, r}, -1});
        }
        unordered_map<int, bool> done;
        sort(ranges.begin(), ranges.end(), comp);
        for (auto &range : ranges)
        {
            if (range.first.first == range.first.second)
            {
                range.second = range.first.first;
                done[range.first.first] = true;
            }
            for (int i = range.first.first; i <= range.first.second; i++)
            {
                if (!done[i])
                {
                    range.second = i;
                    done[i] = true;
                    break;
                }
            }
        }
        for (auto range : ranges)
            cout << range.first.first << " " << range.first.second << " " << range.second << "\n";
    }
    return 0;
}