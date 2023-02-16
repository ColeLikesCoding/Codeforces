#include <iostream>
using namespace std;

int main() {
	int n, ans=0; cin >> n;
	while (n--) {
		int m=0, tmp;
		for (int i = 0; i < 3; ++i) cin >> tmp, m += tmp;
		if (m >= 2) ++ans;
	}
	cout << ans;
	return 0;
}