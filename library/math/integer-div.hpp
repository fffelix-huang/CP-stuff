#pragma once

namespace felix {

template<class T>
T floor_div(T a, T b) {
	return a / b - ((a ^ b) < 0 && a % b != 0);
}

template<class T>
T ceil_div(T a, T b) {
	return a / b + ((a ^ b) > 0 && a % b != 0);
}

} // namespace felix
