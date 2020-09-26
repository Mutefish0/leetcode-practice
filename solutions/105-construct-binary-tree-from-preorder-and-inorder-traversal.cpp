/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 private:
  TreeNode* buildSubTree(unordered_map<int, int>& indexs, vector<int>& preorder,
                         vector<int>& inorder, int left1, int right1, int left2,
                         int right2) {
    if (left1 > right1 || left2 > right2) {
      return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[left1]);
    int index = indexs[preorder[left1]];
    int len1 = index - left2;
    node->left = buildSubTree(indexs, preorder, inorder, left1 + 1,
                              left1 + len1, left2, index - 1);
    node->right = buildSubTree(indexs, preorder, inorder, left1 + len1 + 1,
                               right1, index + 1, right2);
    return node;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> indexs;
    for (int i = 0; i < inorder.size(); i++) {
      indexs[inorder[i]] = i;
    }
    return buildSubTree(indexs, preorder, inorder, 0, preorder.size() - 1, 0,
                        inorder.size() - 1);
  }
};

int main() {
  vector<int> pre = {3, 9, 20, 15, 7};
  vector<int> in = {9, 3, 15, 20, 7};
  Solution s;
  TreeNode* root = s.buildTree(pre, in);
  return 0;
}