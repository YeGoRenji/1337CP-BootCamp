#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> s;
    string line;

    int nb;
    while (cin >> line)
    {
        cin >> nb;
        if (line == "insert")
            s.insert(nb);
        else if (line == "delete")
            s.erase(nb);
        else if (line == "exists")
            cout << (s.find(nb) != s.end() ? "true\n" : "false\n");
    }
}
