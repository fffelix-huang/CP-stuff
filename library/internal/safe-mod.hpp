#pragma once

namespace felix {

namespace internal {

template<class T>
constexpr T safe_mod(T x, T m) {
	x %= m;
	if(x < 0) {
		x += m;
	}
	return x;
}

} // namespace internal

} // namespace felix