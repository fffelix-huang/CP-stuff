---
title: Link Cut Tree
documentation_of: ../library/data-structure/lazy-LCT.hpp
---

## 使用方法
```cpp
int n;
lazy_LCT<S, e, op, reversal, F, id, mapping, composition> lct(n);

int u, v;

lct.link(u, v);
lct.cut(u, v);
bool connected = lct.is_connected(u, v);
lct.set(u, S{});
S val = lct.get(u);
lct.apply(u, v, F{});
S res = lct.prod(u, v);
```

## References
[https://judge.yosupo.jp/submission/7137](https://judge.yosupo.jp/submission/7137)
[https://hitonanode.github.io/cplib-cpp/data_structure/link_cut_tree.hpp](https://hitonanode.github.io/cplib-cpp/data_structure/link_cut_tree.hpp)
