#pragma once
#include <vector>
#include <cassert>
#include "../math/divisor-multiple-transform.hpp"

namespace felix {

template<class T>
std::vector<T> gcd_convolution(const std::vector<T>& a, const std::vector<T>& b) {
	assert(a.size() == b.size());
	auto f = a, g = b;
	divisor_transform::zeta_transform(f);
	divisor_transform::zeta_transform(g);
	for(int i = 0; i < (int) f.size(); i++) {
		f[i] *= g[i];
	}
	divisor_transform::mobius_transform(f);
	return f;
}

} // namespace felix