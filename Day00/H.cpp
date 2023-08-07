#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; int q; cin >> n >> q;

    vector<priority_queue<int> > v(n);
    int op; int t; int x;
    while (q--)
    {
        cin >> op >> t;
        if (op == 0)
        {
            cin >> x;
            v[t].push(x);
        }
        else if (op == 1 && !v[t].empty())
            cout << v[t].top() << '\n';
        else if (op == 2 && !v[t].empty())
            v[t].pop();
    }
}
