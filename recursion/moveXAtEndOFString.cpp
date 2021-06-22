#include <iostream>

using namespace std;

string moveXAtEndOfString(string s)
{
    if (s.length())
    {
        string r = moveXAtEndOfString(s.substr(1));
        if (s[0] == 'x')
            return r + s[0];
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

    cout << moveXAtEndOfString("axxbxxcxdddx");

    return 0;
}