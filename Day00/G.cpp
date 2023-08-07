#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	map<int, int> mp;
    int n; int x; cin >> n >> x;
    int nb;
    int i = 0;
    while (i < n)
    {
        cin >> nb; 
		if (mp[x - nb] != 0)
		{
			cout << mp[x - nb] << ' ' << i + 1 << '\n';
			exit(0);
		}
		mp[nb] = i + 1;
        i++;
    }
    cout << "IMPOSSIBLE\n";
}
