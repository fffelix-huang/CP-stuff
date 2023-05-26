#pragma once
#include <iostream>
#include <cmath>

namespace felix {

namespace geometry {

template<class T>
struct Point {
	T x, y;

	Point(T a = 0, T b = 0) : x(a), y(b) {}
	Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}

	explicit constexpr operator std::pair<T, T>() const { return std::pair<T, T>(x, y); }

	constexpr Point& operator+=(const Point& rhs) & {
		x += rhs.x, y += rhs.y;
		return *this;
	}

	constexpr Point& operator-=(const Point& rhs) & {
		x -= rhs.x, y -= rhs.y;
		return *this;
	}

	constexpr Point& operator*=(const T& rhs) & {
		x *= rhs, y *= rhs;
		return *this;
	}

	constexpr Point& operator/=(const T& rhs) & {
		x /= rhs, y /= rhs;
		return *this;
	}

	constexpr Point operator+() const { return *this; }
	constexpr Point operator-() const { return Point(-x, -y); }
	friend constexpr Point operator+(Point lhs, Point rhs) { return lhs += rhs; }
	friend constexpr Point operator-(Point lhs, Point rhs) { return lhs -= rhs; }
	friend constexpr Point operator*(Point lhs, T rhs) { return lhs *= rhs; }
	friend constexpr Point operator/(Point lhs, T rhs) { return lhs /= rhs; }
	constexpr bool operator==(const Point& rhs) const { return x == rhs.x && y == rhs.y; }
	constexpr bool operator!=(const Point& rhs) const { return !(*this == rhs); }

	// rotate counter-clockwise
	constexpr Point rotate(T theta) const {
		T sin_t = std::sin(theta), cos_t = std::cos(theta);
		return Point(x * cos_t - y * sin_t, x * sin_t + y * cos_t);
	}

	friend constexpr T abs2(Point p) { return p.x * p.x + p.y * p.y; }
	friend constexpr long double abs(Point p) { return std::sqrt(abs2(p)); }
	friend constexpr long double angle(Point p) { return std::atan2(p.y, p.x); }
	friend constexpr T dot(Point lhs, Point rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
	friend constexpr T cross(Point lhs, Point rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }

	friend constexpr std::istream& operator>>(std::istream& in, Point& p) {
		return in >> p.x >> p.y;
	}
};

} // namespace geometry

} // namespace felix
