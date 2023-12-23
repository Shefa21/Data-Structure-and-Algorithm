#include<iostream>
#include<stack>

using namespace std;

// Function to check if a character is an operand
bool isOperand(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return true;
  } else {
    return false;
  }
}

// Function to convert prefix expression to postfix expression
string PrefixToPostfix(string prefix) {
  stack<string> s;

  // Traverse the prefix expression from right to left
  for (int i = prefix.length() - 1; i >= 0; i--) {
    if (isOperand(prefix[i])) {
      // If the character is an operand, push it onto the stack as a string
      string op(1, prefix[i]);
      s.push(op);
    } else {
      // If the character is an operator, pop two operands from the stack, perform the operation, and push the result back onto the stack
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();

      // Concatenate the operands and operator in the correct order and push the result onto the stack
      s.push(op1 + op2 + prefix[i]);
    }
  }

  // The final result is at the top of the stack
  return s.top();
}

int main() {

  string prefix, postfix;

  // Input prefix expression
  cout << "Enter a PREFIX Expression :" << endl;
  cin >> prefix;

  // Display the input prefix expression
  cout << "PREFIX EXPRESSION: " << prefix << endl;

  // Convert prefix to postfix
  postfix = PrefixToPostfix(prefix);

  // Display the resulting postfix expression
  cout << endl << "POSTFIX EXPRESSION: " << postfix;

  return 0;
}
