#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	string number;
	while (t--)
	{
		int n, d; cin >> n >> d;
		string digit(1, d + '0');
		cin >> number;
		bool inserted = false;
		for (int i = 0; i < n; i++) {
			if (d > (number[i] - '0'))
			{
				number.insert(i, digit);
				inserted = true;
				break;
			}
		}
		if (!inserted)
			number.push_back(d + '0');
		cout << number << '\n';
	}
}
