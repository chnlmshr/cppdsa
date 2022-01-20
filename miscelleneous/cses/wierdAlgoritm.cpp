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

  cout << n << " ";
  while (n != 1)
  {
    if (n % 2)
      n = n * 3 + 1;
    else
      n /= 2;
    cout << n << " ";
  }

  return 0;
}