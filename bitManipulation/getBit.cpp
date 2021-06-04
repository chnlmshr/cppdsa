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
    cout << "Enter the position of bit to get: ";
    int p;
    cin >> p;
    cout << "Bit is: " << (n & (1 << p) ? 1 : 0) << endl;

    return 0;
}