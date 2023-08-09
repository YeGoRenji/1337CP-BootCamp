#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x; cin >> n >> x; 
	vector<int> arr(n);
	vector<ll> prefix(n+1);
	map<ll, int> prev_occ;

	ll subarrays = 0;

	prev_occ[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i - 1];
		prefix[i] = prefix[i - 1] + arr[i - 1];
		if (prev_occ.find(prefix[i] - x) != prev_occ.end())
			subarrays += prev_occ[prefix[i] - x];
		prev_occ[prefix[i]]++;
	}

	cout << subarrays << '\n';
	
	return 0;
}
