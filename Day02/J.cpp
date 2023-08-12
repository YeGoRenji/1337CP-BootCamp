#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


ll gcd(ll a, ll b)
{
    if (!b)
        return (a);
    if (a < b)
        swap(a, b);
    return (gcd(b, a % b));

}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

int main(void)
{
    ll a, b; cin >> a >> b;
    cout << lcm(a, b) << '\n';
}
