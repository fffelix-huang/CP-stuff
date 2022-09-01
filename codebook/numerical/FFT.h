using cd = complex<double>;
 
const double PI = 3.141592653589793238;
 
void fft(vector<cd>& a, bool inv) {
	int n = (int) a.size();
	for(int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for(; j & bit; bit >>= 1) {
			j ^= bit;
		}
		j ^= bit;
		if(i < j) {
			swap(a[i], a[j]);
		}
	}
	for(int len = 2; len <= n; len <<= 1) {
		const double ang = 2 * PI / len * (inv ? -1 : +1);
		cd rot(cos(ang), sin(ang));
		for(int i = 0; i < n; i += len) {
			cd w(1);
			for(int j = 0; j < len / 2; ++j) {
				cd u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= rot;
			}
		}
	}
	if(inv) {
		for(auto& x : a) {
			x /= n;
		}
	}
}
