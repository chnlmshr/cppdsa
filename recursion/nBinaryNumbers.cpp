#include <bits/stdc++.h>

using namespace std;

void generate(string s, int n, int one, int zero)
{
    if (!n)
    {
        cout << s << endl;
        return;
    }
    generate(s + "1", n - 1, one + 1, zero);
    if (one != zero)
        generate(s + "0", n - 1, one, zero + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    generate("", n, 0, 0);
    return 0;
}