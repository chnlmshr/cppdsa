#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int maxFrequency = 0, currFrequency = 1;
    char mF = s[0];
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != s[i - 1])
        {
            if (currFrequency > maxFrequency)
            {
                maxFrequency = currFrequency;
                mF = s[i - 1];
            }
            currFrequency = 1;
        }
        else
        {
            currFrequency++;
        }
        if (i == s.length() - 1)
        {
            if (currFrequency > maxFrequency)
            {
                maxFrequency = currFrequency;
                mF = s[i - 1];
            }
        }
    }
    cout << max(maxFrequency, currFrequency) << " " << mF;

    return 0;
}