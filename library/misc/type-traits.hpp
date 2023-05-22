#pragma once
#include <cassert>
#include <numeric>
#include <type_traits>

namespace felix {

namespace internal {

#ifndef _MSC_VER
template<class T> using is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value || std::is_same<T, __int128>::value, std::true_type, std::false_type>::type;
template<class T> using is_unsigned_int128 = typename std::conditional<std::is_same<T, __uint128_t>::value || std::is_same<T, unsigned __int128>::value, std::true_type, std::false_type>::type;
template<class T> using make_unsigned_int128 = typename std::conditional<std::is_same<T, __int128_t>::value, __uint128_t, unsigned __int128>;
template<class T> using is_integral = typename std::conditional<std::is_integral<T>::value || is_signed_int128<T>::value || is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;
template<class T> using is_signed_int = typename std::conditional<(is_integral<T>::value && std::is_signed<T>::value) || is_signed_int128<T>::value, std::true_type, std::false_type>::type;
template<class T> using is_unsigned_int = typename std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value) || is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;
template<class T> using to_unsigned = typename std::conditional<is_signed_int128<T>::value, make_unsigned_int128<T>, typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>, std::common_type<T>>::type>::type;
#else
template<class T> using is_integral = typename std::is_integral<T>;
template<class T> using is_signed_int = typename std::conditional<is_integral<T>::value && std::is_signed<T>::value, std::true_type, std::false_type>::type;
template<class T> using is_unsigned_int = typename std::conditional<is_integral<T>::value && std::is_unsigned<T>::value, std::true_type, std::false_type>::type;
template<class T> using to_unsigned = typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>, std::common_type<T>>::type;
#endif

template<class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template<class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template<class T> using to_unsigned_t = typename to_unsigned<T>::type;

template<class T> struct safely_multipliable {};
template<> struct safely_multipliable<short> { using type = int; };
template<> struct safely_multipliable<unsigned short> { using type = unsigned int; };
template<> struct safely_multipliable<int> { using type = long long; };
template<> struct safely_multipliable<unsigned int> { using type = unsigned long long; };
template<> struct safely_multipliable<long long> { using type = __int128; };
template<> struct safely_multipliable<unsigned long long> { using type = __uint128_t; };
template<> struct safely_multipliable<float> { using type = float; };
template<> struct safely_multipliable<double> { using type = double; };
template<> struct safely_multipliable<long double> { using type = long double; };
template<> struct safely_multipliable<__float128> { using type = __float128; };

template<class T> using safely_multipliable_t = typename safely_multipliable<T>::type;

}  // namespace internal

}  // namespace felix
