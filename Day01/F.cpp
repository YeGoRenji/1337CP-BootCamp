#include <bits/stdc++.h>
#include <climits>

using namespace std;

typedef long long ll;

vector<ll> dp(1e6 + 1, -1);

ll solve(vector<int> &coins, int target)
{
	if (dp[target] != -1) return dp[target];

	dp[target] = 1e18;

	for (auto coin: coins)
	{
		if (coin > target) continue;
		dp[target] = min(dp[target], 1 + solve(coins, target - coin));
	}

	return dp[target];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x; cin >> n >> x; 
	vector<int> coins(n);

	for (int i = 0; i < n; i++) 
		cin >> coins[i];

	dp[0] = 0;

	ll ans = solve(coins, x);

	if (ans != 1e18)
		cout << ans << '\n';
	else
		cout << "-1\n";
}
