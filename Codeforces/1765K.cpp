#include <iostream>
using namespace std;

int main() {
	int n, mn=1e9; cin >> n;
	long long sum=0;
	for(int i=0; i<n; ++i)
	for(int j=0; j<n; ++j) {
		int t; cin >> t;
		sum += t;
		if (j == n-i-1)
			mn = min(mn, t);
	}
	cout << sum - mn;
}