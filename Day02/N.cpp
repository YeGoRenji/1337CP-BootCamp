#include <bits/stdc++.h>

// Notes :
//
//
// 1 and t divides t
// so u are looking for one more divider
// let x be this divider
// so t = x * (t / x) since there is only one more
// x has to be (t/x) so  x = t/x =>  t = x^2
// and x has to be prime so that it itself doesn't have more dividers
//
// the conditions are then  x = sqrt(t) has to be Perfect square and Prime !
//

using namespace std;

typedef long long ll;

#define endl '\n'

vector<bool> is_prime(1e6 + 1, true);

void sieve()
{
	for (int i = 2; i <= 1000; ++i)
		for (int j = i*i; j <= 1e6; j += i)
			is_prime[j] = false;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	sieve();
	vector<ll> v(n);

	for(int i = 0; i < n; ++i)
		cin >> v[i];

	for (auto ai : v)
  	{
		ll x = sqrt(ai);
		bool is_perfect_sq = (x*x == ai);
		bool is_prim = is_prime[x];

		if (is_perfect_sq && is_prim)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
