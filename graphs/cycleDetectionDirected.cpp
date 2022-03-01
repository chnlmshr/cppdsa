#include <bits/stdc++.h>

using namespace std;

bool checkCycle(vector<int> graph[], int node, vector<bool> &vis, vector<bool> &dfsvis) {
  vis[node] = dfsvis[node] = true;
  bool cycleDetected = false;
  for(int conNode : graph[node]) {
    if(vis[conNode] and dfsvis[conNode]) {
      return true;
    } else if(not vis[conNode]) {
      cycleDetected = checkCycle(graph, conNode, vis, dfsvis);
      if(cycleDetected) return true;
    }
  }
  dfsvis[node] = false;
  return cycleDetected;
}

bool hasCycle(vector<int> graph[], int nNodes) {
  vector<bool> vis(nNodes+1, false), dfsvis(nNodes+1, false);
  bool cycleDetected = false;
  for(int node = 1; node <= nNodes; node++) {
    if(not vis[node]) {
      cycleDetected = checkCycle(graph, node, vis, dfsvis);
      if(cycleDetected) return true;
    }
  }
  return cycleDetected;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int nNodes, nEdges; cin >> nNodes >> nEdges;
  vector<int> graph[nNodes+1];

  for(int i = 0; i < nEdges; i++) {
    int from, to; cin >> from >> to;
    graph[from].push_back(to);
  }

  cout << hasCycle(graph, nNodes);  

  return 0;
}