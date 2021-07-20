#include <bits/stdc++.h>

using namespace std;

map<string, string> m;

void perm(string i, string o)
{
    if (i.size() == 0)
    {
        m[o] = o;
        return;
    }
    char c = i[0];
    string ni = i.size() > 1 ? i.substr(1) : "";
    perm(ni, o + c);
    if (c >= 'a' && c <= 'z')
        perm(ni, o + (char)(c - 32));
    else if (c >= 'A' && c <= 'Z')
        perm(ni, o + (char)(c + 32));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string i;
    cin >> i;
    perm(i, "");
    for (auto &&i : m)
    {
        cout << i.first << endl;
    }

    return 0;
}