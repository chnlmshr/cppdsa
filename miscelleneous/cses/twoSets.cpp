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
  long long sm = n * (n + 1) / 2;
  if (sm & 1)
    cout << "NO\n";
  else
  {
    cout << "YES\n";
    vector<int> set1, set2;
    sm /= 2;
    while (n)
    {
      if (n <= sm)
      {
        sm -= n;
        set1.push_back(n--);
      }
      else
      {
        set2.push_back(n--);
      }
    }
    cout << set1.size() << "\n";
    for (long long e : set1)
      cout << e << " ";
    cout << "\n";
    cout << set2.size() << "\n";
    for (long long e : set2)
      cout << e << " ";
    cout << "\n";
  }

  return 0;
}