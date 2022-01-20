#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int t; cin >> t;
  while(t--) {
    long long a, b; cin >> a >> b;
    if(2*a - b >= 0 and 2*b - a >= 0 and (2*a - b) % 3 == 0 and (2*b - a) % 3 == 0) cout << "YES";
    else cout << "NO";
    cout << "\n";
  }

  return 0;
}