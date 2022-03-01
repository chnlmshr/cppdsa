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
    vector<int> cors(6);
    for(auto &cor : cors) cin >> cor;
    if(cors[1] == cors[3] and cors[5] < cors[1]) cout << abs(cors[0] - cors[2]);
    else if(cors[1] == cors[5] and cors[3] < cors[1]) cout << abs(cors[0] - cors[4]);
    else if(cors[5] == cors[3] and cors[1] < cors[5]) cout << abs(cors[4] - cors[2]);
    else cout << 0;
    cout << "\n";
  }

  return 0;
}