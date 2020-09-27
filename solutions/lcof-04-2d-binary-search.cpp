#include <iostream>
#include <vector>

using namespace std;
// 二维的二分查找，非常巧妙
// O(log(m*n))
class Solution {
 private:
  vector<vector<int>>* matrix;
  int target;

  bool findInSubMatrix(int left, int right, int top, int bottom) {
    int hmid, vmid;
    if (left > right || top > bottom) {
      return false;
    }
    hmid = (left + right) >> 1;
    vmid = (top + bottom) >> 1;
    int v = (*matrix)[vmid][hmid];
    if (v == target) {
      return true;
    } else if (v > target) {
      return findInSubMatrix(left, hmid - 1, top, bottom) ||
             findInSubMatrix(hmid, right, top, vmid - 1);
    } else {
      return findInSubMatrix(hmid + 1, right, top, bottom) ||
             findInSubMatrix(left, hmid, vmid + 1, bottom);
    }
  }

 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0) {
      return false;
    }
    this->matrix = &matrix;
    this->target = target;
    return findInSubMatrix(0, matrix[0].size() - 1, 0, matrix.size() - 1);
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
  Solution s;
  cout << s.findNumberIn2DArray(matrix, 20) << endl;
  return 0;
}