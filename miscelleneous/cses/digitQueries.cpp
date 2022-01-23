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
  
  int q; cin >> q;
  while(q--) {
    long long k, n = 9, d = 1, kk, m = 1, p=0; cin >> k;
    while(k - n*d > 0) {
      k -= n*d;
      n *= 10LL;
      d++;
    }
    if(k%d) {
      m = 0;
      p = k%d-1LL;
    } else {
      p = d-1LL;
    }
    
    cout << k << " " << n << " " << d << "\n";
    cout << to_string((n/9) - m + (k/d))[p] << "\n";
  }

  return 0;
}