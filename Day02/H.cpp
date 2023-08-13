#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'

ll MOD = 998244353;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;

	a %= MOD;
	b %= MOD;
	c %= MOD;
	d %= MOD;
	e %= MOD;
	f %= MOD;

	ll abc = (((a * b) % MOD) * (c % MOD)) % MOD;
	ll def = (((d * e) % MOD) * (f % MOD)) % MOD;

	ll ans = (abc - def) % MOD;

	if (ans < 0)
		cout << (MOD + ans) << endl;
	else
		cout << ans << endl;
	return (0);
}
