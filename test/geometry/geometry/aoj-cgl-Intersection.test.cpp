#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include <iostream>
#include "../../../library/geometry/point.hpp"
#include "../../../library/geometry/line.hpp"
#include "../../../library/geometry/geometry.hpp"
using namespace std;
using namespace felix;
using namespace geometry;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		Line<long long> a, b;
		cin >> a >> b;
		cout << segment_intersection(a, b) << "\n";
	}
	return 0;
}
