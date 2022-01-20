#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  long mx = 0, cur = 0;
  char prev = 'X';
  for (char c : s)
  {
    if (c == prev)
      cur++;
    else
      cur = 1;
    mx = max(cur, mx);
    prev = c;
  }

  cout << mx;

  return 0;
}