#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> memo(1000*1000, -1);

int MOD = 1e9 + 7;

ll getpaths(vector<string> &grid, int i, int j, int n)
{
	if (memo[i*n + j] != -1)
		return memo[i*n + j];

	ll paths = 0;
	if (grid[i][j] == '*')
		paths = 0;
	else if (i == n - 1 && j == n - 1)
		paths = 1;
	else {
		if (i + 1 < n && grid[i + 1][j] != '*')
			paths += getpaths(grid, i + 1, j, n) % MOD;
		if (j + 1 < n && grid[i][j + 1] != '*')
			paths += getpaths(grid, i, j + 1, n) % MOD;
	}

	paths %= MOD;
	memo[i*n + j] = paths;

	return (paths);
}


int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n; 
	vector<string> grid(n);

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	if (n == 0)
		return (0);
	if (grid[n-1][n-1] == '*')
		cout << "0\n";
	else
		cout << getpaths(grid, 0, 0, n) << '\n';

	return 0;
}
