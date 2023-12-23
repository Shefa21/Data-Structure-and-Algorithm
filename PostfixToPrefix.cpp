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

// Function to convert postfix expression to prefix expression
string PostfixToPrefix(string postfix) {
  stack<string> s;

  // Traverse the postfix expression from left to right
  for (int i = 0; i < postfix.length(); i++) {
    if (isOperand(postfix[i])) {
      // If the character is an operand, push it onto the stack as a string
      string op(1, postfix[i]);
      s.push(op);
    } else {
      // If the character is an operator, pop two operands from the stack, perform the operation, and push the result back onto the stack
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();

      // Concatenate the operands and operator in the reverse order and push the result onto the stack
      s.push(postfix[i] + op2 + op1);
    }
  }

  // The final result is at the top of the stack
  return s.top();
}

int main() {
  string prefix, postfix;

  // Input postfix expression
  cout << "Enter a POSTFIX Expression :" << endl;
  cin >> postfix;

  // Display the input postfix expression
  cout << "POSTFIX EXPRESSION: " << postfix << endl;

  // Convert postfix to prefix
  prefix = PostfixToPrefix(postfix);

  // Display the resulting prefix expression
  cout << endl << "PREFIX EXPRESSION: " << prefix;

  return 0;
}
