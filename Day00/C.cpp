#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    stack<int> s;

    int op;
    int n;
    while (T--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> n;
            s.push(n);
        }
        else if (op == 2)
        {
            if (!s.empty()) s.pop();
        }
        else if (op == 3)
        {
            if (!s.empty())
                cout << s.top() << '\n';
            else
                cout << "Empty!\n";
        }
    }
}
