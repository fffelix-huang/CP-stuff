#pragma once
#include <vector>
#include "pow-mod.hpp"

namespace felix {

namespace internal {

bool is_prime(long long n, std::vector<long long> x) {
	long long d = n - 1;
	d >>= __builtin_ctzll(d);
	for(auto a : x) {
		if(n <= a) {
			return true;
		}
		long long t = d;
		long long y = pow_mod_constexpr(a, d, n);
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = __int128(y) * y % n;
			t <<= 1;
		}
		if(y != n - 1 && t % 2 == 0) {
			return false;
		}
	}
	return true;
}

} // namespace internal

bool is_prime(long long n) {
	if(n <= 1) {
		return false;
	}
	for(int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}) {
		if(n % p == 0) {
			return n == p;
		}
	}
	// https://miller-rabin.appspot.com/
	if(n < 341531LL) return internal::is_prime(n, {9345883071009581737LL});
	if(n < 1050535501LL) return internal::is_prime(n, {336781006125LL, 9639812373923155LL});
	if(n < 350269456337LL) return internal::is_prime(n, {4230279247111683200LL, 14694767155120705706LL, 16641139526367750375LL});
	if(n < 55245642489451LL) return internal::is_prime(n, {2, 141889084524735LL, 1199124725622454117LL, 11096072698276303650LL});
	if(n < 7999252175582851LL) return internal::is_prime(n, {2, 4130806001517LL, 149795463772692060LL, 186635894390467037LL, 3967304179347715805LL});
	if(n < 585226005592931977LL) return internal::is_prime(n, {2, 123635709730000LL, 9233062284813009LL, 43835965440333360LL, 761179012939631437LL, 1263739024124850375LL});
	return internal::is_prime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

} // namespace felix
