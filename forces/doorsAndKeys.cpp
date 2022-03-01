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
    string s; cin >> s;
    bool rgb[3] = {false, false, false};
    int cnt = 0;
    for(char c: s) {
      if(c == 'r') rgb[0] = true;
      else if(c == 'g') rgb[1] = true;
      else if(c == 'b') rgb[2] = true;
      else if(c == 'R') {
        if(rgb[0]) cnt++;
        else break;
      } else if(c == 'G') {
        if(rgb[1]) cnt++;
        else break;
      } else if(c == 'B') {
        if(rgb[2]) cnt++;
        else break;
      }
    }
    if(cnt == 3) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}