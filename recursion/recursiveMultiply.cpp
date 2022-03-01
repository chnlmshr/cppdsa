#include <bits/stdc++.h>

using namespace std;

int multiply(int a, int b) {
  if(b == 0) return 0;
  int sign = 1;
  if(a < 0 and b < 0) sign = 1;
  else if(a < 0 or b < 0) sign = -1;
  a = abs(a);
  b = abs(b);
  if(a == 0 or b == 0) return 0;
  else {
    int res = 0;
    if(b & 1) res += a;
    res += multiply(a << 1, b >> 1);
    return (sign == -1 ? -res : res);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int a, b, sign; cin >> a >> b;

  cout << multiply(a, b);
  
  return 0;
}