#include <bits/stdc++.h>
 
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

	vector<vector<bool> > adj(n, vector<bool>(n, false));

	int val;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> val;
			adj[i][j] = val;
		}
	}

	vector<bool> vis(n, false);

	int connected = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i])
		{
			dfs(i, vis, adj);
			connected++;
		}
	}

	cout << connected << endl;
}
