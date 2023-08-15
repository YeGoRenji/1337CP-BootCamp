#include <bits/stdc++.h>

// Notes
//
//
// Prefix multiplication + Modular inverse (Fermat's little thorem)
//
//	Fermat's little thorem :   a^p = a [p]  with p prime
//	a^(p-1) = 1 [p]
//
//  instead of doing a / b u can do  a * b^(p-1)  with p = the mod 1e9 + 7
//

using namespace std;

typedef long long ll;

#define endl '\n'

ll MOD = 1e9 + 7;

ll pow(ll a, ll b)
{
	if (b == 0) return (1);

	ll y = pow(a, b/2);

	ll result;
	if (b % 2 == 0)
		result = ((y % MOD) * (y % MOD)) % MOD;
	else
		return ((y * y) % MOD * (a % MOD)) % MOD;

	return (result);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N, Q; cin >> N >> Q;
	vector<ll> v(N);
	vector<ll> prefix(N+1, 1);

	for(int i = 1; i <= N; ++i)
	{
		cin >> v[i-1];
		prefix[i] = (v[i-1] * prefix[i-1]) % MOD;
	}

	// for (auto vi: v)
	// {
	// 	cout << vi << ' ';
	// }
	// cout << endl;

	// for (int i = 1; i <= N; ++i)
	// {
	// 	cout << prefix[i] << ' ';
	// }
	// cout << endl;

	for (int i = 0; i < Q; i++)
	{
		int L, R; cin >> L >> R;
		ll right = prefix[R];
		ll left  = pow(prefix[L - 1], MOD - 2);
		ll res = (left * right) % MOD;
		if (res < 0)
			res += MOD;
		cout << res << endl;
	}
}
