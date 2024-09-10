---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/misc/fastio.hpp
    title: library/misc/fastio.hpp
  - icon: ':question:'
    path: library/misc/type-traits.hpp
    title: library/misc/type-traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb_128bit
    links:
    - https://judge.yosupo.jp/problem/many_aplusb_128bit
  bundledCode: "#line 1 \"test/misc/fastio/yosupo-Many-A+B-128-bit.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb_128bit\"\r\n\r\n#line\
    \ 2 \"library/misc/fastio.hpp\"\n#include <iostream>\n#include <cstring>\n#include\
    \ <type_traits>\n#line 2 \"library/misc/type-traits.hpp\"\n#include <cassert>\r\
    \n#include <numeric>\r\n#line 5 \"library/misc/type-traits.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\n#ifndef _MSC_VER\r\ntemplate<class\
    \ T> using is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value\
    \ || std::is_same<T, __int128>::value, std::true_type, std::false_type>::type;\r\
    \ntemplate<class T> using is_unsigned_int128 = typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value || std::is_same<T, unsigned __int128>::value, std::true_type,\
    \ std::false_type>::type;\r\ntemplate<class T> using make_unsigned_int128 = typename\
    \ std::conditional<std::is_same<T, __int128_t>::value, __uint128_t, unsigned __int128>;\r\
    \ntemplate<class T> using is_integral = typename std::conditional<std::is_integral<T>::value\
    \ || is_signed_int128<T>::value || is_unsigned_int128<T>::value, std::true_type,\
    \ std::false_type>::type;\r\ntemplate<class T> using is_signed_int = typename\
    \ std::conditional<(is_integral<T>::value && std::is_signed<T>::value) || is_signed_int128<T>::value,\
    \ std::true_type, std::false_type>::type;\r\ntemplate<class T> using is_unsigned_int\
    \ = typename std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value)\
    \ || is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;\r\n\
    template<class T> using to_unsigned = typename std::conditional<is_signed_int128<T>::value,\
    \ make_unsigned_int128<T>, typename std::conditional<std::is_signed<T>::value,\
    \ std::make_unsigned<T>, std::common_type<T>>::type>::type;\r\n#else\r\ntemplate<class\
    \ T> using is_integral = typename std::is_integral<T>;\r\ntemplate<class T> using\
    \ is_signed_int = typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\
    \ std::true_type, std::false_type>::type;\r\ntemplate<class T> using is_unsigned_int\
    \ = typename std::conditional<is_integral<T>::value && std::is_unsigned<T>::value,\
    \ std::true_type, std::false_type>::type;\r\ntemplate<class T> using to_unsigned\
    \ = typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>,\
    \ std::common_type<T>>::type;\r\n#endif\r\n\r\ntemplate<class T> using is_signed_int_t\
    \ = std::enable_if_t<is_signed_int<T>::value>;\r\ntemplate<class T> using is_unsigned_int_t\
    \ = std::enable_if_t<is_unsigned_int<T>::value>;\r\ntemplate<class T> using to_unsigned_t\
    \ = typename to_unsigned<T>::type;\r\n\r\ntemplate<class T> struct safely_multipliable\
    \ {};\r\ntemplate<> struct safely_multipliable<short> { using type = int; };\r\
    \ntemplate<> struct safely_multipliable<unsigned short> { using type = unsigned\
    \ int; };\r\ntemplate<> struct safely_multipliable<int> { using type = long long;\
    \ };\r\ntemplate<> struct safely_multipliable<unsigned int> { using type = unsigned\
    \ long long; };\r\ntemplate<> struct safely_multipliable<long long> { using type\
    \ = __int128; };\r\ntemplate<> struct safely_multipliable<unsigned long long>\
    \ { using type = __uint128_t; };\r\n\r\ntemplate<class T> using safely_multipliable_t\
    \ = typename safely_multipliable<T>::type;\r\n\r\n}  // namespace internal\r\n\
    \r\n}  // namespace felix\r\n#line 6 \"library/misc/fastio.hpp\"\n\nnamespace\
    \ std {\n\nstatic struct FastInput {\n\tstatic constexpr int BUF_SIZE = 1 << 20;\n\
    \tchar buf[BUF_SIZE];\n\tsize_t chars_read = 0;\n\tsize_t buf_pos = 0;\n\tFILE\
    \ *in = stdin;\n\tchar cur = 0;\n\n\tinline char get_char() {\n\t\tif(buf_pos\
    \ >= chars_read) {\n\t\t\tchars_read = fread(buf, 1, BUF_SIZE, in);\n\t\t\tbuf_pos\
    \ = 0;\n\t\t\tbuf[0] = (chars_read == 0 ? -1 : buf[0]);\n\t\t}\n\t\treturn cur\
    \ = buf[buf_pos++];\n\t\t// return cur = getchar_unlocked();\n\t}\n\n\tinline\
    \ void tie(int) {}\n\n\tinline explicit operator bool() { return cur != -1; }\n\
    \n\tinline static bool is_blank(char c) { return c <= ' '; }\n\n\tinline bool\
    \ skip_blanks() {\n\t\twhile(is_blank(cur) && cur != -1) {\n\t\t\tget_char();\n\
    \t\t}\n\t\treturn cur != -1;\n\t}\n\n\tinline FastInput& operator>>(char& c) {\n\
    \t\tskip_blanks();\n\t\tc = cur;\n\t\treturn *this;\n\t}\n\n\tinline FastInput&\
    \ operator>>(string& s) {\n\t\tif(skip_blanks()) {\n\t\t\ts.clear();\n\t\t\tdo\
    \ {\n\t\t\t\ts += cur;\n\t\t\t} while(!is_blank(get_char()));\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\n\ttemplate<class T>\n\tinline FastInput& read_integer(T& n) {\n\
    \t\t// unsafe, doesn't check that characters are actually digits\n\t\tn = 0;\n\
    \t\tif(skip_blanks()) {\n\t\t\tint sign = +1;\n\t\t\tif(cur == '-') {\n\t\t\t\t\
    sign = -1;\n\t\t\t\tget_char();\n\t\t\t}\n\t\t\tdo {\n\t\t\t\tn += n + (n << 3)\
    \ + cur - '0';\n\t\t\t} while(!is_blank(get_char()));\n\t\t\tn *= sign;\n\t\t\
    }\n\t\treturn *this;\n\t}\n\n\ttemplate<class T>\n\tinline typename enable_if<felix::internal::is_integral<T>::value,\
    \ FastInput&>::type operator>>(T& n) {\n\t\treturn read_integer(n);\n\t}\n\n\t\
    inline FastInput& operator>>(__int128& n) {\n\t\treturn read_integer(n);\n\t}\n\
    \n\ttemplate<class T>\n\tinline typename enable_if<is_floating_point<T>::value,\
    \ FastInput&>::type operator>>(T& n) {\n\t\tn = 0;\n\t\tif(skip_blanks()) {\n\t\
    \t\tstring s;\n\t\t\t(*this) >> s;\n\t\t\tsscanf(s.c_str(), \"%lf\", &n);\n\t\t\
    }\n\t\treturn *this;\n\t}\n} fast_input;\n\n#define istream FastInput\n#define\
    \ cin fast_input\n\nstatic struct FastOutput {\n\tstatic constexpr int BUF_SIZE\
    \ = 1 << 20;\n\tchar buf[BUF_SIZE];\n\tsize_t buf_pos = 0;\n\tstatic constexpr\
    \ int TMP_SIZE = 1 << 20;\n\tchar tmp[TMP_SIZE];\n\tFILE *out = stdout;\n \n\t\
    inline void put_char(char c) {\n\t\tbuf[buf_pos++] = c;\n\t\tif(buf_pos == BUF_SIZE)\
    \ {\n\t\t\tfwrite(buf, 1, buf_pos, out);\n\t\t\tbuf_pos = 0;\n\t\t}\n\t\t// putchar_unlocked(c);\n\
    \t}\n\n\t~FastOutput() {\n\t\tfwrite(buf, 1, buf_pos, out);\n\t}\n\n\tinline FastOutput&\
    \ operator<<(char c) {\n\t\tput_char(c);\n\t\treturn *this;\n\t}\n\n\tinline FastOutput&\
    \ operator<<(const char* s) {\n\t\twhile(*s) {\n\t\t\tput_char(*s++);\n\t\t}\n\
    \t\treturn *this;\n\t}\n\n\tinline FastOutput& operator<<(const string& s) {\n\
    \t\tfor(int i = 0; i < (int) s.size(); i++) {\n\t\t\tput_char(s[i]);\n\t\t}\n\t\
    \treturn *this;\n\t}\n\n\ttemplate<class T>\n\tinline char* integer_to_string(T\
    \ n) {\n\t\t// beware of TMP_SIZE\n\t\tchar* p = tmp + TMP_SIZE - 1;\n\t\tif(n\
    \ == 0) {\n\t\t\t*--p = '0';\n\t\t} else {\n\t\t\tbool is_negative = false;\n\t\
    \t\tif(n < 0) {\n\t\t\t\tis_negative = true;\n\t\t\t\tn = -n;\n\t\t\t}\n\t\t\t\
    while(n > 0) {\n\t\t\t\t*--p = (char) ('0' + n % 10);\n\t\t\t\tn /= 10;\n\t\t\t\
    }\n\t\t\tif(is_negative) {\n\t\t\t\t*--p = '-';\n\t\t\t}\n\t\t}\n\t\treturn p;\n\
    \t}\n\n\ttemplate<class T>\n\tinline typename enable_if<felix::internal::is_integral<T>::value,\
    \ char*>::type stringify(T n) {\n\t\treturn integer_to_string(n);\n\t}\n\n\tinline\
    \ char* stringify(__int128 n) {\n\t\treturn integer_to_string(n);\n\t}\n\n\ttemplate<class\
    \ T>\n\tinline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T\
    \ n) {\n\t\tsprintf(tmp, \"%.17f\", n);\n\t\treturn tmp;\n\t}\n\n\ttemplate<class\
    \ T>\n\tinline FastOutput& operator<<(const T& n) {\n\t\tauto p = stringify(n);\n\
    \t\tfor(; *p != 0; p++) {\n\t\t\tput_char(*p);\n\t\t}\n\t\treturn *this;\n\t}\n\
    } fast_output;\n\n#define ostream FastOutput\n#define cout fast_output\n\n} //\
    \ namespace std\n#line 4 \"test/misc/fastio/yosupo-Many-A+B-128-bit.test.cpp\"\
    \nusing namespace std;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\t__int128\
    \ a, b;\r\n\t\tcin >> a >> b;\r\n\t\tcout << a + b << \"\\n\";\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb_128bit\"\r\n\
    \r\n#include \"../../../library/misc/fastio.hpp\"\r\nusing namespace std;\r\n\r\
    \nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint tt;\r\
    \n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\t__int128 a, b;\r\n\t\tcin >> a >> b;\r\
    \n\t\tcout << a + b << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/misc/fastio.hpp
  - library/misc/type-traits.hpp
  isVerificationFile: true
  path: test/misc/fastio/yosupo-Many-A+B-128-bit.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 15:49:06+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/fastio/yosupo-Many-A+B-128-bit.test.cpp
layout: document
redirect_from:
- /verify/test/misc/fastio/yosupo-Many-A+B-128-bit.test.cpp
- /verify/test/misc/fastio/yosupo-Many-A+B-128-bit.test.cpp.html
title: test/misc/fastio/yosupo-Many-A+B-128-bit.test.cpp
---