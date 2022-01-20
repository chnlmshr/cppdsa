#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int x, y; cin >> x >> y;
		if(x%2 && y%2) {
			cout << x/2 << " " << y/2+1;
		}
		else if(x%2 || y%2) cout << -1 << " " << -1;
		else cout << x/2 << " " << y/2;
		cout << "\n";
	}
}
