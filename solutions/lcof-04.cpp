#include <vector>

using namespace std;

class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    for (auto v : matrix) {
      int left = 0, right = v.size() - 1;
      int mid;
      while (left <= right) {
        mid = (left + right) >> 1;
        if (v[mid] == target) {
          return true;
        } else if (v[mid] > target) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }
    return false;
  }
};
