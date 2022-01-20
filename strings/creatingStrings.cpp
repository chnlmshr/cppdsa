#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  string s; cin >> s;
  map<string, bool> hash;
  sort(s.begin(), s.end());
  string original = s;
  while(next_permutation(s.begin(), s.end())) hash[s] = true;
  
  cout << hash.size() + 1 << "\n" << original << "\n";
  for(auto s : hash) cout << s.first << "\n";

  return 0;
}