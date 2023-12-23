#include<iostream>
#include<stack>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Function to determine the precedence of an operator
int precedence(char c) 
{ 
    if(c == '^') 
        return 3; 
    else if(c == '*' || c == '/') 
        return 2; 
    else if(c == '+' || c == '-') 
        return 1; 
    else
        return -1; 
} 

// Function to convert infix expression to postfix expression
string InfixToPostfix(stack<char> s, string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			// If the character is an operand, add it to the postfix expression
			postfix += infix[i];
		}
		else if(infix[i] == '(')
		{
			// If the character is an opening parenthesis, push it onto the stack
			s.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			// If the character is a closing parenthesis, pop and add operators from the stack to the postfix expression until an opening parenthesis is encountered
			while((s.top()!='(') && (!s.empty()))
			{
				char temp = s.top();
				postfix += temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				// Pop the opening parenthesis from the stack
				s.pop();
			}
		}
		else if(isOperator(infix[i]))
		{
			// If the character is an operator
			if(s.empty())
			{
				// If the stack is empty, push the operator onto the stack
				s.push(infix[i]);
			}
			else
			{
				if(precedence(infix[i]) > precedence(s.top()))
				{
					// If the operator has higher precedence than the top of the stack, push it onto the stack
					s.push(infix[i]);
				}	
				else if((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
				{
					// If the operator is '^' and has equal precedence to the top of the stack, push it onto the stack
					s.push(infix[i]);
				}
				else
				{
					// Pop and add operators from the stack to the postfix expression until the stack is empty or the top has lower precedence
					while((!s.empty()) && (precedence(infix[i]) <= precedence(s.top())))
					{
						postfix += s.top();
						s.pop();
					}
					// Push the current operator onto the stack
					s.push(infix[i]);
				}
			}
		}
	}

	// Pop and add any remaining operators from the stack to the postfix expression
	while(!s.empty())
	{
		postfix += s.top();
		s.pop();
	}
	
	return postfix;
}

int main() 
{  
  	// Input infix expression
  	string infix_exp, postfix_exp;
  	cout << "Enter an Infix Expression :" << endl;
  	cin >> infix_exp;
  	
  	// Stack to hold operators during conversion
  	stack <char> stack;
	
	// Display the input infix expression
	cout << "INFIX EXPRESSION: " << infix_exp << endl;
  	
  	// Convert infix to postfix
  	postfix_exp = InfixToPostfix(stack, infix_exp);
  	
  	// Display the resulting postfix expression
  	cout << endl << "POSTFIX EXPRESSION: " << postfix_exp;
	  
	return 0;
}
