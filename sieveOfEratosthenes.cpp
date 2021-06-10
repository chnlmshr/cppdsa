// Find the all primes numbers in a rane

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
    int prime[100] = {0}; // array size should > n
    for (int i = 2; i <= n; i++)
        if (!prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = 1;

    for (int i = 2; i <= n; i++)
        if (!prime[i])
            cout << i << " ";

    return 0;
}