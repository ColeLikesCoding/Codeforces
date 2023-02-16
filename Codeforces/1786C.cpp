#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n; cin >> n;
	vector<int> freq(n + 1);
	for (int i = 1; i <= n; ++i) {
		int hp; cin >> hp;
		freq[hp]++;
	}

	deque<int> q;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (!q.empty() && freq[i]) {
			int k = q.front(); q.pop_front();
			ans += i - k;
			--freq[i];
		}
		if (freq[i] == 0) q.push_back(i);
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}