#pragma once
#include <chrono>

namespace felix {

namespace internal {

// http://xoshiro.di.unimi.it/splitmix64.c
struct splitmix64_hash {
	using u64 = unsigned long long;
	static u64 splitmix64(u64 x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	u64 operator()(u64 x) const {
		static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

} // namespace internal

} // namespace felix
