#include <bits/stdc++.h>
 
using namespace std;

typedef unsigned long long ll;

#define endl '\n'

typedef enum {
	UNVISITED,
	CURRVISITED,
	VISITED
} State;

bool	dfs(int s, vector<State> &vis, vector<vector<int> > &neighbrs)
{
	vis[s] = CURRVISITED;

	bool ret = false;
	for (auto nb: neighbrs[s])
	{
		if (vis[nb] == CURRVISITED)
			return (true);
		if (vis[nb] == UNVISITED)
			if ((ret = dfs(nb, vis, neighbrs)))
				return (true);
	}

	vis[s] = VISITED;

	return (ret);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;

	vector<vector<int> > neighbrs(n);

	int val;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> val;
			if (val)
				neighbrs[i].push_back(j);
		}
	}

	vector<State> vis(n, UNVISITED);

	bool is_cycle = dfs(0, vis, neighbrs);

	if (is_cycle)
		cout << "1\n";
	else
		cout << "0\n";
}
