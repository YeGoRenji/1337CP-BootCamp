#include <bits/stdc++.h>

// Notes :
// A graph is a tree if and only if :
// - it is All connected (1 connected groupe)
// - if (number of edges = number of vertices - 1)
 
using namespace std;

typedef unsigned long long ll;

#define endl '\n'

void	dfs(int s, vector<bool> &vis, vector<vector<bool> > &adj)
{
	vis[s] = true;

	for (int i = 0; i < adj[s].size(); i++)
	{
		if (adj[s][i] && !vis[i])
			dfs(i, vis, adj);
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;

	int edges = 0;
	vector<vector<bool> > adj(n, vector<bool>(n, false));

	int val;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> val;
			adj[i][j] = val;
			if (val) edges++;
		}
	}
	edges /= 2;

	vector<bool> vis(n, false);

	dfs(0, vis, adj);

	int visited = count(vis.begin(), vis.end(), true);
	if (visited == n && edges == n - 1)
		cout << "YES\n";
	else
		cout << "NO\n";
}
