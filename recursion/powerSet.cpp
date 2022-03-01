#include <bits/stdc++.h>

using namespace std;

void powerSet(vector<int> &nums, int &n, vector<int> sub, int i = 0) {
  if(i == n) {
    for(int num: sub) cout << num << " ";
    cout << "\n";
  } else {
    powerSet(nums, n, sub, i+1);
    sub.push_back(nums[i]);
    powerSet(nums, n, sub, i+1);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n; cin >> n;
  vector<int> nums(n);
  for(auto &num : nums) cin >> num;
  vector<int> sub;
  powerSet(nums, n, sub);

  return 0;
}