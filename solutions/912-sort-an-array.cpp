#include <vector>
using namespace std;

// Quick Sort
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    sort(nums, 0, nums.size() - 1);
    return nums;
  }

  static void sort(vector<int>& nums, int left, int right) {
    if (left < right) {
      int mid = partion(nums, left, right);
      // pivot不参与后续排序，保证每次至少消耗一个元素，不然会出现死循环
      sort(nums, left, mid - 1);
      sort(nums, mid + 1, right);
    }
  }

  static int partion(vector<int>& nums, int left, int right) {
    int i = left, j = left, p = nums[left];
    while (j < right) {
      j++;
      if (nums[j] <= p) {
        i++;
        swap(nums[i], nums[j]);
      }
    }
    // 把pivot换到中间，后续不参与排序
    swap(nums[i], nums[left]);
    return i;
  }
};