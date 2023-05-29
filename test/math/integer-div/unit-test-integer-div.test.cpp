#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" // dummy

#include <iostream>
#include <cassert>
#include "../../../library/math/integer-div.hpp"
using namespace std;
using namespace felix;

template<class T>
pair<T, T> TEST(T a, T b) {
	return make_pair(floor_div(a, b), ceil_div(a, b));
}

int main() {
	assert(TEST(-2, 4) == make_pair(-1, 0));
	assert(TEST(4, -3) == make_pair(-2, -1));
	assert(TEST(10, 3) == make_pair(3, 4));
	assert(TEST(-10, -3) == make_pair(3, 4));
	assert(TEST(4, -4) == make_pair(-1, -1));
	assert(TEST(-8, 2) == make_pair(-4, -4));
	assert(TEST(12, 3) == make_pair(4, 4));
	assert(TEST(-20, 5) == make_pair(-4, -4));
	assert(TEST(0, 3) == make_pair(0, 0));
	assert(TEST(0, -7) == make_pair(0, 0));

	int a, b;
	cin >> a >> b;
	cout << a + b << "\n";
	return 0;
}
