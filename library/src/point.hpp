#pragma once
#include <iostream>
#include <cmath>

namespace felix {

template<class T>
struct Point {
	T x, y;

	Point(T a = 0, T b = 0) : x(a), y(b) {}

	Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}

	explicit constexpr operator std::pair<T, T>() const {
		return std::pair<T, T>(x, y);
	}

	constexpr Point& operator+=(const Point& rhs) & {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	constexpr Point& operator-=(const Point& rhs) & {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	constexpr Point& operator*=(const T& rhs) & {
		x *= rhs;
		y *= rhs;
		return *this;
	}

	constexpr Point& operator/=(const T& rhs) & {
		x /= rhs;
		y /= rhs;
		return *this;
	}

	constexpr Point operator+() const {
		return *this;
	}

	constexpr Point operator-() const {
		return Point(-x, -y);
	}

	friend constexpr Point operator+(Point lhs, Point rhs) {
		return lhs += rhs;
	}

	friend constexpr Point operator-(Point lhs, Point rhs) {
		return lhs -= rhs;
	}

	friend constexpr Point operator*(Point lhs, T rhs) {
		return lhs *= rhs;
	}

	friend constexpr Point operator/(Point lhs, T rhs) {
		return lhs /= rhs;
	}

	constexpr bool operator==(const Point& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	constexpr bool operator!=(const Point& rhs) const {
		return !(*this == rhs);
	}

	constexpr T dist2() const {
		return x * x + y * y;
	}

	constexpr long double dist() const {
		return std::sqrt(dist2());
	}

	constexpr long double angle() const {
		return std::atan2(y, x);
	}

	friend constexpr T dot(Point lhs, Point rhs) {
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	friend constexpr T cross(Point lhs, Point rhs) {
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}

	friend constexpr Point dot_cross(Point lhs, Point rhs) {
		return Point(dot(lhs, rhs), cross(lhs, rhs));
	}

	friend constexpr std::istream& operator>>(std::istream& in, Point& p) {
		return in >> p.x >> p.y;
	}
};

} // namespace felix
