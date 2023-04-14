---
title: DSU (路徑壓縮)
documentation_of: ../library/data-structure/DSU.hpp
---

## 並查集

只使用路徑壓縮。
除了 `d.groups()` 以外的操作複雜度都是 $O(\log n)$。

## 使用方法
```cpp
int n;
DSU d(n);

int u, v;

int x = d.leader(u);
int sz = d.size(u);
bool success = d.merge(u, v);
bool is_same = d.same(u, v);
vector<vector<int>> g = d.groups();
```

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/dsu.html)
