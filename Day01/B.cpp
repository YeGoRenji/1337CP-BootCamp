#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q; cin >> n >> q; 
	vector<int> arr(n);
	vector<ll> prefix(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i - 1];
		prefix[i] = prefix[i - 1] ^ arr[i - 1];
	}

	int l;
	int r;
	for (int i = 1; i <= q; i++) {
		cin >> l >> r;
		cout << (prefix[r] ^ prefix[l-1]) << '\n';
	}
	
	return 0;
}
