#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const long long int inf = 1e18;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll nCities, nConnections;
    cin >> nCities >> nConnections;
    vector<vector<pair<ll, ll>>> connections(nCities);
    for (int i = 0; i < nConnections; i++)
    {
        ll from, to, dist;
        cin >> from >> to >> dist;
        connections[--from].emplace_back(dist, --to);
    }

    vector<ll> dist(nCities, inf);
    dist[0] = 0;
    vector<bool> vis(nCities, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.emplace(0, 0);

    while (!pq.empty())
    {
        ll p = pq.top().second;
        pq.pop();
        if (!vis[p])
        {
            vis[p] = true;
            for (auto [f, s] : connections[p])
            {
                if (dist[s] > dist[p] + f)
                {
                    dist[s] = f + dist[p];
                    pq.push({dist[s], s});
                }
            }
        }
    }

    for (auto d : dist)
        cout << d << " ";

    return 0;
}