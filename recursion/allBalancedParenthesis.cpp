#include <bits/stdc++.h>

using namespace std;

void generate(string s, int o, int c)
{
    if (!o && !c)
    {
        cout << s << endl;
        return;
    }
    if (o == c)
        generate(s + '(', o - 1, c);
    else if (!o)
        generate(s + ')', o, c - 1);
    else
    {
        generate(s + '(', o - 1, c);
        generate(s + ')', o, c - 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    generate("", n, n);

    return 0;
}