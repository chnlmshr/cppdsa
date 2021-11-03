#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define pii pair<int, int>
vector<pair<int, int>> adj[N];

void dij(int source, int n)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dis(n, 0);
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    pq.push({0, source});
    vector<int> par(n + 1, 0);
    par[1] = 1;

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjnode = it.second;
            int wt = it.first;
            if (dist + wt < dis[adjnode])
            {
                dis[adjnode] = dist + wt;
                par[adjnode] = node;
                pq.push({dist + wt, adjnode});
            }
        }
    }
    vector<int> vec;
    vec.push_back(n);
    int x = n;
    while (par[x] != 1)
    {
        x = par[x];
        vec.push_back(x);
    }
    if (vec.size() <= 1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            cout << vec[i] << " ";
        }
    }
}

int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back({1, v});
        adj[v].push_back({1, u});
    }
    dij(1, n);

    return 0;
}