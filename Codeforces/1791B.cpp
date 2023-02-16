#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	string s; cin >> s;

	int x = 0, y = 0;
	bool flag = 0;
	for (char dir : s) {
		if (dir == 'D') y--;
		else if (dir == 'U') y++;
		else if (dir == 'L') x--;
		else if (dir == 'R') x++;
		flag |= (x == 1 && y == 1);
	}
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