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

	vector<bool> is_source(n, true);
	vector<bool> is_sink(n, true);
	int count_source = n;
	int count_sink = n;

	while (i++ < n)
	{
		j = 0;
		while (j++ < n)
		{
			cin >> value;
			if (value)
			{
				count_sink -= is_sink[i-1] == true;
				count_source -= is_source[j-1] == true;
				is_sink[i-1] = false;
				is_source[j-1] = false;
			}
		}
	}

	cout << count_source;
	for (int i = 0; i < n; i++)
		if (is_source[i])
			cout << ' ' << i+1;
	cout << endl;

	cout << count_sink;
	for (int i = 0; i < n; i++)
		if (is_sink[i])
			cout << ' ' << i+1;
	cout << endl;
}
