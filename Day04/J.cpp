#include <bits/stdc++.h>
 
using namespace std;

typedef unsigned long long ll;

#define endl '\n'

typedef enum {
	UNVISITED,
	CURRVISITED,
	VISITED
} State;

bool	dfs(int s, vector<State> &vis, vector<vector<int> > &neighbrs, int depth)
{
	vis[s] = CURRVISITED;
	// cout << string(4*depth, ' ') << "-- visiting " << s+1 << endl;
	for (auto nb: neighbrs[s])
	{
		// cout << string(4*depth, ' ') << "-> Neighbor " << nb+1 << " is ";
		if (vis[nb] == CURRVISITED)
		{
			// cout << "CURRVISITED" << endl;
			//
			return (true);
		}
		if (vis[nb] == UNVISITED)
		{
			// cout << "UNVISITED" << endl;
			if (dfs(nb, vis, neighbrs, depth+1))
				return (true);
		}
		// else
			// cout << "VISITED" << endl;
		// cout << string(4*depth, ' ') << "-> END " << nb+1 << endl;
	}
	// cout << string(4*depth, ' ') << string(13, '-') << endl;

	vis[s] = VISITED;

	return (false);
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

	int max_ind = 0;
	int max_val = -1;
	for (int i = 0; i < n; i++)
	{
		int sz = neighbrs[i].size();
		if (sz > max_val)
		{
			max_val = sz;
			max_ind = i;
		}
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	cout << "neighbrs of " << i+1 << endl;
	// 	for (auto nb: neighbrs[i])
	// 		cout << nb + 1 << ' ';
	// 	cout << endl;
	// }

	vector<State> vis(n, UNVISITED);

	bool is_cycle = dfs(max_ind, vis, neighbrs, 0);

	cout << is_cycle << endl;
}
