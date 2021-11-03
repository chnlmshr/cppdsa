// https://cses.fi/problemset/task/1192

#include<bits/stdc++.h>
using namespace std;

void mutate(vector<string> &map, int &n, int &m, int i, int j) {
    if(i >= 0 && j >= 0 && i < n && j < m && map[i][j] == '.') {
        map[i][j] = '#';
        mutate(map, n, m, i-1, j);
        mutate(map, n, m, i, j+1);
        mutate(map, n, m, i+1, j);
        mutate(map, n, m, i, j-1);
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, rooms = 0; cin >> n >> m;
    vector<string> map(n);
    for(int i = 0; i < n; i++) cin >> map[i];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            if(map[i][j] == '.') {
                mutate(map, n, m, i, j);
                rooms++;
            }
    cout << rooms;
}
    
