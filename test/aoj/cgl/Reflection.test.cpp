#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"

#include <iostream>
#include <iomanip>
#include <cmath>
#include "../../../library/geometry/point.hpp"
#include "../../../library/geometry/line.hpp"
#include "../../../library/geometry/geometry.hpp"
using namespace std;
using namespace felix;
using namespace geometry;

const long double EPS = 1E-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Line<long double> l;
	cin >> l;
	int q;
	cin >> q;
	while(q--) {
		Point<long double> p;
		cin >> p;
		auto ans = reflection(l, p);
		if(abs(ans.x) < EPS) {
			ans.x = 0;
		}
		if(abs(ans.y) < EPS) {
			ans.y = 0;
		}
		cout << fixed << setprecision(10) << ans.x << " " << ans.y << "\n";
	}
	return 0;
}
