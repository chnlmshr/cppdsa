#include <bits/stdc++.h>

using namespace std;
map<string, string> m;
void subsets(string i, string o)
{
    if (i.size() == 0)
    {
        m[o] = o;
        return;
    }
    char c = i[0];
    string ni = i.size() > 1 ? i.substr(1) : "";
    subsets(ni, o + ' ' + c);
    subsets(ni, o + c);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string i;
    cin >> i;
    string o = i.substr(0, 1);
    string ni = i.size() > 1 ? i.substr(1) : "";
    subsets(ni, o);
    for (auto &&i : m)
    {
        cout << i.first << endl;
    }

    return 0;
}