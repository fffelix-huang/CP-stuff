---
title: Wavelet Tree (靜態區間第 $k$ 大)
documentation_of: ../library/data-structure/wavelet-tree.hpp
---

## 使用方法
```cpp
wavelet_tree tree(v); // 初始化
tree.kth(l, r, k); // 回傳區間 [l, r) 的第 k 大 (0-based)
```
