---
title: DSU
documentation_of: ../library/src/DSU.hpp
---

並查集，啟發式合併 + 路徑壓縮。除了 `d.groups()` 以外的操作都是均攤 $O(\alpha(n))$

## 使用方法
```cpp
DSU d(n);
d.leader(u);
d.size(u);
d.merge(u, v);
d.same(u, v);
d.groups();
```

## Links
https://github.com/atcoder/ac-library/blob/master/document_en/dsu.md