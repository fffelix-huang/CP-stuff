---
title: Wavelet Tree (靜態區間第 $k$ 大)
documentation_of: ../library/data-structure/wavelet-tree.hpp
---

## 使用方法
```cpp
wavelet_tree tree(v); // 初始化
tree.kth(l, r, k); // 回傳區間 [l, r) 的第 k 大 (0-based)
```

## 題目
[AtCoder Library Practice Contest C - Floor Sum](https://atcoder.jp/contests/practice2/tasks/practice2_c)

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/math.html)
[OI wiki - 類歐幾里得算法](https://oi-wiki.org/math/number-theory/euclidean/)
