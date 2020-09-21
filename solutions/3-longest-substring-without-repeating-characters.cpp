#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int len = s.length();
    if (len < 2) {
      return len;
    }
    unordered_set<char> us;
    int max = 1;
    int i = 0, j = 0;
    while (i < len - max) {
      while (j < len && us.find(s[j]) == us.end()) {
        us.insert(s[j]);
        j++;
      }
      if (j - i > max) {
        max = j - i;
      }
      us.erase(s[i]);
      i++;
    }
    return max;
  }
};

int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("a") << endl;
  cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
  cout << s.lengthOfLongestSubstring("aa") << endl;
  cout << s.lengthOfLongestSubstring("ab") << endl;
  cout << s.lengthOfLongestSubstring("pwwkew") << endl;
  cout << s.lengthOfLongestSubstring("au") << endl;
  return 0;
}