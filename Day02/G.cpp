#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'

bool good(vector<ll> &a, ll nsub, ll sum)
{
	ll max_sub = LONG_LONG_MIN;
	ll nb = 0;
	ll sum_tmp = 0;
	cout << "Partition is :";
	for (auto ti : a)
	{
		if (sum_tmp + ti >= sum)
		{
			max_sub = max(max_sub, sum_tmp);
			sum_tmp = 0;
			nb++;
			cout << " |";
		}
		sum_tmp += ti;
		cout << ' ' << ti;
	}
	cout << endl;
	return (nb == nsub && max_sub <= sum);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n, k; cin >> n >> k;
	vector<ll> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	ll start = 1;
	ll end = 1;

	while (good(v, k, end))
		end *= 2;

	ll res = 1;
	while(start <= end)
	{
		ll mid = start + (end - start) / 2;
		cout << "start: " << start << ", mid: " << mid << ", end: " << end << endl;

		if(good(v, k, mid))
		{
			res = mid;
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << res << endl;
}
