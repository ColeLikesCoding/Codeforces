#include <bits/stdc++.h>
using namespace std;
#define cnt(s, c) count(begin(s), end(s), c)
#define chr(c) (c==0 ? 'w' : (c==1 ? 'i' : 'n'))

void solve() {
	int m; cin >> m;
	vector<vector<vector<int>>> tbl(3, vector<vector<int>>(3));
	for (int k = 0; k < m; ++k) {
		string s; cin >> s;
		int w = cnt(s, 'w'),
			i = cnt(s, 'i'),
			n = cnt(s, 'n');
		if (!w) {
			if (i > 1) tbl[0][1].emplace_back(k);
			if (n > 1) tbl[0][2].emplace_back(k);
		}
		if (!i) {
			if (w > 1) tbl[1][0].emplace_back(k);
			if (n > 1) tbl[1][2].emplace_back(k);
		}
		if (!n) {
			if (w > 1) tbl[2][0].emplace_back(k);
			if (i > 1) tbl[2][1].emplace_back(k);
		}
	}

	int ans = 0;
	vector<tuple<int, int, int, int>> exchanges;
	for(int need=0; need<3; ++need)
	for(int extra=0; extra<3; ++extra) {
		while (!tbl[need][extra].empty() && !tbl[extra][need].empty()) {
			exchanges.emplace_back(tbl[need][extra][0], extra, tbl[extra][need][0], need);
			tbl[need][extra].erase(tbl[need][extra].begin());
			tbl[extra][need].erase(tbl[extra][need].begin());
			++ans;
		}
	}

	bool flag = 1;
	while (flag) {
		flag = 0;
		for (int need = 0; need < 3; ++need)
			for (int extra = 0; extra < 3; ++extra) {
				while (!tbl[need][extra].empty()) {
					int i = 0; flag = 1;
					for (; i < 3 && tbl[i][need].empty(); ++i);

					exchanges.emplace_back(tbl[need][extra][0], extra, tbl[i][need][0], need);
					if(i != extra) tbl[i][extra].emplace_back(tbl[i][need][0]);
					tbl[i][need].erase(tbl[i][need].begin());
					tbl[need][extra].erase(tbl[need][extra].begin());
					++ans;
				}
			}
	}
	cout << ans << endl;
	for (auto [a1, c1, a2, c2] : exchanges)
		cout << a1+1 << ' ' << chr(c1) << ' ' << a2+1 << ' ' << chr(c2) << endl;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}