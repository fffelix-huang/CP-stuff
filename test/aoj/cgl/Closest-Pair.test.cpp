#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "../../../library/geometry/point.hpp"
#include "../../../library/geometry/closest-pair.hpp"
using namespace std;
using namespace felix;
using namespace geometry;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Point<long double>> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << fixed << setprecision(10) << sqrt(closest_pair(a)) << "\n";
	return 0;
}
