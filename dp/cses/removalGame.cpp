// https://cses.fi/problemset/task/1097/

#include <bits/stdc++.h>

using namespace std;

void mxScore(int l, int r, vector<int> &nums, int &a, int &b, bool aturn)
{
    if (l == r)
    {
        if (aturn)
            a += nums[l];
        else
            b += nums[l];
        return;
    }
    if (aturn)
    {
        int a1 = a + nums[l], a2 = a + nums[r];
        mxScore(l + 1, r, nums, a1, b, false);
        mxScore(l, r - 1, nums, a2, b, false);
        a = max(a1, a2);
    }
    else
    {
        int b1 = b + nums[l], b2 = b + nums[r];
        mxScore(l + 1, r, nums, a, b1, true);
        mxScore(l, r - 1, nums, a, b2, true);
        b = max(b1, b2);
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../input.txt", "r", stdin);
    //     freopen("../../output.txt", "w", stdout);
    // #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);

    for (auto &&num : nums)
        cin >> num;
    int a = 0, b = 0;
    mxScore(0, n - 1, nums, a, b, true);

    cout << a;

    return 0;
}