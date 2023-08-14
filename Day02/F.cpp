#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'

bool good(vector<ll> &a, ll nprods, ll time)
{
	ll possibleMakes = 0;
	for (auto ti : a)
		possibleMakes += time / ti;
	return (possibleMakes >= nprods);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n, t; cin >> n >> t;
	vector<ll> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	ll start = 1;
	ll end = 1;

	while (!good(v, t, end))
		end *= 2;

	ll res = 1;
	while(start <= end)
	{
		ll mid = start + (end - start) / 2;

		if(good(v, t, mid))
		{
			res = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	cout << res << endl;
}
