#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int len = nums.size();
    if (len == 1 || nums[len - 1] > nums[0]) {
      return nums[0];
    }
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) >> 1;
      if (nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
      } else if (nums[mid] > nums[left]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> input{2, 2, 2, 0, 1};
  cout << s.findMin(input) << endl;
}