#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n'

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;

	vector<vector<int> >  adj(n);

	int n_op; cin >> n_op;

	while (n_op--)
	{
		int op; cin >> op;
		
		if (op == 1) {
			int i,j; cin >> i >> j;
			adj[i-1].push_back(j);
			adj[j-1].push_back(i);
		}
		else {
			int who; cin >> who;
			for (auto aj : adj[who-1])
			{
				cout << aj << ' ';
			}
			cout << endl;
		}
	}
}
