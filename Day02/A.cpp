#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool binsearch(vector<int> &arr ,int start, int end, int to_find)
{
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (arr[mid] == to_find)
			return (true);
		else if (arr[mid] < to_find)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (false);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<int> aquired(n);
	for (int i = 0; i < n; i++)
		cin >> aquired[i];
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		int to_check; cin >> to_check;
		cout << (binsearch(aquired, 0, aquired.size() - 1, to_check) ? "YES\n" : "NO\n");
	}
	return (0);
}
