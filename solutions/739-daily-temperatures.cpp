#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> stack;
    vector<int> result;
    for (int i = 0, size = T.size(); i < size; i++) {
      result.push_back(i);
      while (stack.size() > 0 && T[i] > T[stack.back()]) {
        result[stack.back()] = i;
        stack.pop_back();
      }
      stack.push_back(i);
    }
    for (int i = 0, size = result.size(); i < size; i++) {
      result[i] -= i;
    }
    return result;
  }
};

int main() {
  vector<int> x = {73, 74, 75, 71, 69, 72, 76, 73};
  Solution s;
  vector<int> y = s.dailyTemperatures(x);
  return 0;
}