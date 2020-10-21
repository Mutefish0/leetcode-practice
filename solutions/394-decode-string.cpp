#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string repeat(string src, int index, int count) {
      string result = src.substr(0, index);
      for (int i = 0; i < count; i++) {
        result = result + src.substr(index, src.size() - index);
      }
      return result;
    }

    string decodeString(string s) {
      stack<int> s_index;
      stack<int> s_count;
      string result = "";
      int i = 0;
      while (i < s.size()) {
        char ch = s[i];
        if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z') {
          result.push_back(ch);
        } else if ('0' <= ch && ch <= '9') { //  \d+[
          s_index.push(result.size());
          int count = ch - '0';
          while (s[++i] != '[') {
            count = count * 10 + s[i] - '0';
          }
          s_count.push(count);
        } else if (ch == ']') {
          result = repeat(result, s_index.top(), s_count.top());
          s_index.pop();
          s_count.pop();
        }
        i++;
      }
      return result;
    }
};

int main() {
  Solution s;
  cout << s.decodeString("3[a]2[bc]") << endl;
  return 0;
}