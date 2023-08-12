#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	cout << n << ':';
	int m = n;
	for (int i = 2; i*i < m; ++i)
	{
		while (n % i == 0)
		{
			cout << ' ' << i;
			n /= i;
		}
	}
	if(n >= 2)
		cout << ' ' << n; 
	cout << endl;
}
