// https://cses.fi/problemset/task/1633/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> combinations;

int nCombinations(int n)
{
    if (!n)
        return 1;
    if (n < 0)
        return 0;
    if (combinations[n])
        return combinations[n];
    int res = 0;
    for (int i = 1; i <= 6 && i <= n; i++)
        (res += nCombinations(n - i)) %= 1000000007;
    return combinations[n] = res;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    cout << nCombinations(n) << "\n";

    return 0;
}