#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n), r, b;
	for (int& m : a) cin >> m;
	for (int i = 0; i < n; ++i) {
		char c; cin >> c;
		if (c == 'B') b.emplace_back(a[i]);
		else r.emplace_back(a[i]);
	}
	sort(begin(r), end(r));
	sort(begin(b), end(b));
	int ptrR = 0, ptrB = 0;
	for (int i = 1; i <= n; ++i) {
		if (ptrB >= size(b)) {
			if (r[ptrR++] > i) {
				cout << "NO\n";
				return;
			}
		}
		else if (b[ptrB++] < i) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}