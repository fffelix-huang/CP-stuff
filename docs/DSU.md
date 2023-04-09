---
title: DSU
documentation_of: ../library/data-structure/DSU.hpp
---

## 並查集

只使用路徑壓縮。
除了 `d.groups()` 以外的操作複雜度都是 $O(\log n)$。

## 使用方法
```cpp
DSU d(n);
d.leader(u);
d.size(u);
d.merge(u, v);
d.same(u, v);
d.groups();
```

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/dsu.html)
