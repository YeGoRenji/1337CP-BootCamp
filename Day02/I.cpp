#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define endl '\n'

ll gcd(ll a, ll b)
{
    if (!b)
        return (a);
    if (a < b)
        swap(a, b);
    return (gcd(b, a % b));

}

int main(void)
{
    ll n; cin >> n;
	ll result = 0;
	while (n--)
	{
		ll k; cin >> k;
		result = gcd(k, result);
	}
	cout << result << endl;
}
