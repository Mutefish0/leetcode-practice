#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> left;
      vector<int> right;
      vector<int> result;
      int current_left = 1, current_right = 1;
      for (int i = 0; i < nums.size(); i++) {
        left.push_back(current_left);
        right.push_back(current_right);
        current_left *= nums[i];
        current_right *= nums[nums.size() - 1 - i];
      }
      for (int i = 0; i < nums.size(); i++) {
        result.push_back(left[i] * right[nums.size() - 1 - i]);
      }
      return result;
    }
};

int main() {
  Solution s;
  vector v{1, 2, 3, 4};
  s.productExceptSelf(v);
}