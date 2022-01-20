#include <bits/stdc++.h>
#define atmarama ios_base::sync_with_stdio(false);
#define ananda cin.tie(nullptr);
#define ramana cout.tie(nullptr);

using namespace std;

int solve(int root, vector<int> &nReachable, vector<bool> &vis, vector<vector<int>> &edges)
{
  if (vis[root])
    return 0;
  vis[root] = true;
  for (int edge : edges[root])
  {
    nReachable[root] += solve(edge, nReachable, vis, edges);
  }
  return nReachable[root];
}

int main()
{
  atmarama ananda ramana;
  int t;
  cin >> t;
  while (t--)
  {
    int nNodes, nEdges;
    cin >> nNodes >> nEdges;
    vector<vector<int>> edges(nNodes);
    for (int i = 0; i < nEdges; i++)
    {
      int from, to;
      cin >> from >> to;
      edges[--from].push_back(--to);
    }
    vector<int> nReachable(nNodes, 1);
    vector<bool> vis(nNodes, false);
    nReachable[0] += solve(0, nReachable, vis, edges);
    for (int r : nReachable)
      cout << r << " ";
    cout << "\n";
  }
  return 0;
}