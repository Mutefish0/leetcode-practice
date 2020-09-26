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
  TreeNode* buildSubTree(unordered_map<int, int>& indexs, vector<int>& inorder,
                         vector<int>& postorder, int left1, int right1,
                         int left2, int right2) {
    if (left1 > right1 || left2 > right2) {
      return nullptr;
    }
    TreeNode* node = new TreeNode(postorder[right2]);
    int index = indexs[postorder[right2]];
    int len = index - left1;
    node->left = buildSubTree(indexs, inorder, postorder, left1, index - 1,
                              left2, left2 + len - 1);
    node->right = buildSubTree(indexs, inorder, postorder, index + 1, right1,
                               left2 + len, right2 - 1);
    return node;
  }

 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> indexs;
    for (int i = 0; i < inorder.size(); i++) {
      indexs[inorder[i]] = i;
    }
    return buildSubTree(indexs, inorder, postorder, 0, inorder.size() - 1, 0,
                        postorder.size() - 1);
  }
};

int main() {
  Solution s;
  vector<int> in = {9, 3, 15, 20, 7};
  vector<int> post = {9, 15, 7, 20, 3};
  TreeNode* n = s.buildTree(in, post);
  return 0;
}