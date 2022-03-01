#include <bits/stdc++.h>

using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
//   freopen("../input.txt", "r", stdin);
//   freopen("../output.txt", "w", stdout);
// #endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    if(n == 3) {
      cout << 3 << " " << 2 << " " << 1 << "\n";
      cout << 1 << " " << 3 << " " << 2 << "\n";
      cout << 3 << " " << 1 << " " << 2 << "\n";
      continue;
    }
    for(int i = 0; i < n; i++) {
      for(int j = n-i; j >= 1; j--) {
        cout << j << " ";
      }
      for(int j = n; j > n-i; j--) {
        cout << j << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}