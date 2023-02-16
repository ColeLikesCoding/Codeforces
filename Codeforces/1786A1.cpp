#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	ll n; cin >> n;

	ll a = 1, b = 0, i=1;
	while (a + b < n) {
		b += 8 * i - 3;
		if (a + b >= n) { b -= a + b - n; break; }
		a += 8 * i + 1;
		if (a + b >= n) { a -= a + b - n; }
		++i;
	}
	cout << a << ' ' << b << endl;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}