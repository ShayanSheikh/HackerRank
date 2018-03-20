#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

bool match_brackets(char left, char right) {
  if (left == '(' && right == ')') return true;
  if (left == '[' && right == ']') return true;
  if (left == '{' && right == '}') return true;
  return false;
}

bool is_left(char bracket) {
  return (bracket == '(' || bracket == '[' || bracket == '{');
}

bool is_balanced (string expression) {
  vector<char> stack;
  stack.push_back(expression[0]);
  for (int i = 1; i < expression.size(); i++) {
    if (is_left(expression[i])) stack.push_back(expression[i]);
    else {
      if ( !match_brackets(stack.back(), expression[i]) ) return false;
      stack.pop_back();
    }
  }
  if (!stack.empty()) return false;
  return true;
}