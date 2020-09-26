#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid;
    while (left <= right) {
      mid = (left + right) >> 1;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> v1{-1, 0, 3, 5, 9, 12};
  vector<int> v2{-1, 0, 3, 5, 9, 12};
  cout << s.search(v1, 9) << endl;
  cout << s.search(v2, 2) << endl;
  return 0;
}