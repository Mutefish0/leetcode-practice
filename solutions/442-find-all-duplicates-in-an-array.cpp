#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[abs(nums[i]) - 1] > 0) {
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
      } else {
        result.push_back(abs(nums[i]));
      }
    }
    return result;
  }
};