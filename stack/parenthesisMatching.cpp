#include <iostream>
#include <stack>

using namespace std;

bool match(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    else if (a == '[' && b == ']')
        return true;
    else if (a == '{' && b == '}')
        return true;
    else if (a == '<' && b == '>')
        return true;
    else
        return false;
}

bool isValid(string p)
{
    stack<char> s;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(' || p[i] == '[' || p[i] == '{' || p[i] == '<')
            s.push(p[i]);
        else
        {
            if (!s.empty() && match(s.top(), p[i]))
                s.pop();
            else
                return false;
        }
    }
    return s.empty();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    cout << isValid(s);

    return 0;
}