#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int size = nums.size();

    if (size == 0) {
      return 0;
    } else if (size == 1) {
      return nums[0];
    } else {
      int dp[nums.size()];
      dp[0] = nums[0];
      dp[1] = max(nums[0], nums[1]);
      for (int i = 2; i < size; i++) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
      }
      return dp[size - 1];
    }
  }
};

int main() {
  Solution s;
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(1);
  cout << s.rob(v) << endl;
  return 0;
}