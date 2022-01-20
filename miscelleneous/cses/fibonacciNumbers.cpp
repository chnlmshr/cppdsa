// matrix Exponentition

#include <bits/stdc++.h>

using namespace std;

const long mod = 1e9 + 7;

vector<vector<long>> multiply(vector<vector<long>> &mat1, vector<vector<long>> &mat2)
{
  long n = mat1.size(), m = mat2[0].size(), x = mat1[0].size();
  vector<vector<long>> res(n, vector<long>(m, 0));

  for (long i = 0; i < n; i++)
    for (long j = 0; j < m; j++)
      for (long k = 0; k < x; k++)
        res[i][j] += (mat1[i][k] * mat2[k][j]) % mod;

  return res;
}

vector<vector<long>> exponentiate(vector<vector<long>> mat, long n)
{
  vector<vector<long>> res;
  if (n == 0) // returning identity matrix
  {
    long sz = mat.size();
    res.resize(sz, vector<long>(sz, 0));
    for (long i = 0; i < sz; i++)
      res[i][i] = 1;
  }
  else if (n == 1)
    res = mat;
  else
  {
    res = exponentiate(mat, n / 2);
    res = multiply(res, res);
    if (n & 1)
      res = multiply(res, mat);
  }
  return res;
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

  vector<vector<long>> mat = {{1, 1},
                              {1, 0}};
  cout << exponentiate(mat, n)[0][1] % mod;
  return 0;
}