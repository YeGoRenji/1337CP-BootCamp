#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int n; cin >> n;
    multiset<int> s;

    int nb;
    while (n--)
    {
        cin >> nb;
        s.insert(nb);
    }
    for (auto num: s)
        cout << num << ' ';
    cout << endl;
}