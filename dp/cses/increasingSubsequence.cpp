#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
#endif

	ios_base ::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	for (auto &e : v)
		cin >> e;

	vector<int> dp;

	for (int i = 0; i < n; i++)
	{
		auto it = lower_bound(dp.begin(), dp.end(), v[i]);
		if (it == dp.end())
			dp.push_back(v[i]);
		else
			*it = v[i];
	}

	cout << dp.size();

	return 0;
}