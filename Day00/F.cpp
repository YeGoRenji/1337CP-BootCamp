#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct comp {
    template <typename T>
 
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        return l.first > r.first;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> occ;
    int n; cin >> n;
    string str;
    while (n--)
    {
        cin >> str;
        occ[str]++;
    }
    set<pair<string, int>, comp> sortedSet(occ.begin(), occ.end());

    cout << sortedSet.begin()->first << ' ' << sortedSet.begin()->second << '\n';
}