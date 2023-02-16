#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	string pi = "3141592653589793238462643383279";

	for (int i = 0; i < 30; ++i) {
		if (s[i] != pi[i]) {
			cout << i << endl;
			return;
		}
	}
	cout << "30\n";
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}