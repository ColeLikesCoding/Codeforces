#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n; cin >> n;


	vector<vector<int>> a(n, vector<int>(n));
	int high = n * n, low = 1;
	bool cur = false;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = (cur ? high-- : low++);
				cur = !cur;
			}
		}
		else {
			for (int j = n-1; j >= 0; --j) {
				a[i][j] = (cur ? high-- : low++);
				cur = !cur;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}