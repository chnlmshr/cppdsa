#include <bits/stdc++.h>

using namespace std;

int main() {
// #ifndef ONLINE_JUDGE
//   freopen("../input.txt", "r", stdin);
//   freopen("../output.txt", "w", stdout);
// #endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    unordered_map<int, int> hash;
    for(auto &num: nums) {
      cin >> num;
      hash[num]++;
    }
    sort(nums.begin(), nums.end());
    int res = 0;
    for(int num : nums) {
      if(hash[num]) {
        if(hash[num*k]) hash[num*k]--;
        else res++;
        hash[num]--;
      }
    }
    cout << res << "\n";
  }

  return 0;
}