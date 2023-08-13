---
title: Rolling Hash
documentation_of: ../library/string/rolling-hash.hpp
---

## 使用方法

```cpp
using H = rolling_hash<modint61>;

H s("aaa"), t("aa");
assert(s.get() * 2 == t.get() * 3);

t.add_char('a'); // t = "aaa"
assert(s.get() == t.get());
assert(s.get(0, 2) == t.get(1, 3)); // [l, r)
assert(s.get() + t.get() == H("aaaaaa").get());
```

## 範例

1. [ABC312 Ex - snukesnuke](https://atcoder.jp/contests/abc312/tasks/abc312_h)

## References

1. [https://hitonanode.github.io/cplib-cpp/string/rolling_hash_1d.hpp](https://hitonanode.github.io/cplib-cpp/string/rolling_hash_1d.hpp)
2. [tourist](https://codeforces.com/contest/1609/submission/137263072)
