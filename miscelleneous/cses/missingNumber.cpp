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

  long long n;
  cin >> n;
  long long sm = 0;

  for (int i = 0; i < n - 1; i++)
  {
    int k;
    cin >> k;
    sm += k;
  }

  cout << n * (n + 1) / 2 - sm << " ";

  return 0;
}