#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
	int w, d, h;
	cin >> w >> d >> h;
	int a, b, f, g;
	cin >> a >> b >> f >> g;

	int dist[]{
		(d - b) + abs(a - f) + (d - g),
		b + abs(a - f) + g,
		(w - a) + abs (b - g) + (w - f),
		a + abs(b - g) + f
	};

	int best = *min_element(dist, dist + 4);
	cout << best + h << endl;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}