#include <iostream>

using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif

    cout << "Enter the number: ";
    int n;
    cin >> n;
    cout << "Enter the position of bit to update: ";
    int p;
    cin >> p;
    int b = n & (1 << p) ? 1 : 0;
    int r;
    if (b)
        r = n & ~(1 << p);
    else
        r = n | (1 << p);
    cout << "New number is: " << r << endl;

    return 0;
}