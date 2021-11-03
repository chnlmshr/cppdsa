// https://cses.fi/problemset/task/1667

#include<bits/stdc++.h>
using namespace std;

int main() {
	int nComputers, nConnections;
	cin >> nComputers >> nConnections;
	vector<vector<int>> connections(nComputers);
	for(int i = 0; i < nConnections; i++) {
		int from, to;
		cin >> from >> to;
		connections[--from].push_back(--to);
		connections[to].push_back(from);
	}
	vector<int> trace(nComputers, -1);
	queue<int> q;
	q.push(0);
	trace[0] = 0;
	while(!q.empty()) {
		int computer = q.front();
		q.pop();
		int nCons = connections[computer].size();
		for(int i = 0; i < nCons; i++) {
			if(trace[connections[computer][i]] == -1) {
				q.push(connections[computer][i]);
				trace[connections[computer][i]] = computer;
			}
		}
	}
	if(trace[nComputers-1] == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		int computer = nComputers - 1;
		vector<int> route;
		while(trace[computer] != 0) {
			route.push_back(trace[computer]);
			computer = trace[computer];
		}
		int rs = route.size();
		cout << rs + 2 << "\n";
		cout << 1 << " ";
		for(int i = rs-1; i >= 0; i--) {
			cout << route[i] + 1 << " ";
		}
		cout << nComputers << " ";
	}
}
