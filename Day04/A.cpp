#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n'

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;

	n *= n;
	int value;
	int count = 0;
	while (n--)
	{
		cin >> value;
		count += value;
	}
	count /= 2;

	cout << count << endl;

	return (0);
}
