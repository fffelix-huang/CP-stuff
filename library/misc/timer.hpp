#pragma once

namespace felix {

struct timer {
public:
	void start() {
		origin = rdtsc();
	}
	
	inline double get_time() const {
		return (rdtsc() - origin) * SECONDS_PER_CLOCK;
	}
	
private:
	constexpr static double SECONDS_PER_CLOCK = 1.0 / 3E9;
	unsigned long long origin;
	
	inline static unsigned long long rdtsc() {
		unsigned long long lo, hi;
		__asm__ volatile("rdtsc" : "=a" (lo), "=d" (hi));
		return (hi << 32) | lo;
	}
};

} // namespace felix
