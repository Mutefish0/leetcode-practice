#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if (intervals.size() == 0) {
        return intervals;
      }
      sort(begin(intervals), end(intervals), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
      });
      vector<vector<int>> result{intervals[0]};
      for (int i = 1; i < intervals.size(); i++) {
        vector<int> top = result[result.size() - 1];
        vector<int> curr = intervals[i];
        if (curr[0] > top[1]) { // 没有重叠，直接push
          result.push_back(curr);
        } else if (curr[0] <= top[1] && curr[1] > top[1]) { // 有重叠
          result.pop_back();
          result.push_back(vector<int>{top[0], curr[1]});
        }
      }
      return result;
    }
};

int main() {
  Solution s;
  vector<vector<int>> test{{1, 4}, {7, 12}, {3, 9}};
  vector r = s.merge(test);
  return 0;
}