#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    vector<int> actions = {};
    _hanota(0, 1, 2, A.size(), actions);
    int action_count = actions.size() / 2;
    vector<int>* pointers[3] = {&A, &B, &C};
    for (int i = 0; i < action_count; i++) {
      move(pointers[actions[2 * i]], pointers[actions[2 * i + 1]]);
    }
  }

  // 从A塔移动n个盘子到C盘子
  // 假设满足以下任意2个条件下：
  // 1.  B、C塔上没有盘子
  // 2.  B、C塔上的盘子比要移动的这个n个盘子都要大
  //    （实际上这种情况下，B、C塔这些遗留的盘子根本不需要动，和条件1的结果是一样的）
  void _hanota(int a, int b, int c, int n, vector<int>& actions) {
    // 没有盘子，不需要移动
    if (n == 0) {
      return;
    } else if (n == 1) {  // 只有一个盘子，直接从A移动到C即可
      actions.push_back(a);
      actions.push_back(c);
    } else {
      // 先将 n-1 个盘子从A移动到B（完成后，A要么没有盘子，要么剩下的盘子都比这
      // n - 1 个盘子大）
      _hanota(a, c, b, n - 1, actions);
      // 将剩下的一个盘子直接移动到C (由于假设：C塔要么没盘子，要么比这 n
      // 个盘子都大，所以是合法的操作)
      actions.push_back(a);
      actions.push_back(c);
      // 最后将B上面的 n - 1 个盘子移动到C（此时A、C塔的盘子肯定比B上面的前 n -
      // 1 个盘子要大）
      _hanota(b, a, c, n - 1, actions);
    }
  }

  // 按照题目要求操作堆栈
  void move(vector<int>* from, vector<int>* to) {
    if (from->size() == 0) {
      return;
    }
    int top = from->back();
    from->pop_back();
    to->push_back(top);
  }
};

int main() {
  Solution s;
  vector<int> actions;
  // A塔有3个盘子
  vector<int> A = {0};
  vector<int> B = {};
  vector<int> C = {};
  s.hanota(A, B, C);
  return 0;
}
