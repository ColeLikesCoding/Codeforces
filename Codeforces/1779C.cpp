#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int& e : a) cin >> e;

	int cnt = 0;
	priority_queue<ll> pq;
	ll r = 0;
	for(int i=m-1; i>0; --i) {
		pq.push(a[i]);
		r += a[i];
		if (r > 0) {
			r -= pq.top()*2; pq.pop();
			++cnt;
		}
	}
	priority_queue<ll, vector<ll>, greater<ll>> pq2;
	ll l = 0;
	for (int i = m; i < n; ++i) {
		pq2.push(a[i]);
		l += a[i];
		if (l < 0) {
			l -= pq2.top()*2; pq2.pop();
			++cnt;
		}
	}

	cout << cnt << endl;
}

int main() {
	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}