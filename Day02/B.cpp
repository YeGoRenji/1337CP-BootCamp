#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n';

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
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		cout << pow(a, b) << endl;
	}
	return (0);
}
