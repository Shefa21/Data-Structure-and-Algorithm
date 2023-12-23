#include <iostream>
#include <stack>

using namespace std;

// Function to check if a character is an operand
bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}

// Function to convert postfix expression to infix expression
string PostfixToInfix(string postfix)
{
    stack<string> s;

    for (int i = 0; i < postfix.length(); i++) {
        if (isOperand(postfix[i])) {
            // If the character is an operand, push it onto the stack as a string
            string op(1, postfix[i]);
            s.push(op);
        }
        else {
            // If the character is an operator, pop two operands from the stack, perform the operation, and push the result back onto the stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // Enclose the operands and operator in parentheses and push the result onto the stack
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }

    // The final result is at the top of the stack
    return s.top();
}

int main()
{
    string infix, postfix;

    // Input postfix expression
    cout << "Enter a POSTFIX Expression :" << endl;
    cin >> postfix;

    // Display the input postfix expression
    cout << "POSTFIX EXPRESSION: " << postfix << endl;

    // Convert postfix to infix
    infix = PostfixToInfix(postfix);

    // Display the resulting infix expression
    cout << endl << "INFIX EXPRESSION: " << infix;

    return 0;
}
