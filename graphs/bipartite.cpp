#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector<int> graph[], int nNodes) {
  vector<int> color(nNodes+1, -1);
  for(int node = 1; node <= nNodes; node++) {
    if(color[node] == -1) {
      queue<int> q;
      q.push(node);
      color[node] = 0;
      while(not q.empty()) {
        int curNode = q.front();
        q.pop();
        for(int conNode : graph[curNode]) {
          if(color[conNode] == -1) {
            q.push(conNode);
            color[conNode] = not color[curNode];
          } else if(color[conNode] == color[curNode]) {
            return false;
          }
        }
      }
    }
  }
  return true;
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
  
  cout << isBipartite(graph, nNodes);

  return 0;
}