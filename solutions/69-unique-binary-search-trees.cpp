#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
  unordered_map<int, int> memo;

 public:
  int numTrees(int n) {
    if (n <= 1) {
      return 1;
    }

    auto got = memo.find(n);
    if (got != memo.end()) {
      return got->second;
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
      result += numTrees(i - 1) * numTrees(n - i);
    }

    memo[n] = result;

    return result;
  }
};

int main() {
  Solution s;
  std::cout << s.numTrees(3) << std::endl;
}