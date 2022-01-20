#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int mcm(vector<int> &v, int i, int j)
{
    if (i >= j)
        return 0;
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
        mn = min(mn, mcm(v, i, k) + mcm(v, k + 1, j) + v[i - 1] * v[k] * v[j]);
    return mn;
}

map<pair<int, int>, int> m;
int mcmMemoization(vector<int> &v, int i, int j)
{
    if (i >= j)
        return 0;
    if (m[make_pair(i, j)])
        return m[make_pair(i, j)];
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
        mn = min(mn, mcm(v, i, k) + mcm(v, k + 1, j) + v[i - 1] * v[k] * v[j]);
    return m[make_pair(i, j)] = mn;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v)
        cin >> i;

    auto start = high_resolution_clock::now();
    int mcm1 = mcm(v, 1, n - 1);
    auto stop1 = high_resolution_clock::now();
    int mcm2 = mcmMemoization(v, 1, n - 1);
    auto stop2 = high_resolution_clock::now();

    cout << mcm1 << " " << mcm2 << endl;

    auto duration1 = duration_cast<microseconds>(start - stop1);
    auto duration2 = duration_cast<microseconds>(stop1 - stop2);

    cout << "Time we saved via memoization(in microseconds): " << duration1.count() - duration2.count();
    return 0;
}