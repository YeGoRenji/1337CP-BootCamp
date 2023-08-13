
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'

bool good(vector<int> &a, int n, int t)
{

	return (false)
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, t; cin >> n >> t;
	vector<int> v(n);


	ll start = 0;
	ll end = 0;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	ll res = 1;
	while(start <= end)
	{
		ll mid = start + (end - start) / 2;

		// 000000111111111
		if(good(mid, n))
		{
			end = mid - 1;
			res = mid;
		}
		else
			start = mid + 1;
	}
}
