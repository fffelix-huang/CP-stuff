#pragma once
#include <chrono>

namespace felix {

inline unsigned long long rng() {
	static unsigned long long SEED = std::chrono::steady_clock::now().time_since_epoch().count();
	SEED ^= SEED << 7;
	SEED ^= SEED >> 9;
	return SEED;
}

} // namespace felix
