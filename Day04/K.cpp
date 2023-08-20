#include <bits/stdc++.h>
 
using namespace std;

typedef unsigned long long ll;

#define endl '\n'

void	dfs(int s, vector<bool> &vis, vector<vector<int> > &neighbrs)
{
	vis[s] = true;

	for (auto nb: neighbrs[s])
	{
		if (!vis[nb])
			dfs(nb, vis, neighbrs);
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;

	vector<vector<int> > neighbrs(n);

	while (m--)
	{
		int a, b; cin >> a >> b;
		neighbrs[a-1].push_back(b-1);
		neighbrs[b-1].push_back(a-1);
	}

	vector<bool> vis(n, false);

	vector<int> compo_elt;

	for (int i = 0; i < n; i++) {
		if (!vis[i])
		{
			dfs(i, vis, neighbrs);
			// Save a representitive
			compo_elt.push_back(i+1);
		}
	}

	// ANS: Number of edges between Connected Components
	cout << compo_elt.size() - 1 << endl;
	for (int i = 1; i < compo_elt.size(); i++)
		cout << compo_elt[i-1] << ' ' << compo_elt[i] << endl;
}
