#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	vector<int> L(n), R(n+1);
	set<char> seen;
	for (int i = 0; i < n; ++i) {
		seen.insert(s[i]);
		L[i] = size(seen);
	}
	seen.clear();
	for (int i = n-1; i >=0; --i) {
		seen.insert(s[i]);
		R[i] = size(seen);
	}

	int ans = R[0];
	for (int i = 0; i < n; ++i)
		ans = max(ans, L[i] + R[i + 1]);
	cout << ans << endl;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}