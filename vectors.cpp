#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    for (vector<int>::iterator i = v.begin(); i < v.end(); i++)
    {
        cout << *i << " ";
    }

    for (auto i : v)
    {
        cout << i << " ";
    }

    v.pop_back(); // v = {1}

    vector<int> v2(3, 50); // v2 = {50, 50, 50}

    swap(v, v2);

    sort(v2.begin(), v2.end());

    return 0;
}
