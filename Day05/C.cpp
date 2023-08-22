#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define endl '\n'

struct segTree {

    ll identity = LONG_LONG_MAX;

    ll fn(ll a, ll b) {
        return min(a, b);
    }

    ll n;
    vector<ll> all;
    vector<ll> s;

    segTree(vector<ll> &a) {
        n = a.size();
        s.resize(4 * n, identity);
        all = a;
        build(1, 0, n-1, 0, n-1);
    }

    void build(ll node, ll start, ll end, const ll l, const ll r) {
        if (start > r || end < l)
            return ;
        
        if (start == end) {
            s[node] = all[start];
            return ;
        }

        ll mid = (start + end) / 2;

        build(2*node, start, mid, l, r); // left node
        build(2*node+1, mid + 1, end, l, r); // right node

        s[node] = fn(s[2*node], s[2*node+1]); // left + right
    }

    void update(ll i, ll val) {
        all[i] = val;
        build(1, 0, n-1, i, i);
    }

    ll query(ll node, ll start, ll end, const ll l, const ll r) {

        if (start > r || end < l)
            return identity;

        if (start >= l && end <= r)
            return s[node];


        ll mid = (start + end) / 2;

        ll left = query(2*node, start, mid, l, r);
        ll right = query(2*node+1, mid+1, end, l, r);

        return fn(left, right);
    }

    ll query(ll l, ll r) {
        return query(1, 0, n-1, l, r);
    }
};


int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q; cin >> n >> q;

	vector<ll> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	segTree sg = segTree(arr);

	while (q--)
	{
		int cmd, arg1, arg2; cin >> cmd >> arg1 >> arg2;

		if (cmd == 1)
			sg.update(arg1 - 1, arg2);
		else
			cout << sg.query(arg1 - 1, arg2 - 1) << endl;
	}
}
