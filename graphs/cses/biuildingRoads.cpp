// https://cses.fi/problemset/task/1666

#include<bits/stdc++.h>
using namespace std;

int parent(vector<pair<int, int>> &vertiset, int city) {
	if(vertiset[city].first == city) {
		return city;
	}
	return vertiset[city].first = parent(vertiset, vertiset[city].first);
}

void setUnion(vector<pair<int, int>> &vertiset, int city1, int city2) {
	int parent1 = parent(vertiset, city1), parent2 = parent(vertiset, city2);
	if(vertiset[parent1].second > vertiset[parent2].second) {
		vertiset[parent2].first = parent1;
	}
	else if(vertiset[parent1].second < vertiset[parent2].second) {
		vertiset[parent1].first = parent2;
	}
	else {
		vertiset[parent1].first = parent2;
		vertiset[parent2].second++;
	}
}

int main() {
	int nCities, nRoads; 
	cin >> nCities >> nRoads;
	vector<pair<int, int>> roads(nRoads);
	for(auto &road : roads) {
		cin >> road.first >> road.second;
		road.first--;
		road.second--;
	}
	
	vector<pair<int, int>> vertiset; //parent, rank
	for(int i = 0; i < nCities; i++) {
		vertiset.emplace_back(i, 0);
	}
	
	for(auto road : roads) {
		if(parent(vertiset, road.first) != parent(vertiset, road.second)) {
			setUnion(vertiset, road.first, road.second);
		}
	}
	
	set<int> localities;
	for(auto road : vertiset) {
		localities.insert(parent(vertiset, road.first));
	}
	
	int nLocalities = localities.size();
	cout << nLocalities - 1 << "\n";
	
	for(auto i = localities.begin(); i != localities.end();) {
		auto j = i;
		if(++j == localities.end()) break;
		cout << *i+1 << " " << *(++i)+1 << "\n";
	}
}
