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
    cout << "Enter the position of bit to clear: ";
    int p;
    cin >> p;
    cout << "New number is: " << (n & ~(1 << p)) << endl;

    return 0;
}