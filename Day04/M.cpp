#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define endl '\n'

struct dsu {
	vector<int> par;
	vector<int> sz;
	int cnt;

	dsu(int n) {
		par.resize(n);
		sz.resize(n);
		cnt = n;

		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
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

	int size(int x) {
		return sz[find(x)];
	}

	bool connected(int a, int b) {
		return find(a) == find(b);
	}

	void join(int a, int b) {
		int root1 = find(a), root2 = find(b);

		if (root1 == root2)
			return ;
		
		if (sz[root1] > sz[root2])
			swap(root1, root2);

		par[root1] = root2;
		sz[root2] += sz[root1];

		cnt--;
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;

	dsu network = dsu(n);

	while(m--)
	{
		int grpCount;  cin >> grpCount;

		vector<int> grp(grpCount);
		for (int i = 0; i < grpCount; i++)
			cin >> grp[i], grp[i]--;

		for (int i = 1; i < grpCount; i++)
			network.join(grp[i-1], grp[i]);
	}

	for (int i = 0; i < n; i++)
		cout << network.size(i) << ' ';
}
