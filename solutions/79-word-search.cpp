#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int i;
  int j;
  bool is_visited;
  Node(int _i, int _j) : i(_i), j(_j), is_visited(false){};
};

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0 || word.size() == 0) {
      return false;
    }
    int rows = board.size(), columns = board[0].size(), w_size = word.size();
    vector<vector<bool>> flags(rows, vector<bool>(columns, false));
    stack<Node> st;
    int p = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (board[i][j] == word[0]) {
          st.push(Node(i, j));
        }
      }
    }
    while (st.size() > 0) {
      Node* head = &st.top();
      int i = head->i, j = head->j;

      // 退出
      if (head->is_visited) {
        p--;
        flags[i][j] = false;
        st.pop();
        continue;
      }

      // 进入
      p++;
      if (p >= w_size) {
        return true;
      }
      head->is_visited = true;
      flags[i][j] = true;

      if (i > 0 && !flags[i - 1][j] && board[i - 1][j] == word[p]) {
        st.push(Node(i - 1, j));
      }
      if (i < rows - 1 && !flags[i + 1][j] && board[i + 1][j] == word[p]) {
        st.push(Node(i + 1, j));
      }
      if (j > 0 && !flags[i][j - 1] && board[i][j - 1] == word[p]) {
        st.push(Node(i, j - 1));
      }
      if (j < columns - 1 && !flags[i][j + 1] && board[i][j + 1] == word[p]) {
        st.push(Node(i, j + 1));
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<vector<char>> borad = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  cout << s.exist(borad, "ABCCED") << endl;
  return 0;
}