#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int& e : a) cin >> e;

	vector<int> cpy = a;
	sort(a.begin(), a.end());
	int i;
	for (i = 0; i < n; ++i)
	if (m - a[i] < 0) break;
	else m -= a[i];

	if (i != 0 && i != n && m + a[i-1] >= cpy[i])
		++i;
	cout << n-i+1 << endl;

}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}