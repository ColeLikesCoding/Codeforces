#include <iostream>
using namespace std;

int solve(int has, int goal) {
	if (has >= goal)
		return has - goal;
	return (goal % 2 ? solve(has, goal+1) : solve(has, goal / 2)) + 1;
}


int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	cout << solve(n, m);

	return 0;
}