#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll inf = 1e18;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../input.txt", "r", stdin);
    //     freopen("../../output.txt", "w", stdout);
    // #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll nCities, nRoads, nQueries;
    cin >> nCities >> nRoads >> nQueries;
    vector<vector<ll>> roads(nCities, vector<ll>(nCities, inf));
    for (ll i = 0; i < nRoads; i++)
    {
        ll from, to, dist;
        cin >> from >> to >> dist;
        roads[from][to] = min(dist, roads[--from][--to]);
        roads[to][from] = min(dist, roads[to][from]);
        roads[from][from] = 0;
        roads[to][to] = 0;
    }

    for (ll k = 0; k < nCities; k++)
        for (ll i = 0; i < nCities; i++)
            for (ll j = 0; j < nCities; j++)
                roads[i][j] = min(roads[i][j], roads[i][k] + roads[k][j]);

    for (ll i = 0; i < nQueries; i++)
    {
        ll from, to;
        cin >> from >> to;
        cout << (roads[--from][--to] == inf ? -1 : roads[from][to]) << "\n";
    }

    return 0;
}