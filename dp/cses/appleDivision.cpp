#include <bits/stdc++.h>

using namespace std;

void allSubsetSums(int n, vector<long long> &nums, unordered_map<long long, bool>  &sums, long long sm) {
  if(n == -1) sums[sm] = true;
  else {
    allSubsetSums(n-1, nums, sums, sm+nums[n]);
    allSubsetSums(n-1, nums, sums, sm);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n; cin >> n;
  
  vector<long long> nums(n);
  for(auto &num : nums) cin >> num;
  
  long long sm = accumulate(nums.begin(), nums.end(), 0LL);
  
  unordered_map<long long, bool> sums;
  allSubsetSums(n-1, nums, sums, 0);
  
  long long mn = INT_MAX;
  
  for(auto s : sums) {
    mn = min(mn, abs(sm - s.first*2LL));
  }
  
  cout << mn << "\n";
  
  return 0;
}