#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    cin.ignore();
    char s[n + 1];
    cin.getline(s, n + 1);
    cin.ignore();
    int i = 0, curlen = 0, maxlen = 0, l = 0, ml = 0;
    while (true)
    {
        if (s[i] == ' ')
        {
            if (curlen > maxlen)
            {
                maxlen = curlen;
                ml = l;
            }
            curlen = 0;
            l = i + 1;
        }
        else if (s[i] == '\0')
        {
            if (curlen > maxlen)
            {
                maxlen = curlen;
                ml = l;
            }
            break;
        }
        else
            curlen++;
        i++;
    }

    cout << maxlen << endl;
    for (int i = ml; i < ml + maxlen; i++)
        cout << s[i];
    return 0;
}