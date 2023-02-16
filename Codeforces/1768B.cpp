#include <iostream>
#include <math.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	int curr = 1;
	float cnt = 0;
	while (n--) {
		int m; cin >> m;
		if (m == curr) ++curr;
		else ++cnt;
	}

	cout << ceil(cnt / k) << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}