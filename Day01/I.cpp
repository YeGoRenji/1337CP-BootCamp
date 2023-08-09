#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;

	pair<vector<int>, ll> div1;
	pair<vector<int>, ll> div2;

	for (int i = n; i >= 1; i--) {
		if (div1.second < div2.second) {
			div1.first.push_back(i);
			div1.second += i;
		}
		else {
			div2.first.push_back(i);
			div2.second += i;
		}
	}
	if (div1.second != div2.second)
		cout << "NO\n";
	else {
		cout << "YES " << div1.first.size();
		for (auto nb: div1.first)
			cout << " " << nb;
		cout << " " << div2.first.size();
		for (auto nb: div2.first)
			cout << " " << nb;
		cout << '\n';
	}
}
