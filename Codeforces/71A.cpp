#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		if (size(s) > 10) cout << s[0] << size(s)-2 << s.back();
		else cout << s;
		cout << endl;
	}

	return 0;
}