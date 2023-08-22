#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n';

ll MOD = 1e9 + 7;

ll power(ll a, ll b)
{
	if (b == 0) return (1);
	if (a == 0) return (0);

	ll y = (power(a, b/2)) % MOD;

	if (b % 2 == 0)
		return (y * y) % MOD;
	else
		return ((y * y) % MOD * (a % MOD)) % MOD;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<ll> ans;
	for (int i = 0; i < n; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		// u need to fermat's little theorem
		ll bc = (power(b, c)) % MOD;
		if (bc < 0)
			bc += MOD;
		ll abc = (power(a, bc)) % MOD;
		if (abc < 0)
			abc += MOD;
		ans.push_back(abc);
	}

	for (auto an : ans) {
		cout << an << endl;
	}
	return (0);
}
