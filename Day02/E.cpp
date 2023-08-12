#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'

#define pres 1e-7

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t; cin >> t;

	while (t--)
	{
		double a, b, c; cin >> a >> b >> c;

		double start = 0, end = 1e9;
		double ans;

		while (abs(end - start) > pres)
		{
			ans = start + (end - start) / 2;
			double r = a * ans + b * sin(ans);

			if (r < c)
				start = ans;
			else
				end = ans;
		}
		cout << fixed << setprecision(6) << ans << endl;
	}
}
