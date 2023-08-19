#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n'

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;

	int i = 0;
	int j = 0;
	int value;
	while (i++ < n)
	{
		j = 0;
		while (j++ < n)
		{
			cin >> value;
			if (value && j > i)
				cout << i << ' ' << j << endl;
		}
	}
}
