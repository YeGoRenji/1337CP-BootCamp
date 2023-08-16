#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n'

ll MOD = 1e9 + 7;

ll fact[1000001];

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

ll inv(ll a)
{
	return ((ll)pow(a, MOD - 2)) % MOD;
}

void preprocess()
{
	fact[0] = 1;

	const int len = 1000000;

	for (int i = 1; i <= len; i++)
		fact[i] = (fact[i-1] * i) % MOD;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string str; cin >> str;
	map<char, int> occ;

	preprocess();

	for (auto c : str)
		occ[c]++;

	ll numerator = fact[str.length()];

	ll denominator = 1;
	for (auto p : occ)
	{
		if (p.second != 1)
			denominator = (denominator * inv(fact[p.second])) % MOD;
	}

	cout << (numerator * denominator) % MOD << endl;
}
