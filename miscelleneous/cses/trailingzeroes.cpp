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

  long n, cnt = 0;
  cin >> n;
  while (n >= 5)
  {
    n /= 5;
    cnt += n;
  }

  cout << cnt;

  return 0;
}