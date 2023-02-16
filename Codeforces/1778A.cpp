#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int sum = 0, prev = 0;
	bool flag1 = 0, flag2 = 0;
	while (n--) {
		int cur;  cin >> cur;
		sum += cur;
		if (prev == 0) {
			prev = cur;
			continue;
		}
		flag1 |= prev == -1 && cur == -1;
		flag2 |= prev > 0 != cur > 0;
		prev = cur;
	}
	if (flag1)
		sum += 4;
	else if (!flag2)
		sum -= 4;
	cout << sum << endl;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}