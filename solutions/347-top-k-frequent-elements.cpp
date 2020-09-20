#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    auto comp = [&](int a, int b) { return map[a] < map[b]; };
    priority_queue<int, vector<int>, decltype(comp)> p_queue(comp);
    vector<int> result;
    for (int& num : nums) {
      map[num]++;
    }
    for (auto& [key, value] : map) {
      p_queue.push(key);
    }
    for (int i = 0; i < k; i++) {
      result.push_back(p_queue.top());
      p_queue.pop();
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> v{1, 1, 1, 2, 2, 3};
  auto r = s.topKFrequent(v, 2);
  for (int& n : r) {
    cout << n << endl;
  }
  return 0;
}