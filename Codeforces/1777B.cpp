#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll MOD = 1000000007;

int fact(ll i) {
	if (i == 1)
		return 1;
	return (i * fact(i - 1)) % MOD;
}

void solve() {
	ll N; cin >> N;

	ll ans = fact(N) % MOD;
	ans = (ans * (N - 1)) % MOD;
	ans = (ans * N) % MOD;

	cout << ans << endl;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}