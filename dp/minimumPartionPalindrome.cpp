#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

bool isPalindrome(string s)
{
    int n = s.size();
    bool ispal = true;
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
        {
            ispal = false;
            break;
        }
    return ispal;
}

int mcm(string v, int i, int j)
{
    if (i >= j || isPalindrome(v))
        return 0;
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
        mn = min(mn, mcm(v, i, k) + mcm(v, k + 1, j) + 1);
    return mn;
}

map<pair<int, int>, int> m;
int mcmMemoization(string v, int i, int j)
{
    if (m[make_pair(i, j)])
        return m[make_pair(i, j)];
    if (i >= j || isPalindrome(v))
        return 0;
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
        mn = min(mn, mcm(v, i, k) + mcm(v, k + 1, j) + 1);
    return m[make_pair(i, j)] = mn;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string v;
    cin >> v;

    int mcm1 = mcm(v, 1, v.size() - 1);
    int mcm2 = mcmMemoization(v, 1, v.size() - 1);

    cout << mcm1 << " " << mcm2 << endl;

    return 0;
}