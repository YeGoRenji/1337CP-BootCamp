#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define endl '\n'

struct dsu {
	vector<int> par;
	vector<int> min_gold;
	int cnt;

	dsu(int n, vector<int> gold) {
		par.resize(n);
		min_gold.resize(n);
		cnt = n;

		for (int i = 0; i < n; i++) {
			par[i] = i;
			min_gold[i] = gold[i];
		}
	}

	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		int root = find(par[x]);
		par[x] = root;
		return root;
	}

	bool connected(int a, int b) {
		return find(a) == find(b);
	}

	ll get_overall_min_gold()
	{
		set<int> done_roots;
		int n = par.size();
		ll overall_min = 0;

		for (int i = 0; i < n; i++)
		{
			int root = find(i);
			if (done_roots.find(root) != done_roots.end())
				continue;
			overall_min += min_gold[root];
			done_roots.insert(root);
		}

		return (overall_min);
	}

	// root1 -> root2
	void join(int a, int b) {
		int root1 = find(a), root2 = find(b);

		if (root1 == root2)
			return ;
		
		par[root1] = root2;

		min_gold[root2] = min(min_gold[root2], min_gold[root1]);
		cnt--;
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;

	vector<int> gold(n);
	for (int i = 0; i < n; i++)
		cin >> gold[i];

	dsu network = dsu(n, gold);

	while(m--)
	{
		int a, b; cin >> a >> b;

		network.join(a - 1, b - 1);
	}

	cout << network.get_overall_min_gold() << endl;
}
