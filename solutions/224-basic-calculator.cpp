#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void calc(vector<long>& stack_operand, vector<char>& stack_operator,
            int curr_priority) {
    char top_op;
    long l_value, r_value;
    while (stack_operator.size() > 0 &&
           priority(top_op = stack_operator.back()) >= curr_priority) {
      if (top_op == '(') {
        stack_operator.pop_back();
        break;
      }

      r_value = stack_operand.back();
      stack_operand.pop_back();
      l_value = stack_operand.back();
      stack_operand.pop_back();
      if (top_op == '+') {
        stack_operand.push_back(l_value + r_value);
      } else if (top_op == '-') {
        stack_operand.push_back(l_value - r_value);
      }
      stack_operator.pop_back();
    }
  }

  int priority(char ch) {
    if (ch == '-' || ch == '+') {
      return 1;
    }
    return 0;
  }

  bool consume_digits(string& s, int* index, long* value) {
    int p = *index;
    long number = 0;
    if (s[p] >= '0' && s[p] <= '9') {
      do {
        number = number * 10 + s[p] - '0';
        p++;
      } while (s[p] >= '0' && s[p] <= '9');
      *index = p - 1;
      *value = number;
      return true;
    }
    return false;
  }

  int calculate(string s) {
    vector<long> stack_operand;
    vector<char> stack_operator;

    int index = 0;
    int len = s.size();
    long number = 0;

    while (index < len) {
      if (s[index] == '+') {
        calc(stack_operand, stack_operator, priority('+'));
        stack_operator.push_back('+');
      } else if (s[index] == '-') {
        calc(stack_operand, stack_operator, priority('-'));
        stack_operator.push_back('-');
      } else if (s[index] == '(') {
        stack_operator.push_back('(');
      } else if (s[index] == ')') {
        calc(stack_operand, stack_operator, 0);
      } else if (s[index] == ' ') {
        // ignore
      } else if (consume_digits(s, &index, &number)) {
        stack_operand.push_back(number);
      }
      index++;
    }
    calc(stack_operand, stack_operator, 0);
    return stack_operand.back();
  }
};

int main() {
  Solution s;
  int ret = s.calculate("2 - 1 + 2");
  // int ret = s.calculate("2147483647");
  // int ret = s.calculate("1 - (2 - 3)");
  return 0;
}