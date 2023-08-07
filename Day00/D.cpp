#include <iostream>
#include <stack>

using namespace std;
#define YES "Yes\n"
#define NO "No\n"

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    getline(cin, line);
    if (line.empty())
        exit(0);
    int n = stoi(line);
    stack<char> stk;
    bool printed;
    while (n--)
    {
        getline(cin, line);
        printed = false;
        for (auto c: line)
        {
            if (c == '(')
                stk.push(c);
            else if (c == '[')
                stk.push(c);
            else if (c == ')')
            {
                if (stk.empty() || stk.top() != '(')
                {
                    cout << NO; printed = true;
                    break;
                }
                stk.pop();
            }
            else if (c == ']')
            {
                if (stk.empty() || stk.top() != '[')
                {
                    cout << NO; printed = true;
                    break;
                }
                stk.pop();
            }
            else
            {
                cout << NO; printed = true;
                break;
            }
        }
        if (!printed)
            cout << (stk.empty() ? YES : NO);
        while (!stk.empty())
            stk.pop();
    }
}