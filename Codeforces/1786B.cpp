#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, w, h; cin >> n >> w >> h;

	vector<int> cakes(n), dispensers(n);
	for (int& x : cakes) cin >> x;
	for (int& x : dispensers) cin >> x;

	int l = INT_MIN, r = INT_MAX;
	for (int i = 0; i < n && l<=r; ++i) {
		l = max(l, (cakes[i]-w+h) - dispensers[i]);
		r = min(r, (cakes[i]+w-h) - dispensers[i]);
	}
	//cout << "   " << l << ' ' << r << endl;
	cout << (l <= r ? "YES\n" : "NO\n") << endl;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}