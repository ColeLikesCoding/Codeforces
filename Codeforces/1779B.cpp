#include <iostream>
using namespace std;

void solve() {
	int n; cin >> n;
	if (n == 3) cout << "NO\n";
	else if (n % 2) {
		cout << "YES\n";
		int n1=n/2-1, n2=-n1-1;
		for (int i=n/2; i>0; --i)
			cout << n1 << ' ' << n2 << ' ';
		cout << ' ' << n1 << endl;
	} else {
		cout << "YES\n";
		for (int i = 0; i < n; ++i)
			cout << (i % 2 ? -1 : 1) << ' ';
		cout << endl;
	}
}

int main() {
	int t; cin >> t;
	while(t--) solve();
	return 0;
}