#include <bits/stdc++.h>
 
using namespace std;

typedef unsigned long long ll;

#define endl '\n'

int n, m; 

bool	valid(pair<int, int> &p, vector<string> &map)
{
	if (0 <= p.first && p.first < n
    &&  0 <= p.second && p.second < m
	&&  map[p.first][p.second] != '#')
		return (true);
	return (false);
}

void	dfs(int i, int j, vector<vector<bool> > &vis, vector<string> &map)
{
	vis[i][j] = true;

	vector<pair<int, int> > neighbours = {
	  {i-1, j},
	  {i+1, j},
	  {i, j-1},
	  {i, j+1}
	};

	for (auto nb: neighbours)
	{
		if (!valid(nb, map)) continue;

		if (!vis[nb.first][nb.second])
			dfs(nb.first, nb.second, vis, map);

	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	vector<string> map(n);

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	vector<vector<bool> > vis(n, vector<bool>(m, false));

	int connected = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && map[i][j] != '#')
			{
				dfs(i, j, vis, map);
				connected++;
			}
		}
	}

	cout << connected << endl;
}
