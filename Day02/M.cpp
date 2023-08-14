#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n';

vector<bool> is_prime(300000 + 1, true);

void sieve()
{
	for (int i = 2; i <= 547; ++i)
		for (int j = i*i; j <= 300000; j += i)
			is_prime[j] = false;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n; cin >> m >> n;

	sieve();

	bool absent = true;
	for (int x = m; x <= n; x++)
	{
		if (is_prime[x])
		{
			cout << x << endl;
			absent = false;
		}
	}
	if (absent) cout << "Absent" << endl;
	return (0);
}
