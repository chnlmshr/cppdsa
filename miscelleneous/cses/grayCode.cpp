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
  
  int n; cin >> n;
  
  vector<string> res(pow(2, n));
  
  vector<string> sv = {"0", "1"};
  for(int i = 2; i <= n; i++) {
    for(string &s : sv) {
      s = "0" + s;
    }
    int k = sv.size();
    for(int j = k - 1; j >= 0; j--) {
      string s = sv[j];
      s[0] = '1';
      sv.push_back(s);
    }
  }
  
  for(string s : sv) cout << s << "\n";
  
  return 0;
}