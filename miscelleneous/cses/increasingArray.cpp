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

  long n, prev, moves = 0;
  cin >> n >> prev;
  for (long i = 1; i < n; i++)
  {
    long cur;
    cin >> cur;
    if (cur < prev)
      moves += prev - cur;
    else
      prev = cur;
  }

  cout << moves;

  return 0;
}