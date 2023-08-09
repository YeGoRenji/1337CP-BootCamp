#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n; 
	vector<int> vec;

	int prev = -1;
	int current;
	ll moves = 0;
	for (int i = 0; i < n; i++) {
		cin >> current;
		if (prev != - 1 && current < prev)
		{
			moves += prev - current;
			current = prev;
		}
		prev = current;
	}
	cout << moves << '\n';
}
