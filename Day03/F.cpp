#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n'

ll MOD = 1e9 + 7;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;

	vector<ll> possibles(n + 1);

	possibles[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int d = 1; d <= 6; d++)
		{
			if (d > i) break;
			possibles[i] += possibles[i - d];
			possibles[i] %= MOD;
		}
	}

	cout << possibles[n] << endl;
}
