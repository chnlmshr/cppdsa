#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> a, vector<int> b, int m, int n, int A, int B, int days, unordered_map<int, bool> &hash) {
  if(days) {
    if(days & 1) {
      for(int i = 0; i < m; i++) {
        vector<int> at(a.begin(), a.end()), bt(b.begin(), b.end());
        at.erase(at.begin()+i);
        bt.push_back(a[i]);
        if(A >= a[i]) solve(at, bt, m-1, n+1, A-a[i], B+b[i], days-1, hash);
      }
    } else {
      for(int i = 0; i < n; i++) {
        vector<int> at(a.begin(), a.end()), bt(b.begin(), b.end());
        bt.erase(bt.begin()+i);
        at.push_back(b[i]);
        if(B >= b[i]) solve(at, bt, m+1, n-1, A+b[i], B-b[i], days-1, hash);
      }
    }
  } else if(not hash[A]) hash[A] = true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int m, n, A, B, days; cin >> m >> n >> A >> B >> days;
  vector<int> a(m), b(n);
  for(auto &e : a) cin >> e;
  for(auto &e : b) cin >> e;
  unordered_map<int, bool> hash;
  vector<int> at(a.begin(), a.end()), bt(b.begin(), b.end());
  solve(a, b, m, n, A, B, days, hash);  
  for(auto pair : hash) cout << pair.first << "\n";
  
  return 0;
}