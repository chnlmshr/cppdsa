// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;

int sx[] = {-1, 0, 1, 0}, sy[] = {0, 1, 0, -1};

vector<int> shortestPath(vector<string> &map, int &n, int &m)
{
    queue<pair<int, int>> q;
    vector<vector<int>> steps(n, vector<int>(m));
    pair<int, int> start, end;
    for (int i = 0; i < n && q.empty(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'A')
            {
                start = make_pair(i, j);
                q.emplace(i, j);
                break;
            }
        }
    }
    end.first = -1;
    while (!q.empty() && end.first == -1)
    {
        pair<int, int> ij = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            pair<int, int> step = make_pair(ij.first + sx[k], ij.second + sy[k]);
            int i = step.first, j = step.second;
            if (i >= 0 && i < n && j >= 0 && j < m && map[i][j] != '#')
            {
                if (map[i][j] == 'B')
                {
                    end = make_pair(i, j);
                    map[i][j] = '#';
                    steps[i][j] = k;
                    break;
                }
                map[i][j] = '#';
                steps[i][j] = k;
                q.push(step);
            }
        }
    }
    vector<int> pathv;
    if (end.first != -1 && map[end.first][end.second] == '#')
    {
        while (end.first != start.first || end.second != start.second)
        {
            int step = steps[end.first][end.second];
            pathv.push_back(step);
            end = make_pair(end.first - sx[step], end.second - sy[step]);
        }
    }
    return pathv;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*#ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);
    #endif*/
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        cin >> map[i];
    vector<int> path = shortestPath(map, n, m);
    int pl = path.size();
    if (pl)
    {
        cout << "YES\n"
             << pl << "\n";
        string sd = "URDL";
        for (int i = pl - 1; i >= 0; i--)
            cout << sd[path[i]];
    }
    else
        cout << "NO\n";
}
