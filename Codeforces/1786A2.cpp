#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define total a_w + a_b + b_w + b_b

void solve() {
	ll n; cin >> n;

	ll i = 1, a_w=1, a_b=0, b_w=0, b_b=0;
	while (a_w + a_b + b_w + b_b < n) {

		b_b += i * 2 + 1;
		b_w += i * 2;
		if (total >= n) {
			int dif = total - n;
			b_b -= (dif + 1) / 2;
			b_w -= dif / 2;
			break;
		}
		a_w += (i + 1) * 2 + 1;
		a_b += (i + 1) * 2;
		if (total >= n) { 
			int dif = total - n;
			a_w -= (dif + 1) / 2;
			a_b -= dif / 2;
		}
		i += 2;
	}
	cout << a_w << ' ' << a_b << ' ' << b_w << ' ' << b_b << endl;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}