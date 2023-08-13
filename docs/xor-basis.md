---
title: xor basis (線性基)
documentation_of: ../library/math/xor-basis.hpp
---

## 使用方法

```cpp
xor_basis<60> b; // [0, 2^60)

long long x, k;
b.insert(x);
long long mn = b.get_min();
long long mx = b.get_max();
long long kth = b.get_kth(k); // 如果超過範圍回傳 -1
bool has_x = b.contains(x);

xor_basis<60> c;
b.merge(c); // 把 c 的基底合併進 b
```

## 題目

1. [ABC283 G - Partial Xor Enumeration](https://atcoder.jp/contests/abc283/tasks/abc283_g)
2. [ABC236 F - Spices](https://atcoder.jp/contests/abc236/tasks/abc236_f)
3. [CF 1778E - The Tree Has Fallen!](https://codeforces.com/problemset/problem/1778/E)

## References

1. [CF - A Beautiful Technique for Some XOR Related Problems](https://codeforces.com/blog/entry/68953)
