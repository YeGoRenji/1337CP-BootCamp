#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n'

ll MOD = 1e9 + 7;

void	solve(string &line)
{
	ll nb_cases = 0;

	int len = line.length();
	for (int i = 0; i < len; ++i)
	{
		if (i == 0 && line[i] != '0')
			nb_cases = 1;
		if (line[i] == '?')
			nb_cases *= 10 - (i == 0);
	}
	cout << nb_cases << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;

	string line;
	while (t--)
	{
		cin >> line;
		solve(line);
	}
}
