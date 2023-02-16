#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int k;
long long ans[3], a[3];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for(ll& e : a) cin >> e, --e;
	sort(a, a + 3);
	cin >> k;

	ll tmp = a[2];
	for(int i=0; i<3; ++i) {
		if(a[i]*3 >= k) {
			for(int j=i; j<3; ++j)
				ans[j] += k/(3-i) + (k%(3-i)>j-i);
			break;
		}
		else {
			int n = a[i];
			for (int j = i; j < 3; ++j)
				ans[j] += n, a[j] -= n;
			k -= n*(3-i);
		}
	}
	ans[2] = min(tmp, ans[2]);
	cout << ++ans[0] * ++ans[1] * ++ans[2] << endl;
	return 0;
}