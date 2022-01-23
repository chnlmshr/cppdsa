#include <bits/stdc++.h>

using namespace std;

vector<int> des;
bool vis[9][9];

int trace(int d = 0, int r = 1, int c = 1) {
  if(vis[r][c-1] and vis[r][c+1] and not vis[r-1][c] and not vis[r+1][c]) return 0;
  if(vis[r-1][c] and vis[r+1][c] and not vis[r][c-1] and not vis[r][c+1]) return 0;
  
  if(r == 7 and c == 1) {
    if(d == 48) return 1; 
    return 0;
  }
  if(d == 48) return 0;
  
  vis[r][c] = true;
  int res = 0;
  
  if(des[d] == 0) {
    if(not vis[r-1][c]) res += trace(d+1, r-1, c);
    if(not vis[r][c+1]) res += trace(d+1, r, c+1);
    if(not vis[r+1][c]) res += trace(d+1, r+1, c);
    if(not vis[r][c-1]) res += trace(d+1, r, c-1);
  }
  else if(des[d] == 1 and not vis[r-1][c]) res = trace(d+1, r-1, c);
  else if(des[d] == 2 and not vis[r][c+1]) res = trace(d+1, r, c+1);
  else if(des[d] == 3 and not vis[r+1][c]) res = trace(d+1, r+1, c);
  else if(des[d] == 4 and not vis[r][c-1]) res = trace(d+1, r, c-1);
  
  vis[r][c] = false;
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  string s; cin >> s;
  
  for(char c : s) {
    if(c == 'U') des.push_back(1);
    else if(c == 'R') des.push_back(2);
    else if(c == 'D') des.push_back(3);
    else if(c == 'L') des.push_back(4);
    else des.push_back(0);
  }
  
  for(int i = 0; i <= 8; i++) vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = true;
  
  for(int i = 1; i < 8; i++) {
    for(int j = 1; j < 8; j++) {
      vis[i][j] = false;
    }
  }
  
  cout << trace();

  return 0;
}