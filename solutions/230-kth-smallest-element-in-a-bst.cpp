#include <iostream>
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
  int counter;
  int result;

 public:
  int kthSmallest(TreeNode *root, int k) {
    counter = k;
    walk(root);
    return result;
  }

  void walk(TreeNode *root) {
    if (counter == 0) {
      return;
    }

    if (root->left) {
      walk(root->left);
    }
    counter--;
    if (counter == 0) {
      result = root->val;
      return;
    }
    if (root->right) {
      walk(root->right);
    }
  }
};

//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
int main() {
  TreeNode t1(1);
  TreeNode t2(2, &t1, nullptr);
  TreeNode t4(4);
  TreeNode t3(3, &t2, &t4);
  TreeNode t6(6);
  TreeNode t5(5, &t3, &t6);
  Solution s;
  std::cout << s.kthSmallest(&t5, 3) << std::endl;
  return 0;
}
