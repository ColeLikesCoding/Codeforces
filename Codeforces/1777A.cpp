#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	
	int ans = 0, parity = -1, prev;
	while (N--) {
		int m; cin >> m;
		if (parity < 0) {
			parity = m % 2;
			prev = m;
			continue;
		}

		if (m % 2 == parity) {
			++ans;
			parity = !(!parity || !(m%2));
		} else parity = !parity;

		prev = m;
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}