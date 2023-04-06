---
title: xor basis (線性基)
documentation_of: ../library/math/xor-basis.hpp
---

## 概要

參考 References 的文章。

## 使用方法

```cpp
xor_basis<60> b;
b.insert(x);
b.get_min();
b.get_max();
b.get_kth(); // 如果超過範圍回傳 -1
b.contains(x);
b.merge(c); // 把 c 的基底合併進 b
```

## 題目
[ABC283 G - Partial Xor Enumeration](https://atcoder.jp/contests/abc283/tasks/abc283_g)

[ABC236 F - Spices](https://atcoder.jp/contests/abc236/tasks/abc236_f)

[CF 1778E - The Tree Has Fallen!](https://codeforces.com/problemset/problem/1778/E)

## References
[CF - A Beautiful Technique for Some XOR Related Problems](https://codeforces.com/blog/entry/68953)
