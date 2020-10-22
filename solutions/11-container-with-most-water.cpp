#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int left = 0, right = height.size() - 1;
      int maxArea = 0;
      while (left < right) {
        int area;
        if (height[left] < height[right]) {
          area = height[left] * (right - left);
          left++;
        } else {
          area = height[right] * (right - left);
          right--;
        }
        if (area > maxArea) {
          maxArea = area;
        }
      }
      return maxArea;
    }
};
