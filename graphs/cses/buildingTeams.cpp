// https://cses.fi/problemset/task/1668

#include<bits/stdc++.h>
using namespace std;

void build(vector<int> &teams, int pupil, vector<vector<int>> &friendships, bool &impossible, int team = 1) {
	if(teams[pupil] == -1) {
		teams[pupil] = team;
		team = team == 1 ? 2 : 1;
		for(auto i : friendships[pupil]) {
			build(teams, i, friendships, impossible, team);
		}
	}
	else if(teams[pupil] != team) {
		impossible = true;
	}
}

int main() {
	int nPupils, nFriendships;
	cin >> nPupils >> nFriendships;
	vector<vector<int>> friendships(nPupils);
	for(int i = 0; i < nFriendships; i++) {
		int from, to;
		cin >> from >> to;
		friendships[--from].push_back(--to);
		friendships[to].push_back(from);
	}
	
	vector<int> teams(nPupils, -1);
	bool impossible = false;
	for(int pupil = 0; pupil < nPupils; pupil++) {
		if(teams[pupil] == -1) {
			build(teams, pupil, friendships, impossible);
		}
	}
	
	if(impossible) {
		cout << "IMPOSSIBLE";
	}
	else {
		for(int team : teams) {
			cout << team << " ";
		}
	}
}
