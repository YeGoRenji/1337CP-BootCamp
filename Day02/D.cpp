#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n';

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n; cin >> n;

	double sqrtDelta = sqrt((double)1/4 + 2*n);

	double x1 = (double)-1/2 + sqrtDelta;
	double x2 = (double)-1/2 - sqrtDelta;

	cout << (ll)max(x1, x2) << endl

	return (0);
}
