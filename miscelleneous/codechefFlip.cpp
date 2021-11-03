#include<bits/stdc++.h>
#define debug(z, x) cout << "\nDEBUG (" << z << "): " << x << "\n";

using namespace std;

bool isZero(string &num, int &n) {
    for(char c : num) if(c == '1') return false;
    return true;
}

string flip(string num, int start, int range) {
    for(int i = start; i < start + range; i++) num[i] = (num[i] == '1' ? '0' : '1');
    //debug("flip", num);
    return num;
}

bool possible(string num, int range, int &n, vector<int> &steps) {
    //debug("possible", num);
    if(isZero(num, n)) return true;
    if(range > n) return false;
    for(int i = 0; i + range <= n; i += range) {
        bool p = possible(flip(num, i, range), range * 2, n, steps);
        if(p) {
            steps.push_back(i+1);
            return true;
        }
        //debug("finalPossible", finalPossible);
    }
    return false;
}

int main() {
    int T; cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        string s = "", mask = "";
        for(int i = 0; i < k; i++) s += '1';
        for(int i = 0; i < n-k; i++) s += '0';
        vector<int> steps;
        //debug("main", s);
        bool p = possible(s, 1, n, steps);
        if(p) {
            int sn = steps.size();
            cout << "YES\n" << sn << "\n";
            for(int i = sn - 1; i >= 0; i--) cout << steps[i] << "\n";
        } else cout << "NO\n";
    }
}
