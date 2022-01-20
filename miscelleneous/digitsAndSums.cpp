#include <bits/stdc++.h>

using namespace std;

string secondSmallest(int nDigits, int sum, string currentNum)
{
    if (sum <= 9)
    {
        if (nDigits == 1)
            return to_string(sum) + currentNum;
        return secondSmallest(nDigits - 1, 1, to_string(sum - 1) + currentNum);
    }
    if (sum <= 18 && nDigits == 2)
        return secondSmallest(nDigits - 2, sum - 8, to_string(17) + currentNum);
    return secondSmallest(nDigits - 1, sum - 9, to_string(9) + currentNum);
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

    int nDigits, sum;
    cin >> nDigits >> sum;

    cout << secondSmallest(nDigits, sum, "");

    return 0;
}