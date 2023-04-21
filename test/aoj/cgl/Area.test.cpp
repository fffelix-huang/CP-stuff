#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"

#include <iostream>
#include <vector>
#include "../../../library/geometry/point.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Point<long long>> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += cross(a[i], a[(i + 1) % n]);
	}
	ans = abs(ans);
	cout << ans / 2 << (ans % 2 == 0 ? ".0" : ".5") << "\n";
	return 0;
}
