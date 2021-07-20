#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int evalPrefix(string expression)
{
    stack<int> s;
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
            s.push(expression[i] - '0');
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (expression[i] == '+')
                s.push(a + b);
            else if (expression[i] == '-')
                s.push(a - b);
            else if (expression[i] == '*')
                s.push(a * b);
            else if (expression[i] == '/')
                s.push(a / b);
            else if (expression[i] == '^')
                s.push(pow(a, b));
            else
                return -1;
        }
    }
    return s.top();
}

int evalPostfix(string expression)
{
    stack<int> s;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
            s.push(expression[i] - '0');
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (expression[i] == '+')
                s.push(a + b);
            else if (expression[i] == '-')
                s.push(a - b);
            else if (expression[i] == '*')
                s.push(a * b);
            else if (expression[i] == '/')
                s.push(a / b);
            else if (expression[i] == '^')
                s.push(pow(a, b));
            else
                return -1;
        }
    }
    return s.top();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string prefixExpression = "-+7*45+20", postfixExpression = "02+54*7+-";
    cout << evalPrefix(prefixExpression) << endl;
    cout << evalPostfix(postfixExpression) << endl;

    return 0;
}