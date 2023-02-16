#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> a(N), b(N);
	for (int& e : a) cin >> e;
	for (int& e : b) cin >> e;

	vector<int> V(N + 1);
	for (int i = 0; i < N; ++i)
	if (b[i] < a[i])
		++V[b[i]], --V[a[i]];

	for(int i=1; i<=N; ++i)
		V[i] += V[i-1];

	vector<int> ans;
	for (int k = 1; k <= N; ++k) {
		bool flag = 1;
		for (int i = k; i <= N; i += k)
			flag &= V[i] == 0;
		if (flag) ans.emplace_back(k);
	}

	cout << size(ans) << endl;
	for (int i = 0; i < size(ans); ++i)
		cout << ans[i] << ' ';
	cout << endl;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}