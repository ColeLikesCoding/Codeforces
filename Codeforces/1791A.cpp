#include <bits/stdc++.h>
using namespace std;

void solve() {
	char c; cin >> c;
	string s = "codeforces";
	bool flag = s.find(c) != string::npos;
	if (flag) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}