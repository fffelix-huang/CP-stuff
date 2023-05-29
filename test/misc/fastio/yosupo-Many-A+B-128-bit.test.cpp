#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include "../../../library/misc/fastio.hpp"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		__int128 a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}
