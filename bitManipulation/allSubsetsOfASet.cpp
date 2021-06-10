// substrings of a string

#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    for (int i = 0; i < (1 << s.length()); i++)
    {
        for (int j = 0; j < s.length(); j++)
            if (i & (1 << j))
                cout << s[j];
        cout << endl;
    }

    return 0;
}