#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	string s; cin >> s;
	int l = 0, r = N - 1;
	while (l < r) {
		if (s[l] == s[r]) break;
		l++, r--;
	}

	cout << r - l + 1 << endl;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}