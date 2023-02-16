#include <iostream>
using namespace std;

void solve() {
	int n; cin >> n;
	int l = -1, r = -1;
	for (int i = 0; i < n; ++i) {
		char c; cin >> c;
		if (c == 'L')
			l = i;
		else if (c == 'R' && r == -1)
			r = i;
	}
	//cout << n << ' ' << l << ' ' << r << endl;
	if (r == -1 || l == -1)
		cout << "-1\n";
	else if (r < l)
		cout << "0\n";
	else
		cout << r << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while(t--)
		solve();

	return 0;
}