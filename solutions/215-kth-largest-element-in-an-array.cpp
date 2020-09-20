#include <iostream>
#include <queue>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> q;
    for (int& num : nums) {
      q.push(num);
    }
    for (int i = 0; i < k - 1; i++) {
      q.pop();
    }
    return q.top();
  }
};

int main() {
  Solution s;
  vector<int> nums{3, 2, 1, 5, 6, 4};
  cout << s.findKthLargest(nums, 2) << endl;
  return 0;
}