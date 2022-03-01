#include <bits/stdc++.h>

using namespace std;

bool hasCycle(vector<int> graph[], int nNodes) {
  vector<bool> vis(nNodes+1, false);
  for(int node = 1; node <= nNodes; node++) {
    if(not vis[node]) {
      queue<pair<int, int>> q;
      q.push({node, -1});
      vis[node] = true;
      while(not q.empty()) {
        int curNode = q.front().first;
        int par = q.front().second;
        q.pop();
        for(int conNode : graph[curNode]) {
          if(not vis[conNode]) {
            q.push({conNode, curNode});
            vis[conNode] = true;
          } else if(conNode != par) return true;
        }
      }
    }
  }
  return false;
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
    graph[to].push_back(from);
  }
  
  cout << hasCycle(graph, nNodes);

  return 0;
}