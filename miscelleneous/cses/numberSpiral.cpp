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

  int t;
  cin >> t;
  while (t--)
  {
    unsigned long long r, c;
    cin >> r >> c;
    if (r >= c)
    {
      if (r % 2 == 0)
      {
        cout << r * r - c + 1;
      }
      else
      {
        cout << (r - 1) * (r - 1) + c;
      }
    }
    else
    {
      if (c % 2)
      {
        cout << c * c - r + 1;
      }
      else
      {
        cout << (c - 1) * (c - 1) + r;
      }
    }
    cout << "\n";
  }

  return 0;
}