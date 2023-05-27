#pragma once
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SZ(v) ((int) (v).size())
#define FOR(i, begin, end) for(int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for(int i = (end) - 1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using u128 = __uint128_t;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

template<class T, class U> std::istream& operator>>(std::istream& in, std::pair<T, U>& p) { return in >> p.first >> p.second; }
template<class A, class B, class C> std::istream& operator>>(std::istream& in, std::tuple<A, B, C>& tp) { return in >> std::get<0>(tp) >> std::get<1>(tp) >> std::get<2>(tp); }
template<class T, int N> std::istream& operator>>(std::istream& in, std::array<T, N>& a) { for(T& x : a) in >> x; return in; }
template<class T> std::istream& operator>>(std::istream& in, std::vector<T>& a) { for(T& x : a) in >> x; return in; }

template<class Fun>
class y_combinator_result {
	Fun fun_;
	
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};

template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template<class T> bool chmin(T& a, const T& b) { return a > b ? (a = b, true) : false; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? (a = b, true) : false; }
template<class T> std::vector<T> sort_unique(std::vector<T> v) { std::sort(v.begin(), v.end()), v.erase(std::unique(v.begin(), v.end()), v.end()); return v; }

namespace felix {}
