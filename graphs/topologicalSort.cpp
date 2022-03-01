#include <bits/stdc++.h>

using namespace std;

void dfsSort(vector<int> graph[], int node, vector<bool> &vis, vector<int> &sorted) {
  for(int conNode : graph[node]) {
    if(not vis[conNode]) {
      vis[conNode] = true;
      dfsSort(graph, conNode, vis, sorted);
    }
  }
  sorted.push_back(node);
}

void topoSort(vector<int> graph[], int nNodes) {
  vector<bool> vis(nNodes+1, false);
  vector<int> sorted;
  for(int node = 1; node <= nNodes; node++) {
    if(not vis[node]) {
      vis[node] = true;
      dfsSort(graph, node, vis, sorted);
    }
  }
  for(int i = nNodes - 1; i >= 0; i--) cout << sorted[i] << " ";
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
  
  topoSort(graph, nNodes);

  return 0;
}