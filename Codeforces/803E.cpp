#include <iostream>
using namespace std;

int N, K;
int low[1005], high[1005];

int clamp(int n, int i) {
	if (i == N) return n; // dont clamp on last range
	return min(K - 1, max(-(K - 1), n));
}

bool inBounds(int n, int i) {
	return n <= high[i] && n >= low[i];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	cin >> N >> K;
	string s; cin >> s;

	if (s[N - 1] == 'M') {
		cout << "NO\n";
		return 0;
	}

	for (int i = 1; i <= N; ++i) {
		char c = s[i - 1];
		if (c == 'W') {
			low[i] = low[i - 1] + 1;
			high[i] = max(low[i - 1] + 1, clamp(high[i - 1] + 1, i));
		}
		else if (c == 'L') {
			low[i]  = min(high[i - 1] - 1, clamp(low[i - 1] - 1, i));
			high[i] = high[i - 1] - 1;
		}
		else if (c == 'D') {
			low[i]  = low[i - 1];
			high[i] = high[i - 1];
		} else {
			low[i]  = clamp(low[i - 1]  - 1, i);
			high[i] = clamp(high[i - 1] + 1, i);
		}

		if (clamp(low[i], i) != low[i] || clamp(high[i], i) != high[i]) {
			cout << "NO\n";
			return 0;
		}
	}

	int cur;
	if (high[N] == K) cur = K;
	else if (low[N] == -K) cur = -K;
	else {
		cout << "NO\n";
		return 0;
	}

	for (int i = N; i >= 1; --i) {
		if (s[i - 1] == 'L')
			++cur;
		else if (s[i - 1] == 'W')
			--cur;
		else if (s[i - 1] == '?') {
			if		(inBounds(cur + 1, i - 1))	s[i - 1] = 'L', ++cur;
			else if (inBounds(cur - 1, i - 1))	s[i - 1] = 'W', --cur;
			else								s[i - 1] = 'D';
		}
	}

	cout << s << endl;

	return 0;
}