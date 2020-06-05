#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    vector<char> stack;
    for (int i = 0; i < s.size(); i++) {
      if (stack.size() > 0 && matchPair(stack.back(), s[i])) {
        stack.pop_back();
      } else {
        stack.push_back(s[i]);
      }
    }
    return stack.size() == 0;
  }

  bool matchPair(char a, char b) {
    return (a == '(' && b == ')' || a == '[' && b == ']' ||
            a == '{' && b == '}');
  }
};

int main() {
  Solution s;
  cout << s.isValid("()") << endl;
  cout << s.isValid("()[]{}") << endl;
  cout << s.isValid("(]") << endl;
  cout << s.isValid("([)]") << endl;
  cout << s.isValid("{[]}") << endl;
  cout << s.isValid(")(") << endl;
  cout << s.isValid("()[]{}") << endl;
  return 0;
}