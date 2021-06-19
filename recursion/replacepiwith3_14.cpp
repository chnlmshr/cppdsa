#include <iostream>

using namespace std;

void replacepiwith3_14(string s)
{
    if (s.length() <= 1)
        return;
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacepiwith3_14(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacepiwith3_14(s.substr(1));
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    replacepiwith3_14(s);
    return 0;
}