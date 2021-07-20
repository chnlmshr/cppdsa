#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int precedence(char c)
{
    switch (c)
    {
    case '+':
        return 1;
        break;

    case '-':
        return 1;
        break;

    case '*':
        return 2;
        break;

    case '/':
        return 2;
        break;

    case '^':
        return 3;
        break;

    default:
        return 0;
        break;
    }
}

string infixToPostfix(string expression)
{
    string result = "";
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= 'a' && expression[i] <= 'z')
            result += expression[i];
        else if (expression[i] == '(')
            s.push(expression[i]);
        else if (expression[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                result += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (precedence(expression[i]))
        {
            while (!s.empty() && precedence(s.top()) > precedence(expression[i]))
            {
                result += s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
        else
            return "";
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }
    return result;
}

string infixToPrefix(string expression)
{
    reverse(expression.begin(), expression.end());
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(')
            expression[i] = ')';
        else if (expression[i] == ')')
            expression[i] = '(';
    }
    string result = infixToPostfix(expression);
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string infixExpression = "(a-b/c)*(a/k-l)";

    cout << infixToPrefix(infixExpression) << endl;  // *-/bca-/akl
    cout << infixToPostfix(infixExpression) << endl; // abc/-ak/l-*

    return 0;
}