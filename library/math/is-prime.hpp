#pragma once
#include <vector>
#include "pow-mod.hpp"

namespace felix {

namespace internal {

bool is_prime(long long n, std::vector<unsigned long long> x) {
	long long d = n - 1;
	d >>= __builtin_ctzll(d);
	for(auto a : x) {
		if(n <= a) {
			return true;
		}
		long long t = d;
		__uint128_t y = pow_mod_constexpr(a, d, (unsigned long long) n);
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = y * y % n;
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
	if(n < 341531ULL) return internal::is_prime(n, {9345883071009581737ULL});
	if(n < 1050535501ULL) return internal::is_prime(n, {336781006125ULL, 9639812373923155ULL});
	if(n < 350269456337ULL) return internal::is_prime(n, {4230279247111683200ULL, 14694767155120705706ULL, 16641139526367750375ULL});
	if(n < 55245642489451ULL) return internal::is_prime(n, {2, 141889084524735ULL, 1199124725622454117ULL, 11096072698276303650ULL});
	if(n < 7999252175582851ULL) return internal::is_prime(n, {2, 4130806001517ULL, 149795463772692060ULL, 186635894390467037ULL, 3967304179347715805ULL});
	if(n < 585226005592931977ULL) return internal::is_prime(n, {2, 123635709730000ULL, 9233062284813009ULL, 43835965440333360ULL, 761179012939631437ULL, 1263739024124850375ULL});
	return internal::is_prime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

} // namespace felix
