#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include <iostream>
#include "../../../library/geometry/point.hpp"
#include "../../../library/geometry/geometry.hpp"
using namespace std;
using namespace felix;
using namespace geometry;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Point<long long> a, b;
	cin >> a >> b;
	int q;
	cin >> q;
	while(q--) {
		Point<long long> c;
		cin >> c;
		if(between(a, c, b)) {
			cout << "ON_SEGMENT\n";
		} else if(between(a, b, c)) {
			cout << "ONLINE_FRONT\n";
		} else if(between(c, a, b)) {
			cout << "ONLINE_BACK\n";
		} else {
			int res = orientation(a, b, c);
			if(res < 0) {
				cout << "CLOCKWISE\n";
			} else {
				cout << "COUNTER_CLOCKWISE\n";
			}
		}
	}
	return 0;
}
