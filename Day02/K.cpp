#include <bits/stdc++.h>

// Using prefix gcd
// and   suffix gcd
//
// at each time u can test if removing element ai maximizes the global gcd
// because changing one value of ai can only do two things (keep global gcd the same or lower it)
// so we can only wish for keep in it the same

using namespace std;

typedef long long ll;

#define endl '\n'

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> a(n);
	vector<int> prefix(n+1), suffix(n+2);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		prefix[i] = gcd(prefix[i - 1], a[i - 1]);
	for (int i = n; i >= 1; i--)
		suffix[i] = gcd(suffix[i + 1], a[i - 1]);

	int mx = 1;
	for (int i = 1; i <= n; i++)
		mx = max(mx, gcd(prefix[i-1], suffix[i+1]));

	cout << mx << endl;
}
