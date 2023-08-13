#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cassert>

namespace felix {

struct Bitset {
private:
	using block = unsigned long long;
	static constexpr int block_size = std::numeric_limits<block>::digits;

	int n, len;
	std::vector<block> bits;

	struct bitref {
		block& b;
		std::size_t i;
		operator bool() const { return b >> i & 1; }
		bool test() const { return b >> i & 1; }
		void set() { b |= block(1) << i; }
		void reset() { b &= ~(block(1) << i); }
		void flip() { b ^= block(1) << i; }
		bitref& operator&=(bool val) { b &= block(val) << i; return *this; }
		bitref& operator|=(bool val) { b |= block(val) << i; return *this; }
		bitref& operator^=(bool val) { b ^= block(val) << i; return *this; }
		bitref& operator=(bool val) { val ? set() : reset(); return *this; }
		bitref& operator=(const bitref& v) { return *this = bool(v); }
	};

	constexpr void _clean() {
		if(len != block_size * n) {
			bits.back() &= (block(1) << (len - block_size * (n - 1))) - 1;
		}
	}

public:
	Bitset() {}
	explicit Bitset(int _len): len(_len) {
		n = (len + block_size - 1) / block_size;
		bits.assign(n, 0);
	}

	int size() const { return len; }

	void set() {
		for(block& b : bits) {
			b = ~block(0);
		}
		_clean();
	}

	void reset() {
		std::fill(bits.begin(), bits.end(), block(0));
	}

	bool operator[](int i) const {
		assert(0 <= i && i < len);
		return bits[i / block_size] >> (i % block_size) & 1;
	}

	bitref operator[](int i) {
		assert(0 <= i && i < len);
		return bitref{bits[i / block_size], i % block_size};
	}

	Bitset& operator&=(const Bitset& other) {
		assert(len == other.len);
		for(int i = 0; i < n; i++) {
			bits[i] &= other.bits[i];
		}
		return *this;
	}

	Bitset& operator|=(const Bitset& other) {
		assert(len == other.len);
		for(int i = 0; i < n; i++) {
			bits[i] |= other.bits[i];
		}
		return *this;
	}

	Bitset& operator^=(const Bitset& other) {
		assert(len == other.len);
		for(int i = 0; i < n; i++) {
			bits[i] ^= other.bits[i];
		}
		return *this;
	}

	Bitset& operator<<=(int shift) {
		const int wshift = shift / block_size;
		const int offset = shift % block_size;
		if(offset == 0) {
			for(int i = n - 1; i >= wshift; i--) {
				bits[i] = bits[i - wshift];
			}
		} else {
			const int sub_offset = block_size - offset;
			for(int  i = n - 1; i > wshift; i--) {
				bits[i] = ((bits[i - wshift] << offset) | bits[i - wshift - 1] >> sub_offset);
			}
			bits[wshift] = bits[0] << offset;
		}
		std::fill(bits.begin(), bits.begin() + wshift, block(0));
		_clean();
		return *this;
	}

	Bitset& operator>>=(int shift) {
		const int wshift = shift / block_size;
		const int offset = shift % block_size;
		const int limit = n - wshift - 1;
		if(offset == 0) {
			for(int i = 0; i <= limit; i++) {
				bits[i] = bits[i + wshift];
			}
		} else {
			const int sub_offset = block_size - offset;
			for(int i = 0; i < limit; i++) {
				bits[i] = ((bits[i + wshift] >> offset) | (bits[i + wshift + 1] << sub_offset));
			}
			bits[limit] = bits[n - 1] >> offset;
		}
		std::fill(bits.begin() + limit + 1, bits.end(), block(0));
		return *this;
	}

	Bitset& flip() {
		for(block& b : bits) {
			b = ~b;
		}
		_clean();
		return *this;
	}

	Bitset operator&(const Bitset& other) { return Bitset(*this) &= other; }
	Bitset operator|(const Bitset& other) { return Bitset(*this) |= other; }
	Bitset operator^(const Bitset& other) { return Bitset(*this) ^= other; }
	Bitset operator<<(int shift) { return Bitset(*this) <<= shift; }
	Bitset operator>>(int shift) { return Bitset(*this) >>= shift; }
	Bitset operator~() const { return Bitset(*this).flip(); }

	friend bool operator==(const Bitset& a, const Bitset& b) {
		if(a.len != b.len) {
			return false;
		}
		for(int i = 0; i < a.n; i++) {
			if(a.bits[i] != b.bits[i]) {
				return false;
			}
		}
		return true;
	}

	friend bool operator!=(const Bitset& a, const Bitset& b) {
		return !(a == b);
	}

	bool all() const {
		if(len == 0) {
			return true;
		}
		for(int i = 0; i < (int) bits.size(); i++) {
			if(bits[i] != ~block(0)) {
				return false;
			}
		}
		const std::size_t num = n - ((bits.size() - 1) * block_size);
		assert(num > 0);
		const block upper = ((block(1) << (block_size - num)) - 1) << num;
		return (upper | bits.back()) == ~block(0);
	}

	bool none() {
		_clean();
		return std::count(bits.begin(), bits.end(), block(0)) == n;
	}

	bool any() { return !none(); }

	int count() {
		_clean();
		int res = 0;
		for(auto b : bits) {
			res += __builtin_popcountll(b);
		}
		return res;
	}

	// >
	int find_next(int pos) const {
		pos++;
		int i = pos / block_size;
		if(i >= n) {
			return n;
		}
		int num = block_size - pos % block_size;
		block upper = (num > 0 ? (bits[i] >> (block_size - num) << (block_size - num)) : block(0));
		if(upper != 0) {
			return std::min(n, __builtin_ctzll(upper) | (i * block_size));
		}
		while(++i < (int) bits.size()) {
			if(bits[i] != 0) {
				return std::min(n, __builtin_ctzll(bits[i]) | (i * block_size));
			}
		}
		return n;
	}

	// <
	int find_prev(int pos) const {
		if(pos == 0) {
			return -1;
		}
		if((*this)[--pos] == true) {
			return pos;
		}
		int i = pos / block_size;
		block buf = bits[i] & ((1 << (i % block_size)) - 1);
		if(buf != 0) {
			return i * block_size + 63 - __builtin_ctzll(buf);
		}
		while(i--) {
			if(bits[i] != 0) {
				return i * block_size + 63 - __builtin_ctzll(bits[i]);
			}
		}
		return -1;
	}

	int find_first() const { return find_next(-1); }
	int find_last() const { return find_prev(len); }

	std::string to_string() const {
		std::string s;
		for(int i = 0; i < len; i++) {
			s += (*this)[i] + '0';
		}
		return s;
	}

	friend std::ostream& operator<<(std::ostream& out, const Bitset& b) {
		return out << b.to_string();
	}
};

} // namespace felix
