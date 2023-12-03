---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/bitset.hpp\"\n#include <iostream>\r\
    \n#include <vector>\r\n#include <cstring>\r\n#include <algorithm>\r\n#include\
    \ <limits>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\nstruct Bitset\
    \ {\r\nprivate:\r\n\tusing block = unsigned long long;\r\n\tstatic constexpr int\
    \ block_size = std::numeric_limits<block>::digits;\r\n\r\n\tint n, len;\r\n\t\
    std::vector<block> bits;\r\n\r\n\tstruct bitref {\r\n\t\tblock& b;\r\n\t\tstd::size_t\
    \ i;\r\n\t\toperator bool() const { return b >> i & 1; }\r\n\t\tbool test() const\
    \ { return b >> i & 1; }\r\n\t\tvoid set() { b |= block(1) << i; }\r\n\t\tvoid\
    \ reset() { b &= ~(block(1) << i); }\r\n\t\tvoid flip() { b ^= block(1) << i;\
    \ }\r\n\t\tbitref& operator&=(bool val) { b &= block(val) << i; return *this;\
    \ }\r\n\t\tbitref& operator|=(bool val) { b |= block(val) << i; return *this;\
    \ }\r\n\t\tbitref& operator^=(bool val) { b ^= block(val) << i; return *this;\
    \ }\r\n\t\tbitref& operator=(bool val) { val ? set() : reset(); return *this;\
    \ }\r\n\t\tbitref& operator=(const bitref& v) { return *this = bool(v); }\r\n\t\
    };\r\n\r\n\tconstexpr void _clean() {\r\n\t\tif(len != block_size * n) {\r\n\t\
    \t\tbits.back() &= (block(1) << (len - block_size * (n - 1))) - 1;\r\n\t\t}\r\n\
    \t}\r\n\r\npublic:\r\n\tBitset() {}\r\n\texplicit Bitset(int _len): len(_len)\
    \ {\r\n\t\tn = (len + block_size - 1) / block_size;\r\n\t\tbits.assign(n, 0);\r\
    \n\t}\r\n\r\n\tint size() const { return len; }\r\n\r\n\tvoid set() {\r\n\t\t\
    for(block& b : bits) {\r\n\t\t\tb = ~block(0);\r\n\t\t}\r\n\t\t_clean();\r\n\t\
    }\r\n\r\n\tvoid reset() {\r\n\t\tstd::fill(bits.begin(), bits.end(), block(0));\r\
    \n\t}\r\n\r\n\tbool operator[](int i) const {\r\n\t\tassert(0 <= i && i < len);\r\
    \n\t\treturn bits[i / block_size] >> (i % block_size) & 1;\r\n\t}\r\n\r\n\tbitref\
    \ operator[](int i) {\r\n\t\tassert(0 <= i && i < len);\r\n\t\treturn bitref{bits[i\
    \ / block_size], i % block_size};\r\n\t}\r\n\r\n\tBitset& operator&=(const Bitset&\
    \ other) {\r\n\t\tassert(len == other.len);\r\n\t\tfor(int i = 0; i < n; i++)\
    \ {\r\n\t\t\tbits[i] &= other.bits[i];\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\
    \r\n\tBitset& operator|=(const Bitset& other) {\r\n\t\tassert(len == other.len);\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tbits[i] |= other.bits[i];\r\n\t\t\
    }\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tBitset& operator^=(const Bitset& other)\
    \ {\r\n\t\tassert(len == other.len);\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\
    \t\tbits[i] ^= other.bits[i];\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tBitset&\
    \ operator<<=(int shift) {\r\n\t\tconst int wshift = shift / block_size;\r\n\t\
    \tconst int offset = shift % block_size;\r\n\t\tif(offset == 0) {\r\n\t\t\tfor(int\
    \ i = n - 1; i >= wshift; i--) {\r\n\t\t\t\tbits[i] = bits[i - wshift];\r\n\t\t\
    \t}\r\n\t\t} else {\r\n\t\t\tconst int sub_offset = block_size - offset;\r\n\t\
    \t\tfor(int  i = n - 1; i > wshift; i--) {\r\n\t\t\t\tbits[i] = ((bits[i - wshift]\
    \ << offset) | bits[i - wshift - 1] >> sub_offset);\r\n\t\t\t}\r\n\t\t\tbits[wshift]\
    \ = bits[0] << offset;\r\n\t\t}\r\n\t\tstd::fill(bits.begin(), bits.begin() +\
    \ wshift, block(0));\r\n\t\t_clean();\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tBitset&\
    \ operator>>=(int shift) {\r\n\t\tconst int wshift = shift / block_size;\r\n\t\
    \tconst int offset = shift % block_size;\r\n\t\tconst int limit = n - wshift -\
    \ 1;\r\n\t\tif(offset == 0) {\r\n\t\t\tfor(int i = 0; i <= limit; i++) {\r\n\t\
    \t\t\tbits[i] = bits[i + wshift];\r\n\t\t\t}\r\n\t\t} else {\r\n\t\t\tconst int\
    \ sub_offset = block_size - offset;\r\n\t\t\tfor(int i = 0; i < limit; i++) {\r\
    \n\t\t\t\tbits[i] = ((bits[i + wshift] >> offset) | (bits[i + wshift + 1] << sub_offset));\r\
    \n\t\t\t}\r\n\t\t\tbits[limit] = bits[n - 1] >> offset;\r\n\t\t}\r\n\t\tstd::fill(bits.begin()\
    \ + limit + 1, bits.end(), block(0));\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tBitset&\
    \ flip() {\r\n\t\tfor(block& b : bits) {\r\n\t\t\tb = ~b;\r\n\t\t}\r\n\t\t_clean();\r\
    \n\t\treturn *this;\r\n\t}\r\n\r\n\tBitset operator&(const Bitset& other) { return\
    \ Bitset(*this) &= other; }\r\n\tBitset operator|(const Bitset& other) { return\
    \ Bitset(*this) |= other; }\r\n\tBitset operator^(const Bitset& other) { return\
    \ Bitset(*this) ^= other; }\r\n\tBitset operator<<(int shift) { return Bitset(*this)\
    \ <<= shift; }\r\n\tBitset operator>>(int shift) { return Bitset(*this) >>= shift;\
    \ }\r\n\tBitset operator~() const { return Bitset(*this).flip(); }\r\n\r\n\tfriend\
    \ bool operator==(const Bitset& a, const Bitset& b) {\r\n\t\tif(a.len != b.len)\
    \ {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\treturn a.bits == b.bits;\r\n\t}\r\n\
    \r\n\tfriend bool operator!=(const Bitset& a, const Bitset& b) {\r\n\t\treturn\
    \ !(a == b);\r\n\t}\r\n\r\n\tbool all() const {\r\n\t\tif(len == 0) {\r\n\t\t\t\
    return true;\r\n\t\t}\r\n\t\tfor(int i = 0; i < (int) bits.size(); i++) {\r\n\t\
    \t\tif(bits[i] != ~block(0)) {\r\n\t\t\t\treturn false;\r\n\t\t\t}\r\n\t\t}\r\n\
    \t\tconst std::size_t num = n - ((bits.size() - 1) * block_size);\r\n\t\tassert(num\
    \ > 0);\r\n\t\tconst block upper = ((block(1) << (block_size - num)) - 1) << num;\r\
    \n\t\treturn (upper | bits.back()) == ~block(0);\r\n\t}\r\n\r\n\tbool none() {\r\
    \n\t\t_clean();\r\n\t\treturn std::count(bits.begin(), bits.end(), block(0)) ==\
    \ n;\r\n\t}\r\n\r\n\tbool any() { return !none(); }\r\n\r\n\tint count() {\r\n\
    \t\t_clean();\r\n\t\tint res = 0;\r\n\t\tfor(auto b : bits) {\r\n\t\t\tres +=\
    \ __builtin_popcountll(b);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\t// set\
    \ [l, r) to 1\r\n\tvoid range_set(int l, int r) {\r\n\t\tassert(l <= r && r <=\
    \ len);\r\n\t\tif(l == r) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tstd::size_t lb =\
    \ l / block_size, rb = (r - 1) / block_size;\r\n\t\tstd::size_t li = l % block_size,\
    \ ri = r % block_size;\r\n\t\tif(ri == 0) {\r\n\t\t\tri = block_size;\r\n\t\t\
    }\r\n\t\tif(lb == rb) {\r\n\t\t\tbits[lb] |= mask_range_bits(~block(0), li, ri);\r\
    \n\t\t\treturn;\r\n\t\t}\r\n\t\tbits[lb] |= mask_upper_bits(~block(0), block_size\
    \ - li);\r\n\t\tbits[rb] |= mask_lower_bits(~block(0), ri);\r\n\t\tstd::fill(bits.begin()\
    \ + lb + 1, bits.begin() + rb, ~block(0));\r\n\t\t_clean();\r\n\t}\r\n\r\n\t//\
    \ // set [l, r) to 0\r\n\tvoid range_reset(int l, int r) {\r\n\t\tassert(l <=\
    \ r && r <= len);\r\n\t\tif(l == r) return;\r\n\t\tstd::size_t lb = l / block_size,\
    \ rb = (r - 1) / block_size;\r\n\t\tstd::size_t li = l % block_size, ri = r %\
    \ block_size;\r\n\t\tif(ri == 0) {\r\n\t\t\tri = block_size;\r\n\t\t}\r\n\t\t\
    if(lb == rb) {\r\n\t\t\tbits[lb] &= ~mask_range_bits(~block(0), li, ri);\r\n\t\
    \t\treturn;\r\n\t\t}\r\n\t\tbits[lb] &= ~mask_upper_bits(~block(0), block_size\
    \ - li);\r\n\t\tbits[rb] &= ~mask_lower_bits(~block(0), ri);\r\n\t\tstd::fill(bits.begin()\
    \ + lb + 1, bits.begin() + rb, block(0));\r\n\t}\r\n\r\n\t// set [l, r) to type\r\
    \n\tvoid range_update(int l, int r, bool type) { type ? range_set(l, r) : range_reset(l,\
    \ r); }\r\n\r\n\t// >\r\n\tint find_next(int pos) const {\r\n\t\tpos++;\r\n\t\t\
    int i = pos / block_size;\r\n\t\tif(i >= n) {\r\n\t\t\treturn n;\r\n\t\t}\r\n\t\
    \tblock upper = mask_upper_bits(bits[i], block_size - pos % block_size);\r\n\t\
    \tif(upper != 0) {\r\n\t\t\treturn std::min(n, __builtin_ctzll(upper) | (i * block_size));\r\
    \n\t\t}\r\n\t\twhile(++i < (int) bits.size()) {\r\n\t\t\tif(bits[i] != 0) {\r\n\
    \t\t\t\treturn std::min(n, __builtin_ctzll(bits[i]) | (i * block_size));\r\n\t\
    \t\t}\r\n\t\t}\r\n\t\treturn n;\r\n\t}\r\n\r\n\t// <\r\n\tint find_prev(int pos)\
    \ const {\r\n\t\tif(pos == 0) {\r\n\t\t\treturn -1;\r\n\t\t}\r\n\t\tif((*this)[--pos]\
    \ == true) {\r\n\t\t\treturn pos;\r\n\t\t}\r\n\t\tint i = pos / block_size;\r\n\
    \t\tblock buf = bits[i] & ((1 << (i % block_size)) - 1);\r\n\t\tif(buf != 0) {\r\
    \n\t\t\treturn i * block_size + 63 - __builtin_ctzll(buf);\r\n\t\t}\r\n\t\twhile(i--)\
    \ {\r\n\t\t\tif(bits[i] != 0) {\r\n\t\t\t\treturn i * block_size + 63 - __builtin_ctzll(bits[i]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn -1;\r\n\t}\r\n\r\n\tint find_first() const {\
    \ return find_next(-1); }\r\n\tint find_last() const { return find_prev(len);\
    \ }\r\n\r\n\tstd::string to_string() const {\r\n\t\tstd::string s;\r\n\t\tfor(int\
    \ i = 0; i < len; i++) {\r\n\t\t\ts += (*this)[i] + '0';\r\n\t\t}\r\n\t\treturn\
    \ s;\r\n\t}\r\n\r\n\tfriend std::ostream& operator<<(std::ostream& out, const\
    \ Bitset& b) {\r\n\t\treturn out << b.to_string();\r\n\t}\r\n\r\nprivate:\r\n\t\
    static constexpr block get_lower_bits(block b, std::size_t num) {\r\n\t\treturn\
    \ num ? (b << (block_size - num) >> (block_size - num)) : block(0);\r\n\t}\r\n\
    \tstatic constexpr block get_upper_bits(block b, std::size_t num) {\r\n\t\treturn\
    \ num ? (b >> (block_size - num)) : block(0);\r\n\t}\r\n\tstatic constexpr block\
    \ get_range_bits(block b, std::size_t l, std::size_t r) {\r\n\t\treturn l < r\
    \ ? b << (block_size - r) >> (block_size - r + l) : block(0);\r\n\t}\r\n\tstatic\
    \ constexpr block mask_lower_bits(block b, std::size_t num) {\r\n\t\treturn get_lower_bits(b,\
    \ num);\r\n\t}\r\n\tstatic constexpr block mask_upper_bits(block b, std::size_t\
    \ num) {\r\n\t\treturn num ? (b >> (block_size - num) << (block_size - num)) :\
    \ block(0);\r\n\t}\r\n\tstatic constexpr block mask_range_bits(block b, std::size_t\
    \ l, std::size_t r) {\r\n\t\treturn l < r ? b << (block_size - r) >> (block_size\
    \ - r + l) << l : block(0);\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <iostream>\r\n#include <vector>\r\n#include <cstring>\r\
    \n#include <algorithm>\r\n#include <limits>\r\n#include <cassert>\r\n\r\nnamespace\
    \ felix {\r\n\r\nstruct Bitset {\r\nprivate:\r\n\tusing block = unsigned long\
    \ long;\r\n\tstatic constexpr int block_size = std::numeric_limits<block>::digits;\r\
    \n\r\n\tint n, len;\r\n\tstd::vector<block> bits;\r\n\r\n\tstruct bitref {\r\n\
    \t\tblock& b;\r\n\t\tstd::size_t i;\r\n\t\toperator bool() const { return b >>\
    \ i & 1; }\r\n\t\tbool test() const { return b >> i & 1; }\r\n\t\tvoid set() {\
    \ b |= block(1) << i; }\r\n\t\tvoid reset() { b &= ~(block(1) << i); }\r\n\t\t\
    void flip() { b ^= block(1) << i; }\r\n\t\tbitref& operator&=(bool val) { b &=\
    \ block(val) << i; return *this; }\r\n\t\tbitref& operator|=(bool val) { b |=\
    \ block(val) << i; return *this; }\r\n\t\tbitref& operator^=(bool val) { b ^=\
    \ block(val) << i; return *this; }\r\n\t\tbitref& operator=(bool val) { val ?\
    \ set() : reset(); return *this; }\r\n\t\tbitref& operator=(const bitref& v) {\
    \ return *this = bool(v); }\r\n\t};\r\n\r\n\tconstexpr void _clean() {\r\n\t\t\
    if(len != block_size * n) {\r\n\t\t\tbits.back() &= (block(1) << (len - block_size\
    \ * (n - 1))) - 1;\r\n\t\t}\r\n\t}\r\n\r\npublic:\r\n\tBitset() {}\r\n\texplicit\
    \ Bitset(int _len): len(_len) {\r\n\t\tn = (len + block_size - 1) / block_size;\r\
    \n\t\tbits.assign(n, 0);\r\n\t}\r\n\r\n\tint size() const { return len; }\r\n\r\
    \n\tvoid set() {\r\n\t\tfor(block& b : bits) {\r\n\t\t\tb = ~block(0);\r\n\t\t\
    }\r\n\t\t_clean();\r\n\t}\r\n\r\n\tvoid reset() {\r\n\t\tstd::fill(bits.begin(),\
    \ bits.end(), block(0));\r\n\t}\r\n\r\n\tbool operator[](int i) const {\r\n\t\t\
    assert(0 <= i && i < len);\r\n\t\treturn bits[i / block_size] >> (i % block_size)\
    \ & 1;\r\n\t}\r\n\r\n\tbitref operator[](int i) {\r\n\t\tassert(0 <= i && i <\
    \ len);\r\n\t\treturn bitref{bits[i / block_size], i % block_size};\r\n\t}\r\n\
    \r\n\tBitset& operator&=(const Bitset& other) {\r\n\t\tassert(len == other.len);\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tbits[i] &= other.bits[i];\r\n\t\t\
    }\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tBitset& operator|=(const Bitset& other)\
    \ {\r\n\t\tassert(len == other.len);\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\
    \t\tbits[i] |= other.bits[i];\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tBitset&\
    \ operator^=(const Bitset& other) {\r\n\t\tassert(len == other.len);\r\n\t\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\t\tbits[i] ^= other.bits[i];\r\n\t\t}\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\r\n\tBitset& operator<<=(int shift) {\r\n\t\tconst int wshift\
    \ = shift / block_size;\r\n\t\tconst int offset = shift % block_size;\r\n\t\t\
    if(offset == 0) {\r\n\t\t\tfor(int i = n - 1; i >= wshift; i--) {\r\n\t\t\t\t\
    bits[i] = bits[i - wshift];\r\n\t\t\t}\r\n\t\t} else {\r\n\t\t\tconst int sub_offset\
    \ = block_size - offset;\r\n\t\t\tfor(int  i = n - 1; i > wshift; i--) {\r\n\t\
    \t\t\tbits[i] = ((bits[i - wshift] << offset) | bits[i - wshift - 1] >> sub_offset);\r\
    \n\t\t\t}\r\n\t\t\tbits[wshift] = bits[0] << offset;\r\n\t\t}\r\n\t\tstd::fill(bits.begin(),\
    \ bits.begin() + wshift, block(0));\r\n\t\t_clean();\r\n\t\treturn *this;\r\n\t\
    }\r\n\r\n\tBitset& operator>>=(int shift) {\r\n\t\tconst int wshift = shift /\
    \ block_size;\r\n\t\tconst int offset = shift % block_size;\r\n\t\tconst int limit\
    \ = n - wshift - 1;\r\n\t\tif(offset == 0) {\r\n\t\t\tfor(int i = 0; i <= limit;\
    \ i++) {\r\n\t\t\t\tbits[i] = bits[i + wshift];\r\n\t\t\t}\r\n\t\t} else {\r\n\
    \t\t\tconst int sub_offset = block_size - offset;\r\n\t\t\tfor(int i = 0; i <\
    \ limit; i++) {\r\n\t\t\t\tbits[i] = ((bits[i + wshift] >> offset) | (bits[i +\
    \ wshift + 1] << sub_offset));\r\n\t\t\t}\r\n\t\t\tbits[limit] = bits[n - 1] >>\
    \ offset;\r\n\t\t}\r\n\t\tstd::fill(bits.begin() + limit + 1, bits.end(), block(0));\r\
    \n\t\treturn *this;\r\n\t}\r\n\r\n\tBitset& flip() {\r\n\t\tfor(block& b : bits)\
    \ {\r\n\t\t\tb = ~b;\r\n\t\t}\r\n\t\t_clean();\r\n\t\treturn *this;\r\n\t}\r\n\
    \r\n\tBitset operator&(const Bitset& other) { return Bitset(*this) &= other; }\r\
    \n\tBitset operator|(const Bitset& other) { return Bitset(*this) |= other; }\r\
    \n\tBitset operator^(const Bitset& other) { return Bitset(*this) ^= other; }\r\
    \n\tBitset operator<<(int shift) { return Bitset(*this) <<= shift; }\r\n\tBitset\
    \ operator>>(int shift) { return Bitset(*this) >>= shift; }\r\n\tBitset operator~()\
    \ const { return Bitset(*this).flip(); }\r\n\r\n\tfriend bool operator==(const\
    \ Bitset& a, const Bitset& b) {\r\n\t\tif(a.len != b.len) {\r\n\t\t\treturn false;\r\
    \n\t\t}\r\n\t\treturn a.bits == b.bits;\r\n\t}\r\n\r\n\tfriend bool operator!=(const\
    \ Bitset& a, const Bitset& b) {\r\n\t\treturn !(a == b);\r\n\t}\r\n\r\n\tbool\
    \ all() const {\r\n\t\tif(len == 0) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\tfor(int\
    \ i = 0; i < (int) bits.size(); i++) {\r\n\t\t\tif(bits[i] != ~block(0)) {\r\n\
    \t\t\t\treturn false;\r\n\t\t\t}\r\n\t\t}\r\n\t\tconst std::size_t num = n - ((bits.size()\
    \ - 1) * block_size);\r\n\t\tassert(num > 0);\r\n\t\tconst block upper = ((block(1)\
    \ << (block_size - num)) - 1) << num;\r\n\t\treturn (upper | bits.back()) == ~block(0);\r\
    \n\t}\r\n\r\n\tbool none() {\r\n\t\t_clean();\r\n\t\treturn std::count(bits.begin(),\
    \ bits.end(), block(0)) == n;\r\n\t}\r\n\r\n\tbool any() { return !none(); }\r\
    \n\r\n\tint count() {\r\n\t\t_clean();\r\n\t\tint res = 0;\r\n\t\tfor(auto b :\
    \ bits) {\r\n\t\t\tres += __builtin_popcountll(b);\r\n\t\t}\r\n\t\treturn res;\r\
    \n\t}\r\n\r\n\t// set [l, r) to 1\r\n\tvoid range_set(int l, int r) {\r\n\t\t\
    assert(l <= r && r <= len);\r\n\t\tif(l == r) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\
    \tstd::size_t lb = l / block_size, rb = (r - 1) / block_size;\r\n\t\tstd::size_t\
    \ li = l % block_size, ri = r % block_size;\r\n\t\tif(ri == 0) {\r\n\t\t\tri =\
    \ block_size;\r\n\t\t}\r\n\t\tif(lb == rb) {\r\n\t\t\tbits[lb] |= mask_range_bits(~block(0),\
    \ li, ri);\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tbits[lb] |= mask_upper_bits(~block(0),\
    \ block_size - li);\r\n\t\tbits[rb] |= mask_lower_bits(~block(0), ri);\r\n\t\t\
    std::fill(bits.begin() + lb + 1, bits.begin() + rb, ~block(0));\r\n\t\t_clean();\r\
    \n\t}\r\n\r\n\t// // set [l, r) to 0\r\n\tvoid range_reset(int l, int r) {\r\n\
    \t\tassert(l <= r && r <= len);\r\n\t\tif(l == r) return;\r\n\t\tstd::size_t lb\
    \ = l / block_size, rb = (r - 1) / block_size;\r\n\t\tstd::size_t li = l % block_size,\
    \ ri = r % block_size;\r\n\t\tif(ri == 0) {\r\n\t\t\tri = block_size;\r\n\t\t\
    }\r\n\t\tif(lb == rb) {\r\n\t\t\tbits[lb] &= ~mask_range_bits(~block(0), li, ri);\r\
    \n\t\t\treturn;\r\n\t\t}\r\n\t\tbits[lb] &= ~mask_upper_bits(~block(0), block_size\
    \ - li);\r\n\t\tbits[rb] &= ~mask_lower_bits(~block(0), ri);\r\n\t\tstd::fill(bits.begin()\
    \ + lb + 1, bits.begin() + rb, block(0));\r\n\t}\r\n\r\n\t// set [l, r) to type\r\
    \n\tvoid range_update(int l, int r, bool type) { type ? range_set(l, r) : range_reset(l,\
    \ r); }\r\n\r\n\t// >\r\n\tint find_next(int pos) const {\r\n\t\tpos++;\r\n\t\t\
    int i = pos / block_size;\r\n\t\tif(i >= n) {\r\n\t\t\treturn n;\r\n\t\t}\r\n\t\
    \tblock upper = mask_upper_bits(bits[i], block_size - pos % block_size);\r\n\t\
    \tif(upper != 0) {\r\n\t\t\treturn std::min(n, __builtin_ctzll(upper) | (i * block_size));\r\
    \n\t\t}\r\n\t\twhile(++i < (int) bits.size()) {\r\n\t\t\tif(bits[i] != 0) {\r\n\
    \t\t\t\treturn std::min(n, __builtin_ctzll(bits[i]) | (i * block_size));\r\n\t\
    \t\t}\r\n\t\t}\r\n\t\treturn n;\r\n\t}\r\n\r\n\t// <\r\n\tint find_prev(int pos)\
    \ const {\r\n\t\tif(pos == 0) {\r\n\t\t\treturn -1;\r\n\t\t}\r\n\t\tif((*this)[--pos]\
    \ == true) {\r\n\t\t\treturn pos;\r\n\t\t}\r\n\t\tint i = pos / block_size;\r\n\
    \t\tblock buf = bits[i] & ((1 << (i % block_size)) - 1);\r\n\t\tif(buf != 0) {\r\
    \n\t\t\treturn i * block_size + 63 - __builtin_ctzll(buf);\r\n\t\t}\r\n\t\twhile(i--)\
    \ {\r\n\t\t\tif(bits[i] != 0) {\r\n\t\t\t\treturn i * block_size + 63 - __builtin_ctzll(bits[i]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn -1;\r\n\t}\r\n\r\n\tint find_first() const {\
    \ return find_next(-1); }\r\n\tint find_last() const { return find_prev(len);\
    \ }\r\n\r\n\tstd::string to_string() const {\r\n\t\tstd::string s;\r\n\t\tfor(int\
    \ i = 0; i < len; i++) {\r\n\t\t\ts += (*this)[i] + '0';\r\n\t\t}\r\n\t\treturn\
    \ s;\r\n\t}\r\n\r\n\tfriend std::ostream& operator<<(std::ostream& out, const\
    \ Bitset& b) {\r\n\t\treturn out << b.to_string();\r\n\t}\r\n\r\nprivate:\r\n\t\
    static constexpr block get_lower_bits(block b, std::size_t num) {\r\n\t\treturn\
    \ num ? (b << (block_size - num) >> (block_size - num)) : block(0);\r\n\t}\r\n\
    \tstatic constexpr block get_upper_bits(block b, std::size_t num) {\r\n\t\treturn\
    \ num ? (b >> (block_size - num)) : block(0);\r\n\t}\r\n\tstatic constexpr block\
    \ get_range_bits(block b, std::size_t l, std::size_t r) {\r\n\t\treturn l < r\
    \ ? b << (block_size - r) >> (block_size - r + l) : block(0);\r\n\t}\r\n\tstatic\
    \ constexpr block mask_lower_bits(block b, std::size_t num) {\r\n\t\treturn get_lower_bits(b,\
    \ num);\r\n\t}\r\n\tstatic constexpr block mask_upper_bits(block b, std::size_t\
    \ num) {\r\n\t\treturn num ? (b >> (block_size - num) << (block_size - num)) :\
    \ block(0);\r\n\t}\r\n\tstatic constexpr block mask_range_bits(block b, std::size_t\
    \ l, std::size_t r) {\r\n\t\treturn l < r ? b << (block_size - r) >> (block_size\
    \ - r + l) << l : block(0);\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/bitset.hpp
  requiredBy: []
  timestamp: '2023-12-03 13:41:56+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structure/bitset.hpp
layout: document
redirect_from:
- /library/library/data-structure/bitset.hpp
- /library/library/data-structure/bitset.hpp.html
title: library/data-structure/bitset.hpp
---
