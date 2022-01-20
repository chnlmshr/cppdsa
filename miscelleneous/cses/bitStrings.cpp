#include <bits/stdc++.h>

using namespace std;

const long mod = 1e9 + 7;

// binary exponetiation
long powerof2(long n)
{
  long p;
  if (n == 0)
    p = 1;
  else
  {
    p = powerof2(n / 2);
    p = (p * p) % mod;
    if (n & 1)
      p = p * 2;
  }
  return p;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long n;
  cin >> n;
  cout << powerof2(n) % mod;

  return 0;
}