// https://codeforces.com/blog/entry/61203
// https://ideone.com/No6ksW
inline long long hilbertOrder(int x, int y, int pow, int rotate) {
	if(pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow - 1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	long long subSquareSize = 1LL << (2 * pow - 2);
	long long ans = seg * subSquareSize;
	long long add = hilbertOrder(nx, ny, pow - 1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
