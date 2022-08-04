#ifndef FELIX_INTERNAL_BIT_HPP
#define FELIX_INTERNAL_BIT_HPP 1

namespace felix {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
	int x = 0;
	while((1U << x) < (unsigned int)(n)) {
		x++;
	}
	return x;
}

} // namespace internal

} // namespace felix

#endif // FELIX_INTERNAL_BIT_HPP
