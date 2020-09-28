#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int len = s.size();
    int max = 0;
    string max_s;
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = 0; i < len; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == i) {
          dp[j][i] = true;
        } else if (j + 1 == i) {
          dp[j][i] = s[j] == s[i];
        } else {
          dp[j][i] = s[j] == s[i] && dp[j + 1][i - 1];
        }
        if (dp[j][i] && (i - j + 1) > max) {
          max = i - j + 1;
          max_s = s.substr(j, max);
        }
      }
    }
    return max_s;
  }
};

int main() {
  Solution s;
  cout << s.longestPalindrome("babad") << endl;
  return 0;
}