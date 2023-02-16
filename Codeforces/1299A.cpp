#include <bits/stdc++.h>
using namespace std;

int a[100005], freq[32];

void update(int n) {
    for (int i = 0; n; ++i, n >>= 1)
        freq[i] += n & 1;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], update(a[i]);

    int cmp = 0;
    for (int i = 0; i < 32; ++i)
        cmp |= (freq[i] == 1) << i;

    int best = -1, bestIdx = 0;
    for (int i = 0; i < n; ++i)
        if ((a[i] & cmp) > best)
            best = a[i] & cmp, bestIdx = i;

    int tmp = a[0];
    a[0] = a[bestIdx];
    a[bestIdx] = tmp;

    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    return 0;
}