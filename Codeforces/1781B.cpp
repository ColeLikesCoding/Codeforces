#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> V(N);
	for (int& n : V) cin >> n;

	sort(begin(V), end(V));
	int ans = V[0] != 0;
	for (int i = 0; i < N; ++i)
		if (V[i] <= i && (i + 1 == N || V[i + 1] > i + 1))
			++ans;
	cout << ans << endl;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}