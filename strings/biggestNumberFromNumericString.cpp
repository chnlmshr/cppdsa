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
    sort(s.begin(), s.end(), greater<int>());
    // sort(s.begin(), s.end());
    // reverse(s.begin(), s.end());
    cout << s;

    return 0;
}