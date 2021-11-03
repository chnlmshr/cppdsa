// https://cses.fi/problemset/task/1669

#include <bits/stdc++.h>
using namespace std;

void trip(int city, vector<vector<int>> &roads, vector<int> &distance, vector<int> &parent, vector<int> &trace, bool &impossible)
{
	for (int i : roads[city])
	{
		if (impossible)
		{
			if (parent[i] == -1)
			{
				distance[i] = distance[city] + 1;
				parent[i] = city;
				trip(i, roads, distance, parent, trace, impossible);
			}
			else
			{
				if (distance[city] - distance[i] >= 2)
				{
					trace.push_back(i);
					// cout << distance[city] - distance[i] << "\n";
					while (parent[city] != i)
					{
						trace.push_back(city);
						city = parent[city];
					}
					trace.push_back(city);
					trace.push_back(i);
					impossible = false;
					return;
				}
			}
		}
	}
}

int main()
{

	// #ifndef ONLINE_JUDGE
	// 	freopen("../../input.txt", "r", stdin);
	// 	freopen("../../outout.txt", "w", stdin);
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nCities, nRoads;
	cin >> nCities >> nRoads;
	vector<vector<int>> roads(nCities);
	int mn = INT_MAX;
	for (int i = 0; i < nRoads; i++)
	{
		int from, to;
		cin >> from >> to;
		roads[--from].push_back(--to);
		roads[to].push_back(from);
		mn = min(mn, min(from, to));
	}

	bool impossible = true;
	vector<int> parent(nCities, -1);  // node occuring before current node
	vector<int> distance(nCities, 0); // distance from 0th node

	for (int i = mn; i < nCities; i++)
	{
		if (parent[i] == -1)
		{
			fill(parent.begin(), parent.end(), -1);
			fill(distance.begin(), distance.end(), 0);
			distance[0] = 0;
			parent[0] = -1;
			vector<int> trace;
			trip(i, roads, distance, parent, trace, impossible);
			int nTrace = trace.size();
			if (nTrace)
			{
				cout << nTrace << "\n";
				for (int i = nTrace - 1; i >= 0; i--)
				{
					cout << trace[i] + 1 << " ";
				}
				impossible = false;
				break;
			}
		}
	}

	if (impossible)
	{
		cout << "IMPOSSIBLE";
	}
}