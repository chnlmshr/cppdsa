#include <iostream>

using namespace std;

string removeDups(string s)
{
    if (s.length())
    {
        string r = removeDups(s.substr(1));
        if (s[0] == r[0])
            return r;
        else
            return s[0] + r;
    }
    return "";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cout << removeDups("aaabbcccdeeefghiii");

    return 0;
}