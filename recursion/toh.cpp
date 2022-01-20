#include <bits/stdc++.h>

using namespace std;

void towerOfHanoi(int n, int src, int dest, int helper) {
  if (!n) return;
  towerOfHanoi(n - 1, src, helper, dest);
  cout << src << " " << dest << "\n";
  towerOfHanoi(n - 1, helper, dest, src);
}

int main() {
  
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  int n; cin >> n;
  cout << pow(2, n) - 1 << "\n";
  towerOfHanoi(n, 1, 3, 2);
  return 0;
}