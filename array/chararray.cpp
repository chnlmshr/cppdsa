#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    char c[100] = "hello";
    cin >> c;
    cout << c << endl;
    int i = 0;
    while (c[i] != '\0')
    {
        cout << c[i];
        i++;
    }
    return 0;
}