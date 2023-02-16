#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n; cin >> n;

	vector<int> a(n);
	for (int& e : a) cin >> e;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (i + 1 < n && sum == a[i + 1]) {
			int j = i + 2;
			while (j < n && a[j] == sum)
				++j;
			if (j >= n) {
				j = i;
				while (j >= 0 && a[j]==sum)
					--j;
			}
			if (j < 0) {
				cout << "NO\n";
				return;
			}
			// swap
			int tmp = a[j];
			a[j] = a[i + 1];
			a[i + 1] = tmp;
		}
	}

	cout << "YES\n" << a[0];
	for (int i = 1; i < n; ++i)
		cout << ' ' << a[i];
	cout << endl;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}