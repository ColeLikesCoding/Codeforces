#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, S, R;
	cin >> N >> S >> R;

	vector<int> a(N);
	cout << S - R << ' ';
	
	int val = R / (N - 1),
		extra = R - (N - 1) * val;

	for (int i = 1; i < N; ++i)
		cout << val + (i <= extra) << ' ';
	cout << endl;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}