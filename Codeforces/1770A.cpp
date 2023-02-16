#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		long long tot = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < n; ++i) {
			int k; cin >> k;
			tot += k; pq.push(k);
		}

		for (int i = 0; i < m; ++i) {
			tot -= pq.top(); pq.pop();
			int k; cin >> k;
			tot += k; pq.push(k);
		}
		
		cout << tot << endl;
	}

	return 0;
}