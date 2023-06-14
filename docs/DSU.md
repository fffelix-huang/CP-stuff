---
title: DSU (並查集)
documentation_of: ../library/data-structure/dsu.hpp
---

## 使用方法
```cpp
int n;
DSU d(n); // 只有路徑壓縮
DSU<true> d2(n); // 啟發式合併 + 路徑壓縮

int u, v;

int x = d.leader(u);
int sz = d.size(u);
bool success = d.merge(u, v);
bool is_same = d.same(u, v);
vector<vector<int>> g = d.groups();
```

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/dsu.html)
