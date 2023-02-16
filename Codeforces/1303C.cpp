#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string ans;
unordered_map<char, unordered_set<char>> adj;

void f(char c, bool dir) { // true = right
	if(dir) ans.push_back(c);
	else ans.insert(begin(ans), c);

	if(adj[c].empty()) return;

	char nxt = *begin(adj[c]);
	adj[nxt].erase(c);
	f(nxt, dir);
}

void solve() {
	string s; cin >> s;

	if (size(s) == 1) {
		cout << "YES\nabcdefghijklmnopqrstuvwxyz\n";
		return;
	}

	adj.clear();
	for(int i=0; i<size(s); ++i) {
		if(i>0) adj[s[i]].insert(s[i-1]);
		if(i+1<size(s)) adj[s[i]].insert(s[i+1]);
	}

	int check=0;
	for(auto [_, s] : adj) {
		if (size(s) <= 1)
			++check;
		else if (size(s) > 2) {
			cout << "NO\n";
			return;
		}
	}
	if ((size(adj)<26 && check<1) || (size(adj)==26 && check<2)) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

	ans = s[0];
	
	if (size(adj[s[0]]) > 0) {
		char l = *begin(adj[s[0]]);
			adj[l].erase(s[0]);
			f(l, true);
	}
	
	if (size(adj[s[0]]) > 1) {
		char r = *next(begin(adj[s[0]]), 1);
		adj[r].erase(s[0]);
		f(r, false);
	}
	for (char c : string("abcdefghijklmnopqrstuvwxyz")) {
		if (adj.find(c) == adj.end())
			ans.push_back(c);
	}

	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}