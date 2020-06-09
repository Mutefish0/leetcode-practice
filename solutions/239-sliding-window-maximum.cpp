#include <deque>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // 1 <= nums.length
    // 1 <= k <= nums.length
    vector<int> ret;
    deque<int> d;

    for (int i = 0; i < k; i++) {
      while (d.size() > 0 && nums[d.back()] <= nums[i]) {
        d.pop_back();
      }
      d.push_back(i);
    }

    ret.push_back(nums[d.front()]);

    for (int i = k, end = nums.size(); i < end; i++) {
      if (d.front() < i - k + 1) {
        d.pop_front();
      }
      while (d.size() > 0 && nums[d.back()] <= nums[i]) {
        d.pop_back();
      }
      d.push_back(i);
      ret.push_back(nums[d.front()]);
    }

    return ret;
  }
};

int main() {
  vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
  Solution s;
  auto t = s.maxSlidingWindow(v, 3);
  return 0;
}