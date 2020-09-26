#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    unordered_map<int, bool> m;
    for (int num : nums) {
      if (m[num]) {
        return num;
      }
      m[num] = true;
    }
    return 0;
  }
};