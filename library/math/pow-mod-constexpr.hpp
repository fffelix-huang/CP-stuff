#pragma once
#include <type_traits>
#include "safe-mod.hpp"

namespace felix {

namespace internal {

template<class V, class M>
constexpr V pow_mod_constexpr(V x, long long n, M m) {
	using T = typename std::make_unsigned<V>::type;
	using U = typename std::make_unsigned<M>::type;
    if(m == 1) {
    	return 0;
    }
    U _m = (U) m;
    T r = 1;
    T y = safe_mod<V>(x, m);
    while(n) {
        if(n & 1) {
        	r = (r * y) % _m;
        }
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

} // namespace internal

} // namespace felix
