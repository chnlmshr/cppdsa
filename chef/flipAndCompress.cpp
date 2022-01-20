#include <bits/stdc++.h>

using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int op0 = 0, op1 = 0, cont0 = 0, cont1 = 0;
        char prev = 'x';
        for (char c : s)
        {
            if (c != prev)
            {
                if (cont0)
                {
                    op0++;
                    if (cont0 > 1)
                        op0++;
                }
                else if (cont1)
                {
                    op1++;
                    if (cont1 > 1)
                        op1++;
                }
                cont0 = 0;
                cont1 = 0;
                prev = c;
            }
            if (c == '0')
                cont0++;
            else
                cont1++;
        }

        if (cont0)
        {
            op0++;
            if (cont0 > 1)
                op0++;
        }
        else if (cont1)
        {
            op1++;
            if (cont1 > 1)
                op1++;
        }

        cout << min(op0, op1) << "\n";
    }

    return 0;
}