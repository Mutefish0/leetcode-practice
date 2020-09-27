#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int i;
  int j;
  Node(int _i, int _j) : i(_i), j(_j) {}
};

// 广度优先遍历
class Solution {
 private:
  // 计算 x 的数位之和
  int get(int x) {
    int res = 0;
    for (; x; x /= 10) {
      res += x % 10;
    }
    return res;
  }

  bool check(int i, int j, int m, int n, int k, vector<vector<bool>>& visted) {
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1) {
      return false;
    }
    if (visted[i][j]) {
      return false;
    }
    if (get(i) + get(j) > k) {
      return false;
    }
    return true;
  }

 public:
  int movingCount(int m, int n, int k) {
    if (k == 0) {
      return 1;
    }
    queue<Node> q;
    vector<vector<bool>> visted(m, vector<bool>(n, false));
    int steps = 0;
    q.push(Node(0, 0));
    visted[0][0] = true;
    while (!q.empty()) {
      auto head = q.front();
      int i = head.i, j = head.j;
      q.pop();
      steps++;
      if (check(i - 1, j, m, n, k, visted)) {
        q.push(Node(i - 1, j));
        visted[i - 1][j] = true;
      }
      if (check(i + 1, j, m, n, k, visted)) {
        q.push(Node(i + 1, j));
        visted[i + 1][j] = true;
      }
      if (check(i, j - 1, m, n, k, visted)) {
        q.push(Node(i, j - 1));
        visted[i][j - 1] = true;
      }
      if (check(i, j + 1, m, n, k, visted)) {
        q.push(Node(i, j + 1));
        visted[i][j + 1] = true;
      }
    }
    return steps;
  }
};

int main() {
  Solution s;
  cout << s.movingCount(3, 1, 0) << endl;
}