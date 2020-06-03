#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    int count[26] = {};
    for (int i = s.size() - 1; i >= 0; i--) {
      count[s[i] - 'a']++;
      count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (count[i] != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isAnagram("anagram", "nagraam") << endl;
}
