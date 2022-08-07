// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
class barrett {
public:
	unsigned int m;
	unsigned long long im;

	explicit barrett(unsigned int _m) : m(_m), im((unsigned long long)(-1) / _m + 1) {}

	unsigned int umod() const { return m; }

	unsigned int mul(unsigned int a, unsigned int b) const {
		unsigned long long z = a;
		z *= b;
#ifdef _MSC_VER
		unsigned long long x;
		_umul128(z, im, &x);
#else
		unsigned long long x = (unsigned long long)(((unsigned __int128)(z) * im) >> 64);
#endif
		unsigned int v = (unsigned int)(z - x * m);
		if(m <= v) {
			v += m;
		}
		return v;
	}
};
