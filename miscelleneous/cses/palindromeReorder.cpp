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
  
  string s; cin >> s;
  unordered_map<char, int> freq;
  
  for(char c : s) freq[c]++;
  string left, right, center;
  bool possible = true;
  for(auto &i : freq) {
    if(i.second & 1) {
      if(center.size()) {
        possible = false;
        break;
      } else {
        center += i.first;
        i.second--;
      }
    }
    string ss(i.second/2, i.first);
    left = ss + left;
    right += ss;
  }
  
  if(possible) cout << left + center + right;
  else cout << "NO SOLUTION";

  return 0;
}