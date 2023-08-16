#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n'

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;

	int ignore;
	while (t--)
	{
		int n; cin >> n;

		int choices = 10 - n;
		while (n--)
			cin >> ignore;

		cout << (6 * choices * (choices - 1) / 2) << endl;
	}
}
