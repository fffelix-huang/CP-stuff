#ifndef FELIX_TIMER_HPP
#define FELIX_TIMER_HPP 1

#include "felix/includes.hpp"

namespace felix {

class chrono_t {
public:
	std::chrono::steady_clock::time_point start;

	chrono_t() : start(std::chrono::steady_clock::now()) {}

	inline void reset() {
		start = std::chrono::steady_clock::now();
	}

	inline double get_time() const {
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		return time_span.count();
	}
};

} // namespace felix

#endif // FELIX_TIMER_HPP
