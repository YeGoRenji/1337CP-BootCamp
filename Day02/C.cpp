#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n';

ll MOD = 1e9 + 7;

ll binsearch(ll b)
{
	if (b == 0) return (1);

	ll y = binsearch(b/2);

	ll result;
	if (b % 2 == 0)
		result = ((y % MOD) * (y % MOD)) % MOD;
	else
		result = ((y % MOD) * (y % MOD) * 3) % MOD;

	return (result);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n; cin >> n;

	cout << binsearch(n) << endl;

	return (0);
}
