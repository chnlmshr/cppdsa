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
    char c[n + 1];
    cin >> c;
    bool ispal = true;
    for (int i = 0; i < n / 2; i++)
        if (c[i] != c[n - i - 1])
        {
            ispal = false;
            break;
        }
    if (ispal)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
    return 0;
}