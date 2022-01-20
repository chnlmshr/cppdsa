#include <bits/stdc++.h>

using namespace std;

int lastZero(string &s, int prevZero, int currpos)
{
  if (s[prevZero] == '0')
    return prevZero;
  else
  {
    for (int i = prevZero - 1; i > currpos; i--)
    {
      if (s[i] == '0')
        return i;
    }
  }
  return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int money, flipCost, swapCost;
  cin >> money >> flipCost >> swapCost;

  int l = 0, r = lastZero(s, n - 1, n);
  if (swapCost < flipCost)
  {
    while (l < r)
    {
      if (s[l] == '1')
      {
        r = lastZero(s, r, l);
        if (l < r)
          swap(s[l], s[r]);
        money -= swapCost;
      }
      else
        l++;
    }
  }

  return 0;
}