#include <bits/stdc++.h>
 
using namespace std;

typedef unsigned long long ll;

#define endl '\n'

#define PK push_back

typedef enum {
	NONE,
	COLOR1,
	COLOR2
} State;

bool	dfs(int s, State col, vector<State> &vis, vector<vector<int> > &neighbrs)
{
	vis[s] = col;

	for (auto nb: neighbrs[s])
	{
		if (vis[nb] == col)
			return (false);
		if (vis[nb] == NONE)
			dfs(nb, col == COLOR1 ? COLOR2 : COLOR1, vis, neighbrs);
	}

	return (true);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int n; cin >> n;
		if (!n) break;
		int edges; cin >> edges;

		vector<vector<int> > neighs(n);

		while (edges--)
		{
			int a, b; cin >> a >> b;
			neighs[a-1].PK(b-1);
			neighs[b-1].PK(a-1);
		}

		vector<State> vis(n);

		bool bicolored = dfs(0, COLOR1, vis, neighs);
		if (bicolored)
			cout << "BICOLOURABLE.\n";
		else
			cout << "NOT BICOLOURABLE.\n";
	}
}
