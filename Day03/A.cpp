#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n'

ll MOD = 1e9 + 7;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	ll result = 1;

	while (n--)
		result = (result * 2) % MOD;

	cout << result << endl;

	return (0);
}
