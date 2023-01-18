template<class T>
class Fraction {
public:
	Fraction(T _a = 0) : a(_a), b(1) {}
	Fraction(T _a, T _b) : a(_a), b(_b) {}
	inline Fraction operator-() const { return Fraction(-a, b); }
	inline Fraction operator+(const Fraction& other) const { return {other.b * a + b * other.a, b * other.b}; }
	inline Fraction operator-(const Fraction& other) const { return *this + (-other); }
	inline Fraction operator*(const Fraction& other) const { return {a * other.a, b * other.b}; }
	inline Fraction operator/(const Fraction& other) const { return {a * other.b, b * other.a}; }
	inline Fraction& operator+=(const Fraction& other) { return *this = *this + other; }
	inline Fraction& operator-=(const Fraction& other) { return *this = *this - other; }
	inline Fraction& operator*=(const Fraction& other) { return *this = *this * other; }
	inline Fraction& operator/=(const Fraction& other) { return *this = *this / other; }
	inline bool operator<(const Fraction& other) const { return a * other.b < b * other.a; }
	inline bool operator>(const Fraction& other) const { return other < *this; }
	inline bool operator<=(const Fraction& other) const { return !(other < *this); }
	inline bool operator>=(const Fraction& other) const { return !(*this < other); }
	inline bool operator==(const Fraction& other) const { return a * other.b == b * other.a; }
	inline bool operator!=(const Fraction& r) const { return !(*this == r); }

private:
	T a, b;
};

template<class T>
ostream& operator<<(ostream& out, const Fraction<T>& x) {
	return out << x.a << "/" << x.b;
}
