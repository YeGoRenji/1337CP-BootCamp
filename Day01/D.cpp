#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> memo(45, -1);

ll fibo(int n)
{
	if (memo[n] != -1)
		return memo[n];

	ll ans;
	if (n == 0 || n == 1) ans = 1;
	else ans = fibo(n - 1) + fibo(n - 2);

	memo[n] = ans;
	return (ans);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n; 

	cout << fibo(n) << '\n';

	return 0;
}
