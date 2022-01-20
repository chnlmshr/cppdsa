// Two Knights can only attack when they are in a 3x2 or 2x3 matrix
// So, we just need two find all combinations of two knights possible i the chess board and subtract, the number of 2x3 and 3x2 matries from it.

#include <bits/stdc++.h>

using namespace std;

long long possiblePositions(long long n)
{
  long long allPossibleCombinations = (n * n * (n * n - 1)) / 2;
  long long notPossiblePositions = 4 * (n - 2) * (n - 1); // no. of 3x2 and 2x3 matrices
  return allPossibleCombinations - notPossiblePositions;
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

  long long n;
  cin >> n;
  cout << 0 << "\n";
  for (long long i = 2; i <= n; i++)
  {
    cout << possiblePositions(i) << "\n";
  }

  return 0;
}