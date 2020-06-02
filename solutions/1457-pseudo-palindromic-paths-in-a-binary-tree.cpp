#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int pseudoPalindromicPaths(TreeNode *root) {
    int counts[10] = {};
    return resolve(root, counts);
  }
  int resolve(TreeNode *node, int *counts) {
    // 空指针
    if (!node) {
      return 0;
    }

    int c = 0;
    counts[node->val]++;
    // 叶子节点
    if (!node->left && !node->right) {
      int odds = 0;
      for (int i = 1; i < 10; i++) {
        if (counts[i] & 1) {
          odds++;
        }
      }
      if (odds < 2) {
        c = 1;
      }
    } else {  // 非叶子节点
      c = resolve(node->left, counts) + resolve(node->right, counts);
    }
    // 回溯
    counts[node->val]--;
    return c;
  }
};

int main() {
  TreeNode n4(3);
  TreeNode n5(1);
  TreeNode n7(1);
  TreeNode n2(3, &n4, &n5);
  TreeNode n3(1, nullptr, &n7);
  TreeNode n1(2, &n2, &n3);

  Solution s;
  cout << s.pseudoPalindromicPaths(&n1) << endl;
  return 0;
}